#include<stdio.h>
#include<math.h>

#define LOOP_MAX 256

float g(float);
float h(float);
float length(float, float, int);
float trap(float, float, int, float (*)(float));
void printArea(float, float, float (*)(float));

int main(void){
  printArea(0, 3.14159, &g);
  printf("\n");
  printArea(-2, 2, &h);

  return 0;
}

void printArea(float a, float b, float (*fn)(float)){
  int  n;

  if(&(*fn) == &g)
    printf("Entering trap with function g()...\n\n");
  else if(fn == h) /* Samme resultat, da & og * ophæver hinanden. */
    printf("Entering trap with function h()...\n\n");

  for(n = 2; n <= LOOP_MAX; n *= 2)
    printf("Area under curve with %3d subintervals is: %.3f\n", n, 
		    trap(a, b, n, (*fn)));
}

float trap(float a, float b, int n, float (*f)(float)){
  float f_xi, width_h, xi;
  int i;

  f_xi = 0;
  xi = a;
  width_h = length(a, b, n);

  for(i = 1; i <= n - 1; i++)
    f_xi += (*f)(xi += width_h);

  return ((width_h / 2) * ((*f)(a) + (*f)(b) + 2 * f_xi));
}

float g(float x){
  return (pow(x, 2.0) * sin(x));
}

float h(float x){
  return (sqrt(4.0 - pow(x, 2)));
}

float length(float a, float b, int n){
  return ((b - a)/n);
}
