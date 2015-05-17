#!/Users/jonathaneidelman/.rvm/rubies/ruby-2.1.3/bin/ruby

def cuadratica(a, b, c)
  res1 = (-b + Math.sqrt(b * b - (4 * a * c))) / (2 * a)
  res2 = (-b - Math.sqrt(b * b - (4 * a * c))) / (2 * a)
  puts "Res1: #{res1}, Res2: #{res2}"
end

#Main


puts "Entre a, b, y c, en ese orden"

a = gets.chomp.to_f
b = gets.chomp.to_f
c = gets.chomp.to_f

cuadratica a, b, c
