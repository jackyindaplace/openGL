/*
 * landmark.c
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */

#include "../declarations.h"

void DrawAxes(float X, float Y, float Z) {
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(X, Y, Z);
	glVertex3f(X + 1.34, Y, Z);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(X, Y, Z);
	glVertex3f(X, Y + 1.34, Z);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(X, Y, Z);
	glVertex3f(X, Y, Z + 1.34);
	glEnd();

	//Texte indiquant le nom des axes
//	glRasterPos3f(X + 1.0, Y, Z);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, nomaxex);
//	glRasterPos3f(X, Y + 1.0, Z);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, nomaxey);
//	glRasterPos3f(X, Y, Z + 1.0);
//	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, nomaxez);

	glColor3f(1.0, 1.0, 0.0);

	glTranslated(1.5,0,0);
	glRotated(90,1,0,0);
	//glutSolidCone(0.3, 0.5, 1000, 1000);
	glRotated(-90,1,0,0);
	glTranslated(-1.5,1.5,0);
	glRotated(90,0,1,0);


	glBegin(GL_POLYGON);
	glVertex3f(X + 1.5, Y, Z);
	glVertex3f(X + 1.35, Y - 0.05, Z);
	glVertex3f(X + 1.35, Y - 0.05, Z);
	glEnd();

	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(X, Y + 1.5, Z);
	glVertex3f(X - 0.05, X + 1.35, Z);
	glVertex3f(X + 0.05, X + 1.35, Z);
	glEnd();

	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(X, Y, Z + 1.5);
	glVertex3f(X - 0.05, Y, Z + 1.35);
	glVertex3f(X + 0.05, Y, Z + 1.35);
	glEnd();
}

void coordonnees() {
	char res1[10], res2[10], res3[10];
	sprintf(res1, "%.2f", xbonhomme);
	sprintf(res2, "%.2f", ybonhomme);
	sprintf(res3, "%.2f", zbonhomme);

	//Texte indiquant les coordonnées en temps réel

	int longueurchaine1 = strlen(res1);
	int longueurchaine2 = strlen(res2);
	int longueurchaine3 = strlen(res3);

	int iy = 0;
	glRasterPos3f(xbonhomme - 1.6, ybonhomme - 1.6, zbonhomme + 3.0);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'x');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ':');
	for (iy = 0; iy < longueurchaine1 - 1; iy++) {
		int al = res1[iy];

		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, al);
	}

	glRasterPos3f(xbonhomme - 0.9, ybonhomme - 0.9, zbonhomme + 3.0);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'y');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ':');
	for (iy = 0; iy < longueurchaine2 - 1; iy++) {
		int al = res2[iy];

		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, al);
	}

	glRasterPos3f(xbonhomme - 0.4, ybonhomme - 0.4, zbonhomme + 3.0);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'z');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ':');
	for (iy = 0; iy < longueurchaine3 - 1; iy++) {
		int al = res3[iy];

		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, al);
	}

	/*glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'x');
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'x');*/
	/*glRasterPos3f(xbonhomme,ybonhomme,zbonhomme);
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, ybonhomme);
	 glRasterPos3f(xbonhomme,ybonhomme,zbonhomme+3.0);
	 glutBitmapCharacter(GLUT_BITMAP_9_BY_15, zbonhomme);*/
}
