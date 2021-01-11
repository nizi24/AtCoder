n = gets.chomp.to_i
tour = readlines(chomp: true).map{|line| line.split(' ').map(&:to_i)}
tour_num = 0
x = 0
y = 0
result = false
(0..tour[tour.length - 1][0]).each do |i|
  if tour[tour_num][1] > x
    x += 1
  elsif tour[tour_num][2] > y
    y += 1
  elsif tour[tour_num][1] < x
    x -= 1
  elsif tour[tour_num][2] < y
    y -= 1
  else
    x += 1
  end
  if i + 1 == tour[tour_num][0]
    if tour[tour_num][1] == x && tour[tour_num][2] == y
      result = true
    else
      result = false
      break
    end
    tour_num += 1 if tour[tour_num + 1]
  end
end
puts result ? "Yes":"No"
