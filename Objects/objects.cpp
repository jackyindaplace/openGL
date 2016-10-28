#include "../declarations.h"
#include <cmath>

void drawEarth(float angleRotationX, float angleRotationY){

	glTranslated(0,2,0);
	glRotated(angleRotationY,0,1,0);
	glRotated(angleRotationX,1,0,0);

glColor3f(255,255,255);
glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D,earth);
			GLUquadric* params;
			params = gluNewQuadric();
			gluQuadricTexture(params,GL_TRUE);
			gluQuadricDrawStyle(params, GLU_FILL);
			gluSphere(params,1,20,20);
gluDeleteQuadric(params);

glRotated(-angleRotationX,1,0,0);
glRotated(-angleRotationY,0,1,0);
glTranslated(0,-2,0);

}

void cube(double x, double y, double z) {

	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureCaisse);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0);
	glVertex3d(x - 1, y - 1, z - 1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x - 1, y + 1, z - 1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x + 1, y + 1, z - 1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x + 1, y - 1, z - 1);

	glTexCoord2f(0.0, 0.0);
	glVertex3d(x - 1, y - 1, z - 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y - 1, z - 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x + 1, y - 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y - 1, z + 1);

	//glColor3ub(0,0,255);
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x + 1, y - 1, z - 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y + 1, z - 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x + 1, y + 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x + 1, y - 1, z + 1);

	//glColor3ub(255, 255, 0);
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x + 1, y + 1, z - 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y + 1, z + 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x - 1, y + 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y + 1, z - 1);

	//glColor3ub(255, 0, 255);
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x - 1, y + 1, z + 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x - 1, y + 1, z - 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x - 1, y - 1, z - 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y - 1, z + 1);

	//glColor3ub(0, 255, 255);
	glTexCoord2f(0.0, 0.0);
	glVertex3d(x - 1, y - 1, z + 1);
	glTexCoord2f(0.0, 1.0);
	glVertex3d(x + 1, y - 1, z + 1);
	glTexCoord2f(1.0, 1.0);
	glVertex3d(x + 1, y + 1, z + 1);
	glTexCoord2f(1.0, 0.0);
	glVertex3d(x - 1, y + 1, z + 1);

	glEnd();

}


void wall(float x1, float y1, float z1, float width, float height) {
	glColor3ub(255,255,255);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureGroundDust41);

	glBegin(GL_QUADS);

	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+height, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1+width, y1+height, z1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1);

//	glColor3ub(0, 255, 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+height, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1, y1+height, z1+1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1, y1, z1+1);

//	glColor3ub(0, 0, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1, z1+1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1+width, y1, z1+1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1);

//	glColor3ub(255, 255, 0);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1+width, y1, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1+width, y1+height, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1+width, y1+height, z1+1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1+1);

//	glColor3ub(255, 0, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1+width, y1+height, z1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+height, z1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1, y1+height, z1+1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1+height, z1+1);

//	glColor3ub(0, 255, 255);
	glTexCoord2d(0.0, 0.0);
	glVertex3d(x1+width, y1+height, z1+1);
	glTexCoord2d(0.0, 1.0);
	glVertex3d(x1, y1+height, z1+1);
	glTexCoord2d(1.0, 1.0);
	glVertex3d(x1, y1, z1+1);
	glTexCoord2d(1.0, 0.0);
	glVertex3d(x1+width, y1, z1+1);

	glEnd();

	glColor4f(1.0f,1.0f,1.0f,1.0f);
	glDisable(GL_BLEND);

//	glPopMatrix();

//	if(declare==1) declareChunck(x1, x1+width, y1, y1+1.0, z1, z1+height);

}

void entranceBunker(float x, float y, float z, float width, float height, float width2){

	glBindTexture(GL_TEXTURE_2D, textureGroundDust40);

	glBegin(GL_QUADS);
			glTexCoord2d(0.0, 0.0);
			glVertex3d(x,y,z);
			glTexCoord2d(0.0, 1.0);
			glVertex3d(x, y+height, z);
			glTexCoord2d(1.0, 1.0);
			glVertex3d(x, y+height, z+width2);
			glTexCoord2d(1.0, 0.0);
			glVertex3d(x, y, z+width2);

	glEnd();
	glBegin(GL_QUAD_STRIP);

			glTexCoord2d(0.0, 0.0);
			glVertex3d(x,y,z);
			glTexCoord2d(0.0, 1.0);
			glVertex3d(x, y, z+width2);
			glTexCoord2d(1.0, 1.0);
			glVertex3d(x+width, y, z+width2);
			glTexCoord2d(1.0, 0.0);
			glVertex3d(x+width, y, z);

			glTexCoord2d(0.0, 1.0);
			glVertex3d(x, y+height, z+width2);
			glTexCoord2d(0.0, 0.0);
			glVertex3d(x, y+height, z);
//

	glEnd();

	glBegin(GL_TRIANGLES);
			glTexCoord2d(0.0, 0.0);
			glVertex3d(x,y,z);
			glTexCoord2d(0.0, 1.0);
			glVertex3d(x, y+height, z);
			glTexCoord2d(1.0, 0.0);
			glVertex3d(x+width, y, z);

			glTexCoord2d(0.0, 0.0);
			glVertex3d(x,y,z+width2);
			glTexCoord2d(0.0, 1.0);
			glVertex3d(x, y+height, z+width2);
			glTexCoord2d(1.0, 0.0);
			glVertex3d(x+width, y, z+width2);

	glEnd();


}

void bunker(float x, float y, float z, float width, float height){

	glTranslated(x,y,z);
	wall(0, 0, 0, 20, 10);
	glTranslated(0,0,width+1);
	wall(0, 0, 0, 20, 10);
	glTranslated(0,0,-width-1);

	glRotated(-90,0,1,0);
	glTranslated(1,0,-1);
	wall(0, 0, 0, 20, 10);
	glTranslated(0,0,-width+1);
	wall(0, 0, 0, 20, 10);
	glTranslated(-1,0,width);
	glRotated(90,0,1,0);

//	glColor3ub(255,255,255);
	glBindTexture(GL_TEXTURE_2D, textureGround);

	glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(0,0,0);
		glTexCoord2d(0.0, 1.0);
		glVertex3d(0, 0, width+2);
		glTexCoord2d(1.0, 1.0);
		glVertex3d(width, 0, width+2);
		glTexCoord2d(1.0, 0.0);
		glVertex3d(width, 0, 0);
	glEnd();


//	glTranslated(-x,-y,-z);

//	glTranslated(40,0,50);
	glRotated(180,0,1,0);
	glTranslated(0,0,-5);
		entranceBunker(0, 0, 0, 17, 8, 5);
			glTranslated(0,0,-17);
			entranceBunker(0, 0, 0, 17, 8, 5);
			glTranslated(0,0,17);
	glTranslated(0,0,5);
	glRotated(-180,0,1,0);
	glTranslated(-40,0,-50);

}

void cloture(float x1, float y1, float z1, float width, float height){

	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1.0f,1.0f,1.0f,1.00);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, fence);

	glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(x1, y1, z1);
		glTexCoord2d(0.0, 1.0);
		glVertex3d(x1, y1+height, z1);
		glTexCoord2d(1.0, 1.0);
		glVertex3d(x1+width/4, y1+height, z1);
		glTexCoord2d(1.0, 0.0);
		glVertex3d(x1+width/4, y1, z1);
	glEnd();

		glBindTexture(GL_TEXTURE_2D, fenceTag);
//	glRotated(180,0,1,0);
	glBegin(GL_QUADS);
		glTexCoord2d(1.0, 0.0);
		glVertex3d(x1+width/4, y1, z1);
		glTexCoord2d(1.0, 1.0);
		glVertex3d(x1+width/4, y1+height, z1);
		glTexCoord2d(0.0, 1.0);
		glVertex3d(x1+width/2, y1+height, z1);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(x1+width/2, y1, z1);
	glEnd();
//	glRotated(180,0,1,0);

		glBindTexture(GL_TEXTURE_2D, fence);

	glBegin(GL_QUADS);
		glTexCoord2d(0.0, 0.0);
		glVertex3d(x1+width/2, y1, z1);
		glTexCoord2d(0.0, 1.0);
		glVertex3d(x1+width/2, y1+height, z1);
		glTexCoord2d(2.0, 1.0);
		glVertex3d(x1+width, y1+height, z1);
		glTexCoord2d(2.0, 0.0);
		glVertex3d(x1+width, y1, z1);

	glEnd();


}

/*scalex - scaling of sphere around x-axis
scaley - scaling of sphere around y-axis
r - radius of sphere
*/
void drawWater(int scalex, int scaley, GLfloat r, GLuint texture) {
//int i, j;
//GLfloat v[scalex*scaley][3];
glDisable(GL_TEXTURE_2D);
glEnable(GL_BLEND);
glDepthMask(GL_FALSE);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//
glTranslated(20,0,30);
glRotated(180,1,0,0);
//glColor4f(0.0f,0.0f,1.0f,0.4);
glColor4ub(49,66,221,140);

//
//
//for (i=0; i<scalex; ++i) {
//for (j=0; j<scaley; ++j) {
//v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
//v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
//v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
//}
//}
//
//glBegin(GL_QUADS);
//for (i=0; i<scalex-1; ++i) {
//for (j=0; j<scaley; ++j) {
//glVertex3fv(v[i*scaley+j]);
//glVertex3fv(v[i*scaley+(j+1)%scaley]);
//glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
//glVertex3fv(v[(i+1)*scaley+j]);
//}
//}
//glEnd();




glRotated(90,1,0,0);
GLUquadric* params = gluNewQuadric();

//glEnable(GL_TEXTURE_2D);
//glBindTexture(GL_TEXTURE_2D, sea);
//gluQuadricTexture(params,GL_TRUE);

//glTranslated(0,0,-19.3);
//gluDisk(params,0,1.3,24,1);
//glTranslated(0,0,19.3);
gluDisk(params,0,22,24,1);
glRotated(-90,1,0,0);

gluDeleteQuadric(params);

glRotated(180,1,0,0);
glTranslated(-20,0,-30);

glDepthMask(GL_TRUE);
glDisable(GL_BLEND);



}
