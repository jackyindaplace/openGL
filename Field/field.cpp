///*
// * field.c
// *
// *  Created on: 25 mai 2013
// *      Author: Maxence Fromentin
// */
//
#include "../declarations.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
#include <time.h>
#include <random>
#include <bits/random.h>
#include <cmath>

//Stocking y position of the field in a 2D table for each position (x,z).
//	int const xTaille(500);
//	int const zTaille(500);
//	int const yPositionTaille(4);
	//tableau[x][z][0] = -x et -z; tableau[x][z][1] = -x et z;  tableau[x][z][2] = x et -z; tableau[x][z][3] = x et z;
//	float tableau[xTaille][zTaille][yPositionTaille];

//
//
//void declareChunck(float xstart, float xend, float ystart, float yend, float zstart, float zend)
//{
//	chunck[nbchuncksdeclares][0] = xstart;
//	chunck[nbchuncksdeclares][1] = xend;
//	chunck[nbchuncksdeclares][2] = ystart;
//	chunck[nbchuncksdeclares][3] = yend;
//	chunck[nbchuncksdeclares][4] = zstart;
//	chunck[nbchuncksdeclares][5] = zend;
//	nbchuncksdeclares = nbchuncksdeclares + 1;
//}
//
//int isFree(float x, float y, float z) {
//	int resultat = 1;
//	int ilibre = 0;
//
//	/*chunck[0][0]=9.0;
//	 chunck[0][1]=10.0;
//	 chunck[0][2]=-10.0;
//	 chunck[0][3]=10.0;
//	 chunck[0][4]=0.0;
//	 chunck[0][5]=1.0;*/
//	for (ilibre = 0; ilibre < (nbchuncksdeclares); ilibre++) {
//		/*printf("\n chunck[%d][0]: %f",ilibre,chunck[ilibre][0]);
//		 printf("\n chunck[%d][1]: %f",ilibre,chunck[ilibre][1]);
//		 printf("\n chunck[%d][2]: %f",ilibre,chunck[ilibre][2]);
//		 printf("\n chunck[%d][3]: %f",ilibre,chunck[ilibre][3]);
//		 printf("\n chunck[%d][4]: %f",ilibre,chunck[ilibre][4]);
//		 printf("\n chunck[%d][5]: %f",ilibre,chunck[ilibre][5]); */
//
//		if (x > chunck[ilibre][0] && x < chunck[ilibre][1]
//				&& y > chunck[ilibre][2] && y < chunck[ilibre][3]
//				&& z >= chunck[ilibre][4] && z <= chunck[ilibre][5]) {
//			printf("c est mort");
//			resultat = 0;
//		}
//	}
//	return resultat;
//}
//
//

float createRandom(float LO, float HI){

	float result = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));

//	std::cout << "RandomFunction" << rand() << "\n";
//	fflush(stdout);

	return result;
}

void memorizeYPosition(int x, float y, int z){
	//tableau[x][z][0] = -x et -z; tableau[x][z][1] = -x et z;  tableau[x][z][2] = x et -z; tableau[x][z][3] = x et z;
	int yPositionInTable = 0;
	bool xIsNeg = x<0;
	bool zIsNeg = z<0;

	if (xIsNeg && zIsNeg) yPositionInTable = 0;
	if (xIsNeg && !zIsNeg) yPositionInTable = 1;
	if (!xIsNeg && zIsNeg) yPositionInTable = 2;
	if (!xIsNeg && !zIsNeg) yPositionInTable = 3;


	tableau[abs(x)][abs(z)][yPositionInTable] = y;
//	tableau[1][1][1] = y;

}

float retrieveYPosition(int x,int z){
	//tableau[x][z][0] = -x et -z; tableau[x][z][1] = -x et z;  tableau[x][z][2] = x et -z; tableau[x][z][3] = x et z;
	int yPositionInTable = 0;
	bool xIsNeg = x<0;
	bool zIsNeg = z<0;

	if (xIsNeg && zIsNeg) yPositionInTable = 0;
	if (xIsNeg && !zIsNeg) yPositionInTable = 1;
	if (!xIsNeg && zIsNeg) yPositionInTable = 2;
	if (!xIsNeg && !zIsNeg) yPositionInTable = 3;

	return tableau[abs(x)][abs(z)][yPositionInTable];
//	return tableau[1][1][1];
}

void groundDust(float xmin, float xmax, float y, float zmin, float zmax){
	//Using a fixed number to generate random values which will not change when scene is redisplayed. So the field won't change.
	srand (static_cast <unsigned> (1476764538));

	glBindTexture(GL_TEXTURE_2D, textureGroundDust);

			for(int j=zmin; j<=zmax; j=j+2){
//				glColor3ub(255, 0, 0);
				glBegin(GL_QUADS);
					glTexCoord2f(xmin, j);
					glVertex3f(xmin,0 , j);
					memorizeYPosition(xmin,0,j);
					glTexCoord2f(xmin, j+2);
					glVertex3f(xmin, 0, j+2);
					memorizeYPosition(xmin,0,j+2);
					if(j==zmax||j==zmax-1){
						glTexCoord2f(xmin+2, j+2);
						glVertex3f(xmin+2, 0, j+2);
						memorizeYPosition(xmin+2,0,j+2);
					}
					else{
						y = createRandom(0, 2);
						glTexCoord2f(xmin+2, j+2);
						glVertex3f(xmin+2, y, j+2);
						memorizeYPosition(xmin+2,y,j+2);
					}

					if(j==zmin){
						glTexCoord2f(xmin+2, j);
						glVertex3f(xmin+2, 0, j);
						memorizeYPosition(xmin+2,0,j);
					}
					else{
						glTexCoord2f(xmin+2, j);
						glVertex3f(xmin+2, retrieveYPosition(xmin+2,j), j);
					}
				glEnd();

				glBegin(GL_QUAD_STRIP);
				for(int i=xmin+2; i<=xmax; i=i+2){
					if(j==zmin){
						glTexCoord2f(i, j);
						glVertex3f(i,0, j);
						memorizeYPosition(i,0,j);
					}
					else{
						glTexCoord2f(i, j);
						glVertex3f(i,retrieveYPosition(i,j), j);
					}
					if(i==xmin+2){
						glTexCoord2f(i, j+2);
						glVertex3f(i,retrieveYPosition(i,j+2), j+2);
					}
					else if((i==xmax||i==xmax-1)||(j==zmax||j==zmax-1)){
						glTexCoord2f(i, j+2);
						glVertex3f(i,0, j+2);
						memorizeYPosition(i, 0, j+2);
					}
					else{
						y = createRandom(0, 2);
						glTexCoord2f(i, j+2);
						glVertex3f(i,y, j+2);
						memorizeYPosition(i, y, j+2);
					}
//						cout << 'retrievePosition i j+2' << retrieveYPosition(i,j+2) << endl;
				}
				glEnd();

			}

//				glColor3ub(255, 0, 0);
//				glVertex3f(xmin+1,y, zmin+1);
//				glVertex3f(xmin+1,y, zmin+2);


//				glBegin(GL_QUADS);
//				glTexCoord2f(xmin, zmin+2);
//				glVertex3f(xmin, 3.5, zmin+2);
//				glTexCoord2f(xmin, zmax);
//				glVertex3f(xmin, 0, zmax);
//				glTexCoord2f(xmax, zmax);
//				glVertex3f(xmax, 0, zmax);
//				glTexCoord2f(xmax, zmin+2);
//				glVertex3f(xmax, 1.5, zmin+2);
//				glEnd();
}
//
//	//declareChunck(xstart, xend, ystart, yend, zstart, zend);
//
//
//
//void groundGrass(float xstart, float xend, float ystart, float yend, float zstart, float zend)
//{
//	AppliquerTexture(TextureSolHerbe, 512, 512, 1, 0);
//
//	for (i = xstart; i < xend; i++) {
//			for (j = ystart; j < yend; j++) {
//
//				glBegin(GL_QUADS);
//				glColor3ub(255, 255, 255);
//				glTexCoord2f(0.0, 0.0);
//				glVertex3f(i, j, 0);
//				glTexCoord2f(1.0, 0.0);
//				glVertex3f(i + 1.0, j, 0);
//				glTexCoord2f(1.0, 1.0);
//				glVertex3f(i + 1.0, j + 1.0, 0);
//				glTexCoord2f(0.0, 1.0);
//				glVertex3f(i, j + 1.0, 0);
//				glEnd();
//			}
//	}
//	glDisable(GL_TEXTURE_2D);
//
//	glDeleteTextures(1, TextureSolHerbe);
//
//	declareChunck(xstart, xend, ystart, yend, zstart, zend);
//}
//
//void groundLava(float xstart, float xend, float ystart, float yend, float zstart, float zend)
//{
////	AppliquerTexture(TextureLava, 512, 512, 1, 0);
//	AppliquerTexture(TextureWall_Dirty, 256, 256, 1, 0);
//
//	for (i = xstart; i < xend; i++) {
//			for (j = ystart; j < yend; j++) {
//
//				glBegin(GL_QUADS);
//				glColor3ub(255, 255, 255);
//				glTexCoord2f(0.0, 0.0);
//				glVertex3f(i, j, 0);
//				glTexCoord2f(1.0, 0.0);
//				glVertex3f(i + 1.0, j, 0);
//				glTexCoord2f(1.0, 1.0);
//				glVertex3f(i + 1.0, j + 1.0, 0);
//				glTexCoord2f(0.0, 1.0);
//				glVertex3f(i, j + 1.0, 0);
//				glEnd();
//			}
//	}
//	glDisable(GL_TEXTURE_2D);
//
//	glDeleteTextures(1, TextureWall_Dirty);
//
//	declareChunck(xstart, xend, ystart, yend, zstart, zend);
//}
//
void cube(double x, double y, double z) {

	glColor3ub(255,255,255);
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


	//glColor3ub(0, 255, 0);
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
//
//void caisse(float x, float y, float z) {
//
//	AppliquerTexture(TextureCaisse, 256, 256, 1, 0);
//
//	glBegin(GL_QUADS);
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x - 1, y - 1, z - 1); //face rouge
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x - 1, y + 1, z - 1);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x + 1, y + 1, z - 1);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x + 1, y - 1, z - 1);
//	//glGetFloatv(GL_CURRENT_TEXTURE_COORDS);
//	//system("PAUSE");
//
//	glColor3ub(255, 255, 255);
//
//	//glColor3ub(0,255,0); //face verte
//	glTexCoord2f(0.0, 0.0);
//	glVertex3d(x - 1, y - 1, z - 1);
//	glTexCoord2f(0.0, 1.0);
//	glVertex3d(x + 1, y - 1, z - 1);
//	glTexCoord2f(1.0, 1.0);
//	glVertex3d(x + 1, y - 1, z + 1);
//	glTexCoord2f(1.0, 0.0);
//	glVertex3d(x - 1, y - 1, z + 1);
//
//	glColor3ub(255, 255, 255);
//	//glColor3ub(0,0,255); //face bleue
//	glTexCoord2f(0.0, 0.0);
//	glVertex3d(x + 1, y - 1, z - 1);
//	glTexCoord2f(0.0, 1.0);
//	glVertex3d(x + 1, y + 1, z - 1);
//	glTexCoord2f(1.0, 1.0);
//	glVertex3d(x + 1, y + 1, z + 1);
//	glTexCoord2f(1.0, 0.0);
//	glVertex3d(x + 1, y - 1, z + 1);
//
//	glColor3ub(255, 255, 255); //glColor3ub(255,255,0); //face jaune
//	glTexCoord2f(0.0, 0.0);
//	glVertex3d(x + 1, y + 1, z - 1);
//	glTexCoord2f(0.0, 1.0);
//	glVertex3d(x + 1, y + 1, z + 1);
//	glTexCoord2f(1.0, 1.0);
//	glVertex3d(x - 1, y + 1, z + 1);
//	glTexCoord2f(1.0, 0.0);
//	glVertex3d(x - 1, y + 1, z - 1);
//
//	glColor3ub(255, 255, 255); //glColor3ub(0,255,255); //face cyan
//	glTexCoord2f(0.0, 0.0);
//	glVertex3d(x - 1, y + 1, z + 1);
//	glTexCoord2f(0.0, 1.0);
//	glVertex3d(x - 1, y + 1, z - 1);
//	glTexCoord2f(1.0, 1.0);
//	glVertex3d(x - 1, y - 1, z - 1);
//	glTexCoord2f(1.0, 0.0);
//	glVertex3d(x - 1, y - 1, z + 1);
//
//	glColor3ub(255, 255, 255); //glColor3ub(255,0,255); //face magenta
//	glTexCoord2f(0.0, 0.0);
//	glVertex3d(x - 1, y - 1, z + 1);
//	glTexCoord2f(0.0, 1.0);
//	glVertex3d(x + 1, y - 1, z + 1);
//	glTexCoord2f(1.0, 1.0);
//	glVertex3d(x + 1, y + 1, z + 1);
//	glTexCoord2f(1.0, 0.0);
//	glVertex3d(x - 1, y + 1, z + 1);
//
//	glEnd();
//
//	glDeleteTextures(1, TextureCaisse);
//
//	glDisable(GL_TEXTURE_2D);
//
//	declareChunck(x-1,x+1,y-1,y+1,z-1,z+1);
//
//}
//
//void wall(float x1, float y1, float z1, float width, float height, int declare) {
//
//	AppliquerTexture(TextureWall_Dirty, 256, 256, 1, 0);
////	AppliquerTexture(TextureSpyglass, 512, 512, 1, 1);
//
//	glBegin(GL_QUADS);
//
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x1, y1, z1);
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x1, y1+1, z1);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x1+width, y1+1, z1);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x1+width, y1, z1);
//
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x1, y1, z1);
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x1, y1+1, z1);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x1, y1+1, z1+height);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x1, y1, z1+height);
//
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x1, y1, z1);
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x1, y1, z1+height);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x1+width, y1, z1+height);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x1+width, y1, z1);
//
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x1+width, y1, z1);
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x1+width, y1+1, z1);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x1+width, y1+1, z1+height);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x1+width, y1, z1+height);
//
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x1+width, y1+1, z1);
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x1, y1+1, z1);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x1, y1+1, z1+height);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x1+width, y1+1, z1+height);
//
//	glColor3ub(255, 255, 255);
//	glTexCoord2d(0.0, 0.0);
//	glVertex3d(x1+width, y1+1, z1+height);
//	glTexCoord2d(0.0, 1.0);
//	glVertex3d(x1, y1+1, z1+height);
//	glTexCoord2d(1.0, 1.0);
//	glVertex3d(x1, y1, z1+height);
//	glTexCoord2d(1.0, 0.0);
//	glVertex3d(x1+width, y1, z1+height);
//
//	glEnd();
//
//	glDeleteTextures(1, TextureWall_Dirty);
////	glDeleteTextures(1, TextureSpyglass);
//
//	glDisable(GL_TEXTURE_2D);
//
//	if(declare==1) declareChunck(x1, x1+width, y1, y1+1.0, z1, z1+height);
//
//}
//
//void fourWall(float x1, float y1, float z1, float width, float height)
//{
//	glPushMatrix();
//	wall(x1, y1, z1, width, height, 1);
//		glPushMatrix();
//			glRotatef(90, 0, 0, 1);
//			wall(y1 + 1.0, -x1, z1, width, height, 0);
//			declareChunck(x1-1.0, x1, y1 + 1.0, y1 + 1.0 + width, z1, z1+height);
//			glTranslatef(0.0,-width-1.0,0.0);
//			wall(y1 + 1.0, -x1, z1, width, height, 0);
//			declareChunck(x1+width, x1+width+1.0, y1 + 1.0, y1 + 1.0 + width, z1, z1+height);
//		glPopMatrix();
//	glTranslatef(0.0,width+1.0,0.0);
//	wall(x1, y1, z1, width, height, 0);
//	declareChunck(x1, x1+width, y1+width+1.0, y1+2.0+width, z1, z1+height);
//	glPopMatrix();
//
////	glPushMatrix();
////		wall(5.0, 0.0, 0.1, 14.0, 8.0);// x: 5-19 ; y: 0-1; z: 0.1-8.1
////			glPushMatrix();
////				glRotatef(90, 0, 0, 1);
////				wall(1.0, -5.0, 0.1, 14.0, 8.0);
////				glTranslatef(0.0,-14.0,0.0);
////				wall(1.0, -5.0, 0.1, 14.0, 8.0);
////			glPopMatrix();
////		glTranslatef(0.0,14.0,0.0);
////		wall(5.0, 0.0, 0.1, 14.0, 8.0);
////		glPopMatrix();
//}
//
////void turntable(){
////
////	glBegin(GL_QUADS);
////		glColor3ub(255, 255, 255);
////		glTexCoord2d(0.0, 0.0);
////		glVertex3d(x - 1, y - 1, z - 1); //face rouge
////		glTexCoord2d(0.0, 1.0);
////		glVertex3d(x - 1, y + 1, z - 1);
////		glTexCoord2d(1.0, 1.0);
////		glVertex3d(x + 1, y + 1, z - 1);
////		glTexCoord2d(1.0, 0.0);
////		glVertex3d(x + 1, y - 1, z - 1);
////		//glGetFloatv(GL_CURRENT_TEXTURE_COORDS);
////		//system("PAUSE");
////
////		glColor3ub(255, 255, 255);
////
////		//glColor3ub(0,255,0); //face verte
////		glTexCoord2f(0.0, 0.0);
////		glVertex3d(x - 1, y - 1, z - 1);
////		glTexCoord2f(0.0, 1.0);
////		glVertex3d(x + 1, y - 1, z - 1);
////		glTexCoord2f(1.0, 1.0);
////		glVertex3d(x + 1, y - 1, z + 1);
////		glTexCoord2f(1.0, 0.0);
////		glVertex3d(x - 1, y - 1, z + 1);
////
////		glColor3ub(255, 255, 255);
////		//glColor3ub(0,0,255); //face bleue
////		glTexCoord2f(0.0, 0.0);
////		glVertex3d(x + 1, y - 1, z - 1);
////		glTexCoord2f(0.0, 1.0);
////		glVertex3d(x + 1, y + 1, z - 1);
////		glTexCoord2f(1.0, 1.0);
////		glVertex3d(x + 1, y + 1, z + 1);
////		glTexCoord2f(1.0, 0.0);
////		glVertex3d(x + 1, y - 1, z + 1);
////
////		glColor3ub(255, 255, 255); //glColor3ub(255,255,0); //face jaune
////		glTexCoord2f(0.0, 0.0);
////		glVertex3d(x + 1, y + 1, z - 1);
////		glTexCoord2f(0.0, 1.0);
////		glVertex3d(x + 1, y + 1, z + 1);
////		glTexCoord2f(1.0, 1.0);
////		glVertex3d(x - 1, y + 1, z + 1);
////		glTexCoord2f(1.0, 0.0);
////		glVertex3d(x - 1, y + 1, z - 1);
////
////		glColor3ub(255, 255, 255); //glColor3ub(0,255,255); //face cyan
////		glTexCoord2f(0.0, 0.0);
////		glVertex3d(x - 1, y + 1, z + 1);
////		glTexCoord2f(0.0, 1.0);
////		glVertex3d(x - 1, y + 1, z - 1);
////		glTexCoord2f(1.0, 1.0);
////		glVertex3d(x - 1, y - 1, z - 1);
////		glTexCoord2f(1.0, 0.0);
////		glVertex3d(x - 1, y - 1, z + 1);
////
////		glColor3ub(255, 255, 255); //glColor3ub(255,0,255); //face magenta
////		glTexCoord2f(0.0, 0.0);
////		glVertex3d(x - 1, y - 1, z + 1);
////		glTexCoord2f(0.0, 1.0);
////		glVertex3d(x + 1, y - 1, z + 1);
////		glTexCoord2f(1.0, 1.0);
////		glVertex3d(x + 1, y + 1, z + 1);
////		glTexCoord2f(1.0, 0.0);
////		glVertex3d(x - 1, y + 1, z + 1);
////
////		glEnd();
////
////		glDeleteTextures(1, TextureCaisse);
////
////		glDisable(GL_TEXTURE_2D);
////
////		declareChunck(x-1,x+1,y-1,y+1,z-1,z+1);
////}
