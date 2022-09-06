/*Tim kiem phan tu trong mang*/

#include<stdio.h>
int main(){
	int n,x,i,z;
	printf("Enter the total element of array: ");
	scanf("%d",&n);
	int a[n];
	printf("Enter numbers of array: ");
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	printf("Enter the value you want to find: ");
	scanf("%d",&x);
	int dem=0;
	for(i=0; i<n; i++){
		if(a[i]==x){
			z=i;
			dem++;
			break;
		}
	}
	if(dem==1){
		printf("%d first appear at the position %d in the array\n",x,z+1);
		printf("x appear at the position(s): ");
		for(i=0; i<n; i++){
			if(a[i]==x){
				printf("%d ",i+1);
			}
		}
	}
	else{
		printf("%d is not in array",x);
	}
}
