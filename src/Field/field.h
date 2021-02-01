///*
// * field.h
// *
// *  Created on: 25 mai 2013
// *      Author: Maxence Fromentin
// */
//
//extern void declareChunck(float xstart, float xend, float ystart, float yend, float zstart, float zend);
//
//extern int isFree(float x, float y, float z);
//
//extern void wall(float x1, float y1, float z1, float width, float height, int declare);
//
//extern void fourWall(float x1, float y1, float z1, float width, float height);
//
extern void ground(float xstart, float xend, float ymin, float ymax, float zstart, float zend, int interval, GLuint texture, int scaleTexture, bool changeSRand, int randomize, bool halfSphere);
//
//extern void groundGrass(float xstart, float xend, float ystart, float yend, float zstart, float zend);
//
//extern void groundLava(float xstart, float xend, float ystart, float yend, float zstart, float zend);
//
//extern void caisse(float x, float y, float z);
//

extern void water(float xstart, float zstart,int size, int interval, GLuint texture);

extern void flatGround(float width);

//
//extern void fourWall(float x1, float y1, float z1, float width, float height);
//
//extern void turntable();
