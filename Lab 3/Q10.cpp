//10. Write a program to evaluate double integration of a function using Trapezoidal rule.


#include<iostream>
#include<cmath>
using namespace std;

double f(double x, double y) {
    return x*x + y*y;
}

double trapezoidal(double(*f)(double, double), double a, double b, double c, double d, int n, int m) {
    double h = (b - a) / n;
    double k = (d - c) / m;
    double integral = 0.0;
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        for (int j = 0; j <= m; j++) {
            double y = c + j * k;
            integral += f(x, y);
        }
    }
    integral = (h * k) / (4 * n * m) * integral;
    return integral;
}

int main() {
    double a, b, c, d;
    int n, m;
    cout << "Enter the limits of integration for x: ";
    cin >> a >> b;
    cout << "Enter the limits of integration for y: ";
    cin >> c >> d;
    cout << "Enter the number of subintervals for x: ";
    cin >> n;
    cout << "Enter the number of subintervals for y: ";
    cin >> m;
    double integral = trapezoidal(f, a, b, c, d, n, m);
    cout << "The definite integral is: " << integral << endl;
    return 0;
}