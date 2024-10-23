all:	main

main: main.o enemies.o screenManip.o battle.o mapMovements.o
	g++ -msse2 -mavx2 -lm -ldl -lpthread -lncurses -lmenu main.o enemies.o screenManip.o battle.o mapMovements.o -o main

main.o: main.cpp
	g++ -c main.cpp
enemies.o:  enemies.cpp enemies.h
	g++ -c enemies.cpp
screenManip.o: screenManip.cpp screenManip.h
	g++ -c screenManip.cpp
battle.o: battle.cpp battle.h
	g++ -c battle.cpp
mapMovements.o: mapMovements.cpp mapMovements.h
	g++ -c mapMovements.cpp

clean:
	rm -f *.o main
