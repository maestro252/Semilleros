#!/usr/bin/ruby
def Swap(arr,i,j)
	aux = arr[j]
	arr[j] = arr[i]
	arr[i] = aux
end
def cocktail(arr)
	swapped = false
	start = 0
	fin = arr.length - 1
	begin
		swapped = false
		for i in start...fin 
			if arr[i] > arr[i + 1]
				Swap(arr,i,i + 1)
				swapped = true
			end
		end 
		unless swapped
			return arr
		end
		swapped = false
		fin -= 1
		i = fin - 1
		while i >= start
			if arr[i] > arr[i + 1]
				Swap(arr,i,i+1)
				swapped = true
			end
			i -= 1
		end
		start += 1
	end while swapped
	return arr
end
#main
puts "Ingrese la longitud del arreglo a ordenar"
longitud = gets.chomp.to_i
a = Array.new(longitud)
i = 0
while i <= longitud - 1
	puts "Ingrese el siguiente elemento"
	item = gets.chomp.to_i
	a[i] = item
	i += 1
end
puts "Se comenzará a ordenar"
a = cocktail(a)
puts "Ya fue ordenado, el resultado es"
a.each { |e| puts e }

