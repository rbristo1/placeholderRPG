all:	main

main: main.o implementation/enemies.o implementation/screenManip.o implementation/battle.o implementation/mapMovements.o
	g++ -msse2 -mavx2 -lm -ldl -lpthread -lncurses -lmenu main.o implementation/enemies.o implementation/screenManip.o implementation/battle.o implementation/mapMovements.o -o main

main.o: main.cpp
	g++ -c main.cpp
enemies.o:  implementation/enemies.cpp implementation/enemies.h
	g++ -c implementation/enemies.cpp
screenManip.o: implementation/screenManip.cpp implementation/screenManip.h
	g++ -c implementation/screenManip.cpp
battle.o: implementation/battle.cpp implementation/battle.h
	g++ -c implementation/battle.cpp
mapMovements.o: implementation/mapMovements.cpp implementation/mapMovements.h
	g++ -c implementation/mapMovements.cpp

clean:
	rm -f *.o main
