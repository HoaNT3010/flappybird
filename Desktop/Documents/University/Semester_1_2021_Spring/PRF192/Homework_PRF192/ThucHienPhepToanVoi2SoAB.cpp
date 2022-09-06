/*Bai tap: nhap vao 2 so nguyen va nhap vao 1 trong 4 phep thoan co ban. ket qua se hien thi ket qua cua 2 so nguyen voi phep toan tuong ung*/
/*Input two int numbers, enter an operator and then show the coresponding result to the operator*/
/*char: kieu ky tu.  scanf("%c", c)   printf("%c", c)*/
#include <stdio.h>
int main(){
	int a, b;
	char c;
	printf ("Nhap so nguyen a: ");
	scanf ("%d", &a);
	printf ("Nhap so nguyen b: ");
	scanf ("%d", &b);
	fflush(stdin);
	printf ("Nhap phep toan can thuc hien: ");
	scanf ("%c", &c);
	int result;
	/*khai bao cac truong hop cua c*/
	switch(c){
		case '+':
			result=a+b;
			printf("Ket qua cua phep toan a+b bang %d", result);
			break;
		case '-':
			result=a-b;
			printf("Ket qua cua phep toan a-b bang %d", result);
			break;
		case '*':
			result=a*b;
			printf("Ket qua cua phep toan a*b bang %d", result);
			break;
		case '/':  //sua lai ko cho nguoi dung nhap thuong bang 0
			if(b==0){
				printf("So khong hop le");
				break;
			}
			
			else{
			result=a/b;
			printf("Ket qua cua phep toan a/b bang %d", result);
			break;
		}
		default :
			printf("Phep toan khong hop le");
			break;	
	}
}
