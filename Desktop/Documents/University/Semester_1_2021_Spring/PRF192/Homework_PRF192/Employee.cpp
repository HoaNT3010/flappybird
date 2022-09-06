#include<stdio.h>
#include<string.h>
#include<conio.h>

struct Employee{
	char id[50];
	char name[50];
	float salarylv;
};

typedef Employee EM;
void inputemN(EM a[], int n);
void inputem(EM &em);
void outputemN(EM a[], int n);
void outputem(EM em);
void totalem(int n);
void fileout(EM a[], int n, char filename[]);
void maxsalary(EM a[], int n);
void addem(EM a[], int *n);
void delem(EM a[], int *n);
void sortas(EM a[], int n);
void updateem(EM a[], int n);
void samename(EM a[], int n);
void findem(EM a[], int n);

int main()
{
	char filename[] = "EMPLOYEE.txt";
	int n=0;
	printf("Enter total number of employee: ");
	scanf("%d", &n);
	EM a[n];
	inputemN(a, n);
	outputemN(a, n);
	samename(a, n);
	//totalem(n);
	//fileout(a, n, filename);
	//maxsalary(a, n);
	//delem(a, &n);
	//addem(a, &n);
	//sortas(a, n);
	//updateem(a, n);
	//outputemN(a, n);
}

void totalem(int n){
	printf("\n");
	printf("The total number of employee is: %d", n);
	printf("\n");
}

void inputem(EM &em){
	printf("\nEnter employee's ID: "); fflush(stdin);
	fgets(em.id, 50, stdin);
	printf("Enter employee's Name: "); fflush(stdin);
	fgets(em.name, 50, stdin);
	printf("Enter employee's salary level: "); fflush(stdin);
	scanf("%f", &em.salarylv);
}

void inputemN(EM a[], int n){
	printf("\n");
	for (int i=0; i<n; i++){
		printf("\nEnter employee number %d", i);
		inputem(a[i]);
	}
	printf("\n");
}

void outputem(EM em){
	printf("\nEmployee's ID: %s", em.id);
	printf("           Name: %s", em.name);
	printf("           Salary level: %.1f", em.salarylv);
}

void outputemN(EM a[], int n){
	printf("\n");
	for (int i=0; i<n; i++){
		printf("\nInformation of employee number %d: ", i);
		outputem(a[i]);
		printf("\n");
	}
	printf("\n");
}

void fileout(EM a[], int n, char filename[]){
	FILE * fp;
	fp = fopen(filename, "w");
	for (int i=0; i<n; i++){
		fprintf(fp,"\nEmployee number %d:", i+1);
		fprintf(fp,"\nEmployee's ID: %s", a[i].id);
		fprintf(fp,"           Name: %s", a[i].name);
		fprintf(fp,"           Salary level: %.1f", a[i].salarylv);
	}
	fclose(fp);
}


void maxsalary(EM a[], int n){
	printf ("\nEmployees who have maximum salary level:");
	float maxsl = a[0].salarylv;
	for (int i=0; i<n; i++){
		if(maxsl < a[i].salarylv){
			maxsl = a[i].salarylv;	
		}
	}
	for (int i=0; i<n; i++){
		if(a[i].salarylv == maxsl){
			printf("\nEmployee %d______ID: %s________________Name: %s\n", i+1, a[i].id, a[i].name);
		}
	}
}

void addem(EM a[], int *n){
	int pos = *n;
	float slevel;
	char ID[50], Name[50];
	printf("\nAdd an employee:");
	printf("\nEnter employee's ID: "); fflush(stdin);
	fgets(ID, 50, stdin);
	printf("Enter employee's name: "); fflush(stdin);
	fgets(Name, 50, stdin);
	printf("Enter employee's salary level: "); fflush(stdin);
	scanf("%f", &slevel);
	for(int i = *n; i > pos; i--){
        a[i] = a[i-1];
    }
   		strcpy(a[pos].id, ID);
   		strcpy(a[pos].name, Name);
   		a[pos].salarylv=slevel;
    ++*n;
    printf("\nEmployee Added!");
}

void delem(EM a[], int *n){
	int pos;
	printf("\nEnter deleting position:");
	scanf("%d", &pos);
	if (pos < 0){
		pos = 0;
	}
	else if(pos >= *n){
		pos = *n-1;
	}
	for(int i=pos; i < *n-1; i++){
		a[i] = a[i+1];
	}
	--*n;
} 

void updateem(EM a[], int n){
	int pos;
	float slevel;
	char ID[50], Name[50];
	printf("\nUpdate an Employee:");
	printf ("\nEnter position need to update:");
	scanf("%d", &pos);
	printf("\nInformation of employee %d:", pos);
	printf("\nEmployee's ID: %s", a[pos].id);
	printf("           Name: %s", a[pos].name);
	printf("           Salary level: %.1f\n", a[pos].salarylv);
	printf("\nEnter update employee's ID: "); fflush(stdin);
	fgets(ID, 50, stdin);
	printf("Enter update employee's Name: "); fflush(stdin);
	fgets(Name, 50, stdin);
	printf("Enter update employee's salary level: "); fflush(stdin);
	scanf("%f", &slevel);
	strcpy(a[pos].id, ID);
	strcpy(a[pos].name, Name);
	a[pos].salarylv = slevel;
	printf("\nEmployee Updated!");
}

void sortas(EM a[], int n){
	EM temp;
	for(int i=0; i<n; i++){
		for (int j=0; j<=i; j++){
			if(a[j].salarylv > a[i].salarylv){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}


int check(EM b[], int t, EM em){
	int boo = 0;
	for(int i=0; i<t; i++){
		if(strcmp(b[i].name, em.name) == 0){
			boo = 1;
			break;
		}
	}
	return boo;
}

void samename(EM a[], int n){
	printf("\n Employee who have the same name:");
	int i,j, t=0;
	EM b[50];
	for (i=0; i<n-1; i++){
		if(check(b, t, a[i]) == 1) continue;
		else{
			int dem =0;
			for (j=0; j<=i; j++)
				if(strcmp(a[i].name, a[j].name) == 0) dem++;
				if(dem!=0){
					while(dem!=0){
						printf("Employee ID: %s", a[j].id);
						dem--;
					}
					printf("\n");
					b[t]=a[i];
					t++;
				}
		}
	}
}







