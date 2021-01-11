a = gets.chomp.to_i
b = gets.chomp.to_i
c = gets.chomp.to_i
x = gets.chomp.to_i
count = 0
(0..a).each do |i|
  (0..b).each do |j|
    (0..c).each do |k|
      if i*500 + j*100+ k*50 == x
        count += 1
      end
    end
  end
end
puts count
