#include<iostream>
using namespace std;

double forwardDifferenceInterpolation(double x[], double y[], int n, double x_val) {
    double result = y[0];
    double h = x[1] - x[0];
    double u = (x_val - x[0]) / h;
    double term;

    for (int i = 1; i < n; i++) {
        term = 1;
        for (int j = 0; j < i; j++) {
            term *= (u - j);
        }
        result += (term * y[i]) / (1.0);
        for (int j = i; j < n - 1; j++) {
            y[j] = y[j + 1] - y[j];
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;
    double x[n], y[n];
    cout << "Enter the data points (x and y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    double x_val;
    cout << "Enter value of x to interpolate: ";
    cin >> x_val;
    double result = forwardDifferenceInterpolation(x, y, n, x_val);
    cout << "Interpolated value at x = " << x_val << " is " << result << endl;
    return 0;
}

