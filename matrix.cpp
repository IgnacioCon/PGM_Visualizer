#include "matrix.h"


Matrix::Matrix()
{
    m = NULL;
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;

    m = new float *[rows];

    for(int i = 0; i<rows; i++)
    {
        m[i] = new float[cols];
    }

}

Matrix::~Matrix()
{
    for(int i = 0; i<rows; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}


int Matrix::getRows() const
{
    return rows;
}

void Matrix::setRows(int value)
{
    rows = value;
}

int Matrix::getCols() const
{
    return cols;
}

void Matrix::setCols(int value)
{
    cols = value;
}

void Matrix::initMatrix()
{
    m = new float*[cols];
    for(int i =0; i<cols; i++)
    {
        m[i] = new float[rows];
    }

}

void Matrix::setValue(int row, int cols, float value)
{
    m[row][cols]=value;

}

float Matrix::getValue(int row, int cols)
{
    return m[row][cols];
}

float **Matrix::getData()
{
    return m;
}

void Matrix::setData(int rows, int cols, float **value)
{

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            m[i][j]=value[i][j];
        }
    }
}


void Matrix::showMatrix()
{
    cout<<"Rows: "<<rows<<", Cols: "<<cols<<endl;

    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<cols; j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

}



void Matrix::suma(const Matrix &a)
{
    this->cols = a.getCols();
    this->rows= a.getRows();

    for(int i = 0; i<this->rows; i++)
    {
        for(int j=0; j<this->cols; j++)
        {
            this->m[i][j]+=a.m[i][j];

        }

    }
}

Matrix &Matrix::suma(const Matrix &b) const
{
    Matrix *c = new Matrix(b.rows, b.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = this->m[i][j] + b.m[i][j];
        }
    }

    return *c;
}

Matrix &Matrix::operator +(const Matrix &b)
{
    Matrix *c = new Matrix(b.rows, b.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = this->m[i][j] + b.m[i][j];
        }
    }

    return *c;

}

Matrix Matrix::suma( Matrix &a, Matrix &b)
{
    return a+b;
}

void Matrix::resta(const Matrix &a)
{
    this->cols = a.getCols();
    this->rows= a.getRows();

    for(int i = 0; i<this->rows; i++)
    {
        for(int j=0; j<this->cols; j++)
        {
            this->m[i][j]-=a.m[i][j];

        }

    }

}

Matrix &Matrix::resta(const Matrix &b) const
{
    Matrix *c = new Matrix(b.rows, b.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = this->m[i][j] - b.m[i][j];
        }
    }

    return *c;

}

Matrix &Matrix::operator -(const Matrix &b)
{
    Matrix *c = new Matrix(b.rows, b.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = this->m[i][j] - b.m[i][j];
        }
    }

    return *c;
}

Matrix Matrix::resta(Matrix &a, Matrix &b)
{
    return a-b;
}

Matrix &Matrix::mult(const Matrix &a)
{

    Matrix *c = new Matrix(this->cols, a.rows);

    if(this->cols == a.rows)
    {


    for (int i = 0; i < c->rows; i++)
    {
        for (int j = 0; j < c->cols; j++)
        {
            c->m[i][j]=0;
            for (int k = 0; k < c->cols; k++)
            {
                c->m[i][j] += this->m[i][k]*a.m[k][j];
            }
        }
    }
    }
    else{

        cout<<"No se puede multiplicar"<<endl;
    }
    return *c;
}

Matrix &Matrix::operator *(const Matrix &b)
{
    Matrix *c = new Matrix(b.rows, this->cols);
    if(b.rows == this->cols)
    {


    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            c->m[i][j]=0;
            for (int k = 0; k < this->cols; k++)
            {
                c->m[i][j]=c->m[i][j] + (this->m[i][k]*b.m[k][j]);
            }
        }
    }

    }
    else{

        cout<<"No se puede multiplicar"<<endl;
    }

    return *c;
}

Matrix Matrix::mult(Matrix &a, Matrix &b)
{
    return a*b;
}


Matrix &Matrix::scalar(const Matrix &a, int scalar) const
{
    Matrix *c = new Matrix(a.rows, a.cols);

    for(int i = 0; i<c->rows; i++)
    {
        for(int j = 0; j<c->cols; j++)
        {
            c->m[i][j] = a.m[i][j]*scalar;
        }
    }

    return *c;


}

void Matrix::transpose(const Matrix a)
{
    for(int i = 0; i<this->rows; i++)
    {
        for(int j=0; j<this->cols; j++)
        {
            this->m[j][i]=a.m[i][j];

        }
    }
}

Matrix &Matrix::transpose() const
{
     Matrix *c = new Matrix(this->cols, this->rows);

     for(int i = 0; i<c->cols; i++)
     {
         for(int j=0; j<c->rows; j++)
         {
             c->m[j][i]=this->m[i][j];

         }
     }

     return *c;
}

void Matrix::ingresarDatos(string filename)
{
    ifstream file;

    file.open(filename.c_str());

    if(file.is_open())
    {
        file>>this->rows;
        file>>this->cols;
        this->initMatrix();

        for(int i = 0;i<this->rows;i++)
         {
            for(int j = 0;j<this->cols;j++)
              {
                file >> this->m[i][j];
              }
         }

        file.close();
    }
}

void Matrix::guardarDatos(string filename)
{
    ofstream file;

    file.open(filename.c_str());

    if(file.is_open())
    {
        file<<this->rows<<" "<<file<<this->cols<<endl;

        for(int i = 0;i<this->rows;i++)
         {
            for(int j = 0;j<this->cols;j++)
              {
                file<<this->m[i][j]<<" ";
              }
            file<<endl;
         }

        file.close();
    }
}

ostream& operator <<(ostream &o, const Matrix &a)
{
    o <<"Rows: "<<a.rows<<", Cols: "<<a.cols<<"\n";
    for(int i = 0; i<a.rows; i++)
    {
        for(int j = 0; j<a.cols; j++)
        {
            o<<a.m[i][j]<<" ";
        }
        o<<"\n";
    }
    return o;
}

