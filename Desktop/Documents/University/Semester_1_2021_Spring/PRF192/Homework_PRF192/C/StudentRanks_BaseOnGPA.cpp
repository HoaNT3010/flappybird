#include<stdio.h>
int main(){
	float dtb;
	printf ("Enter your GPA: ");
	scanf ("%f",&dtb);
	if(dtb>=8.0) printf("EX");
		else
			if(dtb>=7.0) printf("Good");
				else
					if(dtb>=5.0) printf("Average");
					else 
						if(dtb<5.0) printf("BA");
					
}
