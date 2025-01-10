#include<iostream>
#include<vector>
using namespace std;

void leastSquaresLinearApproximation(const vector<double>& x, const vector<double>& y, int n) {
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    double m = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double b = (sum_y - m * sum_x) / n;

    cout << "Linear Least Squares Approximation: y = " << m << "x + " << b << endl;
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

    leastSquaresLinearApproximation(x, y, n);

    return 0;
}

