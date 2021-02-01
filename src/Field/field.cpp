///*
// * field.c
// *
// *  Created on: 25 mai 2013
// *      Author: Maxence Fromentin
// */
//
#include "../declarations.h"
#include <iostream>
using namespace std;
#include <cmath>

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


void flatGround(float width){

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureGroundDust40);

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

}

/*	Function used to draw the field. interval is used to create more or less relief.
 *
 */
void ground(float xmin, float xmax, float ymin, float ymax, float zmin, float zmax, int interval, GLuint texture, int scaleTexture, bool changeSRand, int randomize, bool halfSphere){
	//Using a fixed number to generate random values which will not change when scene is redisplayed. So the field won't change.
	srand (static_cast <unsigned> (1476764538));

	int red=49;
	int green=66;
	int blue=221;

	if(changeSRand){
		for(int l=0; l<randomize; l++){
			rand();
		}
	}


	float y;
	float yTemp;

	glBindTexture(GL_TEXTURE_2D, texture);

			for(int j=zmin; j<zmax; j=j+interval){
				glBegin(GL_QUADS);
					glColor3ub(255,255,255);
					glTexCoord2f(0, scaleTexture*((j-zmin)/(zmax-zmin)));
					glVertex3f(xmin,0 , j);
					memorizeYPosition(xmin,0,j);
					glColor3ub(255,255,255);
					glTexCoord2f(0, scaleTexture*((j+interval-zmin)/(zmax-zmin)));
					glVertex3f(xmin, 0, j+interval);
					memorizeYPosition(xmin,0,j+interval);
					if(j==zmax-2){
						glColor3ub(255,255,255);
						glTexCoord2f(scaleTexture*((xmin+interval-xmin)/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
						glVertex3f(xmin+interval, 0, j+interval);
						memorizeYPosition(xmin+interval,0,j+interval);
					}
					else if(halfSphere){
						yTemp = pow((xmax-xmin)/2,2)-(pow(((xmin)+((xmax-xmin)/2))-((xmin)+interval), 2)+pow(((zmin)+((xmax-xmin)/2))-(j+interval),2));
										if(yTemp>0) {
											y = -sqrtf(yTemp);
											glColor3ub(red,green,blue);
										}
										else {
											y = 0;
											glColor3ub(255,255,255);
										}

										glTexCoord2f(scaleTexture*((xmin+interval-xmin)/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
										glVertex3f((xmin)+interval, y, j+interval);
										memorizeYPosition((xmin)+interval,y,j+interval);}
					else{
						y = createRandom(ymin, ymax);
						glColor3ub(255,255,255);
						glTexCoord2f(scaleTexture*((xmin+interval-xmin)/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
						glVertex3f(xmin+interval, y, j+interval);
						memorizeYPosition(xmin+interval,y,j+interval);
					}

					if(j==zmin){
						glColor3ub(255,255,255);
						glTexCoord2f(scaleTexture*((xmin+interval-xmin)/(xmax-(xmin))), scaleTexture*((j-zmin)/(zmax -zmin)));
						glVertex3f(xmin+interval, 0, j);
						memorizeYPosition(xmin+interval,0,j);
					}
					else{
						glColor3ub(255,255,255);
						if(halfSphere) {
							if(retrieveYPosition(xmin+interval,j) != 0) glColor3ub(red,green,blue);
						}

						glTexCoord2f(scaleTexture*((xmin+interval-xmin)/(xmax-(xmin))), scaleTexture*((j-zmin)/(zmax -zmin)));
						glVertex3f(xmin+interval, retrieveYPosition(xmin+interval,j), j);
					}
				glEnd();

				glBegin(GL_QUAD_STRIP);
				for(int i=xmin+interval; i<=xmax; i=i+interval){
					if(j==zmin){
						glColor3ub(255,255,255);
						glTexCoord2f(scaleTexture*((i-(xmin))/(xmax-(xmin))), scaleTexture*((j-zmin)/(zmax -zmin)));
						glVertex3f(i,0, j);
						memorizeYPosition(i,0,j);
					}
					else{
						glColor3ub(255,255,255);
						if(halfSphere)
							{
							if(retrieveYPosition(i,j) != 0) glColor3ub(red,green,blue);
							}
						glTexCoord2f(scaleTexture*((i-(xmin))/(xmax-(xmin))), scaleTexture*((j-zmin)/(zmax -zmin)));
						glVertex3f(i,retrieveYPosition(i,j), j);
					}
					if(i==xmin+interval){
						glColor3ub(255,255,255);
						if(halfSphere)
							{
							if(retrieveYPosition(i,j+interval) != 0) glColor3ub(red,green,blue);
							}
						glTexCoord2f(scaleTexture*((i-(xmin))/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
						glVertex3f(i,retrieveYPosition(i,j+interval), j+interval);
					}
					else if((i==xmax||i==xmax-1)||(j==zmax-2)){
						glColor3ub(255,255,255);
						glTexCoord2f(scaleTexture*((i-(xmin))/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
						glVertex3f(i,0, j+interval);
						memorizeYPosition(i, 0, j+interval);
					}
					else if(halfSphere){

						yTemp = pow((xmax-xmin)/2,2)-(pow(((xmin)+((xmax-xmin)/2))-i, 2)+pow(((zmin)+((xmax-xmin)/2))-(j+interval),2));

										glColor3ub(red,green,blue);
										if(yTemp>0) y = -sqrtf(yTemp);
										else {
											y = 0;
											glColor3ub(255,255,255);
										}
										glTexCoord2f(scaleTexture*((i-(xmin))/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
										glVertex3f(i,y, j+interval);
										memorizeYPosition(i, y, j+interval);}
					else{


						y = createRandom(ymin, ymax);
						glColor3ub(255,255,255);
						glTexCoord2f(scaleTexture*((i-(xmin))/(xmax-(xmin))), scaleTexture*((j+interval-zmin)/(zmax -zmin)));
						glVertex3f(i,y, j+interval);
						memorizeYPosition(i, y, j+interval);
					}
				}
				glEnd();

			}
}



void water(float xstart, float zstart, int size, int interval, GLuint texture){

	float y;
	float yTemp;
	glBindTexture(GL_TEXTURE_2D, texture);

	for(int j=zstart; j<zstart+size; j=j+interval){
		glBegin(GL_QUADS);
			glTexCoord2f(xstart, j);
			glVertex3f(xstart,0 , j);
			memorizeYPosition(xstart,0,j);
			glTexCoord2f(xstart, j+interval);
			glVertex3f(xstart, 0, j+interval);
			memorizeYPosition(xstart,0,j+interval);
			if(j==zstart+size-1||j==zstart+size-2){
				glTexCoord2f(xstart+interval, j+interval);
				glVertex3f(xstart+interval, 0, j+interval);
				memorizeYPosition(xstart+interval,0,j+interval);
			}
			else{
				yTemp = pow(size/2,2)-(pow((xstart+(size/2))-(xstart+interval), 2)+pow((zstart+(size/2))-(j+interval),2));
				if(yTemp>0) y = -sqrtf(yTemp);
				else y = 0;
				glTexCoord2f(xstart+interval, j+interval);
				glVertex3f(xstart+interval, y, j+interval);
				memorizeYPosition(xstart+interval,y,j+interval);
			}

			if(j==zstart){
				glTexCoord2f(xstart+interval, j);
				glVertex3f(xstart+interval, 0, j);
				memorizeYPosition(xstart+interval,0,j);
			}
			else{
				glTexCoord2f(xstart+interval, j);
				glVertex3f(xstart+interval, retrieveYPosition(xstart+interval,j), j);
			}
		glEnd();

		glBegin(GL_QUAD_STRIP);
		for(int i=xstart+interval; i<=xstart+size; i=i+interval){
			if(j==zstart){
				glTexCoord2f(i, j);
				glVertex3f(i,0, j);
				memorizeYPosition(i,0,j);
			}
			else{
				glTexCoord2f(i, j);
				glVertex3f(i,retrieveYPosition(i,j), j);
			}
			if(i==xstart+interval){
				glTexCoord2f(i, j+interval);
				glVertex3f(i,retrieveYPosition(i,j+interval), j+interval);
			}
			else if((i==xstart+size)||(j==zstart+size-2)){
				glTexCoord2f(i, j+interval);
				glVertex3f(i,0, j+interval);
				memorizeYPosition(i, 0, j+interval);
			}
			else{

				yTemp = pow(size/2,2)-(pow((xstart+(size/2))-i, 2)+pow((zstart+(size/2))-(j+interval),2));
				if(yTemp>0) y = -sqrtf(yTemp);
				else y = 0;

				glTexCoord2f(i, j+interval);
				glVertex3f(i,y, j+interval);
				memorizeYPosition(i, y, j+interval);
		}
		}
			glEnd();

}
}
//




//void wall(float xstart, float ystart, float zstart, float xend, float yend, float zend, GLuint texture){
//
//
//
//
//
//}

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
