#define SDL_MAIN_HANDLED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/freeglut.h>
#include <SDL2/SDL_main.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "SDL2/SDL_mouse.h"
#include "declarations.h"
#include "Objects/objects.h"
#include "Textures/initialize.h"
#include "GL/glext.h"
#include "Landmark/landmark.h"
#include "Field/field.h"
#include "Textures/sdlglutils.h"
#include "Scenario/Step-1-Flying-Saucer/saucer.h"
#include <math.h>
#include "Camera/freeflycamera.h"
#include <iostream>
#include "Character/character.h"
using namespace std;


//TODO: For resources allocated by the application, see if static textures are only loaded once or if its are loaded each time
//int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);

/*-lmingw32
 -lSDLmain
 -lSDL
 -lSDL_mixer
 -lSDL_image */

//Generer volume a partir de courbe de spleen

int main(int argc, char **argv) {

	int continuer = 1;
	double angleRotationX = 0;
	double angleRotationY = 0;
	GLdouble xcam = -20;
	GLdouble ycam = 4;
	GLdouble zcam = -10;
	GLdouble tetaCam= 0;
	GLdouble rayon= 15;
	Uint32 last_time = SDL_GetTicks();
	Uint32 current_time, ellapsed_time;
	FreeFlyCamera * camera;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

	//SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");

	SDL_Window *sdlWindow = SDL_CreateWindow("My Game Window",
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          800, 600,
                          SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	// SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);

	// SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &sdlWindow, &sdlRenderer);

	// SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	// SDL_RenderClear(sdlRenderer);
	// SDL_RenderPresent(sdlRenderer);

	// SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	// SDL_RenderSetLogicalSize(sdlRenderer, 640, 480);

	SDL_GLContext glctx  = SDL_GL_CreateContext(sdlWindow);
    glEnable(GL_DEBUG_OUTPUT);
	SDL_GL_MakeCurrent(sdlWindow, glctx);

	// SDL_EnableKeyRepeat(10,10);

	glEnable(GL_TEXTURE_2D);

	initializeTextures();

	camera = new FreeFlyCamera(Vector3D(0,0,2));

//	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)
//			== -1) //Initialisation de l'API Mixer
//			{
//		printf("%s", Mix_GetError());
//	}
//	Mix_Music *musique; //Cr�ation du pointeur de type Mix_Music
	//musique = Mix_LoadMUS("Sound/Sugar feat. Milie oops (do di do di dam).mp3"); //Chargement de la musique
	//Mix_PlayMusic(musique, -1); //Jouer infiniment la musique-----------

	while (continuer) {
		SDL_PollEvent(&event);
		current_time = SDL_GetTicks();
		ellapsed_time = current_time - last_time;
		last_time = current_time;

		switch (event.type) {
			case SDL_QUIT:
				continuer = 0;
	//			Mix_FreeMusic(musique); //Lib�ration de la musique
	//			Mix_CloseAudio(); //Fermeture de l'API
				delete camera;
				SDL_Quit(); //TODO: Bug when closing application
				return EXIT_SUCCESS;

				break;

			case SDL_KEYDOWN:

				switch (event.key.keysym.sym)

				{

					case SDLK_ESCAPE:
						continuer = 0;
			//			Mix_FreeMusic(musique); //Lib�ration de la musique
			//			Mix_CloseAudio(); //Fermeture de l'API
						delete camera;
						SDL_Quit(); //TODO: Bug when closing application
						return EXIT_SUCCESS;
					break;
//					case SDLK_UP:
////						angleRotationX++;
////						if (angleRotationX == 360) angleRotationX = 0;
//
//							break;
//					case SDLK_DOWN:
////						angleRotationX--;
////						if (angleRotationX < 0) angleRotationX = 360;
//						break;
//					case SDLK_LEFT:
//						//if ((event.key.keysym.mod & KMOD_LSHIFT) == KMOD_LSHIFT)
//		//				{
//		//					angle1++;
//		//					if (angle1 > 90)
//		//					angle1 = 90;
//		//				}
//		//				else
//		//				{
//		//					angle2++;
//		//					if (angle2 > 90)
//		//					angle2 = 90;
//		//				}
//						angleRotationY++;
//						if (angleRotationY == 360) angleRotationY = 0;
//						break;

//					case SDLK_RIGHT:
//						angleRotationY--;
//						if (angleRotationY < 0) angleRotationY = 360;
//						break;

					default :
						//std::cout << "key pushed unicode:" << event.key.keysym.unicode << "\n";
					   camera->OnKeyboard(event.key);
					break;
				}
				break;

				case SDL_KEYUP:
				camera->OnKeyboard(event.key);
				break;

				case SDL_MOUSEMOTION:
				       camera->OnMouseMotion(event.motion);
				break;
				case SDL_MOUSEBUTTONUP:
				case SDL_MOUSEWHEEL:
				       camera->OnMouseWheel(event.wheel);
				break;
		}

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(70,(double)640/480,1,1000);
			glEnable(GL_DEPTH_TEST);

			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
			glMatrixMode( GL_MODELVIEW );
			glLoadIdentity( );

			tetaCam += 0.05 * ellapsed_time;
			if (tetaCam > 360) tetaCam = 0;

			camera->animate(ellapsed_time);

			camera->look();

//*************//MAIN VIDEO GAME DRAWING**********************************************

			glEnable(GL_TEXTURE_2D);

			//TestGround
//			ground(-30, -14, 0, 0, -30, -14, 2,textureGroundDust40, false, 0, false);

			//Create Ground
			ground(-10, 10, 0, 1, -10, 10, 2,textureGroundDust40, 1, false, 0, false);
			ground(10, 20, 0, 1, -10, 10, 2,textureGroundDust40, 1, false, 0, false);
			ground(-30, -6, 4, 9, 10, 72, 2,textureRock, 10, false, 0, false);
			ground(-30, -6, 7, 12, 0, 10, 2,textureRock, 5, false, 0, false);
			for(int k=20;k<60;k=k+6){
				ground(-6,0, k*0.1, k*0.2, k, k+6, 2,textureRock, 1,true, k-18, false);
			}
			ground(-6,0, 0, 2, 10, 14, 2,textureRock, 1,false, 0, false);
			ground(-6,0, -2, 2, 10, 20, 2,textureGroundDust40, 1,false,0, false);
			ground(0, 8, -1, 3, 5, 11, 2,textureRock, 1, false,0, false);
			ground(-20,-10, 5, 10, -10, 10, 2,textureRock, 4, false,0, false);
			ground(20, 40, 0, 0, -10, 10, 2,textureGroundDust40, 1, false,0, false);
//							ground(10, 20, -2, 0, 10, 20, 2,eau, 1, false,0, false);
			ground(0, 40, 0, 1, 50, 72, 2,textureGrass, 2, false,0, false);
			ground(40, 60, 7, 10, 40, 50, 2,textureRock, 2, false,0, false);

			//Create passage in the rock
//			ground(40, 60, 0, 4, -10, 50, 2, textureRock, 2, false, 0, false);

			//Create water container (ground)
//			water(0, 10, 40, 2, textureGroundDust40);
//			glColor4f(1.0f,1.0f,1.0f,0.3f);
			ground(0, 40, 0, -20, 10, 50, 2,textureGroundDust40, 4, false,0, true);

			//Fill with water
			drawWater(24, 24, 19.3, sea);

//			glBlendFunc(GL_SRC_ALPHA, GL_ONE);

//			//Create a bunker
			bunker(40, 0, 50, 20, 10);
//
//			//Create cube
			cube(10,1,60);
			cube(12.1,1,60);
			cube(11.05,1,62);
			cube(11.05,3,61);

			//Create rotating earth
			angleRotationY += 0.05 * ellapsed_time;
			angleRotationX += 0.05 * ellapsed_time;
//			glPushMatrix();
//				glScaled(1,1.5,1);
//				drawEarth(angleRotationX,angleRotationY);
//			glPopMatrix();

			ellapsed_time = SDL_GetTicks() - current_time;
			if (ellapsed_time < 10)   SDL_Delay(10 - ellapsed_time);

//			glLoadIdentity();
			//gluLookAt(rayon*cos(tetaCam * 2 * pi / 360), ycam, rayon*sin(tetaCam * 2 * pi / 360) , 0,2,0,0,1,0);
//			camera->look();

			//Draw UFO engine
			glTranslated(4,9,0);
			glRotated(-90,1,0,0);
				soucoupe();
			glRotated(90,1,0,0);
			glTranslated(-4,-9,0);

			/* Draw character*/

					character();


			/*Draw fence - no trespassing violators.
			Transparency elements should be drawn at the end.*/
			cloture(-7, 0, 3, 47, 10);

			//DrawAxes(0.0,0.0,0.0);
			//dessinerRepere(2);

//****************MAIN VIDEO GAME DRAWING END******************************************

			glFlush();
			SDL_GL_SwapWindow(sdlWindow);
		}

		return 0;
	}




/* Dessine le rep�re actuel pour faciliter la compr�hension des transformations.
 Utiliser � echelle � pour avoir un rep�re bien orient� et positionn� mais avec une �chelle diff�rente. */

void Resize(int Width, int Height) {
	GLdouble Aspect;
	glViewport(0, 0, (GLsizei) Width, (GLsizei) Height);
	Aspect = (GLdouble) Width / (GLdouble) Height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, Aspect, 0.01, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void Keyfunc(unsigned char Key, int X, int Y) {
	switch (Key) {
	case 'z':
		touchez = 1;
		//if(c=0)
		//while(anglebras<180.0) anglebras=anglebras+1.0;

		//else anglebras=90.0;
		break;
	case 'q':
		toucheq = 1;
		break;
	case 'd':
		touched = 1;
		break;
	case 's':
		touches = 1;
		break;
	case 'f':
		printf("f\n");
		break;
	case 32:
		spacebar = 1;
		break;
	}
}

void KeyfuncUp(unsigned char Key, int X, int Y) {
	switch (Key) {
	case 'z':
		touchez = 0;
		break;
	case 'q':
		toucheq = 0;
		break;
	case 'd':
		touched = 0;
		break;
	case 's':
		touches = 0;
		break;
	case 'f':
		printf("f\n");
		break;
	case 32:
		spacebar = 0;
		break;
	}
}

void Menu(int Value) {
	perspectiveChoice = Value;
}


