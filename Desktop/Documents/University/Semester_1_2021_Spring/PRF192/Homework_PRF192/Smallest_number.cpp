/*Enter 3 numbers and find the smallest*/

#include<stdio.h>
int main(){
	int a,b,c,smallest;
	printf("Please enter 3 numbers: ");
	scanf("%d %d %d",&a,&b,&c);
	smallest=a;
	if(smallest>b){
		smallest=b;
	}
	if(smallest>c){
		smallest=c;
	}
	printf("The smallest number is: %d",smallest);
	
}
