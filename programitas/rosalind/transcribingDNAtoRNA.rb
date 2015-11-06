#!/Users/jonathaneidelman/.rvm/rubies/ruby-2.1.3/bin/ruby

def change(s)
  i = 0
  while i < s.length
    if s[i] == 'T'
      s[i] = 'U'
    end
    i += 1
  end
  return s
end

#main
#

s = gets.chomp
res = change(s)

puts res 
