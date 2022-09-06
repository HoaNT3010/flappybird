/*write a program in c that permits user type his own ID.
If the ID is valid it will ask him to enter his password, if the password is correct the program will print "wealcome you!",
otherwise, the program will print Incorrect Password and if the ID does not exist, the program will print Incorrecr ID.*/
#include<stdio.h>
int main(){
	int id=12345;
	int password=67890;
	int user_input_id, user_input_password;
	printf("Please enter ID: ");
	scanf("%d", &user_input_id);
	switch(user_input_id) {
		case 12345:
			printf("Please enter Password: ");
			scanf("%d", &user_input_password);
			switch(user_input_password){
				case 67890:
					printf("Welcome You!");
					break;
				default :
					printf("Incorrect Password");
					break;
			}
			break;
		default :
			printf("Incorrect ID");
			break;
	}
}
