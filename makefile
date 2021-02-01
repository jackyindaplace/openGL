INCLUDES = -I ./lib

all: base.exe

base.exe: base.o
	g++ -o base.exe base.o ${INCLUDES}

base.o: base.cpp
	g++ -c base.cpp ${INCLUDES}

