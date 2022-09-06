/*Enter two numbers and find the least common multiple*/

#include<stdio.h>
int main(){
	int a,b,i=1;
	printf("Please enter two numbers: ");
	scanf("%d %d",&a,&b);
	while(i>0){
		if(i%a==0 && i%b==0){
			printf("Least common multiple of two numbers is: %d",i);
			break;
		}
		else{
			i++;
		}
	}
}
