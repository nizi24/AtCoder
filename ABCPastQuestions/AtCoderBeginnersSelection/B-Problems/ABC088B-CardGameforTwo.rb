n = gets.to_i
cards = gets.chomp.split(" ").map(&:to_i).sort.reverse
alice = 0
bob = 0
cards.each_with_index do |c, i|
  if i % 2 == 0
    alice += c
  else
    bob += c
  end
end
p alice - bob
