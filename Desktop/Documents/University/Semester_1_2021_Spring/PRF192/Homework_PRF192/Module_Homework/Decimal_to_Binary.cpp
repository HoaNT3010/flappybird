/*Convert decimal number to binary*/

#include<stdio.h>
int main(){
	int decimal,a[100],i;
	printf("Enter a decimal number: ");
	scanf("%d",&decimal);
	for(i=0;decimal>0;i++){
		a[i]=decimal%2;
		decimal=decimal/2;
	}
	printf("Binary equivilent is: ");
	for(i=i-1;i>=0;i--){
		printf("%d",a[i]);
	}
}
