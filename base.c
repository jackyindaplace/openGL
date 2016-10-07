#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/freeglut.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include "declarations.h"
#include <GL/glext.h>

//TODO: For resources allocated by the application, see if static textures are only loaded once or if its are loaded each time
//TODO: Lower The FPS and compare the processor allocation.
int Mix_OpenAudio(int frequency, Uint16 format, int channels, int chunksize);

/*-lmingw32 
 -lSDLmain
 -lSDL
 -lsdl_mixer*/

//zip et cc françois le floch
//Thierry.SOBANSKI@ICL-LILLE.FR
//Generer volume a partir de courbe de spleen

void ChargerTexture(char *nomfichier, unsigned int *nomtexture, int hauteur, int largeur) {
	char chaine1[50] = "Textures/";
	char *nom = strcat(chaine1, nomfichier);
	//Ouverture d'une texture. Syntaxe : fopen(nom_de_fichier, mode) avec r:read, b:write
	OuvrirTexture = fopen(nom, "rb");
	if (OuvrirTexture) {
		/*The first parameter is a pointer to where you want the data stored.
		 The second parameter is the size of each element that you want to read.
		 The third is the number of elements of that size toread. The final parameter a pointer to the stream obtained from fopen.*/
		fread(nomtexture, hauteur * largeur * 3, 1, OuvrirTexture);
		fclose(OuvrirTexture);
	}
}

void Initialize(int Width, int Height) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	Resize(Width, Height);
	ChargerTexture("soucoupe.bmp", TextureGrilleSoucoupe, 32, 32);
	ChargerTexture("icewater.tga", TextureSolEau, 512, 512);
	ChargerTexture("sand03.tga", TextureSolSable, 512, 512);
	ChargerTexture("grass.tga", TextureSolHerbe, 512, 512);
	ChargerTexture("lavarock3.tga", TextureLava, 512, 512);
	ChargerTexture("sandro_facemap.bmp", TextureFace, 512, 256);
	ChargerTexture("pantalon.bmp", TexturePantalon, 80, 128);
	ChargerTexture("ceinture.bmp", TextureCeinture, 240, 32);
	ChargerTexture("caisse.tga", TextureCaisse, 256, 256);
	ChargerTexture("Bassin.bmp", TextureBassin, 400, 64);
	ChargerTexture("chaussures.bmp", TextureChaussures, 140, 28);
	ChargerTexture("wall_dirty.tga", TextureWall_Dirty, 256, 256);
	ChargerTexture("spyglass.bmp", TextureSpyglass, 512, 512);
	ChargerTexture("transparent.bmp", TextureTransparent, 512, 512);
	ChargerTexture("fond.bmp", TextureFond, 512, 512);
	ChargerTexture("black.bmp", TextureBlack, 512, 512);
	ChargerTexture("Red.bmp", TextureRed, 512, 512);
	ChargerTexture("rgb.bmp", TextureRgb, 512, 512);
	//ChargerTexture("halo.bmp",TextureHalo,256,256);
	OuvrirTexture = fopen("Textures/halo.bmp", "rb");
	if (OuvrirTexture) {/*The first parameter is a pointer to where you want the data stored.
	 The second parameter is the size of each element that you want to read.
	 The third is the number of elements of that size toread. The final parameter a pointer to the stream obtained from fopen.*/
		fread(TextureHalo, 256 * 256 * 4, 1, OuvrirTexture);
		fclose(OuvrirTexture);
	}
	//for(dd=0;dd<256;dd++) {printf("%d",TextureSol[dd]);system("PAUSE");}
	//for(dd=0;dd<256;dd++) {printf("%d",TextureHalo[dd]);
	/* system("PAUSE");*///};
}

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

int main(int argc, char **argv) {
	int continuer = 1;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption("OpenGL",NULL);
	SDL_SetVideoMode(640, 480, 32, SDL_OPENGL);




// void update(){
//
//   glutPostRedisplay(); //Tell GLUT that the scene has changed
//   glutTimerFunc(100, update, 0);//Tell GLUT to call update again in 700 milliseconds
//   }
//
//   update(Drawscene);

	SDL_Event event;

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)
			== -1) //Initialisation de l'API Mixer
			{
		printf("%s", Mix_GetError());
	}
	Mix_Music *musique; //Création du pointeur de type Mix_Music
	musique = Mix_LoadMUS("Sound/Sugar feat. Milie oops (do di do di dam).mp3"); //Chargement de la musique
	Mix_PlayMusic(musique, -1); //Jouer infiniment la musique-----------

	while (continuer) {
		SDL_WaitEvent(&event);

		switch (event.type) {
		case SDL_QUIT:
			continuer = 0;
			Mix_FreeMusic(musique); //Libération de la musique
			Mix_CloseAudio(); //Fermeture de l'API
			SDL_Quit(); //TODO: Bug when closing application
			return EXIT_SUCCESS;

			break;
		}

		glClear(GL_COLOR_BUFFER_BIT);

		        glBegin(GL_TRIANGLES);
		            glColor3ub(255,0,0);    glVertex2d(-0.75,-0.75);
		            glColor3ub(0,255,0);    glVertex2d(0,0.75);
		            glColor3ub(0,0,255);    glVertex2d(0.75,-0.75);
		        glEnd();


//		glutInit(&argc, argv);
//			glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//			glutInitWindowSize(WindowWidth, WindowHeight);
//			glutCreateWindow("OpenGL & Glut: Programme de base");
//			glutDisplayFunc(Drawscene);
//			glutReshapeFunc(Resize);
//			glutKeyboardFunc(Keyfunc);
//			glutKeyboardUpFunc(KeyfuncUp);
//			glutMouseFunc(Mousefunc);
//			glutWarpPointer(WindowWidth/2, WindowHeight/2);
//			glutMotionFunc(Mousemove);
//			glutPassiveMotionFunc(PassiveMove);
//			Initialize(1200, 700);
//
//			glutCreateMenu(Menu);
//			//glutAddMenuEntry("--------", 0);
//			glutAddMenuEntry("Vue de dessus", 1);
//			glutAddMenuEntry("Vue soucoupe", 2);
//			glutAddMenuEntry("Vue dessus", 3);
//			glutAddMenuEntry("Vue de face", 4);
//			glutAddMenuEntry("Vue de gauche", 5);
//			glutAddMenuEntry("Vue de droite", 6);
//			glutAddMenuEntry("Quit", 666);
//			glutAttachMenu(GLUT_RIGHT_BUTTON);
//			glutIdleFunc(Drawscene);
//
//		glutMainLoop();

		glFlush();
			    SDL_GL_SwapBuffers();
	}

	//En mode non SDL
//	glutMainLoop();

	return 0;
}
