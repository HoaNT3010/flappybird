/*Enter two number and find the greatest common factor (greatest common divisor)*/

#include<stdio.h>
int main(){
	int a,b,j;
	printf("Please enter two number: ");
	scanf("%d %d",&a,&b);
	for(int i=1; i<=a || i<=b;i++){
		if (a%i==0 && b%i==0){
			j=i;
		}
	}
	printf("Greatest common factor of two numbers is: %d",j);
}
