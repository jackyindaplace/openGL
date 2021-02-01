//#include "../declarations.h"
//#include "math.h"
//
//void Polarview(GLdouble Radius, GLdouble Twist, GLdouble Longitude,
//		GLdouble Latitude) {
//	glTranslated(0.0, 0.0, -Radius);
//	glRotated(-Twist, 0.0, 0.0, 1.0);
//	glRotated(-Latitude, 1.0, 0.0, 0.0);
//	glRotated(Longitude, 0.0, 0.0, 1.0);
//}
//
////Default View
//void VueSuivreBonhomme() {
//	gluLookAt(xbonhomme - 6.0 * cos(teta * 2 * pi / 360),
//			ybonhomme - 6.0 * sin(teta * 2 * pi / 360),
//			zbonhomme + 4.5,
//
//			xbonhomme + cos(teta * 2 * pi / 360) * cos (zeta),
//			ybonhomme + sin(teta * 2 * pi / 360) * cos (zeta),
//			zbonhomme + 4.5 + 6.0 * sin(zeta * 2 * pi / 360),
//
//			0.0, 0.0, 1.0);
//}
//
//void VueCameraSoucoupe() {
//
//	/*glRotatef(anglesoucoupe,0,0,1);
//	 glTranslatef(5.0,5.0,5.0);
//	 gluLookAt(-4,-4,0,0,0,0,0.0,0.0,1.0);*/
//	//gluLookAt(xPosSoucoupe-4.0,yPosSoucoupe-4.0,5.0,xPosSoucoupe,yPosSoucoupe,5.0,0.0,0.0,1.0);
//	anglesuivresoucoupe = anglesuivresoucoupe + 0.01;
//	if (anglesuivresoucoupe == 360.0)
//		anglesuivresoucoupe = 0.001;
//// gluLookAt(30.0*cos(anglesoucoupe),30.0*sin(anglesoucoupe),25.0,-tt,-tt,20.0,0.0,0.0,1.0);
//	gluLookAt(tt - 12.0, tt - 12.0, 28.0, tt - 1.0, tt - 1.0, 20.0, 0.0, 0.0,
//			1.0);
//	//5.0*cos(anglesuivresoucoupe),5.0*sin(anglesuivresoucoupe)
////5.0*cos(anglesoucoupe),5.0*sin(anglesoucoupe),5.0
//	//gluLookAt(0.0,0.0,1.0,1.0,1.0,1.0,0.0,0.0,1.0);
//}
//
//void VueCameraDessus() {
//	gluLookAt(xbonhomme - 0.01, ybonhomme - 0.01, zbonhomme + 10.0, xbonhomme,
//			ybonhomme, zbonhomme, 0.0, 0.0, 1.0);
//}
//
//void VueDevantBonhomme() {
//	gluLookAt(xbonhomme + 5.0 * cos(teta * 2 * pi / 360),
//			ybonhomme + 5.0 * sin(teta * 2 * pi / 360), zbonhomme + 5.0,
//			xbonhomme, ybonhomme, zbonhomme + 2.0, 0.0, 0.0, 1.0);
//}
//
//void VueGaucheBonhomme() {
//	gluLookAt(xbonhomme + 5.0 * cos((teta + 90) * 2 * pi / 360),
//			ybonhomme + 5.0 * sin((teta + 90) * 2 * pi / 360), zbonhomme + 5.0,
//			xbonhomme, ybonhomme, zbonhomme + 2.0, 0.0, 0.0, 1.0);
//}
//
//void VueDroiteBonhomme() {
//	gluLookAt(xbonhomme + 5.0 * cos((teta - 90) * 2 * pi / 360),
//			ybonhomme + 5.0 * sin((teta - 90) * 2 * pi / 360), zbonhomme + 5.0,
//			xbonhomme, ybonhomme, zbonhomme + 2.0, 0.0, 0.0, 1.0);
//}
//
//void VueDescenteBonhomme() {
////	gluLookAt(xbonhomme - 10.0 * zooz * cos(teta * 2 * pi / 360),
////			ybonhomme - 10.0 * zooz * sin(teta * 2 * pi / 360),
////			zbonhomme + 15.0, xbonhomme, ybonhomme, zbonhomme + 15.0, 0.0, 0.0,
////			1.0);
//}
//
//void spyglassMod(){
//
////	AppliquerTexture(TextureSpyglass, 256, 256, 1, 1);
//	AppliquerTexture(TextureRed, 512, 512, 1, 1);
////	AppliquerTexture(TextureBlack, 512, 512, 1, 0);
////	AppliquerTexture(TextureWall_Dirty, 256, 256, 1, 0);
////	perspectiveChoice = 3;
//
//	glPushMatrix();
//
//			glTranslatef(xbonhomme, ybonhomme, zbonhomme+4.0);
//			glRotatef(teta, 0, 0, 1);
////			glRotatef(teta, 0, 0, 1);
//			glRotatef(-zeta, 0.0, 1.0, 0.0);
//
////	glTranslatef(0.0, -2.5, 0.0);
//
//	glBegin(GL_QUADS);
//
//		glColor3ub(0, 0, 0);
//		glTexCoord2d(0.0, 0.0);
//		glVertex3d(2.0, -2.0, -2.0);
//		glTexCoord2d(0.0, 1.0);
//		glVertex3d(2.0, 2.0, -2.0);
//		glTexCoord2d(1.0, 1.0);
//		glVertex3d(2.0, 2.0, 2.0);
//		glTexCoord2d(1.0, 0.0);
//		glVertex3d(2.0, -2.0, 2.0);
//
//	glEnd();
//
////	glDeleteTextures(1, TextureSpyglass);
//	glDeleteTextures(1, TextureRed);
////	glDeleteTextures(1, TextureBlack);
//
//	glDisable(GL_TEXTURE_2D);
//
//	glPopMatrix();
//
//}
//
//void spyglassView(){
//
//	gluLookAt(	xbonhomme + 1.0 * cos(teta * 2 * pi / 360),
//				ybonhomme + 1.0 * sin(teta * 2 * pi / 360),
//				zbonhomme + 4.5,
//
//				xbonhomme + 2.0 * cos(teta * 2 * pi / 360) * cos (zeta * 2 * pi / 360),
//				ybonhomme + 2.0 * sin(teta * 2 * pi / 360) * cos (zeta * 2 * pi / 360),
//				zbonhomme + 4.5 + 6.0 * sin(zeta * 2 * pi / 360),
//
//				0.0, 0.0, 1.0);
//}
//
//void print_actual_matrix() {
//	int ii, jj;
//	GLfloat matrix[4][4];
//	glGetFloatv(GL_MODELVIEW_MATRIX, (GLfloat *) matrix);
//
//	for (ii = 0; ii < 4; ii++) {
//		for (jj = 0; jj < 4; jj++) {
//			//printf("matrix [%d][%d] :", jj, ii);
//			//printf("%f \n", matrix[jj][ii]);
//
//		}
//		//printf("\n");
//	}
//	/*xbonhomme=matrix[2][4];
//	 printf("%f",xbonhomme);
//	 printf("\n");
//	 ybonhomme=matrix[3][2];
//	 printf("%f",ybonhomme);
//	 printf("\n");*/
//}
//
//void choosePerspective(int perspectiveChoice){
//	switch (perspectiveChoice) {
//		case 1:
//			VueSuivreBonhomme();
//			break;
//		case 2:
//			VueCameraSoucoupe();
//			break;
//		case 3:
////			VueCameraDessus();
//			spyglassView();
//			break;
//		case 4:
//			VueDevantBonhomme();
//			break;
//		case 5:
//			VueGaucheBonhomme();
//			break;
//		case 6:
//			VueDroiteBonhomme();
//			break;
//		case 7:
//			VueDescenteBonhomme();
//			break;
//		case 666:
////			SDL_Quit();
//			exit(0);
//			break;
//		}
//}
//
//void zoom(){
//	GLdouble Aspect;
//	Aspect = (GLdouble) WindowWidth / (GLdouble) WindowHeight;
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(25.0, Aspect, 0.01, 100.0);
//	glMatrixMode(GL_MODELVIEW);
//}
