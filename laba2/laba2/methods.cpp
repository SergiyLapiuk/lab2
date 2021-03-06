#include <iostream> //Lapiuk Sergiy
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include "laba2.h"

using namespace std;



void Laba2::Gauss() {
    while (true) {
        cout << "1 - find the roots;\n2 - find the determinant;\n3 - invarse matrix\n4 - return to menu\n";
        int i;
        cin >> i;
        if (i == 1) {
            methodGauss();
            Gauss();
            break;
        }
        else if (i == 2) {
            determinant();
            Gauss();
            break;
        }
        else if (i == 3) {
            InverseMatrix();
            Gauss();
            break;
        }
        else { menu(); };
    }
}

void Laba2::methodGauss() {
    double x[5];
    double a[6][6] = { {0,0,0,0,0,0},
                        {0,4,3,1,0,14},
                        {0,-2,2,6,1,31},
                        {0,0,5,2,3,33},
                        {0,0,1,2,7,45} };
    int n = 4;


    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
    };

    double m;
    cout << setprecision(5);
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            m = a[j][i] / a[i][i];

            for (int k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - m * a[i][k];
            };
        };
        cout << endl;
        cout << "Step: " << i << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n + 1; j++) {
                cout << a[i][j] << "\t";
                if (j == n) {
                    cout << "| ";
                }
            };
            cout << "\n";
        };
    };

    x[n] = a[n][n + 1] / a[n][n];

    for (int i = n - 1; i >= 1; i--)
    {
        x[i] = a[i][n + 1];
        for (int j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        };
        x[i] = x[i] / a[i][i];
    };

    cout << endl << "Roots: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << ": " << x[i] << endl;
    };
}

void Laba2::determinant() {
    //double a[5][5] = { {0,0,0,0,0,},
    //                    {0,4,3,1,0},
    //                    {0,-2,2,6,1},
    //                    {0,0,5,2,3},
    //                    {0,0,1,2,7} };

    double a[6][6] = { {0,0,0,0,0,0},
                    {0,4,3,1,0,14},
                    {0,-2,2,6,1,31},
                    {0,0,5,2,3,33},
                    {0,0,1,2,7,45} };

    int n = 4;
    double a_1[5][5] = {};
    double det_part[5];
    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n+1; j++) {//
            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
    };



    double m;
    cout << setprecision(5);
    for (int i = 1; i <= n; i++)//
    {
        for (int j = i + 1; j <= n+1; j++)//
        {
            m = a[j][i] / a[i][i];

            for (int k = 1; k <= n + 1 + 1; k++)
            {
                a[j][k] = a[j][k] - m * a[i][k];
            };
        };
        det_part[i] = a[i][i];

        if (i == 4)
            break;
        cout << endl;
        cout << "Step: " << i << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n+1; j++) {//
                cout << a[i][j] << "\t";
                if (j == n) {
                    cout << "| ";
                }
            };
            cout << "\n";
        };
    };

    cout << "\nLeading elements: \n";
    for (int i = 1; i <= n; i++) {

        cout << det_part[i] << endl;
    }
    double det = 1;
    for (int i = 1; i <= n; i++) {
        det *= det_part[i];
    }

    cout << endl;
    cout << "Determinant: " << det << endl;
}

void Laba2::InverseMatrix() {
    double a[12][12] = { {0,0,0,0,0,0,0,0},
                            {0,4,3,1,0},
                            {0,-2,2,6,1},
                            {0,0,5,2,3},
                            {0,0,1,2,7} };
    int n = 4;

    cout << "Matrix:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << "\t";
        };
        cout << "\n";
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                a[i][j + n] = 1;
            }
            else
            {
                a[i][j + n] = 0;
            }
        };
    };

    cout << endl;
    cout << setprecision(3);
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {

            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
        if (i == n) { break; }
    };

    double m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                m = a[j][i] / a[i][i];
                for (int k = 1; k <= 2 * n; k++)
                {
                    a[j][k] = a[j][k] - m * a[i][k];
                };
            }
        };
    };

    if (1)
    {
        a[1][4] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1 + n; j <= 2 * n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        };
    };

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = a[i][j] / a[i][i];
        };
    };

    cout << endl;
    cout << setprecision(3);
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = 1; j <= 2 * n; j++) {

            if (a[i][j] == -0) { a[i][j] = 0; }

            cout << a[i][j] << "\t";
            if (j == n) {
                cout << "| ";
            }
        };
        cout << "\n";
        if (i == n) { break; }
    };


    cout << setprecision(3);
    cout << endl << "Inverse matrix:" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n + 1; j <= 2 * n; j++)
        {
            if (a[i][j] == -0) { a[i][j] = 0; }

            cout << a[i][j] << "\t";
        };
        cout << endl;
    };
}

void Laba2::progonka() {
    double a[3][3] = { {1, 2, 0},
                       {2, 2, 4},
                       {0, 4, 3} };
    double f[3] = { 11,
                    34,
                    31 };
    int dim = 3;

    double alfa[3] = {};
    double beta[3] = {};
    double z[3] = {};
    double x[4] = {};

    double roots[3] = { 3, 4, 5 };

    cout << "Matrix:\n";
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            cout << a[i][j] << " ";
        };
        cout << "|" << f[i] << endl;
    };

    cout << "root x1: " << roots[0] << endl;
    cout << "root x2: " << roots[1] << endl;
    cout << "root x3: " << roots[2] << endl << endl;

    cout << "alpha and beta calculation:\n";
    alfa[0] = a[0][1] / -a[0][0];
    beta[0] = -f[0] / -a[0][0];

    cout << "iteration: 1" << endl;
    cout << "alpha1" << ": " << alfa[0] << endl;
    cout << "beta1" << ": " << beta[0] << endl;
    cout << endl;

    for (int i = 1; i <= dim - 1; i++) {
        z[i] = -a[i][i] - a[i][i - 1] * alfa[i - 1];
        alfa[i] = a[i][i + 1] / z[i];
        beta[i] = (-f[i] + a[i][i - 1] * beta[i - 1]) / z[i];
        if (i == dim - 1) {
            alfa[i] = 0;
        }
        cout << "iteration: " << i + 1 << endl;
        cout << "alpha" << i + 1 << ": " << alfa[i] << endl;
        cout << "beta" << i + 1 << ": " << beta[i] << endl;
        cout << "z" << i + 1 << ": " << z[i] << endl;
        cout << endl;
    };

    cout << endl;
    x[dim - 1] = beta[dim - 1];
    for (int i = 1; i >= 0; i--) {
        x[i] = alfa[i] * x[i + 1] + beta[i];
    };

    cout << "calculated roots:\n";
    for (int i = 0; i < dim; i++) {
        cout.precision(15);
        cout << "x" << i + 1 << ": " << x[i] << endl;
    };
}

void Laba2::Seidel() {
    double eps;
    cout << "enter accuracy (10^-3 = 1e-3):\n";
    cin >> eps;


    double x1[100] = {};
    double x2[100] = {};
    double x3[100] = {};
    double x4[100] = {};
    double a[4][4] = { {4, 0, 1, 1},
                       {0, 3, 0, 1},
                       {1, 0, 2, 0},
                       {1, 1, 0, 5} };
    double b[4] = { 11,
                    10,
                    7,
                    23 };
    double dim = 4;

    x1[0] = 0;
    x2[0] = 0;
    x3[0] = 0;
    x4[0] = 0;

    cout << "Matrix:\n";
    for (int i = 0; i <= dim - 1; i++)
    {
        for (int j = 0; j <= dim - 1; j++)
        {
            cout << a[i][j] << " ";
        };
        cout << "|" << b[i] << endl;
    };

    cout << "Starting x1_0: " << x1[0] << endl;
    cout << "Starting x2_0: " << x2[0] << endl;
    cout << "Starting x3_0: " << x3[0] << endl;
    cout << "Starting x4_0: " << x4[0] << endl;

    cout << "answer:\nx1 = 1\nx2 = 2\nx3 = 3\nx4 = 4\n\n";

    int i = 1;
    while (true) {
        x1[i] = (b[0] - x3[i - 1] - x4[i - 1]) / a[0][0];
        x2[i] = (b[1] - x4[i - 1]) / a[1][1];
        x3[i] = (b[2] - x1[i]) / a[2][2];
        x4[i] = (b[3] - x1[i] - x2[i]) / a[3][3];

        cout << "iteration:" << i << endl;
        cout.precision(15);
        cout << "x1: " << x1[i] << endl;
        cout << "x2: " << x2[i] << endl;
        cout << "x3: " << x3[i] << endl;
        cout << "x4: " << x4[i] << endl;
        cout << endl;

        if ((abs(x1[i] - x1[i - 1]) <= eps) && (abs(x2[i] - x2[i - 1]) <= eps) && (abs(x3[i] - x3[i - 1]) <= eps) && (abs(x4[i] - x4[i - 1]) <= eps))
        {
            break;
        }

        i++;
    }
}

void Laba2::menu() {
    while (true) {
        cout << "1 - Gaus, determinant, inverse matrix;\n2 - Method progonki\n3 - Seidel method\n4 - Exit\n";
        int i;
        cin >> i;
        if (i == 1) {
            Gauss();
            menu();
            break;
        }
        else if (i == 2) {
            progonka();
            menu();
            break;
        }
        else if (i == 3) {
            Seidel();
            menu();
            break;
        }
        else { break; };
    }
}
