/*
 * textures.c
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */
#include "../declarations.h"
#include <GL/glext.h>

void AppliquerTexture(unsigned int* texture, int largeur, int hauteur, int numerotext, int isTransparent) {
	glEnable(GL_TEXTURE_2D);

	if(isTransparent == 1){
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	glGenTextures(numerotext, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);
	//Les bitmaps sont en BGR et non pas RGB !
		if (isTransparent == 1){
				glTexImage2D(GL_TEXTURE_2D, 0, 4, largeur, hauteur, 0, GL_BGRA, GL_UNSIGNED_BYTE,
							texture);
		}
		else {
			glTexImage2D(GL_TEXTURE_2D, 0, 3, largeur, hauteur, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, texture); //GL_RGB
		}

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR,*materialColor);
	//glTexParameter{if}v() avec GL_TEXTURE_BORDER_COLOR comme 2e paramètre et un tableau de 4 valeurs (RGBA pour changer) comme 3e paramètre.
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void freeTextures() {
	glDeleteTextures(1, TextureSolEau);
	glDeleteTextures(1, TextureGrilleSoucoupe);
	glDeleteTextures(1, TextureFace);
	glDeleteTextures(1, TexturePantalon);
	glDeleteTextures(1, TextureCeinture);
	glDeleteTextures(1, TextureBassin);
	glDeleteTextures(1, TextureHalo);
}
