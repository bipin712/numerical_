// 3. Write a program to calculate integration using composite Trapezoidal rule.

#include <iostream>
#include <cmath>

// Function to define the integrand
double f(double x) {
    return sin(x); // Example function: sin(x)
}

// Function to calculate integration using composite Trapezoidal rule
double compositeTrapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += f(x);
    }

    return h * sum;
}

int main() {
    double a, b;
    int n;

    std::cout << "Enter the lower limit of integration (a): ";
    std::cin >> a;
    std::cout << "Enter the upper limit of integration (b): ";
    std::cin >> b;
    std::cout << "Enter the number of subintervals (n): ";
    std::cin >> n;

    double result = compositeTrapezoidalRule(a, b, n);

    std::cout << "The result of integration using the composite Trapezoidal rule is: " << result << std::endl;

    return 0;
}