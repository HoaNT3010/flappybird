#include<stdio.h>

int spt;

int Nhapmang(int mang[]){
	int n;
	printf("Nhap so phan tu trong mang: ");
	scanf("%d", &n);
	spt=n;
	for (int i=0; i<n; i++){
		printf("\nNhap gia tri cho phan tu a[%d] cua mang: ", i);
	scanf("%d",&mang[i]);
	}
}

int Xuatmang(int mang[]){
	int n;
	printf("\nMang co cac gia tri la: ");
	for(int i=0; i<n; i++){
		printf("%d ",mang[i]);
	}
}

int Timkiem(int mang[]){
	printf("\nNhap mot so can tim trong mang: ");
	int num;
	scanf("%d", &num);
	int dem=0;
	for(int i=0; i<spt; i++){
		if (mang[i]==num){
			dem++;
		}
	}
	if(dem != 0){
		printf("\nso %d co trong mang", num);
	}
	else {
		printf("\nSo %d khong co trong mang", num);
	}
}




void Themphantu(int a[], int n){
	int val,pos;
	printf("Nhap gia tri can them vao mang:");
	scanf("%d", &val);
	printf("Nhap vi tri can chen: ");
	scanf("%d", &pos);
    // Mang da day, khong the them.
    if(n >= MAX){
        return;
    }
    // Neu pos <= 0 => Them vao dau
    if(pos < 0){
        pos = 0;
    }
    // Neu pos >= n => Them vao cuoi
    else if(pos > n){
        pos = n;
    }
    // Dich chuyen mang de tao o trong truoc khi them.
    for(int i = n; i > pos; i--){
        a[i] = a[i-1];
    }
    // Chen val tai pos
    a[pos] = val;
    // Tang so luong phan tu sau khi chen.
    ++n;
    printf("Mang sau khi da chen them mot phan tu: ");
    for (int i=0; i<n; i++){
    	printf("%d ",a[i]);
	}
}


	
}
int main(){
int n;
int a1[n];
Nhapmang(a1);
Xuatmang(a1);
Timkiem(a1);
}


