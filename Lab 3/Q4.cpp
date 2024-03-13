//4. Write a program to calculate integration using Simpson’s 1/3 rule.

#include <iostream>
#include <cmath>

// Function to define the integrand
double f(double x) {
    return sin(x); // Example function: sin(x)
}

// Function to calculate integration using Simpson's 1/3 rule
double simpsonsOneThirdRule(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x);
    }

    for (int i = 2; i < n - 1; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    return (h / 3) * sum;
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

    if (n % 2 != 0) {
        std::cerr << "Number of subintervals must be even for Simpson's 1/3 rule." << std::endl;
        return 1;
    }

    double result = simpsonsOneThirdRule(a, b, n);

    std::cout << "The result of integration using Simpson's 1/3 rule is: " << result << std::endl;

    return 0;
}

