INCLUDES = -I ./lib

all: base.exe

base.exe: base.o
	g++ -o base.exe base.o ${INCLUDES}

base.o: base.cpp
	g++ -I ./lib -include ./Camera/*.cpp -include ./Character/*.cpp -include ./Field/*.cpp -include ./Landmark/*.cpp -include ./Moves/*.cpp -include ./Objects/*.cpp -include ./Perspectives/*.cpp -include ./Scenario/*.cpp -include ./Textures/*.cpp -c *.cpp
