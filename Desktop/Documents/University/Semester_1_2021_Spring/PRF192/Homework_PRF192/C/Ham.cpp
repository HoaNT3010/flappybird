#include<stdio.h>
int a=0, b=0;
void Input(int x, int y){
	printf("Input two int number:");
	scanf("%d %d",&x,&y); a=x; b=y;
}

void Output(int a, int b){
	printf("Total of the two number is: %d",a+b);
}

int main(){
	Input(a,b);
	Output(a,b);
}
