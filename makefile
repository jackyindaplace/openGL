INCLUDES = -I ./include
LIBRARY_PATH = -L./lib

all: build

copy-textures:
	xcopy "src\Textures\textures" Release\textures /E/H/Y

build: copy-textures
	g++ ${INCLUDES} ${LIBRARY_PATH} -o ./Release/game.exe src/*.cpp\
	 src/Camera/*.cpp\
	 src/Character/*.cpp\
	 src/Field/*.cpp\
	 src/Landmark/*.cpp\
	 src/Objects/*.cpp\
	 src/Scenario/Step-1-Flying-Saucer/*.cpp\
	 src/Textures/*.cpp\
	 -lmingw32 -lopengl32 -lglu32 -lglew32 -lfreeglut -lSDLmain -lSDL -lSDL_mixer -lSDL_image