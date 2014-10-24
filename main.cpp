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

    a.loadData(filename);

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

    a.displayImage(); //Display original image;

    glFlush();
    glutPostRedisplay();
}

void display2()
{
    funcInit(w,h);
    b = !a; //Negative filter applied

    b.displayImage();

    glFlush();
    glutPostRedisplay();
}
void display3()
{
    funcInit(w,h);

    b = a>200; //Threshold filter applied

    b.displayImage();

    glFlush();
    glutPostRedisplay();
}

void saveImage(void)
{
    cout<<"Name your file:"; cin>>file;
    b.saveData(file.c_str()); //Save file

}



