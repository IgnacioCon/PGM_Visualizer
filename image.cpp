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

void keyboard(unsigned char key, int x, int y)
{

    switch(key)
    {
    case 'x':
        exit(0);
        break;
    case 'a':

        cout<<"Threshold Filter"<<endl;
        glutDisplayFunc(display3);

        break;
    case 's':
       cout<<"Negative Filter"<<endl;
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

void funcInit(int w, int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, 0, 1);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.375, 0.375, 0);
}

void instructions(void)
{
    cout<<"                             PGM-VISUALIZER"<<endl;
    cout<<"Press A to apply Threshold Filter."<<endl;
    cout<<"Press S to apply Negative Filter."<<endl;
    cout<<"Press D to view original image."<<endl;
    cout<<"Press F to save the image."<<endl;
    cout<<"Press X to exit."<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;

    cout<<"Enter the name of the Image:"<<endl;
}



