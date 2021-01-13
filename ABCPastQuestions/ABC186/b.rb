o = gets.chomp
blocks = readlines(chomp: true).map{|l| l.split(' ').map(&:to_i)}
min = 100
blocks.each do |l|
  nm = l.min
  min = nm if nm < min
end
cnt = 0
blocks.each do |l|
  l.map do |e|
    cnt += e - min
  end
end
puts cnt
