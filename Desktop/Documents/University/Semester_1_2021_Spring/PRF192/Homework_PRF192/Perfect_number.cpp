/*Enter an integer number and check if it is a perfect number or not*/

#include<stdio.h>
int main(){
	int a,sum=0;
	printf("Please enter an int number: ");
	scanf("%d",&a);
	for(int i=1;i<a;i++){
		if(a%i==0){
			sum+=i;
		}
	}
	if(sum==a){
		printf("%d is a perfect number",a);
	}
	else{
		printf("%d is not a perfect number",a);
	}
}
