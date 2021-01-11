n,y = gets.split(" ").map(&:to_i)
jj = -1
kk = -1
ii = -1
catch(:break) do
  (0..n).each do |j|
    (0..n).each do |k|
      break if n < j+k
      i = n - j - k
      if y == 10000*k + 5000*j + 1000*i
        ii = i
        kk = k
        jj = j
        throw(:break)
      end
    end
  end
end
puts "#{kk} #{jj} #{ii}"
