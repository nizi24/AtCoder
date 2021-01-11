n = gets.to_i
mochi = readlines.map(&:to_i).sort.reverse
r = 0
pre = 101
mochi.each do |m|
  if pre > m
    r += 1
    pre = m
  end
end
p r
