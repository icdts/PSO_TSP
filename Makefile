test: velocity.o position.o particle.o test.o
	g++ velocity.o position.o particle.o test.o -o test

particle.o: particle.cpp particle.h
	g++ -c particle.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

position.o: position.cpp position.h
	g++ -c position.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf test *.o
