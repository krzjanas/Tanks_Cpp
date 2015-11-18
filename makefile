CXXLAGS=-g -std=c++11 
LFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

OBJS=Obj/TanksGame.o Obj/GlobalCoordinates.o Obj/Stage.o Obj/Grid.o Obj/VisTankBase.o

C=Configure/
S=Stage/
SA=Stage/Additions/
TV=Tanks/Vis/

TanksGame: $(OBJS)
	g++ -o TanksGame $(OBJS) $(LFLAGS)

Obj/TanksGame.o: TanksGame.cpp $(C)GlobalCoordinates.hpp
	g++ -c -o Obj/TanksGame.o TanksGame.cpp $(CXXLAGS)
	
Obj/GlobalCoordinates.o: $(C)GlobalCoordinates.cpp $(C)GlobalCoordinates.hpp
	g++ -c -o Obj/GlobalCoordinates.o $(C)GlobalCoordinates.cpp $(CXXLAGS)
	
Obj/Stage.o: $(S)Stage.cpp $(C)GlobalCoordinates.hpp $(SA)Grid.hpp $(S)Stage.hpp
	g++ -c -o Obj/Stage.o $(S)Stage.cpp $(CXXLAGS)	
	
Obj/Grid.o: $(SA)Grid.cpp $(C)GlobalCoordinates.hpp $(SA)Grid.hpp
	g++ -c -o Obj/Grid.o $(SA)Grid.cpp $(CXXLAGS)	
	
Obj/VisTankBase.o: $(TV)VisTankBase.cpp $(TV)VisTankBase.hpp
	g++ -c -o Obj/VisTankBase.o $(TV)VisTankBase.cpp $(CXXLAGS)		
		
.PHONY: clean run

clean:
	rm -f TanksGame Obj/*.o
	
run:
	./TanksGame
