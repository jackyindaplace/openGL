/*
 * saucer.c
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */

#include "../../declarations.h"
#include <GL/glext.h>
#include "string.h"

void soucoupe() {

	glPushMatrix();

	GLUquadric* params;
	params = gluNewQuadric();

	glDisable(GL_TEXTURE_2D);

	//Cône : Partie inférieure de la soucoupe
	glColor3ub(81, 183, 96); //Vert
	gluCylinder(params, 1.7, 0.0, 0.2, 20, 1);

	//Cône: Partie supérieure de la soucoupe
	glColor3ub(0, 0, 0); //Noir
	gluCylinder(params, 2, 1.7, 0.2, 20, 1);

	//Translation de 0.2 selon l'axe des z
	glTranslatef(0, 0, 0.2);

	//2ème Cône du haut de la soucoupe.
	glColor3ub(61, 139, 73); //Vert Pas mal
	gluCylinder(params, 1.7, 1.5, 0.05, 20, 1);

	//Translation de 0.05 selon l'axe des z
	glTranslatef(0, 0, 0.05);

	//Disque : Dessus de la soucoupe
	glColor3ub(0, 0, 0); //Noir
	//glColor3ub(61, 139, 73); //Vert Pas mal
	gluDisk(params, 0.1, 1.5, 100, 1);

	//Translation de 0.55 selon l'axe des z
	glTranslatef(0, 0, -0.55);

	//Cylindre du milieu de la soucoupe.
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureGrilleSoucoupe);

	//glColor3ub(255, 255, 255); //Blanc
	gluQuadricDrawStyle(params, GLU_FILL);
	gluQuadricTexture(params, GL_TRUE);
	gluCylinder(params, 2, 2, 0.3, 20, 1);
	glDisable(GL_TEXTURE_2D);

	//Rotation de 180° par rapport à l'axe des x
	glRotatef(180, 1, 0, 0);

	//Cône : Partie inférieure de la soucoupe

	gluQuadricTexture(params, GL_FALSE);

	glColor3ub(0, 0, 0); //Noir
	gluCylinder(params, 2, 1.7, 0.2, 20, 1);

	//Translation de 0.2 selon l'axe des z
	glTranslatef(0, 0, 0.2);

	//Cône : Partie inférieure de la soucoupe
	//glColor3ub(253, 57, 116); //Rose
	glColor4ub(81, 183, 96, 255); //Vert
	//glColor3ub(61, 139, 73); //Vert Pas mal
	gluCylinder(params, 1.7, 0.0, 0.2, 20, 1);
	//halo lumineux
	glTranslatef(0.0, 0.0, 0.2);

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textureHalo);

	gluQuadricDrawStyle(params, GLU_FILL);
	gluQuadricTexture(params, GL_TRUE);
	gluCylinder(params, 0.3, 2.5, 6.0, 20, 1);
	glDisable(GL_TEXTURE_2D);

	glColor4ub(255, 255, 255, 255);

	glPopMatrix();
}

//void kinematicSaucer(){
//
//	if (strcmp(step, "kinematicSaucerArrives") == 0) {
//		glTranslatef(tt, tt, 0.0);
//		tt = tt + 1.0;
//		if (tt == 0.0)	step = "kinematicSaucerDebarkation";
//	}
//
//	if (strcmp(step, "kinematicSaucerDebarkation") == 0) {
//		makeCharacter = 1;
//		perspectiveChoice = 1;
//		if (zbonhomme > 0.2)	zbonhomme = zbonhomme - 0.01;
//		if (zbonhomme<= 0.2)	step = "kinematicSaucerMoves";
//	}
//
//	if (strcmp(step, "kinematicSaucerMoves") == 0) {
//		bougersoucoupe = 1;
//		step = "play";
//		}
//
//	if (bougersoucoupe == 1) {
//			glTranslatef(-8, 8, 13);
//		}
//
//		glTranslatef(0.0, 0.0, 20.0);
//		glScalef(3.0, 3.0, 3.0);
//		soucoupe();
//
//	if (strcmp(step, "play") == 0) moveMan = 1;
//}
