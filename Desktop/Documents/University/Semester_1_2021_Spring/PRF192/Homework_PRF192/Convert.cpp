#include<stdio.h>
#include<string.h>
int main(){
	char str[50] = "a";
	int num, len;
	len = strlen(str);
	for (int i=0; i<len; i++){
		num = num*10 + (str[i] - '0');
	}
	printf ("%d", num);
	return 0;
}
