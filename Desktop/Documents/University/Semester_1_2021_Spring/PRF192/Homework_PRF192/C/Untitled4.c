/*Input an integer number and determine whether it is an odd or an even number*/
#include<stdio.h>
int main(){
    int a;
    printf("Please enter the number: ");
	scanf("%d",&a);
	/*Neu a/2==0 thi a la so chan, con khong a la so le*/
	if(a/2==0) printf("The number is even");
	else printf("The number is odd");
	/*(a/2==0): bieu t */
}
