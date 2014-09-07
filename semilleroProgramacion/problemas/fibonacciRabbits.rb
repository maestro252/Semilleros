#!/usr/bin/ruby
#no esta bien resuelto.
    
def func(pairs, to)
	return 0 if to.zero?
	mature = 0
	young = 1
	next_mature = 0
	next_young = 0
	result = 0
	i = 0
	while i <= to
		result = mature + young
		next_mature = mature + young
		next_young = mature * pairs
		mature = next_mature
		young = next_young
		i += 1
	end
	return result
end
puts "entre las parejas y los meses"
pairs = gets.chomp.to_i
to = gets.chomp.to_i
res = func(pairs, to)
puts res 