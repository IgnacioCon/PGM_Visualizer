#include "matrix.h"
#include "pgm.h"
#include "image.h"

#define M 3
#define N 3


PGM a,b;
double r;
int w, h;
string filename, file;
int main(int argc, char **argv)
{
    cout<<"Enter the name of the Image:"<<endl;
    cin>>filename;
   // cin>>file;
    glutInit(&argc, argv); //Inicializacion de GLUT
    a.initMatrix();
    //b.initMatrix();

    a.ingresarDatos(filename);
    //a.guardarDatos(file.c_str());
   // b = a.displayThreshImage();
   // b.guardarDatos(file.c_str());
    w = a.getRows() , h = a.getCols();
    //Inicializacion de la visualizacion
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    //Inicializa la posicion espacial de la ventana
    glutInitWindowPosition(100,100);

    //Inicializa el tamano de la ventana
    glutInitWindowSize(a.getRows(),a.getCols());

    //Aqui se crea la ventana
    glutCreateWindow(filename.c_str());

    //Pantalla Completa
    //glutFullScreen();

    init();

    //Puntero a funcion para el pintado
    glutDisplayFunc(display);

    //Puntero a funcion para el redimensionamiento
    //glutReshapeFunc(reshape);
    glutMainLoop();


    return 0;
}

void display()
{

       glMatrixMode(GL_PROJECTION);
       glLoadIdentity();
       glOrtho(0, w, h, 0, 0, 1);
       glMatrixMode(GL_MODELVIEW);
       glClear(GL_COLOR_BUFFER_BIT);

       glLoadIdentity();
       glTranslatef(0.375, 0.375, 0);

       glBegin(GL_POINTS);

       a.displayImage();

       glEnd();

       glFlush(); //Esta funcion es para buffer Single
       glutPostRedisplay();
}






