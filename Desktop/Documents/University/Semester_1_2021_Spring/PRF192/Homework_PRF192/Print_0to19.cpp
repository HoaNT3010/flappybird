/*print out 0 to 19*/

#include<stdio.h>
int main(){
	 for (int i=0;i<=9;i++){
	 	printf("%d   ",i);
	 	if(i==9){
	 		printf("\n");
		 }
	 }
	 for(int i=10; i<=19; i++){
	 	printf("%d  ",i);
	 }
}
