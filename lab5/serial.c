#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double Trap(double a, double b, int n);

double f(double x){
        return exp(x);
}
  
int main(int argc, char* argv[]){
        double a, b;
        int n;
	a = strtol(argv[1], NULL, 10);
        b = strtol(argv[2], NULL, 10);
	n = strtol(argv[3], NULL, 10);
        double result = Trap(a, b, n);
        printf("With n = %d trapezoids, our estimate\n", n);
        printf("of the integral from %f to %f = %.14e\n", a , b, result);
        return 0;
}

double Trap(double a, double b, int n){
        double h, approx, x_i;
        int i ;
        h = (b-a)/n;
        approx = (f(a) + f(b))/2.0;
        for(i = 1; i<=n-1; i++){
                x_i = a + i*h;
                approx += f(x_i);
        }
        approx = h * approx;
        return approx;
}
