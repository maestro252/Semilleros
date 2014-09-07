#!/usr/bin/ruby
puts "Ingrese un año y diré el ganador de ese mundial"
año = gets.chomp
ganador = case año
	  when "1998"
	       puts "Francia"
	  when "2002"
	       puts "Brasil"
	  when "2006"
	       puts "Italia"
	  when "2010"
	       puts "España"
	  when "1994"
	  	   puts "Brasil"
	  when "1990"
	  	   puts "Alemania"
	  when "1986"
	  	   puts "Argentina"
	  when "1982"
	  	   puts "Brasil"
	  when "1978"
	  	   puts "Argentina"
	  when "1974"
	  	   puts "Alemania"
	  when "1970"
	  	   puts "Brasil"
	  when "1966"
	  	   puts "Inglaterra"
	  when "1962"
	  	   puts "Brasil"
	  when "1958"
	  	   puts "Brasil"
	  when "1954"
	  	   puts "Alemania"
	  when "1950"
	  	   puts "Uruguay"
	  when "1946"
	  	   puts "No hubo mundial"
	  when "1942"
	  	   puts "No hubo mundial"
	  when "1938"
	  	   puts "Francia"
	  when "1934"
	  	   puts "Italia"
	  when "1930"
	  	   puts "Uruguay"
	  else
		puts "En el año #{año} no hubo mundial."
	  end

def primo?(num)
	cont = 0
	i = 1
	while i <= num
		if num % i == 0
			cont += 1
		end
		i += 1
	end
	return true if cont == 2
	return false
end

puts "Ingrese un numero y dire si es primo"
x = gets.chomp.to_i
puts "Es primo" if primo?(x) == true
puts "No es primo" if primo?(x) == false

