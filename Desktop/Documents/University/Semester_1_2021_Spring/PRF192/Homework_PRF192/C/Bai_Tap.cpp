/*
-Study three commands: for, while, do...while
-Introduce three example about for, while and do...while so that we can distinguish advantages(values) of the commands
 Analyze the problem and check whether it requires a pre-test or a post-test loop.
If pre-test is required, use a while or for a loop.
If post-test is required, use a do-while loop.
-Continue to read slides from slot 1->6
*/
#include<stdio.h>
int main(){
	int i, sum=0;
	do{
		printf("Enter the integer number you want to add: ");
		scanf("%d", &i);
		if(i==0)
		{
				break;}
		
			sum+=i;
			
		
	}
	while (i!=0);
	printf("The Sum is: %d", sum);
}
