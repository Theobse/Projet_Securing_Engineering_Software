#include <stdio.h>
#include <math.h>
//predefine pi value, and can be used throughout an entire program
#define pi 3.14159265359
int main() {
	//I have to write this line of code to disable buffer, because my output is being buffered.
   setbuf(stdout, NULL);
   double r;
   printf("Enter radius of the circle:");
   scanf("%lf",&r);
   //use pow function to conpute the area of a circle
   printf("The area of the circle is %f", pi * pow(r,2));
   return 0;
}
