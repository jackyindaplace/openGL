INCLUDES = -I ./include
LIBRARY_PATH = -L./lib

all: build-and-run

copy-textures:
	xcopy "src\Textures\textures" Release\textures /E/H/Y

copy-sounds:
	xcopy "src\Sound" Release\sounds /E/H/Y

build-and-copy: copy-textures copy-sounds build
	
build: 
	g++ ${INCLUDES} ${LIBRARY_PATH} -o ./Release/game.exe src/*.cpp\
	 src/Camera/*.cpp\
	 src/Character/*.cpp\
	 src/Field/*.cpp\
	 src/Landmark/*.cpp\
	 src/Objects/*.cpp\
	 src/Scenario/Step-1-Flying-Saucer/*.cpp\
	 src/Textures/*.cpp\
	 -lmingw32 -lopengl32 -lglu32 -lglew32 -lfreeglut -lSDL2 -lSDL2_mixer -lSDL2_image

run:
	./Release/game.exe

build-and-run: build run

