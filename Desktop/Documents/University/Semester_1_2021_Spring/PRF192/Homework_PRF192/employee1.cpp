#include<stdio.h>
#include<string.h>
#include<conio.h>

struct Employee{
	char id[50];
	char name[50];
	float salarylv;
};

typedef Employee EM;
//void inputemN(EM a[], int n);
//void inputem(EM &em);
void outputemN(EM a[], int n);
void outputem(EM em);
void totalem(int n);
void fileout(EM a[], int n, char filename[]);
void maxsalary(EM a[], int n, FILE*fpt);
void addem(EM a[], int *n);
void delem(EM a[], int *n);
void sortas(EM a[], int n);
void updateem(EM a[], int n);
void samename(EM a[], int n);
//void findem(EM a[], int n);
//void foutput(EM a[], int n);
int Menu();

int main()
{
	int n = 3;
	EM a[n];
	FILE * fp;
	fp = fopen("emp.txt", "r");
	fseek(fp, 26, SEEK_SET);
	for(int i=0; i< n; i++){
		fscanf(fp,"%s	%s	%f", &a[i].id, &a[i].name, &a[i].salarylv);
	}
	fclose(fp);
	outputemN(a, n);
	
	int userchoice;
	do{
		userchoice=Menu();
		switch(userchoice){
			case 1: addem(a, &n);
					break;
			case 2: delem(a,&n);
					break;	
			case 3: updateem(a,n);
					break;
			case 4: sortas(a,n);
					outputemN(a, n);
					break;
			case 5: FILE *fpt;
			fpt = fopen("emp2.txt", "w");
			fprintf(fpt, "Total employee: %d", n);
			maxsalary(a, n, fpt);
			fclose(fpt);
;					break;
			case 0: printf("\n=====Good Bye!=====\n");
					break;
			default: printf("\n**Invalid choice. Please try agian!**\n");
					break;														
		}
		fflush(stdin);
	}
	while (userchoice != 0);
	return 0;
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
	printf("\nEmployee's ID: %s		Name: %s		Salary level: %.1f", em.id, em.name, em.salarylv);
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




void maxsalary(EM a[], int n, FILE *fpt){
	fprintf (fpt, "\nEmployees who have maximum salary level:");
	float maxsl = a[0].salarylv;
	for (int i=0; i<n; i++){
		if(maxsl < a[i].salarylv){
			maxsl = a[i].salarylv;	
		}
	}
	for (int i=0; i<n; i++){
		if(a[i].salarylv == maxsl){
			fprintf(fpt, "\nEmployee %d______ID: %s________________Name: %s\n", i+1, a[i].id, a[i].name);
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
	scanf("%f",&slevel);
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
	gets(ID);
	printf("Enter update employee's Name: "); fflush(stdin);
	gets(Name);
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


int check(EM b[], int t, EM a){
	bool flag = false;
	for(int i=0; i<t; i++){
		if(strcmp(b[i].name, a.name) == 0){
			flag = true;
			break;
		}
	}
	return flag;
}

void samename(EM a[], int n){
	printf("\n Employee who have the same name:");
	int i,j, t=0;
	EM b[50];
	for (i=0; i<n; i++){
		if(check(b, t, a[i]) == true) continue;
		else{
			int dem =0;
			for (j=i+1; j< n; j++)
				if(strcmp(a[i].name, a[j].name) == 0) dem++;
				if(dem!=0){
					while(dem!=-1){
						printf("%s, ", a[j].id);
						dem--;
					}
					printf(";");
					
					b[t]=a[i];
					t++;
				}
		}
	}
}

/*void fileout(EM a[], int n, char filename[]){
	FILE * fp;
	fp = fopen(filename, "w");
	for (int i=0; i<n; i++){
		fprintf(fp,"\nEmployee number %d:", i+1);
		fprintf(fp,"\nEmployee's ID: %s", a[i].id);
		fprintf(fp,"           Name: %s", a[i].name);
		fprintf(fp,"           Salary level: %.1f", a[i].salarylv);
	}
	fclose(fp);
}*/

int Menu(){
	char choice;
	int num = 0;
	bool flag = false;
	printf("\n              MENU");
	printf("\n|[1]       Add Employee         ");
	printf("\n|[2]      Delete Employee      ");
	printf("\n|[3]      Update Employee   ");
	printf("\n|[4]       Sort Employee       ");
	printf("\n|[5]      Output to File     ");
	printf("\n|[0]           Exit          ");
	printf("\n=====>Enter your choice here: ");
	while(true) {
		scanf("%c", &choice);
		if (choice == '\n') break;
		if (choice < '0' || choice > '9') {
			flag = true;
			continue;
		}	
		num = num * 10 + choice - '0';
	}
	if (flag == true) return 10;
	return num;	
}


