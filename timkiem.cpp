#include<stdio.h>
#include<stdio.h>
#include<math.h>
void nhapmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("\na[%d]=",i);
		scanf("%d", &a[i]);
	}
}
void xuatmang(int a[], int n){
	for(int i=0; i<n; i++){
		printf("\t%d",a[i]);
	}
}
int timtuantu(int a[], int n, int x){
	int i=0;
	while(i<n && a[i]!=x) i++;
	if(i==n) return -1;
	else return i;

}

int hoanvi(int &a, int &b){
	int tam=a;
	a=b;
	b=tam;
}

int sapxep(int a[], int n){
	for(int i=0; i<n-1; i++){
		int min =i;
		for(int j=i+1; j<n; j++){
			if(a[j]<a[min])
			min=j;
		}
		hoanvi(a[min],a[i]);
	}
}

int timnhiphan(int a[], int n, int x)
{
	int l=0,  r=n-1;
	int mid;
	do{
		mid= (l+r)/2;
		if(x==a[mid]) return mid;
		else if(x<mid) r= mid-1;
		else l= mid+1;
	}while(l<=r);
	return -1;
}

int dem_xuat_hien_duyet_tuan_tu(int a[], int n, int x){
	int i=0;
	int dem=0;
	while(i<n ){
		if(a[i]==x){
			dem++; 	
		}
		i++;
	}
	if(dem!=0) return dem;
	return -1;

}

int dem_xuat_hien_duyet_nhi_phan(int a[], int n, int x){
	sapxep(a,n);
	xuatmang(a,n);
	int l=0, r=n-1;
	int mid;
	int dem=0;
	do{
		mid=(l+r)/2;
		if(x==a[mid]){
			dem++;
			for(int i=mid; i<n; i--){
				if(a[i]==a[mid])
				dem++;
			}
			for(int i=mid; i<n; i++){
				if(a[i]==a[mid])
				dem++;
			}
		}
		else if(x<mid) r= mid-1;
		else l= mid+1;	
	}while(l<=r);
	return -1;
	
}

int main()
{
	int a[50], n, x;
	printf("Nhap so phan tu cua mang(n<=50): "); scanf("%d",&n);
	nhapmang(a,n);
	printf("\nMang sau khi nhap: ");
	xuatmang(a,n);
	//tim kiem tuyen tinh
//	printf("\nNhap gia tri x can tim: "); scanf("%d",&x);
//	int val=timtuantu(a,n,x);
//	if(val!=-1){
//		printf("\nx xuat hien o vi tri a[%d]", val);
//	}
//	else printf("\Khong tim thay x trong mang");
	
	//tim kiem nhi phan
//	sapxep(a,n);
//	printf("\nMang sau khi sap xep theo thu tu tu be den lon: ");
//	xuatmang(a,n);
//	printf("\nNhap gia tri x can tim: "); scanf("%d",&x);
//	int tam=timtuantu(a,n,x);
//	if(tam!=-1){
//		printf("\nx xuat hien o vi tri a[%d]", tam);
//	}
//	else printf("\nKhong tim thay x trong mang");

    //dem so lan xuat hien duyet tuan tu
//    printf("\nNhap phan tu can dem tan xuat: "); scanf("%d",&x);
//    int dem=dem_xuat_hien(a,n,x);
//    if(dem!=-1){
//		printf("\nx xuat hien %d lan", dem);
//	}
//	else printf("\nKhong tim thay x trong mang");
	
	//dem so lan xuat hien duyet nhi phan
	printf("\nNhap phan tu can dem tan xuat: "); scanf("%d",&x);
	int dem=dem_xuat_hien_duyet_nhi_phan(a,n,x);
	if(dem!=-1){
		printf("\nx xuat hien %d lan", dem);
	}
	else printf("\nKhong tim thay x trong mang");
}
