#!/usr/bin/ruby
puts "Ingrese la cadena de ADN"
s = gets.chomp
s.downcase!
i = 0
rna = ""
while i < s.length
	rna << s[i] unless s[i] == "t"
	rna << "u" if s[i] == "t"
	i += 1
end
rna.upcase!
puts rna