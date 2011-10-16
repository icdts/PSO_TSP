pso_opt: obj/velocity.o obj/position.o obj/particle.o obj/pso_opt.o obj/node.o obj/swarm.o
	g++ obj/velocity.o obj/position.o obj/particle.o obj/pso_opt.o obj/node.o obj/swarm.o -o bin/pso_opt

obj/swarm.o: src/swarm.cpp src/swarm.h
	g++ -c src/swarm.cpp -o obj/swarm.o

obj/particle.o: src/particle.cpp src/particle.h
	g++ -c src/particle.cpp -o obj/particle.o

obj/velocity.o: src/velocity.cpp src/velocity.h
	g++ -c src/velocity.cpp -o obj/velocity.o 

obj/position.o: src/position.cpp src/position.h
	g++ -c src/position.cpp -o obj/position.o

obj/node.o: src/node.cpp src/node.h
	g++ -c src/node.cpp -o obj/node.o

obj/pso_opt.o: src/pso_opt.cpp
	g++ -c src/pso_opt.cpp -o obj/pso_opt.o

clean:
	rm -rf bin/* obj/*
