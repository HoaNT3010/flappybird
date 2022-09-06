/*Convert binary number to decimal*/

#include<stdio.h>
#include<math.h>
int main(){
	int binary;
	printf("Please enter a binary number: ");
	scanf("%d",&binary);
	int Binary2=binary;
	int decimal=0,position=0;
	while (Binary2>0){
		if(Binary2%10==1){
			decimal+=pow(2,position);
		}	
		Binary2/=10;
		position++;
	}
	printf("%d has the decimal value of: %d",binary,decimal);
}
