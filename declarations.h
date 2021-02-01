/*
 * declarations.c
 *
 *  Created on: 22 mai 2013
 *      Author: Maxence Fromentin
 */

#include "GL/freeglut.h"
#include "SDL/SDL_mixer.h"

//	#define xTaille 500;
//	#define zTaille 500;
//	#define yPositionTaille 4;


//	extern const int  zTaille;
//	extern const int  yPositionTaille;
	extern float tableau[500][500][4];

// Textures declarations

	extern GLuint textureCaisse;
	extern GLuint textureGroundDust40;
	extern GLuint textureGroundDust41;
	extern GLuint textureGround;
	extern GLuint textureLava;
	extern GLuint textureGrilleSoucoupe;
	extern GLuint textureHalo;
	extern GLuint textureRock;
	extern GLuint textureGrass;
	extern GLuint earth;
	extern GLuint grind;
	extern GLuint eau;
	extern GLuint sea;
	extern GLuint fence;
	extern GLuint fenceTag;
	extern GLuint transparent;
	extern GLuint faceCharacter;

//Application Parameters Main Declarations

	extern void Drawscene ( void );

	//Window Size

	extern float WindowWidth;
	extern float WindowHeight;
	extern void Resize ( int Width, int Height );

	//Mouse Moves

	extern GLboolean Move_Flag;
	extern GLboolean Zoom_Flag;
	extern GLdouble Radius;
	extern GLdouble Twist;
	extern GLdouble Longitude;
	extern GLdouble Latitude;

	extern void Mousefunc ( int Button, int State, int X , int Y );
	extern void Mousemove ( int X, int Y);
	extern void PassiveMove(int X, int Y);

	extern int X_Start_Move;
	extern int Y_Start_Move;

	extern int Y_Start_Zoom;//vas is das ? deprecated ?

	extern int Xvalue;
	extern int Yvalue;

//Game Scenario

	//Saucer

	extern float anglesoucoupe;
	extern float anglesuivresoucoupe;
	extern int aurevoirsoucoupe, bougersoucoupe;
	extern char step[];
	extern float tt; // TODO: Change name

	//Main Character

	extern float xbonhomme;
	extern float ybonhomme;
	extern float zbonhomme;

	extern float armAngle;

	extern int makeCharacter;

		//Character Moves

	extern int touchez,toucheq,touched,touches,toucher;
	extern float zzx, zzy, qqx, qqy, ddx, ddy, ssx, ssy, zzddx, zzddy, zzqqx, zzqqy, ssqqx,
						ssqqy, ssddx, ssddy;
	extern float jack; // TODO: Change Name
	extern int moveMan;
	extern float jumpHeight;
	extern float jumpMaxHeight; //Nombre Impair
	extern int sautencours;


//Camera Perspective

	extern int perspectiveChoice;
	extern float teta;
	extern float zeta;

	//Spyglass Mod

	extern float xCenterSpyglass, yCenterSpyglass, zCenterSpyglass;

// Axis

	extern char nomaxex;
	extern char nomaxey;
	extern char nomaxez;

// Field

	// Lock areas

	extern float chunck[100][6];
	extern int nbchuncksdeclares;

//General variables

	extern float i, j;
	extern int spacebar;
	extern float pi;

