/*
 ============================================================================
 Name        : lab2_problem1.c
 Author      : Benjarit Hotrabhavananda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

//function prototypes
void factorial();
void leapYear();
void maximum();
void division();

//functions definition
int main(void) {
	setbuf(stdout, NULL);
	int loop = 1;
	int choice;
	//lebel 'again' will be used when user enters invalid choice
	again:while(loop == 1){
		//promt user to enter one of the choices
		printf("Select an option from below:\nI. Factorial\nII. Leap year or not\nIII. Maximum\nIV. Division of two numbers\nV. Exit\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				factorial();
				break;
			case 2:
				leapYear();
				break;
			case 3:
				maximum();
				break;
			case 4:
				division();
				break;
			case 5:
				printf("Bye\n");
				return 0;
				break;
			default:
				printf("Invalid Input\n");
				goto again;
				break;
		}
		printf("\n");
	}
}
void factorial(){
	unsigned short input;
	unsigned short counter;
	unsigned long output,output2;
	again:output = 1;
	printf("Enter a positive number: ");
	scanf("%hu",&input);
	//error checking
	//check if input value is 0, if so, then just equal to 1
	if(input!=0){
		for(counter = input; counter > 0; --counter){
			//store one state below current output
			output2 = output;
			output = output * counter;
			//check if new output is lower than 1 previous output,
			if(output2 > output){
				printf("Invalid input! Output exceeds range.\n");
				goto again;
			}
		}
		printf("The factorial of %hu is %lu\n\n", input, output);
	}
	else{
		printf("%d! = 1\n", input);
	}
}
void leapYear(){
	unsigned int year;
	printf("Please enter the year to test: ");
	scanf("%u",&year);
	//leap year happens every four years
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		printf("%u is the leap year.\n\n",year);
	else
		printf("%u is not the leap year.\n\n",year);
}
void maximum(){
	float num1, num2;
	printf("Please enter first number: ");
	scanf("%f",&num1);
	printf("Please enter second number: ");
	scanf("%f",&num2);
	//first, check if two numbers are equal
	//then if not, check if first number is bigger
	(num1 == num2)?printf("First and second number are equal.\n\n"):(num1 > num2)?printf("First number is larger.\n\n"):printf("Second number is larger.\n\n");
}
void division(){
	int num1, num2;
	float result;
	printf("Please enter first number: ");
	scanf("%d",&num1);
	printf("Please enter second number: ");
	scanf("%d",&num2);
	while(num2 == 0){
		printf("Invalid number, please enter second number again: ");
		scanf("%d",&num2);
	}
	//type cast to float because integer devided by integer will result in integer
	//but we want result to be in float type
	result = (float)num1 / num2;
	printf("Result: %f\n\n", result);
}
