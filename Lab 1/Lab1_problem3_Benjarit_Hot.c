#include <stdio.h>
int main() {
   setbuf(stdout, NULL);
   //operands 1 and operands 2
   double op1,op2;
   char operator;
   //lebel again is used when user enters wrong format
   again:printf("Operand 1:");
   //%*c will clear stuff in stdin buffer
   scanf("%lf%*c", &op1);
   printf("operator:");
   operator = getchar();
   printf("Operand 2:" );
   scanf("%lf", &op2);
   switch(operator){
   case '+':
	   printf("%f + %f = %f", op1,op2, (op1 + op2));
	   break;
   case '-':
	   printf("%f - %f = %f", op1,op2, (op1 - op2));
	   break;
   case '*':
	   printf("%f x %f = %f", op1,op2, (op1 * op2));
	   break;
   case '/':
	   if(op2 != 0){
		   printf("%f / %f = %f", op1,op2, (op1 / op2));
	   }
	   else{
		   printf("Error! Division by zero.");
	   }
	   break;
    default:
	    printf("Wrong format! Please re-enter!\n");
	    //This line will bring the flow to the top again
	    goto again;
		break;
   	}
   return 0;
}
