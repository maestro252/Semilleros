from mpi4py import MPI
import subprocess
import sys
import time
def grep(word, file):
	f = open(file, "r")
	res = []
	cont = 1
	for line in f:
		time.sleep(0.2)
		try:
			line.index(word)
			res.append(str(cont))
			cont = cont + 1
		except:
			cont = cont + 1
			continue
	return res


comm = MPI.COMM_WORLD

rank = comm.Get_rank()

numworkers = comm.size - 1
start = int(round(time.time() * 1000))
if rank == 0:
	command = "ls"
	command = command + " " + sys.argv[1]
	pro = subprocess.Popen(command.split(), stdout=subprocess.PIPE)
	output = pro.communicate()[0]
	output = output.split()	
	print output
	numarchivos = len(output)/numworkers
	cont = 1
	for i in range(0, numworkers):
		if i == 0:
			arr = output[0:numarchivos+len(output)%numworkers]
			cont += numarchivos + len(output)%numworkers
			comm.send(arr, dest=1)
		else:
			arr = output[cont-1:(cont-1)+numarchivos]
			cont += numarchivos
			comm.send(arr, dest=i+1)
	for j in range (1, numworkers+1):
		print "Del worker: ", j
		print comm.recv(source=j)

	end = int(round(time.time() * 1000))
	print "Time: " , end - start

if rank > 0:
	data = comm.recv(source=0)
	#print rank, " me llego ", data
	res = ""
	for file in data:
		lista = ', '.join(grep(sys.argv[2], sys.argv[1]+ "/" + file))
		res += "Archivo: " + file + " lineas: " + lista + "\n"
	comm.send(res, dest=0)
		
