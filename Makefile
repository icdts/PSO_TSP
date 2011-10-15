test: velocity.o position.o particle.o test.o node.o
	g++ velocity.o position.o particle.o test.o node.o -o test

particle.o: particle.cpp particle.h
	g++ -c particle.cpp

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

position.o: position.cpp position.h
	g++ -c position.cpp

node.o: node.cpp node.h
	g++ -c node.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf test *.o
