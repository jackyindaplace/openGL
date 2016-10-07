/*
 * perspectives.h
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */

extern void Polarview(GLdouble Radius, GLdouble Twist, GLdouble Longitude,
		GLdouble Latitude);

extern void VueSuivreBonhomme();

extern void VueCameraSoucoupe();

extern void VueCameraDessus();

extern void VueDevantBonhomme();

extern void VueGaucheBonhomme();

extern void VueDroiteBonhomme();

extern void VueDescenteBonhomme();

extern void spyglassMod();

extern void spyglassView();

extern void print_actual_matrix();

extern void choosePerspective(int perspectiveChoice);

extern void zoom();
