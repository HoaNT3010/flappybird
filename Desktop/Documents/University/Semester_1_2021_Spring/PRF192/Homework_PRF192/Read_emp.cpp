#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
struct EM{
	char id[50], name[50];
	float slvl;
};

int main(){
	EM a[3];
	FILE * fp;
	fp = fopen("emp.txt", "r");
	fseek(fp, 26, SEEK_SET);
	for (int i=0; i<3; i++){
		fscanf(fp, "%s	%s	%f",&a[i].id, &a[i].name, &a[i].slvl);
	}
	fclose(fp);
	for(int i=0; i<3; i++){
		printf("\n%s	%s	%.1f",a[i].id, a[i].name, a[i].slvl);
	}
	return 0;
}
