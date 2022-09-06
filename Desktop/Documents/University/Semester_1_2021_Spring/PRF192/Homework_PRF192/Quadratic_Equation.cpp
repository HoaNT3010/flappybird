/*nhap va tim nghiem cua phuong trinh bac 2*/


#include<stdio.h>
#include<math.h>
int main(){
	double a,b,c;
	double delta,x1,x2;
	printf("Enter a, b, c: ");
	scanf("%lf %lf %lf",&a,&b,&c);
	if (a==0){
		printf("Incorrect constant");
	}
	delta=(b*b)-(4*a*c);
	if (delta<0){
		printf("The equation has no root");
	}
		else if(delta==0){
			printf("The equation has two identical roots: ");
			x1=(double) (-b)/(2*a);
			printf("x1=x2=%lf",x1);
		}
			else if(delta>0){
					printf("The equation has two roots:\n");
			x1=(double) ((-b+sqrt(delta))/(2*a));
			x2=(double) ((-b-sqrt(delta))/(2*a));
			printf("x1= %lf\n",x1);
			printf("x2= %lf",x2);
			}
}
