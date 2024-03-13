//1. Write a program to calculate derivative from divided difference table





#include <iostream>
#include <vector>
#include <cmath>

// Function to calculate factorial
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Function to calculate divided difference table
void dividedDifferenceTable(const std::vector<double>& x, const std::vector<double>& y, std::vector<std::vector<double>>& table) {
    int n = x.size();
    table.resize(n);
    for (int i = 0; i < n; ++i)
        table[i].resize(n - i);

    for (int i = 0; i < n; ++i)
        table[i][0] = y[i];

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            table[i][j] = table[i + 1][j - 1] - table[i][j - 1];
        }
    }
}

// Function to calculate derivative using divided difference table
double calculateDerivative(double x0, const std::vector<double>& x, const std::vector<std::vector<double>>& table) {
    int n = x.size();
    double h = x[1] - x[0];
    double result = 0.0;

    for (int i = 0; i < n; ++i) {
        double term = table[0][i] / (factorial(i) * std::pow(h, i));
        result += term * std::pow(x0 - x[0], i);
    }

    return result;
}

int main() {
    int n;
    std::cout << "Enter the number of data points: ";
    std::cin >> n;

    std::vector<double> x(n), y(n);

    std::cout << "Enter the values of x: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    std::cout << "Enter the values of y: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> y[i];
    }

    std::vector<std::vector<double>> table;

    dividedDifferenceTable(x, y, table);

    double x0;
    std::cout << "Enter the point at which you want to calculate the derivative: ";
    std::cin >> x0;

    double derivative = calculateDerivative(x0, x, table);

    std::cout << "The derivative at x = " << x0 << " is: " << derivative << std::endl;

    return 0;
}