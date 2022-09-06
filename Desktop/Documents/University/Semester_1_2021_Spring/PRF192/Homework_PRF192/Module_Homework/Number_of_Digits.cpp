/*Count number of digits in an integer*/

#include<stdio.h>
int main(){
	int n;
	printf("Enter an integer: ");
	scanf("%d",&n);
	int count=0;
	for (int i=1; i<=n; i*=10){
		if(n/i>0){
			count++;
		}
	}
	printf("The number of digits is: %d\n",count);
}
