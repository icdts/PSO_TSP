#!/usr/bin/ruby

#particle_counts = (2..9).to_a | (1..9).to_a.map{|i| i*10} | (1..5).to_a.map{|i| i*100}
#particle_counts = (7..9).to_a.map{|i| i*10} | (1..5).to_a.map{|i| i*100}
particle_counts = [400]


output = File.open("results.csv", "w")

puts "Filename, Particle Count, Best Value, Time Taken"
output.puts "Filename, Particle Count, Best Value, Time Taken"
particle_counts.each do |count|
  Dir.foreach("/home/robb/workspace/ai/PSO_TSP/tests") do |file|
    next if file == '.' or file == '..'

    (0...5).each do 
      begin_time = Time.now
      val = %x{/home/robb/workspace/ai/PSO_TSP/bin/pso_opt #{file} #{count} 0.2 0.4 0.4}
      end_time = Time.now

      val.strip!
      val = "%f" % val
      puts "#{file}, #{count}, #{val}, #{(end_time - begin_time)}"
      output.puts "#{file}, #{count}, #{val}, #{(end_time - begin_time)}"
    end
  end
end
