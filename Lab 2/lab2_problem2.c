/*
 ============================================================================
 Name        : lab2_problem2.c
 Author      : Benjarit Hotrabhavananda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void arithmetic(unsigned short);
void bitwise(unsigned short);

int main(void) {
	setbuf(stdout, NULL);
	unsigned short input,choice;
	//take in user input
	printf("Enter a number to display in binary representation: ");
	scanf("%hu",&input);
	//take in type of operation
	printf("Enter 1(arithmetic operation) or 2(bitwise operation): ");
	scanf("%hu",&choice);
	if(choice == 1){
		arithmetic(input);
	}
	else if(choice ==2){
		bitwise(input);
	}
	//
	else{
		printf("\nInvalid input!!");
	}
	return 0;
}
void arithmetic(unsigned short input){
	//initiate 16 bits
	// '\0' places at the end automaticlally
	char arr[] = "0000000000000000";
	int counter = 0;

	while(input > 0){
		if(input%2 == 0){
			arr[counter] = '0';
		}
		else{
			arr[counter] = '1';
		}
		input/= 2;
		counter++;
	}
	printf("\nBinary representation is ");
	for(counter = 15; counter >= 0; counter--){
		printf("%c",arr[counter]);
	}
}
void bitwise(unsigned short input){
	//mask is 100000000000000 which is equivalent to 32768 in decimal
	unsigned short mask = 32768;
	printf("\nBinary representation is ");
	while(mask > 0){
		if((input&mask) == 0){
			printf ("0");
		}
		else{
			printf ("1");
		}
		//shift mask by 1 bit to the right
		mask>>= 1;
	}
}
