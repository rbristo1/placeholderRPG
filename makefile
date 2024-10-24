all:	main

main: compiled/main.o compiled/enemies.o compiled/screenManip.o compiled/battle.o compiled/mapMovements.o
	g++ -msse2 -mavx2 -lm -ldl -lpthread -lncurses -lmenu compiled/main.o compiled/enemies.o compiled/screenManip.o compiled/battle.o compiled/mapMovements.o -o main

compiled/: compiled/
	mkdir compiled
compiled/main.o: implementation/main.cpp
	g++ -c implementation/main.cpp
	mv main.o compiled
compiled/enemies.o:  implementation/enemies.cpp implementation/enemies.h
	g++ -c implementation/enemies.cpp
	mv enemies.o compiled
compiled/screenManip.o: implementation/screenManip.cpp implementation/screenManip.h
	g++ -c implementation/screenManip.cpp
	mv screenManip.o compiled
compiled/battle.o: implementation/battle.cpp implementation/battle.h
	g++ -c implementation/battle.cpp
	mv battle.o compiled
compiled/mapMovements.o: implementation/mapMovements.cpp implementation/mapMovements.h
	g++ -c implementation/mapMovements.cpp
	mv mapMovements.o compiled

clean:
	rm -f *.o main
