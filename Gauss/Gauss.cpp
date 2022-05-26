#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "GaussSolver.h"

int main(){
    
    Matrix A(3, 3);
    Vector b(3);

    Matrix tmp_A(3, 3);
    Vector tmp_b(3);

    GaussSolver Gauss;

    A[0][0] = 4;
    A[0][1] = 2;
    A[0][2] = -1;
    A[1][0] = 5;
    A[1][1] = 4;
    A[1][2] = -2;
    A[2][0] = -3;
    A[2][1] = 2;
    A[2][2] = -3;

    b[0] = 1;
    b[1] = 2;
    b[2] = 0;

    A.print();
    b.print();

    std::vector<Vector> result = Gauss.solve(A, b);

    std::cout << "result:" << std::endl;
    for (int i = 0; i < result.size(); i++) {
        result[i].print();
    }

    return 0;
}