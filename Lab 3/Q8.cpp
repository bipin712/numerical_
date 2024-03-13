//8. Write a program to evaluate integration of a function using Gauss integration algorithm.


#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/* Define function here */
#define f(x) 1/(1+pow(x,2))

/* Function to calculate the weight of each point */
double gaussWeight(int n, double x)
{
    double t = 1.0;
    for(int i=1; i<=n; i++)
    {
        t *= (x*x - 1.0)/(double)(2*i - 1);
    }
    return t;
}

/* Function to calculate the integral using Gauss integration algorithm */
double gaussIntegration(double lower, double upper, int n)
{
    double x[n], sum = 0.0;
    vector<double> xValues, weightValues;

    /* Calculate the Gauss points and weights */
    for(int i=1; i<=n; i++)
    {
        x[i-1] = cos(M_PI*(i - 0.25)/(double)n);
        xValues.push_back(x[i-1]);
        weightValues.push_back(gaussWeight(n, x[i-1]));
    }

    /* Calculate the integral */
    for(int i=0; i<n; i++)
    {
        sum += weightValues[i] * f(xValues[i]);
    }

    sum = sum * (upper - lower);

    return sum;
}

int main()
{
    double lower, upper, integration;

    /* Input */
    cout<<"Enter lower limit of integration: ";
    cin>>lower;
    cout<<"Enter upper limit of integration: ";
    cin>>upper;

    /* Calculation */
    integration = gaussIntegration(lower, upper, 3);

    cout<< endl <<"Required value of integration is: "<< integration;

    return 0;
}