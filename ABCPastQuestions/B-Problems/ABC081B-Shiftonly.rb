i=gets.to_i
ary=gets.chomp.split(" ").map(&:to_i)
r=0
while ary.filter { |n| n%2==0 }.length == i
  ary = ary.map { |n| n/2 }
  r+=1
end
puts "#{r}"
