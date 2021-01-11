n,a,b = gets.chomp.split(" ").map(&:to_i)
result = 0
(0..n).each do |m|
  str_ary = m.to_s.split(//)
  sum = str_ary.inject(0) { |sum, n| sum += n.to_i }
  if a <= sum && b >= sum
    result += m
  end
end
p result
