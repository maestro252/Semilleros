#!/Users/jonathaneidelman/.rvm/rubies/ruby-2.2.3/bin/ruby 

def mapping(cc)
  cc.downcase!
  res = case cc
          when "a" then "z"
          when "b" then "y"
          when "c" then "x"
          when "d" then "w"
          when "e" then "v"
          when "f" then "u"
          when "g" then "t"
          when "h" then "s"
          when "i" then "r"
          when "j" then "q"
          when "k" then "p"
          when "l" then "o"
          when "m" then "n"
          when "n" then "m"
          when "o" then "l"
          when "p" then "k"
          when "q" then "j"
          when "r" then "i"
          when "s" then "h"
          when "t" then "g"
          when "u" then "f"
          when "v" then "e"
          when "w" then "d"
          when "x" then "c"
          when "y" then "b"
          when "z" then "a"
          when "\n" then "\n"
          when "\r" then "\r"
          when "\r\n" then "\r\n"
          when nil then "\n"
          when " " then " "
          when "" then ""
          else
            cc
        end
  return res
end

#main
#puts "Ingrese la cadena a traducir"
file = File.new("in.txt", "r")
text = ""
while line = file.gets
  text += line
  text += "\n"
end 
x = text.length
trad = ""
i = 0
(x).times{
  cc = " \n"
  if text[i] != nil
    cc = text[i]
    cc = mapping cc
  else
    cc = " a\n"
  end
  trad << cc
  i += 1
}
file = File.new("out.txt", "w")
file.puts(trad)
file.close
