#include<iostream>
using namespace std;

double lagrangeInterpolation(double x[], double y[], int n, double x_val) {
    double result = 0;
    for (int i = 0; i < n; i++) {
        double term = y[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                term = term * (x_val - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
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
    double result = lagrangeInterpolation(x, y, n, x_val);
    cout << "Interpolated value at x = " << x_val << " is " << result << endl;
    return 0;
}

