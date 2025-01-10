#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <sstream>  // For stringstream to parse input

using namespace std;

void solveGaussian(vector<vector<double>>& A, vector<double>& B, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][i] == 0) {
                cout << "Singular matrix!" << endl;
                return;
            }
            double ratio = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= ratio * A[i][k];
            }
            B[j] -= ratio * B[i];
        }
    }

    // Back substitution
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            B[i] -= A[i][j] * B[j];
        }
        B[i] /= A[i][i];
    }
}

void leastSquaresPolynomialApproximation(vector<double>& x, vector<double>& y, int n, int degree) {
    vector<vector<double>> A(degree + 1, vector<double>(degree + 1, 0));
    vector<double> B(degree + 1, 0);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            for (int k = 0; k < n; k++) {
                A[i][j] += pow(x[k], i + j);
            }
        }

        for (int k = 0; k < n; k++) {
            B[i] += y[k] * pow(x[k], i);
        }
    }

    solveGaussian(A, B, degree + 1);

    cout << "The polynomial of degree " << degree << " is: y = ";
    for (int i = 0; i <= degree; i++) {
        if (i > 0) cout << " + ";
        cout << fixed << setprecision(3) << B[i] << "x^" << i;
    }
    cout << endl;
}

int main() {
    int n, degree;
    
    cout << "Enter the number of data points: ";
    cin >> n;

    cout << "Enter the degree of the polynomial: ";
    cin >> degree;
    
    vector<double> x(n), y(n);
    
    // Clear the input buffer before reading lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter the data points (x, y): \n";
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line); // Read the entire line as a string
        stringstream ss(line);
        
        ss >> x[i] >> y[i]; // Parse the values from the stringstream
    }

    leastSquaresPolynomialApproximation(x, y, n, degree);

    return 0;
}

