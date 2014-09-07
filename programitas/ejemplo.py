#!/usr/bin/python
import time
class Algoritmos():
	def elevar(self, n=33):
		return n**2
	def fib(self, n):
		if n == 1:
			return 1
		elif n <= 0:
			return 0
		else:
			return (n * self.c(n - 1))
	def primos(self):
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

		final = int(time.time())

		print "Tiempo total: %i segundos" % (final - inicial)


a = Algoritmos()
a.primos()
