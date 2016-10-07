#include <GL/freeglut.h>
#include <time.h>
#include <GL/glext.h>
#include <stdlib.h>  
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <string.h>
#include "declarations.h"
#include "Perspectives/perspectives.h"
#include "Character/character.h"
#include "Field/field.h"
#include "Landmark/landmark.h"
#include "Moves/moves.h"
#include "Scenario/Step 1 - Flying Saucer/saucer.h"
#include "Scenario/Exit/exit.h"
#include "Textures/textures.h"

void Drawscene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_LIGHTING);
	/*float ambientColor[]={0.8, 0.8, 0.8, 1.0};
	 float lightPosition[]={0.0, 0.0, -1.0, 1.0};
	 glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	 glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
	 glLightfv(GL_LIGHT4, GL_POSITION, lightPosition);*/

	glEnable(GL_DEPTH_TEST);

	glLoadIdentity(); //print_actual_matrix();
	glClearColor(0.5, 0.5, 1.0, 1.0); //r,v,b
//	zoom();
	//Polarview(Radius, Twist, Longitude, Latitude);

	choosePerspective(perspectiveChoice);

//	DrawAxes(0.0, 0.0, 0.0);

//	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

//	cube(3.0, 3.0, 1.0);
//	cube(6.0, 6.0, 1.0);
//	cube(9.0, 9.0, 3.0);
//	cube(9, 7, 5);
//	cube(9, 5, 7);
//	cube(9, 1, 7);
//	cube(9, -4, 7);
//	cube(9, -9, 7);
//	cube(7, -9, 8);
//	cube(4, -9, 8);
//	cube(1, -9, 9);
//	cube(-4, -9, 10);
//	cube(-9, -9, 11);
//	cube(-9, -5, 12);
//	cube(-9, 0, 12);
//	cube(-9, 4, 13);
//	cube(0, 0, -1);

//	groundGrass(-10.0, 20.0, -20.0, 20.0, -100.0, 0.0);
//	groundDust(-25.0, -20.0, -20.0, 20.0, -100.0, 0.0);
//	fourWall(-4.0, -6.0, 0.1, 10.0, 10.0);

//	wall(0.0,0.0, 0.1, 10.0, 10.0, 1);
//	groundGrass(-20.0, 20.0, -20.0, 20.0, -100.0, 0.0);
	groundGrass(-30.0, 30.0, -30.0, 30.0, -100.0, 0.0);
	groundLava(30.0, 40.0, -10.0, 10.0, -100.0, 0.0);
	groundDust(40.0, 70.0, -10.0, 10.0, -100.0, 2.0);

	makeCharacter = 1;
	moveMan = 1;

	glPushMatrix();

		glTranslatef(xbonhomme, ybonhomme, zbonhomme);
		glPushMatrix();
			glTranslatef(0.0,0.0,1.8);
			DrawAxes(0.0, 0.0, 0.0);
		glPopMatrix();
		//printf("\n xbonhomme : %f", xbonhomme);printf("\n ybonhomme : %f", ybonhomme);
		//printf("\n teta,cos teta,sin teta avant rotation : %f %f %f",teta,cos(teta),sin(teta));
		glRotatef(teta, 0, 0, 1);
//		glRotatef(zeta*100.0, 0, 1, 0);
		//printf("\n teta,cos teta,sin teta apres rotation : %f %f %f",teta,cos(teta),sin(teta));
		//printf("\n xbonhomme apres rotation : %f ", xbonhomme);printf("\n ybonhomme apres rotation: %f", ybonhomme);

//		if (makeCharacter == 1) bonhomme();
		// Dessin de la tete du personnage
		if (makeCharacter == 1) bonhomme();
//		{
//			GLUquadric* params;
//				params = gluNewQuadric();
//		glColor3ub(255, 255, 255); //Blanc
//		gluQuadricDrawStyle(params, GLU_FILL);
//		gluQuadricTexture(params, GL_TRUE);
//		AppliquerTexture(TextureFace, 512, 256, 3, 0);
//		glScalef(0.5, 0.65, 0.9);
//
//		gluSphere(params, 0.5, 30, 30);
//
//		glDisable(GL_TEXTURE_2D);
//		glDeleteTextures(1, TextureFace);}
		if (makeCharacter == 1 && moveMan == 1) DeplacementBonhomme();

	glPopMatrix();

	printf("\n xbonhomme %f",xbonhomme);
	printf("\n ybonhomme %f",ybonhomme);
	printf("\n zbonhomme %f",zbonhomme);

	coordonnees();

//	spyglassMod();

//	kinematicSaucer();
//	perspectiveChoice = 3;


	/*glBegin(GL_QUADS);
	 xmax=10;
	 for(j=-xmax;j<xmax;j++)
	 {
	 rep=(int)(i+j)%2;
	 if(rep==1)
	 glColor3f(1.0,1.0,1.0);

	 else
	 glColor3f(0.2,0.4,0.6);
	 }*/
	/* glColor3ub(255, 255, 255);
	 glVertex3f(9,j,0);
	 glVertex3f(10,j,0);
	 glVertex3f(10,j+1.0,0);
	 glVertex3f(9,j+1.0,0);
	 }
	 glEnd();*/

	/*glPushMatrix();
	 glTranslatef(5.0*cos(anglesoucoupe),5.0*sin(anglesoucoupe),5.0);
	 soucoupe();
	 glPopMatrix();*/
	/*glEnable(GL_CLIP_PLANE0);
	 fenetre();
	 glDisable(GL_CLIP_PLANE0);*/


	exitWhenAchieveGoal();

	printf("\n chucks declare %d", nbchuncksdeclares);
	printf("\n chucks 1 %f", chunck[0][0]);
	printf("\n chucks 1 %f", chunck[0][1]);
	printf("\n chucks 1 %f", chunck[0][2]);
	printf("\n chucks 1 %f", chunck[0][3]);
	printf("\n chucks 1 %f", chunck[0][4]);
	printf("\n chucks 1 %f", chunck[0][5]);

	nbchuncksdeclares = 0;

	freeTextures();

	printf("\n zeta %f",zeta);
	printf("\n teta %f",teta);
	printf("\n XValue %d",Xvalue);
	printf("\n YValue %d",Yvalue);

	glutSwapBuffers();
}
