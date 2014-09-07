#!/usr/bin/ruby

def mapear(s)
	case s
	when "uuu" then return "f"
	when "uuc" then return "f"
	when "uua" then return "l"
	when "uug" then return "l"
	when "ucu" then return "s"
	when "ucc" then return "s"
	when "uca" then return "s"
	when "ucg" then return "s"	
	when "uau" then return "y"
	when "uac" then return "y"
	when "uaa" then return ""
	when "uag" then return ""
	when "ugu" then return "c"
	when "ugc" then return "c"
	when "uga" then return ""
	when "ugg" then return "w"	
	when "cuu" then return "l"
	when "cuc" then return "l"
	when "cua" then return "l"
	when "cug" then return "l"
	when "ccu" then return "p"
	when "ccc" then return "p"
	when "cca" then return "p"
	when "ccg" then return "p"	
	when "cau" then return "h"
	when "cac" then return "h"
	when "caa" then return "q"
	when "cag" then return "q"
	when "cgu" then return "r"
	when "cgc" then return "r"
	when "cga" then return "r"
	when "cgg" then return "r"
	when "auu" then return "i"
	when "auc" then return "i"
	when "aua" then return "i"
	when "aug" then return "m"
	when "acu" then return "t"
	when "acc" then return "t"
	when "aca" then return "t"
	when "acg" then return "t"	
	when "aau" then return "n"
	when "aac" then return "n"
	when "aaa" then return "k"
	when "aag" then return "k"
	when "agu" then return "s"
	when "agc" then return "s"
	when "aga" then return "r"
	when "agg" then return "r"	
	when "guu" then return "v"
	when "guc" then return "v"
	when "gua" then return "v"
	when "gug" then return "v"
	when "gcu" then return "a"
	when "gcc" then return "a"
	when "gca" then return "a"
	when "gcg" then return "a"	
	when "gau" then return "d"
	when "gac" then return "d"
	when "gaa" then return "e"
	when "gag" then return "e"
	when "ggu" then return "g"
	when "ggc" then return "g"
	when "gga" then return "g"
	when "ggg" then return "g"	
	end
end
file = File.new("rosalind_prot.txt", "r")
cadena = ""
while (line = file.gets)
	line.chomp!
	cadena << line
end
file.close
res = ""

cadena.downcase!
i = 0
while i < cadena.length
	s = cadena[(i)..(i+2)]
	s = mapear(s)
	res += s
	i += 3
end
res.upcase!
puts res
file2 = File.new("answer.txt", "w")
file2.print(res)