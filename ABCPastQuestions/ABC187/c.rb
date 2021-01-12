n = gets.chomp.to_i
str_ary = readlines.map(&:chomp)
a,b = str_ary.partition { |s| s[0, 1] == "!" }
a.map { |aa| aa.delete!("!") }
r = a & b
puts r == [] ? "satisfiable" : r[0]
