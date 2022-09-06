#include<stdio.h>
#include<math.h>

void square(int a[], int n, FILE *fpt);
void oddeven(int a[], int n, FILE *fpt);
void sortas(int a[], int n);
int mostFrequent(int *a, int n, FILE *fpt);
void output(int a[], int n, FILE * fpt);
 int main(){
 	int n;
	int a[50];
 	FILE * fp;
 	fp = fopen("As4in.txt", "r");
 	fscanf(fp, "%d", &n);
 	fseek(fp, 3, SEEK_SET);
 	for (int i=0; i<n; i++){
 		fscanf(fp, "%d", &a[i]);
	 }
	fclose(fp);

	FILE * fpt;
	fpt = fopen("As4out.txt", "w");
	square(a, n, fpt);
	fprintf(fpt,"\nThe most frequent element is: ");
	mostFrequent(a, n, fpt);
	oddeven(a, n, fpt);
	fprintf(fpt, "\nThe list after sorting: ");
	sortas(a, n);
	output(a, n, fpt);
	fclose(fpt);
	return 0;
 }
 
 void square(int a[], int n, FILE *fpt){
 	fprintf(fpt, "\nSquare numbers in the array: ");
 	float b[50];
 	int dem=0, ivar;
 	float fvar;
 	for(int i=0; i<n; i++){
 		b[i] = (float)a[i];
	 }
 	for (int i=0; i<n; i++){
 		fvar = sqrt(b[i]);
 		ivar = fvar;
 		if (fvar == ivar){
 			dem ++;
 			fprintf(fpt, "\n-Element index: %d", i);
		 }
	 }
	if (dem == 0){
		fprintf(fpt,"Not found!");
	} 
 }
 
 void oddeven(int a[], int n, FILE*fpt){
 	int odd=0, even = 0;
 	for(int i=0; i<n; i++){
 		if((a[i] % 2) == 0){
 			even ++;
		 }
		 else odd++;
	 }
	 fprintf(fpt,"\nThe amount of odd number is: %d", odd);
	 fprintf(fpt,"\nThe amount of even number is: %d", even);
 }
 
 void sortas(int a[], int n){
 	int t;
 	for (int i=0; i<n; i++){
 		for (int j=0; j<=i; j++){
 			if(a[j] > a[i]){
 				t = a[i];
 				a[i] = a[j];
 				a[j] = t;
			 }
		 }
	 }
 }
 
 int mostFrequent(int *a, int n, FILE * fpt) 
{ 
  	sortas(a,n);
    int max_count = 1, res = a[0], curr_count = 1; 
    for (int i = 1; i < n; i++) { 
        if (a[i] == a[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = a[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = a[n - 1]; 
    } 
  	fprintf(fpt,"%d",res);
    return res; 
}

void output(int a[], int n, FILE *fpt){
	for(int i=0; i<n; i++){
		fprintf(fpt, "%d ", a[i]);
	}
}
