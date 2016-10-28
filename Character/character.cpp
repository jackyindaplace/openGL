/*
 * character.c
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */

#include "../declarations.h"
#include <GL/glut.h>

//void bonhomme() { //Hauteur totale  : 3.2
//	GLUquadric* params;
//	params = gluNewQuadric();
//
//	glPushMatrix();
//
//	//Dessin des chaussures du personnage
//
//	glRotatef(90, 0, 0, 1);
//
//		glPushMatrix();
//			glTranslatef(-0.3, 0.0, 0.0);
//			//glScalef(0.6, 1.6, 1.0);
////			AppliquerTexture(TextureChaussures, 140, 28, 1, 0);
//			glColor3ub(255, 255, 255); //Blanc
//			gluQuadricDrawStyle(params, GLU_FILL);
////			gluQuadricTexture(params, GL_TRUE);
//				glPushMatrix();
//					//glScalef(1.3, 0.7, 1.5);
//					gluCylinder(params, 0.2, 0.8 * 0.2, 0.1, 20, 1);
//				glPopMatrix();
//			glTranslatef(0.6, 0.0, 0.0);
//			gluCylinder(params, 0.2, 0.8 * 0.2, 0.1, 20, 1);
//		glPopMatrix();
//
//	glTranslatef(0.0, 0.0, 0.1);
//
//	//Dessin des jambes du personnage
//
//	//glColor3ub(38, 86, 213); //Bleu
//	glColor3ub(255, 255, 255); //Blanc
//	//glScalef(1.0, 0.4, 1.0);
//	glPushMatrix();
//		glTranslatef(-0.3, 0.0, 0.0);
//		glScalef(1.0, 0.8, 1.0);
////		AppliquerTexture(TexturePantalon, 80, 128, 1, 0);
//		glRotatef(180, 0, 0, 1);
//		gluQuadricDrawStyle(params, GLU_FILL);
////		gluQuadricTexture(params, GL_TRUE);
//		gluCylinder(params, 0.2, 0.2, 1.6, 20, 1);
//		glTranslatef(-0.6, 0.0, 0.0);
//		gluCylinder(params, 0.2, 0.2, 1.6, 20, 1);
////		glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//	glTranslatef(0.0, 0.0, 1.6);
//
//	//Dessin du bassin du personnage
//	glPushMatrix();
//		glColor3ub(255, 255, 255); //Blanc
//		glScalef(1.0, 0.4, 1.0);
////		AppliquerTexture(TextureBassin, 400, 64, 5, 0);
//		glRotatef(-110, 0, 0, 1);
//		gluQuadricDrawStyle(params, GLU_FILL);
////		gluQuadricTexture(params, GL_TRUE);
//		gluCylinder(params, 0.5, 0.5, 0.3, 20, 1);
////		glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//	glTranslatef(0.0, 0.0, 0.3);
//
//	glPushMatrix();
//		glColor3ub(255, 255, 255); //Blanc
//		glScalef(1.0, 0.4, 1.0);
//		glRotatef(-170, 0, 0, 1);
////		AppliquerTexture(TextureCeinture, 240, 32, 5, 0);
//		gluQuadricDrawStyle(params, GLU_FILL);
////		gluQuadricTexture(params, GL_TRUE);
//
//		gluCylinder(params, 0.5, 0.5, 0.2, 20, 1);
////		glDisable(GL_TEXTURE_2D);
//	glPopMatrix();
//
//	//Dessin du buste du personnage
//
//	glTranslatef(0.0, 0.0, 0.2);
//	glPushMatrix();
//		glColor3ub(61, 139, 73); //Vert Pas mal
//		glScalef(1.0, 0.4, 1.0);
//		gluCylinder(params, 0.5, 0.5, 1.1, 20, 1);
//	glPopMatrix();
//
//	glTranslatef(0.0, 0.0, 1.1);
//
//	glPushMatrix();
//		glColor3ub(61, 119, 63); //Vert Pas mal
//		glTranslatef(0.55, 0.0, -0.8);
//		gluCylinder(params, 0.15, 0.15, 0.7, 20, 1);
//		glRotatef(armAngle, 1, 0, 0);
//		gluCylinder(params, 0.15, 0.15, 0.4, 20, 1);
//		glRotatef(-armAngle, 1, 0, 0);
//		glTranslatef(-1.1, 0.0, 0.0);
//		gluCylinder(params, 0.15, 0.15, 0.7, 20, 1);
//		glRotatef(armAngle, 1, 0, 0);
//		gluCylinder(params, 0.15, 0.15, 0.4, 20, 1);
//	glPopMatrix();
//
//	//Dessin du cou du personnage
//	glColor3ub(226, 157, 133);
//	gluCylinder(params, 0.15, 0.15, 0.3, 20, 1);
//
////		glPushMatrix();
////			glTranslatef(0.0, -2.0, 0.0);
////			spyglassMod();
////		glPopMatrix();
//
//	glTranslatef(0.0, 0.0, 0.5);
//
//	// Dessin de la tete du personnage
//
//	glColor3ub(255, 255, 255); //Blanc
//	gluQuadricDrawStyle(params, GLU_FILL);
////	gluQuadricTexture(params, GL_TRUE);
////	AppliquerTexture(TextureFace, 512, 256, 3, 0);
//	glScalef(0.5, 0.65, 0.9);
//
//	gluSphere(params, 0.5, 30, 30);
//
////	glDisable(GL_TEXTURE_2D);
//
//	glPopMatrix();
//}

void character(){

	glPushMatrix();
		glTranslated(0,5.7,0);

		GLUquadric* params;
		params = gluNewQuadric();
		gluQuadricDrawStyle(params, GLU_FILL);
		gluQuadricTexture(params, GL_TRUE);

	/* Draw Head */
		glColor3ub(255, 255, 255); //Blanc
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,faceCharacter);

		glRotated(-90,1,0,0);
		glScalef(0.5, 0.7*0.5, 0.5);
			gluCylinder(params, 1,1,3,20,1);
		glScalef(2, 1/0.35, 2);
		glRotated(90,1,0,0);

	/* Draw upper body */
		glTranslated(0,-2.2,0);
		glDisable(GL_TEXTURE_2D);
		glColor3ub(255, 0, 0);

		glRotated(-90,1,0,0);
		glScalef(1, 0.7*0.5, 1);
			gluCylinder(params, 0.8, 1, 2.2, 20, 1);
		glScalef(1, 1/0.35, 1);
		glRotated(90,1,0,0);

	/* Draw arms */
		glTranslated(-1,1.1,0);
		glColor3ub(255, 0, 255);

		glRotated(-90,1,0,0);
		glRotated(10,0,1,0);
			gluCylinder(params, 0.2, 0.2, 1.1, 20, 1);
		glRotated(-10,0,1,0);
		glRotated(90,1,0,0);

		glTranslated(2,0,0);

		glRotated(-90,1,0,0);
		glRotated(-10,0,1,0);
			gluCylinder(params, 0.2, 0.2, 1.1, 20, 1);
		glRotated(10,0,1,0);
		glRotated(90,1,0,0);

	/* Draw arm part2 */
		glTranslated(-2,-1.1,0);
			glRotated(-90,1,0,0);
				gluCylinder(params, 0.2, 0.2, 1.1, 20, 1);
			glRotated(90,1,0,0);

		glTranslated(2,0,0);
			glRotated(-90,1,0,0);
				gluCylinder(params, 0.2, 0.2, 1.1, 20, 1);
			glRotated(90,1,0,0);

		glTranslated(-1,0,0);

	/* Draw hands */
		glColor3ub(0, 255, 0);
		glTranslated(-1,-0.4,0);
			glRotated(-90,1,0,0);
				gluCylinder(params, 0.15, 0.2, 0.4, 20, 1);
			glRotated(90,1,0,0);

		glTranslated(2,0,0);
			glRotated(-90,1,0,0);
				gluCylinder(params, 0.15, 0.2, 0.4, 20, 1);
			glRotated(90,1,0,0);

		glTranslated(-1,0.4,0);

	/* Draw butt*/
		glTranslated(-0.4,-0.8,0);
			glColor3ub(255, 255, 0);

			glRotated(-90,1,0,0);
				glScalef(1, 0.7, 1);
				gluCylinder(params, 0.4, 0.4, 0.8, 20, 1);
				glScalef(1, 1/0.7, 1);
			glRotated(90,1,0,0);

			glTranslated(0.8,0,0);
			glRotated(-90,1,0,0);
				glScalef(1, 0.7, 1);
				gluCylinder(params, 0.4, 0.4, 0.8, 20, 1);
				glScalef(1, 1/0.7, 1);
			glRotated(90,1,0,0);
		glTranslated(-0.4,0,0);

	/* Draw legs */
		glTranslated(-0.4,-1,0);
		glColor3ub(255, 255, 0);

		glRotated(-90,1,0,0);
			glScalef(1, 0.7, 1);
			gluCylinder(params, 0.3, 0.4, 1, 20, 1);
			glScalef(1, 1/0.7, 1);
		glRotated(90,1,0,0);

		glTranslated(0.8,0,0);
		glRotated(-90,1,0,0);
			glScalef(1, 0.7, 1);
			gluCylinder(params, 0.3, 0.4, 1, 20, 1);
			glScalef(1, 1/0.7, 1);
		glRotated(90,1,0,0);
		glTranslated(-0.4,0,0);

	/* Draw legs part 2 */
		glTranslated(-0.4,-0.8,0);
		glColor3ub(255, 255, 0);

		glRotated(-90,1,0,0);
			glScalef(1, 0.7, 1);
			gluCylinder(params, 0.3, 0.3, 0.8, 20, 1);
			glScalef(1, 1/0.7, 1);
		glRotated(90,1,0,0);

		glTranslated(0.8,0,0);
		glRotated(-90,1,0,0);
			glScalef(1, 0.7, 1);
			gluCylinder(params, 0.3, 0.3, 0.8, 20, 1);
			glScalef(1, 1/0.7, 1);
		glRotated(90,1,0,0);
		glTranslated(-0.4,-0.0,0);

	/* Draw shoes */
		glTranslated(-0.4,-0.4,0);
			glColor3ub(255, 255, 255);

			glRotated(-90,1,0,0);
				glScalef(1, 0.7, 1);
				gluCylinder(params, 0.3, 0.3, 0.4, 20, 1);
				glScalef(1, 1/0.7, 1);
			glRotated(90,1,0,0);

			glTranslated(0.8,0,0);
			glRotated(-90,1,0,0);
				glScalef(1, 0.7, 1);
				gluCylinder(params, 0.3, 0.3, 0.4, 20, 1);
				glScalef(1, 1/0.7, 1);
			glRotated(90,1,0,0);
		glTranslated(-0.4,-0.0,0);

		glTranslated(-0.4,0.15,0.3*0.7);
//			glRotated(-90,1,0,0);
				glScalef(1, 0.7, 1);
				gluCylinder(params, 0.3, 0.2, 0.6, 20, 1);
				glScalef(1, 1/0.7, 1);
//			glRotated(90,1,0,0);

			glTranslated(0.8,0,0);
//			glRotated(-90,1,0,0);
				glScalef(1, 0.7, 1);
				gluCylinder(params, 0.3, 0.2, 0.6, 20, 1);
				glScalef(1, 1/0.7, 1);
//			glRotated(90,1,0,0);
		glTranslated(-0.4,-0.0,0);

	glPopMatrix();

}
