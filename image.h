#ifndef IMAGE_H
#define IMAGE_H
#include <GL/gl.h>
#include <GL/glut.h>
#include "matrix.h"
#include "pgm.h"


void init();
void display(void);  //Funcion para el pintado en pantalla
void keyboard(unsigned char key, int x, int y);
void display2(void);
void display3(void);

void funcInit(int w, int h);
void saveImage(void);

void instructions(void);
#endif // IMAGE_H
