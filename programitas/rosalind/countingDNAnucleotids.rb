#!/Users/jonathaneidelman/.rvm/rubies/ruby-2.1.3/bin/ruby

def nuc(s)
  a = 0
  c = 0
  g = 0
  t = 0
  
  i = 0

  while i < s.length
    if s[i] == 'A'
      a += 1
    elsif s[i] == 'G'
      g += 1
    elsif s[i] == 'C'
      c += 1
    else
      t += 1
    end 
    i += 1
  end  
  return [a, c, g, t]
end

#main

s = gets.chomp

res = nuc(s)

puts "#{res[0]} #{res[1]} #{res[2]} #{res[3]}"
