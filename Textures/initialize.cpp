#include "../declarations.h"
#include "sdlglutils.h"

void initializeTextures(){

	textureCaisse = loadTexture("Textures/caisse.tga", false );
	textureGroundDust40 = loadTexture("Textures/sand40.bmp", false );
	textureGroundDust41 = loadTexture("Textures/sand41.tga", false );
	textureGround = loadTexture("Textures/sol.bmp", false );
	textureLava = loadTexture("Textures/lavarock3Sym.png", false );
	textureRock = loadTexture("Textures/rock.png", false);
	textureGrass = loadTexture("Textures/grass.tga", false);
	fence = loadTexture("Textures/fence2.png", false);
	fenceTag = loadTexture("Textures/fence4.png", false);
	transparent = loadTexture("Textures/transparent2.tga", false);

	textureGrilleSoucoupe = loadTexture("Textures/soucoupe.bmp", false );
	textureHalo = loadTexture("Textures/halo.bmp", false );
	grind = loadTexture("Textures/grind.bmp",false);

	earth = loadTexture("Textures/earth.jpg", false);
	eau = loadTexture("Textures/eau.jpg", false);

}
