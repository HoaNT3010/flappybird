/*Enter an int number and check if it is a square number or not*/

#include<stdio.h>
int main(){
	int a,count=0;
	printf("Please enter an int number: ");
	scanf("%d",&a);
	for(int i=1;i<=a;i++){
		if(i*i==a){
			count++;
		}
	}
	if(count==0){
		printf("%d is not a square number",a);
	}
	else{
		printf("%d is a square number",a);
	}
}
