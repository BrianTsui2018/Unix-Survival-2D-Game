##*******************************************************************
## Program name:	Project 4 
## Author:  		Brian Tsui
## Date:  			16/11/2017
## Description: 	This is the Make file for Project 3 
##*******************************************************************

Main : Main.o Validate.o SpaceList.o Die.o Game.o Space.o Clear.o Key.o Gate.o Water.o Bread.o Wall.o Hammer.o Edge.o Displayer.o Mapper.o
	g++ -std=c++0x Main.o Validate.o SpaceList.o Die.o Game.o Space.o Clear.o Key.o Gate.o Water.o Bread.o Wall.o Hammer.o Edge.o Displayer.o Mapper.o -o Main

Main.o : Main.cpp GameObjs.hpp
	g++ -std=c++0x -c Main.cpp
	
Validate.o : Validate.cpp Validate.hpp
	g++ -std=c++0x -c Validate.cpp
	
SpaceList.o : SpaceList.cpp SpaceList.hpp
	g++ -std=c++0x -c SpaceList.cpp
	
Die.o : Die.cpp Die.hpp
	g++ -std=c++0x -c Die.cpp

Game.o : Game.cpp Game.hpp
	g++ -std=c++0x -c Game.cpp
	
Space.o : Space.cpp Space.hpp
	g++ -std=c++0x -c Space.cpp
	
Clear.o : Clear.cpp Clear.hpp
	g++ -std=c++0x -c Clear.cpp
	
Key.o : Key.cpp Key.hpp
	g++ -std=c++0x -c Key.cpp
	
Gate.o : Gate.cpp Gate.hpp
	g++ -std=c++0x -c Gate.cpp
	
Water.o : Water.cpp Water.hpp
	g++ -std=c++0x -c Water.cpp

Bread.o : Bread.cpp Bread.hpp
	g++ -std=c++0x -c Bread.cpp

Wall.o : Wall.cpp Wall.hpp
	g++ -std=c++0x -c Wall.cpp	
	
Hammer.o : Hammer.cpp Hammer.hpp
	g++ -std=c++0x -c Hammer.cpp	

Edge.o : Edge.cpp Edge.hpp
	g++ -std=c++0x -c Edge.cpp

Displayer.o : Displayer.cpp Displayer.hpp
	g++ -std=c++0x -c Displayer.cpp

Mapper.o : Mapper.cpp Mapper.hpp
	g++ -std=c++0x -c Mapper.cpp
	
.PHONY : clean
	
clean :
	rm *.o Main
	
