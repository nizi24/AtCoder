n = gets.to_i
map = readlines(chomp: true).map{|line| line.split(' ').map(&:to_i)}
result = 0
map.each_with_index do |m, i|
  result += map.select.with_index { |n, ii|
    ii > i && (-1..1).include?((n[1]-m[1]).to_f / (n[0]-m[0]).to_f)
  }.length
end
puts result
