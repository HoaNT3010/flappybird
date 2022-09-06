/*Loops:
-for
-while
-do...while*/
#include<stdio.h>
int main(){
	int Password=1234, password;
	do{
	printf("Enter your password: ");
	scanf("%d",&password);
}
	while(password!=Password);
	printf("Welcome");
}


