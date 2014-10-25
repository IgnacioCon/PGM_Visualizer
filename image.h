#ifndef IMAGE_H
#define IMAGE_H
#include <GL/gl.h>
#include <GL/glut.h>
#include "matrix.h"
#include "pgm.h"


void init();
void display(void);  //Funcion para el pintado en pantalla
void keyboard(unsigned char key, int x, int y);

void funcInit(int w, int h);

void instructions(void);
#endif // IMAGE_H
