#include "pgm.h"


PGM::PGM()
{
}

PGM::PGM(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    m = new float*[cols];

    for(int i = 0; i<cols; i++)
    {
        m[i] = new float[rows];
    }
}

int PGM::getGray() const
{
    return gray;
}

void PGM::setGray(int value)
{
    gray = value;
}

string PGM::getComment() const
{
    return comment;
}

void PGM::setComment(const string &value)
{
    comment = value;
}

string PGM::getCode() const
{
    return code;
}

void PGM::setCode(const string &value)
{
    code = value;
}


PGM::~PGM()
{
    for(int i = 0; i<rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;

}

void PGM::ingresarDatos(string filename)
{
    ifstream file;

    file.open(filename.c_str());

    if(file.is_open())
    {
        file>>this->code;  //Read the Magic Number, and comment line.

        for(int i = 0; i<7; i++)
        {
            file>>this->comment;
        }
        file>>this->rows;
        file>>this->cols;     //Read rows and cols.
        file>>this->gray;     //Read the grayscale number
        this->initMatrix();

        /*Begin reading the picture.*/
        for(int i = 0;i<this->cols;i++)
         {
            for(int j = 0;j<this->rows;j++)
              {
                file >> this->m[i][j];
              }
         }

        file.close();
    }

}

void PGM::guardarDatos(string filename)
{
    ofstream file;

    file.open(filename.c_str());

    if(file.is_open())
    {
        file<<this->code<<endl;
        file<<"# CREATOR: GIMP PNM Filter Version 1.1"<<endl; //Add the comment line to keep the image format
        file<<this->rows<<" "<<this->cols<<endl;
        file<<this->gray<<endl;

        for(int i = 0;i<this->cols;i++)
         {
            for(int j = 0;j<this->rows;j++)
              {
                file<<this->m[i][j];
                file<<endl;
              }

         }

        file.close();
    }
}

void PGM::displayImage()
{
    double r;
    glBegin(GL_POINTS);
    for(int j=0;j<this->rows;j++)
    {
        for(int i=0;i<this->cols;i++)
        {
           r=(this->m[i][j])/this->gray;
            glColor3f(r,r,r);
            glVertex2s(j,i);
        }

    }
    glEnd();
}


PGM &PGM::operator >(const int value)
{
    return this->createThresholdImage(value);

}

PGM &PGM::createThresholdImage(int value) const
{
    PGM *b = new PGM(this->rows, this->cols);

    b->code = this->code; b->gray = this->gray;

    int T = value;
    for(int j=0;j<this->rows;j++)
    {
        for(int i=0;i<this->cols;i++)
        {
            if(this->m[i][j]>=T)
            {
                b->m[i][j] = 255;
            }
            else
            {
                b->m[i][j] = 0;
            }

        }

    }

    return *b;
}


PGM &operator !(const PGM &a)
{
    return a.createNegativeImage();
}


PGM &PGM::createNegativeImage() const
{
    PGM *b = new PGM(this->rows, this->cols);
    b->code = this->code; b->gray = this->gray;

    for(int j=0;j<this->rows;j++)
    {
        for(int i=0;i<this->cols;i++)
        {
           b->m[i][j]=(255-this->m[i][j]);

        }
    }
    return *b;
}








