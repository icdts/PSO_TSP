#!/usr/bin/ruby

to_remove = Array.new
Dir.foreach("tests") do |item|
	next if item == '.' or item == '..'

	File.open("tests/#{item}") do |io|
		euc_file = false
		io.each do |line| 
			if line =~ /EUC_2D/
				euc_file = true
				break
			end
		end

		to_remove.push("tests/#{item}") if !euc_file
	end
end

to_remove.each do |file|
	File.delete(file)
end
