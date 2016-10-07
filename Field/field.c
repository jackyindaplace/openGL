/*
 * field.c
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */

#include "../declarations.h"
#include "../Textures/textures.h"


void declareChunck(float xstart, float xend, float ystart, float yend, float zstart, float zend)
{
	chunck[nbchuncksdeclares][0] = xstart;
	chunck[nbchuncksdeclares][1] = xend;
	chunck[nbchuncksdeclares][2] = ystart;
	chunck[nbchuncksdeclares][3] = yend;
	chunck[nbchuncksdeclares][4] = zstart;
	chunck[nbchuncksdeclares][5] = zend;
	nbchuncksdeclares = nbchuncksdeclares + 1;
}

int isFree(float x, float y, float z) {
	int resultat = 1;
	int ilibre = 0;

	/*chunck[0][0]=9.0;
	 chunck[0][1]=10.0;
	 chunck[0][2]=-10.0;
	 chunck[0][3]=10.0;
	 chunck[0][4]=0.0;
	 chunck[0][5]=1.0;*/
	for (ilibre = 0; ilibre < (nbchuncksdeclares); ilibre++) {
		/*printf("\n chunck[%d][0]: %f",ilibre,chunck[ilibre][0]);
		 printf("\n chunck[%d][1]: %f",ilibre,chunck[ilibre][1]);
		 printf("\n chunck[%d][2]: %f",ilibre,chunck[ilibre][2]);
		 printf("\n chunck[%d][3]: %f",ilibre,chunck[ilibre][3]);
		 printf("\n chunck[%d][4]: %f",ilibre,chunck[ilibre][4]);
		 printf("\n chunck[%d][5]: %f",ilibre,chunck[ilibre][5]); */

		if (x > chunck[ilibre][0] && x < chunck[ilibre][1]
				&& y > chunck[ilibre][2] && y < chunck[ilibre][3]
				&& z >= chunck[ilibre][4] && z <= chunck[ilibre][5]) {
			printf("c est mort");
			resultat = 0;
		}
	}
	return resultat;
}


void groundDust(float xstart, float xend, float ystart, float yend, float zstart, float zend)
{
	AppliquerTexture(TextureSolSable, 512, 512, 1, 0);

	for (i = xstart; i < xend; i++) {
			for (j = ystart; j < yend; j++) {

				glBegin(GL_QUADS);
				glColor3ub(255, 255, 255); //White Color to See Texture is the right color
				glTexCoord2f(0.0, 0.0);
				glVertex3f(i, j, zend);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(i + 1.0, j, zend);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(i + 1.0, j + 1.0, zend);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(i, j + 1.0, zend);
				glEnd();
			}
	}
	glDisable(GL_TEXTURE_2D);

	glDeleteTextures(1, TextureSolSable);

	declareChunck(xstart, xend, ystart, yend, zstart, zend);

}

void groundGrass(float xstart, float xend, float ystart, float yend, float zstart, float zend)
{
	AppliquerTexture(TextureSolHerbe, 512, 512, 1, 0);

	for (i = xstart; i < xend; i++) {
			for (j = ystart; j < yend; j++) {

				glBegin(GL_QUADS);
				glColor3ub(255, 255, 255);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(i, j, 0);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(i + 1.0, j, 0);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(i + 1.0, j + 1.0, 0);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(i, j + 1.0, 0);
				glEnd();
			}
	}
	glDisable(GL_TEXTURE_2D);

	glDeleteTextures(1, TextureSolHerbe);

	declareChunck(xstart, xend, ystart, yend, zstart, zend);
}

void groundLava(float xstart, float xend, float ystart, float yend, float zstart, float zend)
{
//	AppliquerTexture(TextureLava, 512, 512, 1, 0);
	AppliquerTexture(TextureWall_Dirty, 256, 256, 1, 0);

	for (i = xstart; i < xend; i++) {
			for (j = ystart; j < yend; j++) {

				glBegin(GL_QUADS);
				glColor3ub(255, 255, 255);
				glTexCoord2f(0.0, 0.0);
				glVertex3f(i, j, 0);
				glTexCoord2f(1.0, 0.0);
				glVertex3f(i + 1.0, j, 0);
				glTexCoord2f(1.0, 1.0);
				glVertex3f(i + 1.0, j + 1.0, 0);
				glTexCoord2f(0.0, 1.0);
				glVertex3f(i, j + 1.0, 0);
				glEnd();
			}
	}
	glDisable(GL_TEXTURE_2D);

	glDeleteTextures(1, TextureWall_Dirty);

	declareChunck(xstart, xend, ystart, yend, zstart, zend);
}

void cube(float x, float y, float z) {

	AppliquerTexture(TextureCaisse, 256, 256, 1, 0);

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x - 1, y - 1, z - 1); //face rouge
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x - 1, y + 1, z - 1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + 1, y + 1, z - 1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + 1, y - 1, z - 1);
	//glGetFloatv(GL_CURRENT_TEXTURE_COORDS);
	//system("PAUSE");

	glColor3ub(255, 255, 255);

	//glColor3ub(0,255,0); //face verte
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x - 1, y - 1, z - 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y - 1, z - 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x + 1, y - 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y - 1, z + 1);

	glColor3ub(255, 255, 255);
	//glColor3ub(0,0,255); //face bleue
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x + 1, y - 1, z - 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y + 1, z - 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x + 1, y + 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x + 1, y - 1, z + 1);

	glColor3ub(255, 255, 255); //glColor3ub(255,255,0); //face jaune
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x + 1, y + 1, z - 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y + 1, z + 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x - 1, y + 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y + 1, z - 1);

	glColor3ub(255, 255, 255); //glColor3ub(0,255,255); //face cyan
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x - 1, y + 1, z + 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x - 1, y + 1, z - 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x - 1, y - 1, z - 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y - 1, z + 1);

	glColor3ub(255, 255, 255); //glColor3ub(255,0,255); //face magenta
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x - 1, y - 1, z + 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y - 1, z + 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x + 1, y + 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y + 1, z + 1);

	glEnd();

	glDeleteTextures(1, TextureCaisse);

	glDisable(GL_TEXTURE_2D);

	declareChunck(x-1,x+1,y-1,y+1,z-1,z+1);

}

void wall(float x1, float y1, float z1, float width, float height, int declare) {

	AppliquerTexture(TextureWall_Dirty, 256, 256, 1, 0);
//	AppliquerTexture(TextureSpyglass, 512, 512, 1, 1);

	glBegin(GL_QUADS);

	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+1, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1+width, y1+1, z1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1);

	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+1, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1, y1+1, z1+height);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1, y1, z1+height);

	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1, z1+height);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1+width, y1, z1+height);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1);

	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1+width, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1+width, y1+1, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1+width, y1+1, z1+height);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1+height);

	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1+width, y1+1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+1, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1, y1+1, z1+height);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1+1, z1+height);

	glColor3ub(255, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1+width, y1+1, z1+height);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+1, z1+height);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1, y1, z1+height);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1+height);

	glEnd();

	glDeleteTextures(1, TextureWall_Dirty);
//	glDeleteTextures(1, TextureSpyglass);

	glDisable(GL_TEXTURE_2D);

	if(declare==1) declareChunck(x1, x1+width, y1, y1+1.0, z1, z1+height);

}

void fourWall(float x1, float y1, float z1, float width, float height)
{
	glPushMatrix();
	wall(x1, y1, z1, width, height, 1);
		glPushMatrix();
			glRotatef(90, 0, 0, 1);
			wall(y1 + 1.0, -x1, z1, width, height, 0);
			declareChunck(x1-1.0, x1, y1 + 1.0, y1 + 1.0 + width, z1, z1+height);
			glTranslatef(0.0,-width-1.0,0.0);
			wall(y1 + 1.0, -x1, z1, width, height, 0);
			declareChunck(x1+width, x1+width+1.0, y1 + 1.0, y1 + 1.0 + width, z1, z1+height);
		glPopMatrix();
	glTranslatef(0.0,width+1.0,0.0);
	wall(x1, y1, z1, width, height, 0);
	declareChunck(x1, x1+width, y1+width+1.0, y1+2.0+width, z1, z1+height);
	glPopMatrix();

//	glPushMatrix();
//		wall(5.0, 0.0, 0.1, 14.0, 8.0);// x: 5-19 ; y: 0-1; z: 0.1-8.1
//			glPushMatrix();
//				glRotatef(90, 0, 0, 1);
//				wall(1.0, -5.0, 0.1, 14.0, 8.0);
//				glTranslatef(0.0,-14.0,0.0);
//				wall(1.0, -5.0, 0.1, 14.0, 8.0);
//			glPopMatrix();
//		glTranslatef(0.0,14.0,0.0);
//		wall(5.0, 0.0, 0.1, 14.0, 8.0);
//		glPopMatrix();
}

//void turntable(){
//
//	glBegin(GL_QUADS);
//		glColor3ub(255, 255, 255);
//		glTexCoord2d(0.0, 0.0);
//		glVertex3d(x - 1, y - 1, z - 1); //face rouge
//		glTexCoord2d(0.0, 1.0);
//		glVertex3d(x - 1, y + 1, z - 1);
//		glTexCoord2d(1.0, 1.0);
//		glVertex3d(x + 1, y + 1, z - 1);
//		glTexCoord2d(1.0, 0.0);
//		glVertex3d(x + 1, y - 1, z - 1);
//		//glGetFloatv(GL_CURRENT_TEXTURE_COORDS);
//		//system("PAUSE");
//
//		glColor3ub(255, 255, 255);
//
//		//glColor3ub(0,255,0); //face verte
//		glTexCoord2f(0.0, 0.0);
//		glVertex3d(x - 1, y - 1, z - 1);
//		glTexCoord2f(0.0, 1.0);
//		glVertex3d(x + 1, y - 1, z - 1);
//		glTexCoord2f(1.0, 1.0);
//		glVertex3d(x + 1, y - 1, z + 1);
//		glTexCoord2f(1.0, 0.0);
//		glVertex3d(x - 1, y - 1, z + 1);
//
//		glColor3ub(255, 255, 255);
//		//glColor3ub(0,0,255); //face bleue
//		glTexCoord2f(0.0, 0.0);
//		glVertex3d(x + 1, y - 1, z - 1);
//		glTexCoord2f(0.0, 1.0);
//		glVertex3d(x + 1, y + 1, z - 1);
//		glTexCoord2f(1.0, 1.0);
//		glVertex3d(x + 1, y + 1, z + 1);
//		glTexCoord2f(1.0, 0.0);
//		glVertex3d(x + 1, y - 1, z + 1);
//
//		glColor3ub(255, 255, 255); //glColor3ub(255,255,0); //face jaune
//		glTexCoord2f(0.0, 0.0);
//		glVertex3d(x + 1, y + 1, z - 1);
//		glTexCoord2f(0.0, 1.0);
//		glVertex3d(x + 1, y + 1, z + 1);
//		glTexCoord2f(1.0, 1.0);
//		glVertex3d(x - 1, y + 1, z + 1);
//		glTexCoord2f(1.0, 0.0);
//		glVertex3d(x - 1, y + 1, z - 1);
//
//		glColor3ub(255, 255, 255); //glColor3ub(0,255,255); //face cyan
//		glTexCoord2f(0.0, 0.0);
//		glVertex3d(x - 1, y + 1, z + 1);
//		glTexCoord2f(0.0, 1.0);
//		glVertex3d(x - 1, y + 1, z - 1);
//		glTexCoord2f(1.0, 1.0);
//		glVertex3d(x - 1, y - 1, z - 1);
//		glTexCoord2f(1.0, 0.0);
//		glVertex3d(x - 1, y - 1, z + 1);
//
//		glColor3ub(255, 255, 255); //glColor3ub(255,0,255); //face magenta
//		glTexCoord2f(0.0, 0.0);
//		glVertex3d(x - 1, y - 1, z + 1);
//		glTexCoord2f(0.0, 1.0);
//		glVertex3d(x + 1, y - 1, z + 1);
//		glTexCoord2f(1.0, 1.0);
//		glVertex3d(x + 1, y + 1, z + 1);
//		glTexCoord2f(1.0, 0.0);
//		glVertex3d(x - 1, y + 1, z + 1);
//
//		glEnd();
//
//		glDeleteTextures(1, TextureCaisse);
//
//		glDisable(GL_TEXTURE_2D);
//
//		declareChunck(x-1,x+1,y-1,y+1,z-1,z+1);
//}
