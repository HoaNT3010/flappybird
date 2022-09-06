#include<stdio.h>

void Input(int *x, int *y){
	printf("Please enter two int numbers: ");
	scanf("%d %d",x,y);
}

void Output(int m, int n){
	printf("Total of the two number: %d",m+n);
}

int main(){
	int a=0,b=0;
	Input(&a,&b);
	Output(a,b);
}
