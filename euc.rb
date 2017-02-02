#!/usr/bin/ruby

to_remove = Array.new
Dir.foreach("tests") do |item|
  next if item == '.' or item == '..'

  File.open("tests/#{item}") do |io|
    euc_file = false
    io.each do |line| 
      if euc_file
        if /^\s*\d/ =~ line 
          if /\d+e[\+-]\d/ =~ line
            euc_file = false
            break
          else
            break
          end
        end
      end
      if line =~ /\s*EDGE_WEIGHT_TYPE\s*:\s*EUC_2D\s*/
        euc_file = true
      end
    end

    to_remove.push("tests/#{item}") if !euc_file
  end
end

to_remove.each do |file|
  File.delete(file)
end
