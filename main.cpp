#include "matrix.h"
#include "pgm.h"
#include "image.h"

#define M 3
#define N 3


PGM a;
PGM b;
double r;
int w, h;
string filename, file;
int main(int argc, char **argv)
{
    instructions();
    cin>>filename;

    glutInit(&argc, argv); //Begin to use GLUT

    b.initMatrix();

    a.loadData(filename); //load PGM image
    b.copyPGM(a);         //copy the PGM to manipulate
    w = a.getRows() , h = a.getCols();

    //Begin display
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowPosition(100,100);

    //Window size
    glutInitWindowSize(a.getRows(),a.getCols());

    glutCreateWindow(filename.c_str());

    init();

    glutDisplayFunc(display); //Begin visualization of the image
    glutKeyboardFunc(keyboard);//Captures the key pressed by the user

    glutMainLoop();


    return 0;
}

void display()
{

    funcInit(w,h);

    b.displayImage(); //Display original image;

    glFlush();
    glutPostRedisplay();
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
         b = a>200; //Threshold filter applied

        break;
    case 's':
       cout<<"Negative Filter"<<endl;
         b = !a; //Negative filter applied
        break;
    case 'd':

        cout<<"Original"<<endl;
         b.copyPGM(a);
        break;
    case 'f':

        cout<<"Save Image"<<endl;
        cout<<"Name your file:";    cin>>file; //Name save file
        b.saveData(file.c_str()); //Save file
        cout<<"Image saved!"<<endl;

        break;
    }
}

