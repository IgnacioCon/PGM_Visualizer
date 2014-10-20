#ifndef PGM_H
#define PGM_H

#include "matrix.h"
#include <fstream>
#include <GL/gl.h>
#include <GL/glut.h>



class PGM : public Matrix
{

private:
    string code;
    string comment;

    int gray;

public:
    PGM();
    PGM(int rows, int cols);
    ~PGM();

    int getGray() const;
    void setGray(int value);
    string getComment() const;
    void setComment(const string &value);
    string getCode() const;
    void setCode(const string &value);

    void ingresarDatos( string filename);
    void guardarDatos(string filename);
    void displayImage();

    void displayNegativeImage();
    PGM &displayNegImage() const;

    void displayThresholdImage();
    PGM &displayThreshImage() const;



};





#endif // PGM_H
