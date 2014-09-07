#!/usr/bin/ruby
#main
#programa que imprime todos los numero primos, se puede parametrizar para que tome solo un intervalo,
#ademas calcula el tiempo de ejecucion.
puts "A continuacion se imprimiran todos los numero primos"
i = 2
van = 0
inicial = Time.now.to_i
while i <= 5000
	j = 1
	dividen = 0
	while j <= i
		if i % j == 0
			dividen += 1
		end
		j += 1
	end
	if dividen == 2
		puts "Primo encontrado: #{i}"
		#sleep(0.02)
		#system 'say plop'
		van += 1
	end 
	# case i
	# 	when 100 then puts "En los primeros 100 numeros hay #{van} primos"
	# 	when 1000 then puts "En los primeros 1000 numeros hay #{van} primos"
	# 	when 5000 then puts "En los primeros 5000 numeros hay #{van} primos"
	# 	when 7000 then puts "En los primeros 7000 numeros hay #{van} primos"
	# 	when 10000 then puts "En los primeros 10000 numeros hay #{van} primos"
	# 	when 15000 then puts "En los primeros 15000 numeros hay #{van} primos"
	# end
	dividen = 0
	j = 1
	i += 1
end
final = Time.now.to_i

puts "Tiempo total de ejecucion #{final - inicial} segundos"

