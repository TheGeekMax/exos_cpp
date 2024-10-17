#include <iostream>
#include <vector>

#include "MatrixNumerical.h"

using namespace std;

int main(){

    //test pour le determinant
    MatrixNumerical<int> matrix = MatrixNumerical<int>(3,3);
    matrix.addElement(0,0,1);
    matrix.addElement(0,1,2);
    matrix.addElement(0,2,3);
    matrix.addElement(1,0,4);
    matrix.addElement(1,1,5);
    matrix.addElement(1,2,6);
    matrix.addElement(2,0,7);
    matrix.addElement(2,1,8);
    matrix.addElement(2,2,10);
    matrix.display();
    cout << "Determinant: " << matrix.getDeterminant() << endl;


    //test des differentes matrices
    MatrixNumerical<int> matrix1 = MatrixNumerical<int>(2,2);
    matrix1.addElement(0,0,1);
    matrix1.addElement(0,1,2);
    matrix1.addElement(1,0,3);
    matrix1.addElement(1,1,4);
    matrix1.display();

    MatrixNumerical<int> matrix2 = MatrixNumerical<int>(2,2);
    matrix2.addElement(0,0,5);
    matrix2.addElement(0,1,6);
    matrix2.addElement(1,0,7);
    matrix2.addElement(1,1,8);
    matrix2.display();

    //operation sur les matrices
    MatrixNumerical<int> matrix3 = matrix1 + matrix2;
    matrix3.display();
    MatrixNumerical<int> matrix4 = matrix1 - matrix2;
    matrix4.display();
    MatrixNumerical<int> matrix5 = matrix1 * matrix2;
    matrix5.display();

    //test avec differends type float et double
    MatrixNumerical<float> matrix6 = MatrixNumerical<float>(2,2);
    matrix6.addElement(0,0,1.1);
    matrix6.addElement(0,1,2.2);
    matrix6.addElement(1,0,3.3);
    matrix6.addElement(1,1,4.4);
    matrix6.display();

    MatrixNumerical<double> matrix7 = MatrixNumerical<double>(2,2);
    matrix7.addElement(0,0,5.5);
    matrix7.addElement(0,1,6.6);
    matrix7.addElement(1,0,7.7);
    matrix7.addElement(1,1,8.8);
    matrix7.display();

    return 0;
}
