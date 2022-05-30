#include "GaussSolver.h"
#include <vector>

#include "GaussSolver.h"
#include <vector>

std::vector<Vector> GaussSolver::solve(const Matrix& A, const Vector& b) {

    std::vector<Vector> a;
    a.reserve(1);

    Matrix M(A.lines, A.columns + 1);

    for (int i = 0; i < A.columns; i++) {
        for (int j = 0; j < A.columns; j++) {
            M[i][j] = A[i][j];
        }
        M[i][A.columns] = b[i];
    }

    int i = 0;
    int n = M.columns;
    int m = M.lines;

    for (int j = 0; j < n; j++) {
        double maxElement = 0;
        int line = i;
        for (int k = i; k < m; k++) {
            if (abs(M[k][j]) > abs(maxElement)) {
                maxElement = M[k][j];
                line = k;
            }
        }

        if (abs(maxElement) < 1e-10) {
            continue;
        }

        Vector tmp = M[i];

        M[i] = M[line];
        M[line] = tmp;
        M[i] *= (1 / M[i][j]);

        for (int l = 0; l < i; l++) {
            M[l] -= M[i] * M[l][j];
        }
        for (int l = i + 1; l < m; l++) {
            M[l] -= M[i] * M[l][j];
        }
        i++;
    }
    
    Vector solution(m);

    for (int i = 0; i < m; i++) {
        solution[i] = M[i][n - 1];
    }

    a.push_back(solution);

    return a;
}