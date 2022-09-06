/*write a program in c that permits user type his own ID.
If the ID is valid it will ask him to enter his password, if the password is correct the program will print "wealcome you!",
otherwise, the program will print Incorrect Password and if the ID does not exist, the program will print Incorrecr ID.*/
#include<stdio.h>
int main(){
	int id=123, password=456;
	int Inputid, Inputpassword;
	printf("Enter your ID: ");
	scanf("%d", &Inputid);
	if(Inputid==id){
		printf("Enter your Password: ");
		scanf("%d", &Inputpassword);
		if(Inputpassword==password){
			printf("Welcome You!");
		}
		else {
			printf("Incorrect Password");
		}
	}
	else{
		printf("Incorrect ID");
	}	
			
}

