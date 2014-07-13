#include <stdio.h>
#include <math.h>

void solveQuadraticEquation();
double calculateDiscriminant();
double calculateFirstRoot();
double calculateSecondRoot();

int main(void) {
  double a, b, c;
  
  do{
    printf("Enter coeficients a, b, and c: ");
    scanf(" %lf %lf %lf", &a, &b, &c);
  
    solveQuadraticEquation(a, b, c);  
  }while(a != 0 && b != 0 && c != 0);

  return 0;
}

void solveQuadraticEquation(double a, double b, double c){
  double discriminant, root1, root2;
   
  discriminant = calculateDiscriminant(a, b, c);

  if (discriminant < 0)
    printf("No roots. \n");
  else if (discriminant == 0)
    printf("One root: %f. \n", 
		    calculateFirstRoot(a, b, discriminant));
  else
    printf("Two roots: %f and %f. \n", 
		    calculateFirstRoot(a, b, discriminant), 
		    calculateSecondRoot(a, b, discriminant));

}

double calculateDiscriminant(double a, double b, double c){
  return (pow(b, 2) - 4 * a * c);
}

double calculateFirstRoot(double a, double b, double disc){
  return disc == 0 ? (-b/(2*a)) : (-b + sqrt(disc))/(2*a);
}

double calculateSecondRoot(double a, double b, double disc){
  return (-b - sqrt(disc))/(2*a);   
}
