#!/usr/bin/ruby
puts "ingrese la cadena a procesar"
s = gets.chomp
s.downcase!
i = 0
dnainv = ""
while i < s.length
	dnainv = "a" + dnainv if s[i] == "t"
	dnainv = "t" + dnainv if s[i] == "a"
	dnainv = "g" + dnainv if s[i] == "c"
	dnainv = "c" + dnainv if s[i] == "g"
	i += 1
end
dnainv.upcase!()
puts dnainv