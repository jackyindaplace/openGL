#include "../declarations.h"
#include "sdlglutils.h"

void initializeTextures(){

	textureCaisse = loadTexture("textures/caisse.tga", false );
	textureGroundDust40 = loadTexture("textures/sand40.bmp", false );
	textureGroundDust41 = loadTexture("textures/sand41.tga", false );
	textureGround = loadTexture("textures/sol.bmp", false );
	textureLava = loadTexture("textures/lavarock3Sym.png", false );
	textureRock = loadTexture("textures/rock.png", false);
	textureGrass = loadTexture("textures/grass.tga", false);
	fence = loadTexture("textures/fence2.png", false);
	fenceTag = loadTexture("textures/fence4.png", false);
	transparent = loadTexture("textures/transparent2.tga", false);

	textureGrilleSoucoupe = loadTexture("textures/soucoupe.bmp", false );
	textureHalo = loadTexture("textures/halo.bmp", false );
	grind = loadTexture("textures/grind.bmp",false);

	earth = loadTexture("textures/earth.jpg", false);
	eau = loadTexture("textures/eau.jpg", false);
	sea = loadTexture("textures/sea.jpg", false);

	/* Character Texture */
	faceCharacter = loadTexture("textures/swayze2.png", false);

}
