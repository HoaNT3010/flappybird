#include<stdio.h>

struct student 
{
	int ID;
	float marks;
};
//student <-> int, char, float

void InputOneStd (struct student *);
void OutputOnestd (struct student);
void InputList (struct student *, int *);
void OutputList (struct student *, int );

int main ()
{
	student a[10];
	int n;
	InputList (a,&n);
	OutputList (a,n);
}

void InputOneStd (struct student &p)
{
	printf("\nInput student ID: ");
	scanf("%d",&p.ID);
	printf("\nInput student's marks: ");
	scanf("%f",&p.marks);
	
}


void InputList(struct student *p, int *n)
{
	printf("Input the number of student: ");
	scanf("%d",n);
	for (int i=0; i<*n; i++)
	{
		printf("\nInput data for student %d: ", i);
		InputOneStd(p[i]);
	}
}

void OutputOnestd (struct student p)
{
	printf("%d has %.1f mark!\n",p.ID,p.marks);
}

void OutputList (struct student *p, int m)
{
	for (int i = 0; i<m; i++)
	{
		OutputOnestd(p[i]);
	}
}
