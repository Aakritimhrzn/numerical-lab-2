#include <iostream>
#include <vector>
using namespace std;

void cubicSplineInterpolation(const vector<double>& x, const vector<double>& y, int n, double x_val) {
    vector<double> h(n-1), alpha(n-1), l(n), mu(n), z(n), c(n), b(n-1), d(n-1), result(n);

    for (int i = 0; i < n - 1; i++) {
        h[i] = x[i+1] - x[i];
    }

    for (int i = 1; i < n - 1; i++) {
        alpha[i] = (3.0 / h[i]) * (y[i+1] - y[i]) - (3.0 / h[i-1]) * (y[i] - y[i-1]);
    }

    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    for (int i = 1; i < n - 1; i++) {
        l[i] = 2.0 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    l[n-1] = 1;
    z[n-1] = 0;
    c[n-1] = 0;

    for (int j = n - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (y[j+1] - y[j]) / h[j] - h[j] * (c[j+1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j+1] - c[j]) / (3.0 * h[j]);
        result[j] = y[j] + b[j] * (x_val - x[j]) + c[j] * (x_val - x[j]) * (x_val - x[j]) + d[j] * (x_val - x[j]) * (x_val - x[j]) * (x_val - x[j]);
    }

    cout << "Interpolated value at x = " << x_val << " is " << result[0] << endl;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    vector<double> x(n), y(n);
    cout << "Enter the data points (x and y):\n";
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double x_val;
    cout << "Enter value of x to interpolate: ";
    cin >> x_val;

    cubicSplineInterpolation(x, y, n, x_val);

    return 0;
}

