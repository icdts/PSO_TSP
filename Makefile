test: velocity.o position.o test.o
	g++ velocity.o position.o test.o -o test

velocity.o: velocity.cpp velocity.h
	g++ -c velocity.cpp

position.o: position.cpp position.h
	g++ -c position.cpp

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -rf test *.o
