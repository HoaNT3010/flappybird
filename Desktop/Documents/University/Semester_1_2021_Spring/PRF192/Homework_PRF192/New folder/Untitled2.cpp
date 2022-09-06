#include<stdio.h>
int n;
const int MAX=100;
void Nhapmang(float a[],int *n){
	printf("\nPlease enter the number of element: ");
	scanf("%d",&*n);
	for(int i=0; i<*n; i++){
		printf("\nEnter mark for element a[%d]: ", i);
		scanf("%f",&a[i]);
	}
	printf("\nMarks saved!\n");
}

void Xuatmang(float a[], int *n){
	for(int i=0; i<*n; i++){
		printf("\nElement a[%d] has mark: ",i);
		printf("%.2f",a[i]);
	}
}

void FindMaximum(float a[], int *n){
	float max=a[0];
	for(int i=0; i<*n; i++){
		if(max < a[i]){
		max = a[i];	
		}
	}
	printf("\nThe maximum mark is: %.2f", max);
}

void MarkGreater(float a[], int *n){
	float avg=0,sum=0;
	for(int i=0; i<*n; i++){
		sum+=a[i];
	}
	avg=sum/ *n;
	printf("\nMarks greater than avarage: ");
	for(int i=0; i<*n; i++){
		if(a[i] >= avg){
			printf("%.2f   ", a[i]);
		}
	}
}

void Themphantu(float a[], int *n){
	if(*n >= MAX){
		printf("\nArray is full, can not insert!");
		return;
	}
	int pos;
	float val;
	printf("\nEnter insert position: ");
	scanf("%d", &pos);
	printf("\nEnter insert mark: ");
	scanf("%f", &val);
	if(pos < 0){
		pos = 0;
	}
	else if(pos > *n){
		pos = *n;
	}
	for(int i=*n; i>pos; i--){
		a[i]=a[i-1];
	}
	a[pos]=val;
	++*n;
	printf("Inserted!");
}

void Xoaphantu (float a[], int *n){
	if(*n<0){
		printf("Array is empty, can not delete!");
		return;
	}
	int pos;
	printf("\nEnter delete position: ");
	scanf("%d", &pos);
	if(pos > MAX){
		printf("Invalid position!");
		return;
	}
	if(pos<0){
		printf("Invalid position!");
		return;
	}
	else if(pos >= *n){
		pos = *n-1;
	}
	for(int i=pos; i<*n; i++){
		a[i]=a[i+1];
	}
	--*n;
	printf("Deleted!");
}

void SortAscending(float a[], int *n){
	float temp;
	for(int i=0; i<*n; i++){
		for(int j=0; j<=i; j++){
			if(a[j] > a[i]){
				temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
}

void Between(float a[], int *n){
	float A,B;
	printf("\nEnter number A and B (A < B): ");
	scanf("%f  %f", &A, &B);
	if(A > B){
		printf("Wrong condition!");
		return;
	}
	for(int i=0; i< *n; i++){
		if(a[i] >= A && a[i] <= B){
			printf("%.2f  ", a[i]);
		}
	}
}

int menu(){
	int choice;
	printf("\n==================MENU==================");
	printf("\n0--------------------------------------0");
	printf("\n|     1: Input Array                   |");
	printf("\n|     2: Print out Marks               |");
	printf("\n|     3: Find Maximum Mark             |");
	printf("\n|     4: Marks Greater than Avarage    |");
	printf("\n|     5: Insert a Mark                 |");
	printf("\n|     6: Delete a Mark                 |");
	printf("\n|     7: Sort the Array                |");
	printf("\n|     8: Find Marks Between A and B    |");
	printf("\n|     9: Help                          |");
	printf("\n|     Other: Exit                      |");
	printf("\n0--------------------------------------0");
	printf("\nPlease Enter your choice: ");
	scanf("%d", &choice);
	return choice;
}

void Help(){
	printf("\n1: Declare the number of marks and insert mark into the array");
	printf("\n2: Print out the array of marks");
	printf("\n3: Find the highest mark in the array");
	printf("\n4: Find marks that are greater than the avarage mark");
	printf("\n5: Insert a mark into the existing array");
	printf("\n6: Delete a mark out of the existing array");
	printf("\n7: Sort the array with ascending order");
	printf("\n8: Find the marks that are between the range A to B (greater or equal to A & lesser or equal to B)\n");
}
int main(){
	int userchoice; 

	float a[n];
	do{
		userchoice = menu();
		switch (userchoice)
		{
			case 1: Nhapmang(a,&n);
			break;
			case 2: if(n<=0)
				printf("Please input Array first!");
				else Xuatmang(a,&n);			
				break;
			case 3:if(n<=0)
				printf("Please input Array first!");
				else FindMaximum(a,&n);
			break;
			case 4:if(n<=0)
				printf("Please input Array first!");
				else MarkGreater(a,&n);
			break;
			case 5:if(n<=0)
				printf("Please input Array first!");
				else Themphantu(a,&n);
			break;
			case 6:if(n<=0)
				printf("Please input Array first!");
				else Xoaphantu(a,&n);
			break;
			case 7:if(n<=0)
				printf("Please input Array first!");
				else {
				SortAscending(a,&n);
				printf("\nMarks after Sorting: ");
				Xuatmang(a, &n);}
			break;
			case 8:if(n<=0)
				printf("Please input Array first!");
				else Between(a, &n);
			break;
			case 9: Help();
			break;
			case 0: printf("See you later!");
			break;
			default: printf("Invalid Choice, Try Again");
		}
	}
		while (userchoice != 0);
	}
