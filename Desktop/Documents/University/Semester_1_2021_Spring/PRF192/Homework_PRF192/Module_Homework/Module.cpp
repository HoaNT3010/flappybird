#include<stdio.h>
#include<math.h>

void BtoD(){
	int binary;
	printf("\nPlease enter a binary number: ");
	scanf("%d",&binary);
	int Binary2=binary;
	int decimal=0,position=0;
	while (Binary2>0){
		if(Binary2%10==1){
			decimal+=pow(2,position);
		}	
		Binary2/=10;
		position++;
	}
	printf("%d has the decimal value of: %d",binary,decimal);
}

void DtoB(){
		int decimal,a[100],i;
	printf("\nEnter a decimal number: ");
	scanf("%d",&decimal);
	for(i=0;decimal>0;i++){
		a[i]=decimal%2;
		decimal=decimal/2;
	}
	printf("Binary equivilent is: ");
	for(i=i-1;i>=0;i--){
		printf("%d",a[i]);
	}
}

void Reverse(){
	int n,i;
	printf("\nEnter an int number: ");
	scanf("%d",&n);
	int a[100];
	for(i=0;n>0;i++){
		a[i]=n%10;
		n/=10;
	}
	int z=i;
	printf("The reverse is: ");
	for(i=0;i<z; i++){
		printf("%d",a[i]);
	}
}

void MulTable(){
		for(int i=1; i<10; i++){
		for(int j=1; j<=10; j++){
			printf("%dx%d=%d\n",i,j,i*j);
		}
		printf("\n");
}
}

void Digits(){
	int n;
	printf("\nEnter an integer: ");
	scanf("%d",&n);
	int count=0;
	for (int i=1; i<=n; i*=10){
		if(n/i>0){
			count++;
		}
	}
	printf("The number of digits is: %d\n",count);
}

int menu(){
	int choice;
	printf("\n             MENU          ");
	printf("\n1: Convert Binary to Decimal");
	printf("\n2: Convert Decimal to Binary");
	printf("\n3: Reverse an int number");
	printf("\n4: Dispkay Multiplication table from 1 to 9");
	printf("\n5: Count number of digits of an int number");
	printf("\nOther: Exit");
	printf("\nPlease Choose: ");
	scanf("%d", &choice);
	return choice;
}
int main(){
	int userchoice;
	do{
		printf("\n");
		userchoice=menu();
		switch (userchoice)
		{
			case 1: BtoD();
			break;
			case 2: DtoB();
			break;
			case 3: Reverse();
			break;
			case 4: MulTable();
			break;
			case 5: Digits();
			break;
			default: printf("Goodbye");
		}
	}
	while (userchoice>=1 && userchoice<6);
}
