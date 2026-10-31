#include <stdio.h>
#include <string.h>

typedef struct{
	int maHang;
	char tenHang[50];
	int soLuong;
	float donGia;
}CuaHang;

int index(CuaHang ds[], int n, int ma){
	for(int i = 0; i<n; i++){
		if (ds[i].maHang == ma){
			return i;
		}
	}
	return -1;
};



float thanhTien(int soLuong, float donGia){
	return soLuong*donGia;
};

void tieuDe(){
	printf("%-10s %-25s %-10s %-10s %-12s","Ma","Ten mat hang", "So luong", "Don gia", "Thanh Tien");
}

void inDuLieu(CuaHang ch){
	printf("%-10s %-25s %-10s %-10s",ch.maHang,ch.tenHang,ch.soLuong,ch.donGia,thanhTien(ch.soLuong,ch.donGia));
}

int ThemHang(CuaHang ds[],int n){
	if(n==50){
		printf("Danh sach da day!");
		return n;
	}
	
	int ma;
	printf("Nhap ma mat hang muon them: ");
	scanf("%d",&ma);
	
	if(index(ds,n,ma)!=-1){
		printf("Ma mat hang da ton tai!");
		return n;
	}
	
	CuaHang hangmoi;
	hangmoi.maHang = ma;
	
	printf("Nhap ten mat hang muon them: ");
	fgets(hangmoi.tenHang,sizeof(hangmoi.tenHang),stdin);
	
	printf("Nhap so luong: ");
	scanf("%d",&hangmoi.soLuong);
	while(hangmoi.maHang<0 ){
		printf("So luong khong hop le");
		scanf("%d",&hangmoi.soLuong);
	}
	
	printf("Nhap don gia: ");
	scanf("%d",&hangmoi.donGia);
	while(hangmoi.maHang<=0 ){
		printf("So luong khong hop le");
		scanf("%d",&hangmoi.soLuong);
	}
	
	ds[n] = hangmoi;
	n++;
	
	printf("Them mat hang thanh cong!");
	return n;
};

void hienThi(CuaHang ds[],int n){
	if(n==0){
		printf("Danh sach rong!");
		return;
	} 
	
	tieuDe();
	for(int i=0; i<n; i++){
		inDuLieu(ds[i]);
	}
}

void capNhat(CuaHang ds[], int n){
	if(n==0){
		printf("Danh sach rong!");
		return;
	}
	
	int ma;
	printf("Nhap ma mat hang muon cap nhat: ");
	scanf("%d",&ma);
	
	int pos = index(ds,n,ma);
	if(pos == -1){
		printf("Không tim thay mat hang do");
		return;
	}
	
	printf("Nhap ten mat hang muon cap nhat: ");
	fgets(ds[pos].tenHang,sizeof(ds[pos].tenHang),stdin);
	
	printf("Nhap so luong: ");
	scanf("%d",&ds[pos].soLuong);
	while(ds[pos].maHang<0 ){
		printf("So luong khong hop le");
		scanf("%d",&ds[pos].soLuong);
	}
	
	printf("Nhap don gia: ");
	scanf("%d",&ds[pos].donGia);
	while(ds[pos].maHang<=0 ){
		printf("So luong khong hop le");
		scanf("%d",&ds[pos].soLuong);
	}
	
	for(int i = pos; i<n-1; i++){
		ds[i]=ds[i+1];
	}
	
	printf("Cap nhat thanh cong");
}

int xoaHang(CuaHang ds[], int n){
	if(n==0){
		printf("Danh sach rong!");
		return n;
	}
	int ma;
	printf("Nhap ma mat hang muon xoa: ");
	scanf("%d",&ma);
	
	int pos = index(ds,n,ma);
	if(pos != -1){
		printf("Không tim thay mat hang do");
		return n;
	}
	
	for(int i = index; i<n-1; i--){
		ds[i]=ds[i-1];
	}
	n--;
	printf("Xoa thanh cong")
	
}




int main(){
	CuaHang ds[50];
	int n = 0;
	int choice;
	do{
		printf("==== QUAN LY MAT HANG ====\n");
		printf("1. Them mat hang\n");
		printf("2. Hien thi danh sach mat hang\n");
		printf("3. Cap nhat mat hang theo ma\n");
		printf("4. Xoa mat hang theo ma\n");
		printf("5. Tim mat hang theo ten\n");
		printf("6. Thong ke kho hang\n");
		printf("0. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d",&choice );
		
		switch(choice){
			case 1:
				n = ThemHang(ds,n);
				break;
			case 2:
				hienThi(ds,n);
				break;
			case 3:
				capNhat(ds,n);
				break;
			case 4:
				n = xoaHang(ds,n);
				break;
			case 5:
				break;
			case 6:
				break;
			case 0: 
				printf("Tam biet!");
				break;
			default:
				printf("Lua chon khong phu hop. Vui long chon lai(0-6)!");
				break;
		}
	}while(choice !=0);
}
