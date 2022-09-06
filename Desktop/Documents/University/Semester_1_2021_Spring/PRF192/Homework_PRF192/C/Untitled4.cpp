#include <stdio.h>
int main(){
int a,b;
printf ("Enter two numbers");
scanf ("%d%d", &a, &b);
fflush(stdin);
char c;
printf("Enter an operator");
scanf("%c", &c);
printf ("%d %d %c", a, b, c);
}
