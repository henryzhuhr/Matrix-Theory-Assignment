#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
int main()
{
    Matrix<double, 5, 5> A;
    A << 14, 8, 0, 4, 4, 4, 10, 18, 9, 9, 2, 1, 14, 19, 12, 5, 5, 9, 10, 13, 6, 16, 11, 10, 7;
    cout << "matrix A:" << endl << A << endl << endl;

    FullPivLU<Matrix<double, 5, 5>> lu(A);

    // L
    Matrix<double, 5, 5> L                              = Matrix<double, 5, 5>::Identity();
    L.block<5, 5>(0, 0).triangularView<StrictlyLower>() = lu.matrixLU();
    cout << "matrix L:" << endl << L << endl << endl;

    // U
    Matrix<double, 5, 5> U = lu.matrixLU().triangularView<Upper>();
    cout << "matrix U:" << endl << U << endl << endl;

    // reconstruct A
    cout << "reconstruct the original matrix A:" << endl;
    auto reconstruct = lu.permutationP().inverse() * L * U * lu.permutationQ().inverse();
    cout << reconstruct << endl;

    return 0;
}
