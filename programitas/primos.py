#!/usr/bin/python
import time
#programa que imprime los primos (se puede parametrizar para que sea hasta cierto intervalo) y calcula
#el tiempo de ejecucion.
def primos():
		inicial = int(time.time())

		primo = 2
		while primo <= 5000:
			i = 1
			dividen = 0
			while i <= primo:
				if primo % i == 0:
					dividen += 1
				i += 1
			if dividen == 2:
				print "Primo encontrado %i" % (primo)
			primo += 1

		final = float(time.time())

		print "Tiempo total: %i segundos" % (final - inicial)

primos()
