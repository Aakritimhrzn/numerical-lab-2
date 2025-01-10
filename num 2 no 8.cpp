#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void leastSquaresNonLinearApproximation(const vector<double>& x, const vector<double>& y, int n) {
    double sum_x = 0, sum_ln_y = 0, sum_x2 = 0, sum_x_ln_y = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_ln_y += log(y[i]);
        sum_x2 += x[i] * x[i];
        sum_x_ln_y += x[i] * log(y[i]);
    }

    // Solving the system of equations:
    // A = ln(a) and B = b
    double B = (n * sum_x_ln_y - sum_x * sum_ln_y) / (n * sum_x2 - sum_x * sum_x);
    double A = (sum_ln_y - B * sum_x) / n;

    double a = exp(A);  // a = e^A
    double b = B;       // b = B

    cout << "Non-Linear Least Squares Approximation: y = " << a << "e^(" << b << "x)" << endl;
}

int main() {
    int n;
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the data points (x and y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    leastSquaresNonLinearApproximation(x, y, n);

    return 0;
}

