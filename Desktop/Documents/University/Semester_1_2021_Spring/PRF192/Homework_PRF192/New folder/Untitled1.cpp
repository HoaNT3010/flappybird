#include<stdio.h>
struct student{
	char s[100];
	int ID;
};

int main(){
	int n;
	student s[n];
	
}

void inputlist(struct student p)

void inputonestd(struct student &p){
	printf("\nEnter student name: ");
	gets(&p.s);
	printf("\nEnter student ID: ");
	scanf("%d",&p.ID);
}


