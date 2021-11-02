#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;
int main()
{
    MatrixXf A(4, 5);
    A << 2, 19, 18, 7, 0, 8, 13, 13, 13, 5, 18, 0, 15, 3, 0, 15, 16, 14, 14, 1;
    cout << "matrix A:" << endl << A << endl << endl;


    JacobiSVD<MatrixXf> svd(A, ComputeThinU | ComputeThinV);
    cout << "Its singular values are:" << endl << svd.singularValues() << endl<< endl;
    cout << "matrix U: " << endl << svd.matrixU() << endl<< endl;
    cout << "matrix V: " << endl << svd.matrixV() << endl<< endl;
    
    return 0;
}
