import sys
import subprocess
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
startTime = int(round(time.time() * 1000))
dir = sys.argv[1]
command = "ls " + dir
pro = subprocess.Popen(command.split(), stdout=subprocess.PIPE)
output = pro.communicate()[0]

output = output.split()

for file in output:
	print grep(sys.argv[2], dir + "/" + file)
finishTime = int(round(time.time() * 1000))
time = finishTime - startTime
print "Tiempo: " , time

