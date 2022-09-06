/*Excercise 1:
	Input: 347
	Output: So chu so: 3
			Hang tram: 3
			Hang chuc: 4
			Hang don vi: 7
*/
#include<stdio.h>
int main(){
	int n;
	printf("Please enter an int number: ");
	scanf("%d", &n);
	int count=0;
	for (int i=1; i<=n; i*=10){
		if(n/i>0){
			count++;
		}
	}
	printf("So chu so: %d\n",count);
	int a1,a2,a3,a4,a5,b1,b2,b3,b4;
	a1=n/10000;
	b1=n%10000;
	a2=b1/1000;
	b2=b1%1000;
	a3=b2/100;
	b3=b2%100;
	a4=b3/10;
	b4=b3%10;
	a5=b4/1;
	printf("Hang chuc nghin: %d\n",a1);
	printf("Hang nghin: %d\n",a2);
	printf("Hang tram: %d\n",a3);
	printf("hang chuc: %d\n",a4);
	printf("hang don vi: %d",a5);
}
