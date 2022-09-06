#include<stdio.h>
#include<conio.h>
void nhapmang(int a[],int n)
{
int i;
for(i=0;i<n;i++)
{ printf("nhap vao phan tu thu %d ",i+1);
scanf("%d",&a[i]);
}
}
void xuatmang(int a[],int n)
{
int i;
for(i=0;i<n;i++)
printf("%d ",a[i]);
}

	int ktra(int b[],int t,int k)    //ki?m tra xem ph?n t? k dã du?c ki?m tra chua
{ int boo=0;
for(int i=0;i<t;i++)
 if(b[i]==k) {boo =1; break;}
return boo;
}

	void giongnhau(int a[],int n)
{
printf("\n") ;
int i,j,b[50],t=0;
for(i=0;i<n-1;i++)
  {
    if(ktra(b,t,a[i])==1) continue;  //n?u ph?n t? a[i] dã là ph?n t? th?a mãn dk thu?c m?ng ch? g?m các ph?n t? gi?ng //nhau thì b? qua
    else
    {
      int dem=0;
      for(j=i+1;j<n;j++)
         if(a[i]==a[j]) dem++;  //d?m sô ph?n t? a[i] trong m?ng
      if(dem!=0)
      {
         while(dem!=-1) {printf("%d",a[i]); dem--;}  //in các ph?n t? gi?ng nhau
         printf("\n") ;
         b[t]=a[i];  //thêm a[i] vào m?ng ch?a các ph?n t? gi?ng nhau
         t++;
      }
    }
  }
}

int main()
{ int a[50];
int n;
printf("nhap vao n = ");
scanf("%d",&n);
nhapmang(a,n);
xuatmang(a,n);
giongnhau(a,n);
getch();
} 
