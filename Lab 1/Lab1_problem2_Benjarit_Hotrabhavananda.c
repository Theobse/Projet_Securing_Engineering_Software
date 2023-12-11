#include <stdio.h>
int main() {
   setbuf(stdout, NULL);
   double sell, cost,net;
   printf("Enter cost price: ");
   scanf("%lf", &cost);
   printf("Enter selling price: ");
   scanf("%lf", &sell);
   net = sell - cost;
   if(net < 0){
	   // put negative sign in front of net in this case because we know net will be negative number but I don't it to display negative sign
	   //Money represents two decimal place so we use %.2f
	   printf("You incurred lost by : $%.2f",-net);
   }
   else if(net > 0){
   	   printf("You made profit by : $%.2f",net);
   }
   else{
	   printf("You made neither profit or incurred lost");
   }
   return 0;
}
