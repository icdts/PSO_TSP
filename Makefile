test: obj/velocity.o obj/position.o obj/particle.o obj/test.o obj/node.o obj/swarm.o
	g++ -g -O0 obj/velocity.o obj/position.o obj/particle.o obj/test.o obj/node.o obj/swarm.o -o bin/test

obj/swarm.o: src/swarm.cpp src/swarm.h
	g++ -g -O0 -c src/swarm.cpp -o obj/swarm.o

obj/particle.o: src/particle.cpp src/particle.h
	g++ -g -O0 -c src/particle.cpp -o obj/particle.o

obj/velocity.o: src/velocity.cpp src/velocity.h
	g++ -g -O0 -c src/velocity.cpp -o obj/velocity.o 

obj/position.o: src/position.cpp src/position.h
	g++ -g -O0 -c src/position.cpp -o obj/position.o

obj/node.o: src/node.cpp src/node.h
	g++ -g -O0 -c src/node.cpp -o obj/node.o

obj/test.o: src/test.cpp
	g++ -g -O0 -c src/test.cpp -o obj/test.o

clean:
	rm -rf bin/* obj/*
