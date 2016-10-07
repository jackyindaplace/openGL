/*
 * field.h
 *
 *  Created on: 25 mai 2013
 *      Author: Maxence Fromentin
 */

extern void declareChunck(float xstart, float xend, float ystart, float yend, float zstart, float zend);

extern int isFree(float x, float y, float z);

extern void wall(float x1, float y1, float z1, float width, float height, int declare);

extern void fourWall(float x1, float y1, float z1, float width, float height);

extern void groundDust(float xstart, float xend, float ystart, float yend, float zstart, float zend);

extern void groundGrass(float xstart, float xend, float ystart, float yend, float zstart, float zend);

extern void groundLava(float xstart, float xend, float ystart, float yend, float zstart, float zend);

extern void cube(float x, float y, float z);

extern void wall(float x1, float y1, float z1, float width, float height, int declare);

extern void fourWall(float x1, float y1, float z1, float width, float height);

extern void turntable();
