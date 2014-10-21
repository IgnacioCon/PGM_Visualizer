#include "image.h"
#include <stdio.h>
#include <stdlib.h>

void init()
{   //int b=600;

   // glMatrixMode(GL_PROJECTION);
    //glClearColor(0.0,0.0,0.0,0.0);
   // gluOrtho2D(-b,b,500,-500);
   glClearColor(0.0,0.0,0.0,0.0); //Esta funcion recive un valor RGBA
}

void keyboard(unsigned char key,int x, int y)
{

    switch(key)
    {
    case 27: //Tecla de escape
        //exitAndClean();
        break;
    case 'a':

        cout<<"Threshold"<<endl;
        glutDisplayFunc(display3);

        break;
    case 's':

       cout<<"Negativo"<<endl;
       glutDisplayFunc(display2);
        break;
    case 'd':

        cout<<"Original"<<endl;
        glutDisplayFunc(display);
        break;

    case 'f':

        cout<<"Save Image"<<endl;
        saveImage();
        cout<<"Image saved!"<<endl;

        break;
    }
}

void funcInit(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 480, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.375, 0.375, 0);
}




