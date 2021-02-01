INCLUDES = -I .
LIBRARY_PATH = -L./lib

all: base.exe

base.exe: base.o
	g++ -o base.exe base.o

base.o: base.cpp
	g++ -I ./lib -include ./Camera/*.cpp -include ./Character/*.cpp -include ./Field/*.cpp -include ./Landmark/*.cpp -include ./Moves/*.cpp -include ./Objects/*.cpp -include ./Perspectives/*.cpp -include ./Scenario/*.cpp -include ./Textures/*.cpp -c *.cpp

test: 
	g++ ${INCLUDES} ${LIBRARY_PATH} -o myprog.exe *.cpp\
	 Camera/*.cpp\
	 Character/*.cpp\
	 Field/*.cpp\
	 Landmark/*.cpp\
	 Objects/*.cpp\
	 Scenario/"Step 1 - Flying Saucer"/*.cpp\
	 Textures/*.cpp\
	 -lmingw32 -lopengl32 -lglu32 -lglew32 -lfreeglut -lSDLmain -lSDL -lSDL_mixer -lSDL_image