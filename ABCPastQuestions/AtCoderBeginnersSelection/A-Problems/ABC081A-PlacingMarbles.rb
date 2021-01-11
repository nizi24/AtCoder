a=gets.chomp.split(//)
r=0
a.each do |s|
  if s == "1"
    r += 1
  end
end
puts "#{r}"
