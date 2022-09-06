/*Reverse an integer*/

#include<stdio.h>
int main(){
	int n,i;
	printf("Enter an int number: ");
	scanf("%d",&n);
	int a[100];
	for(i=0;n>0;i++){
		a[i]=n%10;
		n/=10;
	}
	int z=i;
	printf("The reverse is: ");
	for(i=0;i<z; i++){
		printf("%d",a[i]);
	}
}
