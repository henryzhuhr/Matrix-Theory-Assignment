#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
int main()
{
    MatrixXf A(3, 5);
    A << 16, 18, 5, 19, 19, 18, 12, 10, 3, 9, 2, 1, 19, 19, 16;
    cout << "matrix A:" << endl << A << endl << endl;


    HouseholderQR<MatrixXf> qr(A);
    qr.compute(A);
    MatrixXf R = qr.matrixQR().triangularView<Upper>();
    MatrixXf Q = qr.householderQ();
    cout << "matrix Q:" << endl << Q << endl << endl;
    cout << "matrix R:" << endl << R << endl << endl;

    return 0;
}
