#!/usr/bin/ruby

def is_numeric?(s)
  begin
    Float(s)
  rescue
    false # not numeric
  else
    true # numeric
  end
end

#particle_counts = (2..9).to_a | (1..9).to_a.map{|i| i*10} | (1..5).to_a.map{|i| i*100}
#particle_counts = (7..9).to_a.map{|i| i*10} | (1..5).to_a.map{|i| i*100}
particle_counts = [400]

if ARGV.length != 3
  puts "Args Required:"
  puts "  1: test file directory"
  puts "  2: path of pso bin to use"
  puts "  3: output file"
else
  tests_folder = ARGV[0]
  pso_bin = ARGV[1]
  output_file = ARGV[2]
  output = File.open(output_file, "w")

  puts "Filename, Particle Count, Best Value, Time Taken"
  output.puts "Filename, Particle Count, Best Value, Time Taken"
  particle_counts.each do |count|
    Dir.foreach(tests_folder) do |file|
      next if file == '.' or file == '..'

      (0...5).each do
        begin_time = Time.now
        val = %x{#{pso_bin} #{tests_folder}/#{file} #{count} 0.2 0.4 0.4}
        end_time = Time.now

        val.strip!
        Kernel.abort(val) if not is_numeric?(val)

        val = "%f" % val
        puts "#{file}, #{count}, #{val}, #{(end_time - begin_time)}"
        output.puts "#{file}, #{count}, #{val}, #{(end_time - begin_time)}"
      end
    end
  end
end
