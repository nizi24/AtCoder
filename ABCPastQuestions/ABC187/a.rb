a,b = gets.chomp.split(" ")
aa = 0
bb = 0
a.split(//).each do |i|
  aa += i.to_i
end
b.split(//).each do |n|
  bb += n.to_i
end
puts aa > bb ? aa : bb
