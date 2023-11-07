#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for (int i = a ; i <= b ;i++)
class Khachhang{
	private:
		string maso;
		string hoten;
		string diachi;
		int smtt;
		int ngay,thang,nam;
	public:
		void nhap(){
			while (1){
				cin.ignore();
				cout<<"Nhap ma so: "; getline(cin,maso);
				cout<<"Nhap ho ten: "; getline(cin,hoten);
				cout<<"Nhap dia chi: "; getline(cin,diachi);
				cout<<"Nhap so m tieu thu: "; cin>>smtt;
				cout<<"Nhap ngay thang nam: "; cin>>ngay>>thang>>nam;
				if (hople()) break;
				cout<<"Thong tin khach hang khong hop le vui long nhap lai\n";
			}
		}
		bool hople(){
			int A[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}; 
			if ( nam % 400 == 0 || nam % 4 == 0 && nam % 100 != 0) A[2] = 29;
			if (min(ngay,thang) <= 0|| min(smtt,nam) < 0 || ngay > A[thang] || thang > 12) return false;
			return true;
		}
		int sotienphaitra(){
			return smtt * dongia();
		}
		friend bool sosanhngay(Khachhang a,Khachhang b){
			return  ( (a.nam > b.nam ) || ( (a. nam == b.nam) && (a.thang > b.thang) ) ||
			( (a. nam == b.nam) && (a.thang == b.thang) && ( a.ngay > b.ngay) ) );
		}
		int dongia(){
			if (smtt <= 100) return 2000;
			else if (smtt <= 200) return 3000;
			else return 5000;
		}
		void xuat(){
			cout<<"Nhap ma so: "<<maso<<"\n";
			cout<<"Nhap ho ten: "<<hoten<<"\n";
			cout<<"Nhap dia chi: "<<diachi<<"\n";
			cout<<"Nhap so m tieu thu: "<<smtt<<"\n";
			cout<<"Nhap ngay thang nam: "<<ngay<<"/"<<thang<<"/"<<nam<<"\n";
			cout<<"So tien phai tra: "<<sotienphaitra()<<endl;
		}
}; 
class Quanly{
	private:
		int n;
		Khachhang A[101];
		map <string,bool> mp;
	public :
		void nhap(){
			cout<<"Nhap so khach hang can quan ly: ";
			cin>>n;
			fr (i,1,n){
				A[i].nhap();
			}
		}
		void xuat(){
			fr (i,1,n) A[i].xuat();
		}
		void xuatkhln(){
			int ln = 0;
			fr (i,1,n){
				ln = max(ln , A[i].sotienphaitra());
			}
			fr (i,1,n){
				if (ln == A[i].sotienphaitra()) A[i].xuat();
			}
		}
		void sapxep(){
			fr (i,1,n){
				fr(j,i,n){
					if (sosanhngay(A[i],A[j]) ) swap(A[i],A[j]);
				}
			}
		}
};
int main(){
	Quanly A;
	A.nhap();
	A.sapxep();
	A.xuatkhln();
	cout<<"_____sau khi sap xep____________";
	A.xuat();
	
}
