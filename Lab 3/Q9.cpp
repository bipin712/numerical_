//9. Write a program to evaluate integration of a function using Romberg integration formula.

#include<iostream>
#include<cmath>
using namespace std;

double f(double x) {
    return pow(x, 3) - 4 * pow(x, 2) + 3 * x - 5;
}

void compositeSimpsons13Rule(double a, double b, int n) {
    double h = (b - a) / n;
    double x[n], y[n];
    x[0] = a;
    y[0] = f(a);
    for (int i = 1; i < n; i++) {
        x[i] = a + i * h;
        y[i] = f(x[i]);
    }
    x[n] = b;
    y[n] = f(b);
    double result = y[0] + y[n];
    for (int i = 1; i <= n - 1; i += 2) {
        if (i == 1) {
            result += 4 * y[i];
        } else {
            result += 2 * y[i];
        }
    }
    for (int i = 2; i <= n - 2; i += 2) {
        result += 4 * y[i];
    }
    result *= h / 3;
    cout << "The definite integral of the function from " << a << " to " << b << " using composite Simpson's 1/3 rule is " << result << endl;
}

int main() {
    double a, b;
    int n;
    cout << "Enter the lower limit: ";
    cin >> a;
    cout << "Enter the upper limit: ";
    cin >> b;
    cout << "Enter the number of sub-intervals: ";
    cin >> n;
    compositeSimpsons13Rule(a, b, n);
    return 0;
}