///*
// * moves.c
// *
// *  Created on: 25 mai 2013
// *      Author: Maxence Fromentin
// */
//
//#include "../declarations.h"
//#include "math.h"
//#include "../Field/field.h"
//
//void Mousefunc(int Button, int State, int X, int Y) {
//	switch (Button) {
//	case GLUT_LEFT_BUTTON:
//		switch (State) {
//		case GLUT_DOWN:
//			Y_Start_Zoom = Y;
//			//Move_Flag = GL_TRUE;
//			Zoom_Flag = GL_TRUE;
//			break;
//		case GLUT_UP:
//			Zoom_Flag = GL_FALSE;
//			break;
//
//		}
//		break;
//	case GLUT_RIGHT_BUTTON:
//		switch (State) {
//		case GLUT_DOWN:
//			Y_Start_Zoom = Y;
//			Zoom_Flag = GL_TRUE;
//			break;
//		case GLUT_UP:
//			Zoom_Flag = GL_FALSE;
//			break;
//		}
//		break;
//	case GLUT_MIDDLE_BUTTON:
//		switch (State) {
//		case GLUT_DOWN:
//			break;
//		case GLUT_UP:
//			break;
//		}
//		break;
//	}
//}
//
//void Mousemotionmove(int X, int Y) {
//	Longitude = Longitude + (GLdouble) (X - X_Start_Move);
//	Latitude = Latitude - (GLdouble) (Y - Y_Start_Move);
//	X_Start_Move = X;
//	Y_Start_Move = Y;
//	glutPostRedisplay();
//}
//
////Allow to change the main view by following the mouse cursor.
//void PassiveMove(int X, int Y) {
////	glutWarpPointer(WindowWidth/2, WindowHeight/2);
//
//	if (X_Start_Move != 0)	teta = teta + (GLdouble) (X_Start_Move - X);
//
//	//Y goes like that  : 	|
//	//						v	(down : here, from 0 to 700)
//
//	if (Y_Start_Move != 0)
//	{
//
//		if(zeta<=55.0 && zeta >= -40.0)
//			{
//			zeta = zeta + (GLdouble)(Y_Start_Move - Y)/3;
//			}
//
//	//		glutWarpPointer(WindowWidth/2, WindowHeight/2);
//	//		}
//	//	else if(Y_Start_Move < Y)
//	//		{
//	//		zeta = zeta + (GLdouble)(Y_Start_Move - Y)/100;
//	////		glutWarpPointer(WindowWidth/2, WindowHeight/2);
//
//	}
//
//
//	//Block the view on z axis if it is too on the top or too on the bottom.
//	if (zeta>55.0) zeta=55.0;
//	if (zeta<-40.0) zeta=-40.0;
//
//
//
//	//Retrieve values of X and Y to print in console.
//	Xvalue = X;
//	Yvalue = Y;
//
//	X_Start_Move = X;
//	Y_Start_Move = Y;
//	glutPostRedisplay();
//}
//
//void Mousemotionzoom(int X, int Y) {
//	//Radius = Radius - (GLdouble)(Y - Y_Start_Zoom) / 10.0;
////	zooz = zooz + (GLdouble) (Y - Y_Start_Zoom) / 100.0;
//	//printf("\n %f", zooz);
////	Y_Start_Zoom = Y;
////	glutPostRedisplay();
//}
//
//void Mousemove(int X, int Y) {
//	if (Move_Flag)
//		Mousemotionmove(X, Y);
//	else if (Zoom_Flag)
//		Mousemotionzoom(X, Y);
//}
//
//void DeplacementBonhomme() {
//	zzx = xbonhomme + jack * cos(teta * 2 * pi / 360);
//	zzy = ybonhomme + jack * sin(teta * 2 * pi / 360);
//
//	qqx = xbonhomme + jack * cos((teta + 90) * 2 * pi / 360);
//	qqy = ybonhomme + jack * sin((teta + 90) * 2 * pi / 360);
//
//	ddx = xbonhomme + jack * cos((teta - 90) * 2 * pi / 360);
//	ddy = ybonhomme + jack * sin((teta - 90) * 2 * pi / 360);
//
//	ssx = xbonhomme - jack * cos(teta * 2 * pi / 360);
//	ssy = ybonhomme - jack * sin(teta * 2 * pi / 360);
//
//	zzqqx = xbonhomme + jack * cos(teta * 2 * pi / 360)
//			+ jack * cos((teta + 90) * 2 * pi / 360);
//	zzqqy = ybonhomme + jack * sin(teta * 2 * pi / 360)
//			+ jack * sin((teta + 90) * 2 * pi / 360);
//	zzddx = xbonhomme + jack * cos(teta * 2 * pi / 360)
//			+ jack * cos((teta - 90) * 2 * pi / 360);
//	zzddy = ybonhomme + jack * sin(teta * 2 * pi / 360)
//			+ jack * sin((teta - 90) * 2 * pi / 360);
//	ssqqx = xbonhomme - jack * cos(teta * 2 * pi / 360)
//			+ jack * cos((teta + 90) * 2 * pi / 360);
//	ssqqy = ybonhomme - jack * sin(teta * 2 * pi / 360)
//			+ jack * sin((teta + 90) * 2 * pi / 360);
//	ssddx = xbonhomme - jack * cos(teta * 2 * pi / 360)
//			+ jack * cos((teta - 90) * 2 * pi / 360);
//	ssddy = ybonhomme - jack * sin(teta * 2 * pi / 360)
//			+ jack * sin((teta - 90) * 2 * pi / 360);
//
//	float hauteur = 0.0, hauteurmax = 3.2;
//	int refuse = 0;
//
//	//Appui sur une seule touche
//	if (touchez == 1 && toucheq != 1 && touched != 1 && touches != 1) {
//
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//			if (isFree(zzx, zzy, zbonhomme + hauteur) != 1)
//				refuse = 1;
//		}
//		if (refuse == 0) {
//			xbonhomme = zzx;
//			ybonhomme = zzy;
//		}
//	}
//	refuse = 0;
//
//	if (toucheq == 1 && touchez != 1 && touched != 1 && touches != 1) {
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//			if (isFree(qqx, qqy, zbonhomme + hauteur) != 1)
//				refuse = 1;
//		}
//		if (refuse == 0) {
//			xbonhomme = qqx;
//			ybonhomme = qqy;
//		}
//	}
//	refuse = 0;
//
//	if (touched == 1 && touchez != 1 && toucheq != 1 && touches != 1) {
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//			if (isFree(ddx, ddy, zbonhomme + hauteur) != 1)
//				refuse = 1;
//		}
//		if (refuse == 0) {
//			xbonhomme = ddx;
//			ybonhomme = ddy;
//		}
//	}
//	refuse = 0;
//
//	if (touches == 1 && touchez != 1 && toucheq != 1 && touched != 1) {
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//			if (isFree(ssx, ssy, zbonhomme + hauteur) != 1)
//				refuse = 1;
//		}
//		if (refuse == 0) {
//			xbonhomme = ssx;
//			ybonhomme = ssy;
//		}
//	}
//	refuse = 0;
//	//Appui sur deux touches simultanées
//	if (touchez == 1 && toucheq == 1 && touched != 1 && touches != 1) {
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//			if (isFree(zzqqx, zzqqy, zbonhomme + hauteur) != 1)
//							refuse = 1;
//			}
//		if (refuse == 0) {
//			xbonhomme = zzqqx;
//			ybonhomme = zzqqy;
//		}
//	}
//	if (touchez == 1 && touched == 1 && toucheq != 1 && touches != 1) {
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//					if (isFree(zzddx, zzddy, zbonhomme + hauteur) != 1)
//									refuse = 1;
//					}
//
//			if (refuse == 0) {
//			xbonhomme = zzddx;
//			ybonhomme = zzddy;
//		}
//	}
//	if (touches == 1 && toucheq == 1 && touched != 1 && touchez != 1) {
//		for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//		if (isFree(ssqqx, ssqqy, zbonhomme + hauteur) != 1)
//						refuse = 1;
//		}
//			if (refuse == 0) {
//			xbonhomme = ssqqx;
//			ybonhomme = ssqqy;
//			}
//
//	}
//	if (touches == 1 && touched == 1 && toucheq != 1 && touchez != 1) {
//			for (hauteur = 0.0; hauteur < hauteurmax; hauteur++) {
//			if (isFree(ssddx, ssddy, zbonhomme + hauteur) != 1)
//						refuse = 1;
//			}
//			if (refuse == 0) {
//			xbonhomme = ssddx;
//			ybonhomme = ssddy;
//			}
//
//	}
//
//	if (spacebar == 1)
//		sautencours = 1;
//
//	if (sautencours == 1) {
//		if (jumpHeight < jumpMaxHeight) {
//			if (jumpHeight < (jumpMaxHeight + 1.0) / 2.0) {
//				if (isFree(xbonhomme, ybonhomme, zbonhomme + 1.0 / jumpHeight) == 1
//						&& isFree(xbonhomme, ybonhomme,
//								zbonhomme + 3.2 + 1.0 / jumpHeight) == 1)
//
//						{
//					zbonhomme = zbonhomme + 1.0 / jumpHeight;
//					jumpHeight = jumpHeight + 1.0;
//				} else {
//					sautencours = 0;
//					jumpHeight = 1.0;
//				}
//			}
//
//			else if (isFree(xbonhomme, ybonhomme, zbonhomme - 1.0 / (jumpMaxHeight - jumpHeight))
//					== 1) {
//				zbonhomme = zbonhomme - 1.0 / (jumpMaxHeight - jumpHeight);
//				jumpHeight = jumpHeight + 1.0;
//			} else {
//				sautencours = 0;
//				jumpHeight = 1.0;
//			}
//		} else {
//			jumpHeight = 1.0;
//			sautencours = 0;
//		}
//	}
//	//printf("\n z : %f \n", zbonhomme);
//
//	//Gravité
//	if (sautencours == 0 ) {//&& step != 0
//		if (isFree(xbonhomme, ybonhomme, zbonhomme - 0.1) == 1)
//			{printf("\n c est libre ");
//			//&& zbonhomme > 0.1
//			zbonhomme = zbonhomme - 0.1;}
////		if (zbonhomme < 0.1 && isFree(xbonhomme, ybonhomme, 0.0) == 1)
////			zbonhomme = 0.0;
//		if (zbonhomme < -20.0)
//					zbonhomme = 5.0;
//	}
//}
