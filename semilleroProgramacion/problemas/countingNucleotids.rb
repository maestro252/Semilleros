#!/usr/bin/ruby
contA = 0
contG = 0
contC = 0
contT = 0

#main
puts "Ingrese la cadena de nucleotidos a analizar"
s = gets
s.chomp!
s.downcase!
i = 0
while i < s.length
	contA += 1 if s[i] == "a"
	contG += 1 if s[i] == "g"
	contC += 1 if s[i] == "c"
	contT += 1 if s[i] == "t"
	i += 1
end
puts "#{contA} #{contC} #{contG} #{contT}"