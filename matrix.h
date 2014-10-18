#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>

using namespace std;
class Matrix
{
protected:

    int rows;
    int cols;
    float **m;

public:
    Matrix();
    Matrix(int rows, int cols);
    ~Matrix();

    int getRows() const;
    void setRows(int value);
    int getCols() const;
    void setCols(int value);

    void initMatrix();

    void setValue(int row, int cols, float value);
    float getValue(int row, int cols);

    float **getData();
    void setData(int rows, int cols,float **value);
    void showMatrix(); //para uno ver si esta ve, no recomendable para produccion


    void suma(const Matrix &a, const Matrix &b);
    Matrix &suma(const Matrix &b) const;
    Matrix& operator +(const Matrix &b);

    void resta(const Matrix &a, const Matrix &b);
    Matrix &resta(const Matrix &b) const;
    Matrix& operator -(const Matrix &b);

    Matrix &mult(const Matrix &a, const Matrix &b);
    Matrix& operator *(const Matrix &b);


    void scalar(int scalar);
    Matrix &scalar(const Matrix &a, int scalar) const;


    void transpose(const Matrix a);
    Matrix &transpose() const;

    void ingresarDatos( string filename);
    void guardarDatos(string filename);


    friend ostream& operator <<(ostream &o,const Matrix &a);
};

#endif // MATRIX_H
