//21T1020818 - Hoang Thanh Tung
#include<iostream>
#include<string.h>
using namespace std;
class Canbo{
	private:
		string Macanbo, Hoten;
		int ngay, thang, nam; // ngay vao co quan
	public:
		Canbo();
		Canbo(string Macanbo, string Hoten, int ngay, int thang, int nam);
		string get_Macanbo(){
			return Macanbo;
		}
		string get_Hoten(){
			return Hoten;
		}
		int get_ngay(){
			return ngay;
		}
		int get_thang(){
			return thang;
		}
		int get_nam(){
			return nam;
		}
		void nhap();
		void xuat();
		bool operator >(Canbo Testers);
};
Canbo::Canbo(){
	this->Macanbo = this->Hoten = " ";
	this->ngay = this->thang = this->nam = 0;
}
Canbo::Canbo(string Macanbo, string Hoten, int ngay, int thang, int nam){
	this->Macanbo = Macanbo;
	this->Hoten = Hoten;
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}
void Canbo::nhap(){
	fflush(stdin);
	cout<<"Nhap ma can bo: ";
	getline(cin,Macanbo);
	fflush(stdin);
	cout<<"Nhap ho ten: ";
	getline(cin,Hoten);
	fflush(stdin);
	cout<<"Nhap ngay vao co quan: "; cin>>ngay>>thang>>nam;
}
void Canbo::xuat(){
	cout<<"\n----------------------------------------";
	cout<<"\nMa can bo: " << Macanbo
	<<"\nHo ten: " << Hoten
	<<"\nNgay vao co quan " << ngay << "/" << thang << "/" << nam;
}
bool Canbo::operator >(Canbo Testers){
	if(nam > Testers.nam) return true;
	if((nam == Testers.nam) && (thang > Testers.thang)) return true;
	if((nam == Testers.nam) && (thang == Testers.thang) && (ngay > Testers.ngay)) return true;
	return false;
}
class Giangvien : public Canbo{
	private:
		string Donvi;
		float HeSoLuong;
		float PhuCapChucVu;
		long Luong;
	public:
		Giangvien();
		Giangvien(string Donvi,float HeSoLuong, float PhuCapChucVu);
		void nhap();
		string get_Donvi(){
			return Donvi;
		}
		float get_HeSoLuong(){
			return HeSoLuong;
		}
		float get_PhuCapChucVu(){
			return PhuCapChucVu;
		}
		void HienThi();
		long get_Luong(){
			long Luong = HeSoLuong * 1490000 + PhuCapChucVu;
			return Luong;
		}
};
Giangvien::Giangvien(){
	this->Donvi = "";
	this->HeSoLuong = 0;
	this->PhuCapChucVu = 0;
}
Giangvien::Giangvien(string Donvi,float HeSoLuong, float PhuCapChucVu){
	this->Donvi = Donvi;
	this->HeSoLuong = HeSoLuong;
	this->PhuCapChucVu = PhuCapChucVu;
}
void Giangvien::nhap(){
	Canbo::nhap();
	fflush(stdin);
	cout<<"Nhap Don vi cua giang vien: "; 
	getline(cin,Donvi);
	fflush(stdin);
	cout<<"Nhap He So Luong cua giang vien: "; cin >> HeSoLuong;
	cout<<"Nhap phu cap chuc vu cua giang vien: "; cin >> PhuCapChucVu;
}
void Giangvien::HienThi(){
	long Luong = HeSoLuong * 1490000 + PhuCapChucVu;
	Canbo::xuat();
	cout<<"\nDon vi: " << Donvi
	<<"\nHe So Luong: " << HeSoLuong
	<<"\nPhu Cap Chuc Vu: " << PhuCapChucVu
	<<"\nTien Luong: " << Luong;
}
class NhapGiangVien{
	private:
		int n;
		Giangvien GV[50];
	public:
		void nhap();
		void sapxep();
		void LuongTB();
		void InBangLuong();
};
void NhapGiangVien::nhap(){
	cout<<"Nhap so luong giang vien: ";
	do{
		cin>>n;
	}while(n>50);
	for(int i=0;i<n;i++){
		GV[i].nhap();
	}
}
void NhapGiangVien::sapxep(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(GV[i] > GV[j]){
				swap(GV[i],GV[j]);
			}
		}
	}
	cout<<"Danh sach sau khi sap xep: ";
	for(int i=0;i<n;i++){
		GV[i].HienThi();
	}
}
void NhapGiangVien::LuongTB(){
	long TrungBinh = 0;
	for(int i=0;i<n;i++){
		TrungBinh += GV[i].get_Luong();
		cout<<"\nLuong trung binh cua cac giang vien: " << TrungBinh/n << endl;
	}
}
void NhapGiangVien::InBangLuong(){
	 for (int i=0;i<n;i++)
		for (int j=i+1;j<n;j++)
			if (GV[i].get_Donvi()>GV[j].get_Donvi()){
				swap(GV[i],GV[j]);
			}
	string DV;
	DV=GV[0].get_Donvi();
	cout<<"\nBang Luong Cua Giang Vien Theo Don Vi:  "<<DV;
	for (int i=0;i<n;i++){
	if (GV[i].get_Donvi() == DV){
		GV[i].HienThi();
	}
	else{
	DV = GV[i].get_Donvi();
	cout<<"\nBang Luong Cua Giang Vien Theo Don Vi: "<<DV;
	GV[i].HienThi();
	}
	}
}
int main(){
	NhapGiangVien GV;
	GV.nhap();
	GV.sapxep();
	GV.LuongTB();
	GV.InBangLuong();
	return 0;
}
