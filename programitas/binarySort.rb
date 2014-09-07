#!/usr/bin/ruby
arr = Array.new
def binary(arr, start, final, target)
	mid = (start + final) / 2
	return -1 if start > final
	if arr[mid] == target then
		return mid
	elsif target > arr[mid] then
		return binary(arr, mid+1, final, target)
	else
		return binary(arr, start, mid - 1, target)
	end

	return -1
end


puts "ingrese la longitud del arreglo"
longitud = gets.chomp.to_i
for i in (0...longitud)
	puts "ingrese el siguiente numero"
	arr[i] = gets.chomp.to_i
end
puts "ingrese el numero a buscar"
buscar = gets.chomp.to_i
arr.sort!
for k in (0...arr.length)
	print "#{arr[k]}, "
end
if arr.include? buscar then
	ans = binary(arr, 0, arr.length, buscar)
	puts "El numero buscado se encuentra en #{ans} !!!"
else
	puts "El elemento buscado no se encuentra en el arreglo" 
end


