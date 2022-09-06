/*Nhap vao diem trung binh va xep hang hoc tap theo diem trung binh do*/
/*Input a GPA and put it into the level as follows:
"Ex, Good, Ave, BA*/
#include<stdio.h>
int main(){
	float dtb;
	printf("Please enter GPA: ");
	scanf("%f",&dtb);
	if(dtb>=8.0) printf("Ex");
	else if(dtb>=7.0) printf("Good");
	else if(dtb>=5.0) printf("Ave");
	else if(dtb<5.0) printf("BA");
}
