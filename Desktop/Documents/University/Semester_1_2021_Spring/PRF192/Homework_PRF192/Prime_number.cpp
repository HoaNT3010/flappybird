/*Enter a number and check if it is a prime number or not*/

#include<stdio.h>
#include<math.h>
int main(){
	int a;
	printf("Please enter an int number: ");
	scanf("%d",&a);
	if(a<=1){
		printf("%d is not a prime number",a);
		return 0;
	}
	int count=0;
	for(int i=2; i<=sqrt(a);i++){
		if(a%i==0){
			count++;
		}
	}
	if(count==0){
		printf("%d is a prime number",a);
	}
	else{
		printf("%d is not a prime number",a);
	}
}
