#include<stdio.h>
#include<string.h>
int n, userchoice;
const int MAX=100;
struct student{
	int ID;
	char name[50];
	float GPA;
};

void Inputonestd(struct student &p){
	printf("\nInput student ID: ");
	scanf("%d", &p.ID);
	printf("\nInput student name: ");
	fgets(p.name, 50, stdin);
	scanf("%[^\n]%*c", &p.name);
	printf("\nInput student GPA: ");
	scanf("%f", &p.GPA);
}

void Inputlist(struct student *p, int *n){
	printf("Input the number of student: ");
	scanf("%d", n);
	for(int i=0; i<*n; i++){
		printf("Input data for student %d: ",i);
		Inputonestd(p[i]);
	}
}

void Outputonestd(struct student &p){
	printf("\nStudent ID: %d ----- ",p.ID);
	printf("Student name: %s ----- ", p.name);
	printf("Student GPA: %.2f\n",p.GPA);
}

void Outputlist(struct student *p, int n){
	for(int i=0; i<n; i++){
		Outputonestd(p[i]);
	}
}

void findstdID(struct student *p, int *n){
	int id, dem=0,pos;
	float gpa;
	printf("\nEnter ID need to search: ");
	scanf("%d",&id);
	for(int i=0; i<*n; i++){
		if (p[i].ID == id){
			Outputonestd(p[i]);
			pos=i;
			dem++;
			gpa = p[i].GPA;
		}
	}
	if(dem==0){
		printf("\nNo student found!\n");
	}
	if(dem!=0){
	if(p[pos].GPA >= 8 && p[pos].GPA <=10){
		printf("\nVery Good!");
	}else if(p[pos].GPA >=7 && p[pos].GPA <8){
		printf("\nGood!");
		}else if(p[pos].GPA >=6 && p[pos].GPA <7){
			printf("\nAbove average!");
		}else if(p[pos].GPA >=5 && p[pos].GPA <6){
			printf("\nAverage!");	
		}else if(p[pos].GPA <5){
				printf("\nWeak!");
			}
	}
}

void findstdName(struct student *p, int *n){
	printf("\nEnter student name: ");
	char sname[50];
	int dem=0,pos;
	fgets(sname, 50, stdin);
	scanf("%[^\n]%*c", sname);
	
	for(int i=0; i<*n;i++){
		if(strcmp(p[i].name , sname)==0){
			Outputonestd(p[i]);
			pos=i;
		}
		else dem++;
	}
	if(dem==1){
		printf("\nNo student found!\n");
	}
	if(dem!=1){
	if(p[pos].GPA >= 8 && p[pos].GPA <=10){
		printf("\nVery Good!");
	}else if(p[pos].GPA >=7 && p[pos].GPA <8){
		printf("\nGood!");
		}else if(p[pos].GPA >=6 && p[pos].GPA <7){
			printf("\nAbove average!");
		}else if(p[pos].GPA >=5 && p[pos].GPA <6){
			printf("\nAverage!");	
		}else if(p[pos].GPA <5){
				printf("\nWeak!");
			}
}
}

int Menufindstd(){
	printf("\n");
	int choice;
	printf("\n[1] Find student base on ID");
	printf("\n[2] FInd student base on Name");
	printf("\n[0] Back");
	printf("\n Please enter your choice: ");
	scanf("%d",&choice);
	return choice;
}

void Findstudent(struct student *p, int *n){
	printf("\n");
	int choice;
	do{
		choice = Menufindstd();
		switch (choice){
			case 1: findstdID(p,n);
				break;
			case 2: findstdName(p,n);
				break;
			case 0: printf("Back to main menu!\n");
				break;
			default : printf("\n**Invalid choice, Try Again!**\n");
				break;
		}
	}
	while(choice!=0);
}

//sort the student list according to ascending GPA order
void GPAsortA(struct student *p, int *n){
	printf("\n");
	struct student temp;
	for(int i=0; i<*n; i++){
		for(int j=0; j<=i; j++){
			if(p[j].GPA > p[i].GPA){
				temp = p[j];
				p[j] = p[i];
				p[i] = temp;
			}
		}
	}
	printf("\nAfter sorting, the student list is: ");
	for(int i=0; i<*n; i++){
		printf("\nStudent ID: %d ----- ",p[i].ID);
		printf("Student name: %s ----- ", p[i].name);
		printf("Student GPA: %.2f\n",p[i].GPA);
	}
}
//show top 3 student who have highest gpa, if n<=3 --> show all student.


void Top3student(struct student *p, int *n){
	printf("\n");
	if(*n<=3){
		printf("=====Top highest GPA student=====");
		Outputlist(p,*n);
	}
	else{
	printf("\n=====Top 3 highest GPA student=====");
	printf("\nStudent ID: %d ----- ",p[*n-1].ID);
	printf("Student name: %s ----- ", p[*n-1].name);
	printf("Student GPA: %.2f\n",p[*n-1].GPA);
	printf("\nStudent ID: %d ----- ",p[*n-2].ID);
	printf("Student name: %s ----- ", p[*n-2].name);
	printf("Student GPA: %.2f\n",p[*n-2].GPA);
	printf("\nStudent ID: %d ----- ",p[*n-3].ID);
	printf("Student name: %s ----- ", p[*n-3].name);
	printf("Student GPA: %.2f\n",p[*n-3].GPA);
	}
}

int Menu(){
	int choice;
	printf("\n---------------MENU---------------");
	printf("\n|[1]    Input Student List       |");
	printf("\n|[2]    Output Student List      |");
	printf("\n|[3]       Find student          |");
	printf("\n|[4]     Sort Student List       |");
	printf("\n|[5]      Show Top 3 GPA         |");
	printf("\n|[6]           Help              |");
	printf("\n|[0]           Exit              |");
	printf("\n----------------------------------\n");
	printf("\n=====>Enter your choice here: ");
	scanf("%d", &choice);
	return choice;
}

void Help(){
	printf("\n");
	printf("\n[1]: Input students information, need to declare number of student first.");
	printf("\n[2]: Print out student list to the screen");
	printf("\n[3]: Find student base on 2 information: Student's ID and Student's Name");
	printf("\n[4]: Sort the student list with the ascending order.");
	printf("\n[5]: Show information of top 3 student who have highest GPA. Need to sort student list first!");
	printf("\n[0]: Exit this program");
	printf("\n[NOTE]: Module 2 -> 5: Need to Input student information first to be execute!");
}

int main(){
	student a[n];
	do{
		userchoice=Menu();
		switch(userchoice){
			case 1: Inputlist(a,&n);
					break;
			case 2: if(n<=0)
				printf("\n**Please input Student List first!**\n");
				else Outputlist(a,n);
					break;
			case 3: if(n<=0)
				printf("\n**Please input Student List first!**\n");
				else Findstudent(a,&n);
					break;
			case 4: if(n<=0)
				printf("\n**Please input Student List first!**\n");
				else GPAsortA(a,&n);
					break;
			case 5: if(n<=0)
				printf("\n**Please input Student List first!**\n");
				else Top3student(a,&n);
					break;
			case 6: Help();
					break;
			case 0: printf("\n=====Good Bye!=====\n");
					break;
			default: printf("\n**Invalid choice. Please try agian!**\n");
					break;														
		}
	}
	while (userchoice != 0);
	fflush(stdin);
	getchar();
	return 0;
}
