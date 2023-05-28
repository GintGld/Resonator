#include<iostream>
#include<cmath>
#include<iomanip>

double f(double x) {
    /* return the equation whose root is to be determined. Here, we have used equation: cos(x)-3x+5=0 */
    return std::cos(x) - 3 * x + 5;
}

double g(double x) {
    /* In this function we have to return x. For cos(x)-3*x+5=0, value of x will be (cos(x)+5)/3. */
    return (std::cos(x) + 5) / 3;
}

int main() {
    double x0, xn = 1;
    int iter = 0;

    std::cout << "Enter the initial approximation: ";
    std::cin >> x0;

    std::cout << "\nIteration     x0        xn\n";

    while (f(x0) * f(xn) > 0) {
        xn = x0;
        x0++;
    }

    /* 0.000001 is the accepted error */
    while (std::fabs(xn - x0) > 0.000001) {
    x0 = xn;
    xn = g(x0);
    iter++;

    std::cout << '\t' << iter << '\t' << x0 << '\t' << std::setprecision(6) << xn << std::endl;
}

    std::cout<<"\n\nThe root of the equation cos(x)-3x+5=0 is "<<xn;

    return 0;
}
