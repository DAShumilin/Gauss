#pragma once

#include <vector>
#include "Matrix.h"
#include "Vector.h"

class GaussSolver {

public:

	std::vector<Vector> solve(const Matrix& A, const Vector& b);	
};