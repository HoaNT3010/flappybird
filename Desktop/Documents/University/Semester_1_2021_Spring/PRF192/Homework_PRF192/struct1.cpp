#include<stdio.h>
#include<string.h>
struct student{
	int ID;
	char name[50];
	float GPA;
};

void Inputstd(student p[], int *n){
	printf("Input the number of student: ");
	scanf("%d",n);
	for(int i=0; i<*n; i++){
		printf("\nInput student ID: ");
		scanf("%d", &p[i].ID);
		getchar();
		printf("\nInput student name: ");
		fgets(p[i].name, sizeof(p[i].name), stdin);
		printf("\nInput student GPA: ");
		scanf("%f", &p[i].GPA);
	}
	printf("\nInput Completed, back to main menu!");
}

void Outputstd(student p[], int *n){
	printf("\n======Student List======");
	for(int i=0; i<*n; i++){
		fflush(stdin);
		printf("\nStudent %d: ",i);
		printf("\nStudent ID: %d ----- ",p[i].ID);
		printf("Student name: %s ----- ", p[i].name);
		printf("Student GPA: %.2f\n",p[i].GPA);
	}
}
void Addstd(student p[], int *n);

int Menuaddstd(){
	int addchoice;
	printf("\nDo you want to add new student?");
	printf("\n[1]: Yes");
	printf("\n[2]: No");
	printf("\nEnter your choice: ");
	scanf("%d",&addchoice);
	return addchoice;
}

void findstdID(struct student p[], int *n){
	int id, dem=0,pos;
	float gpa;
	int Achoice;
	printf("\nEnter ID need to search: ");
	scanf("%d",&id);
	for(int i=0; i<*n; i++){
		if (p[i].ID == id){
			printf("\nStudent %d: ",i);
			printf("\nStudent ID: %d ----- ",p[i].ID);
			printf("Student name: %s ----- ", p[i].name);
			printf("Student GPA: %.2f\n",p[i].GPA);
			pos=i;
			dem++;
			gpa = p[i].GPA;
		}
	}
	if(dem==0){
		printf("\nNo student found!\n");
		do{
			Achoice=Menuaddstd();
			switch (Achoice){
				case 1: Addstd(p,n);
				break;
				case 2: printf("\nBack to find student!");
				break;
				default:printf("\nInvalid choice, please try agian!");
				break;
			}
		}
		while(Achoice!=2);
		fflush(stdin);
		getchar();
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

void findstdName(struct student p[], int *n){
	char sname[50];
	int dem=1,pos,Achoice;
	getchar();
	printf("\nEnter student name: ");
	fgets(sname, sizeof(sname), stdin);
	for(int i=0; i<*n;i++){
		if(strcmp(p[i].name , sname)==0){
			printf("\nStudent %d: ",i);
			printf("\nStudent ID: %d ----- ",p[i].ID);
			printf("Student name: %s ----- ", p[i].name);
			printf("Student GPA: %.2f\n",p[i].GPA);
			pos=i;
			dem--;
		}
	}
	if(dem==1){
		printf("\nNo student found!\n");
		do{
			Achoice=Menuaddstd();
			switch (Achoice){
				case 1: Addstd(p,n);
				break;
				case 2: printf("\nBack to find student!");
				break;
				default:printf("\nInvalid choice, please try agian!");
				break;
			}
		}
		while(Achoice!=2);
		fflush(stdin);
		getchar();
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
	printf("\n========Find Student========");
	printf("\n[1] Find student base on ID");
	printf("\n[2] Find student base on Name");
	printf("\n[0] Back");
	printf("\n Please enter your choice: ");
	scanf("%d",&choice);
	return choice;
}

void Findstudent(struct student p[], int *n){
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
	fflush(stdin);
	getchar();
}

void GPAsortA(struct student p[], int *n){
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
		fflush(stdin);
		printf("\nStudent %d: ",i);
		printf("\nStudent ID: %d ----- ",p[i].ID);
		printf("Student name: %s ----- ", p[i].name);
		printf("Student GPA: %.2f\n",p[i].GPA);
	}
}

void Top3student(struct student *p, int *n){
	student t[40];
	student temp;
	for(int i=0; i<*n; i++){
		t[i]=p[i];
	}
	for(int i=0; i<*n; i++){
		for(int j=0; j<=i; j++){
			if(t[j].GPA > t[i].GPA){
				temp = t[j];
				t[j] = t[i];
				t[i] = temp;
			}
		}
	}
	printf("\n");
	if(*n<=3){
		printf("=====Top highest GPA student=====");
		for(int i=0; i<*n; i++){
		fflush(stdin);
		printf("\nStudent %d: ",i);
		printf("\nStudent ID: %d ----- ",t[i].ID);
		printf("Student name: %s ----- ", t[i].name);
		printf("Student GPA: %.2f\n",t[i].GPA);
		}
	}
	else{
	printf("\n=====Top 3 highest GPA student=====");
	printf("\nStudent ID: %d ----- ",t[*n-1].ID);
	printf("Student name: %s ----- ", t[*n-1].name);
	printf("Student GPA: %.2f\n",t[*n-1].GPA);
	printf("\nStudent ID: %d ----- ",t[*n-2].ID);
	printf("Student name: %s ----- ",t[*n-2].name);
	printf("Student GPA: %.2f\n",t[*n-2].GPA);
	printf("\nStudent ID: %d ----- ",t[*n-3].ID);
	printf("Student name: %s ----- ", t[*n-3].name);
	printf("Student GPA: %.2f\n",t[*n-3].GPA);
	}
}

int Menu(){
	char choice;
	int num = 0;
	bool flag = false;
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
	
void Help(){
	printf("\n");
	printf("\n[1]: Input students information, need to declare number of student first.");
	printf("\n[2]: Print out student list to the screen");
	printf("\n[3]: Find student base on 2 information: Student's ID and Student's Name");
	printf("\n[4]: Sort the student list with the ascending order.");
	printf("\n[5]: Show information of top 3 student who have highest GPA!");
	printf("\n[0]: Exit this program");
	printf("\n[NOTE]: Function 2 -> 5: Need to Input student information first to be execute!");
}

void Addstd(student p[], int *n){
    int pos=*n, nID;
    float nGPA;
    char nname[50];
    printf("\n======Add a Student======");
    printf("\nInput new student's ID: ");
    scanf("%d", &nID);
    getchar();
    printf("\nInput new student's name: ");
    fgets(nname, sizeof(nname), stdin);
    printf("\nInput new student's GPA: ");
    scanf("%f", &nGPA);
    for(int i = *n; i > pos; i--){
        p[i] = p[i-1];
    }
   	p[pos].ID=nID;
   	strcpy(p[pos].name, nname);
   	p[pos].GPA=nGPA;
    ++*n;
    printf("\nStudent Added!");
}

int main(){
	student a[20];
	int n=0;
	int userchoice;
	do{
		userchoice=Menu();
		switch(userchoice){
			case 1: Inputstd(a,&n);
					break;
			case 2: if(n<=0){
				printf("\n**Please input Student List first!**\n");
				}
				else Outputstd(a,&n);
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
		fflush(stdin);
	}
	while (userchoice != 0);
	fflush(stdin);
	getchar();
	return 0;
}


