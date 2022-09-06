#include<stdio.h>
const int MAX=100;

void Nhapmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("\nXin moi nhap gia tri cho phan tu thu a[%d]: ",i);
		scanf("%d", &a[i]);
	}
}

void Xuatmang(int a[], int n){
	printf("\nCac phan tu trong mang: ");
	for (int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
}

void Timkiem(int a[],int n){
	printf("\nXin moi nhap mot so can tim trong mang: ");
	int num;
	scanf("%d", &num);
	int dem=0;
	for(int i=0; i<n; i++){
		if (a[i]==num){
			dem++;
		}
	}
	if(dem != 0){
		printf("\nSo %d co trong mang", num);
	}
	else {
		printf("\nSo %d khong co trong mang", num);
	}
}

void Themphantu(int a[], int n){
	int giatri,vitri;
	printf("\nNhap gia tri can them vao mang:");
	scanf("%d", &giatri);
	printf("Nhap vi tri can chen: ");
	scanf("%d", &vitri);
    if(n >= MAX){
        return;
    }
    if(vitri < 0){
        vitri = 0;
    }
    else if(vitri > n){
        vitri = n;
    }
    for(int i = n; i > vitri; i--){
        a[i] = a[i-1];
    }
    a[vitri] = giatri;
    ++n;
    printf("Mang sau khi da chen them mot phan tu: ");
    for (int i=0; i<n; i++){
    	printf("%d ",a[i]);
	}
}

int menu(){
	int choice;
	printf("\n======MENU======");
	printf("\n===1: Xuat mang===");
	printf("\n===2: Tim kiem");
	printf("\n===3: Them mot phan tu vao mang===");
	printf("\n===Khac: Thoat===");
	printf("\n   Xin Moi Nguoi Dung Chon: ");
	scanf("%d", &choice);
	return choice;
}

int main(){
	int n;
	int mang[n];
	printf("Xin moi nhap so luong phan tu trong mang: ");
	scanf("%d", &n);
	Nhapmang(mang,n);
	int userchoice;
	do{
		printf("\n");
		userchoice=menu();
		switch (userchoice)
		{
			case 1: Xuatmang(mang,n);
			break;
			case 2: Timkiem(mang,n);
			break;
			case 3: Themphantu(mang,n);
			break;
			default: printf("Tam Biet");
		}
	}
	while (userchoice>=1 && userchoice<4);
}

