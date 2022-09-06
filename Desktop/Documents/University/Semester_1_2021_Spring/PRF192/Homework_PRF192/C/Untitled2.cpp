//Giai phuong trinh bac 2 su dung ham

#include<stdio.h>
#include<math.h>

int a,b,c,delta;
double x,y;

void nhap_abc(int a1, int b1, int c1){
	printf("Nhap ba so a, b, c: ");
	scanf("%d %d %d",&a1, &b1, &c1);
	a=a1; b=b1; c=c1;
}

void tinh_delta(int a1, int b1, int c1, int delta1){
	delta1= (b1*b1)-4*a1*c1;
	delta=delta1;
	printf("Phuong trinh co delta la: %d\n", delta1);
}


void nghiem_pt(int a1,int b1,int c1,int delta1){
	double x1, y1;
	if(delta1<0){
		printf("PT vo nghiem");
	}
	else if(delta1==0){
		printf("PT co nghiem kep x1=x2=");
		x1= (-b1)/(2*a1);
		printf("%lf", x1);
	}
	else if(delta>0){
					printf("Phuong trinh co 2 nghiem:\n");
			x1=(double) ((-b+sqrt(delta))/(2*a));
			y1=(double) ((-b-sqrt(delta))/(2*a));
			printf("x1= %lf\n",x1);
			printf("x2= %lf",y1);
			}
}

int main(){
	nhap_abc(a,b,c);
	tinh_delta(a,b,c,delta);
	nghiem_pt(a,b,c,delta);
}


