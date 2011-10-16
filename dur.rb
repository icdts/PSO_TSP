#!/usr/bin/ruby
if (/\d+e[\+-]\d/ =~ "1 1.6390003 2.1560003")
	puts true
else
	puts false
end
