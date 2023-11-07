#include<bits/stdc++.h>
using namespace std;

class Giaodich{
	private:
		string ngay;
		long long ma, tien;
	public:
		Giaodich(){
		}
		Giaodich(long long ma,string ngay, long long tien){
			this->ma=ma;
			this->ngay=ngay;
			this->tien=tien;
		}
		
		long long getmaa(){
			return ma;
		}
		string getngay(){
			return ngay;
		}
		
		long long gettien(){
			return tien;
		}
		void Nhap(){
			cout<<"\nNhap ma giao dich: ";cin>>ma;
			cout<<"Nhap ngay giao dich: "; cin.ignore();
			getline(cin,ngay);
			cout<<"Nhap so tien: "; cin>>tien;
		}
		void Hienthi(){
			cout<<"\n || Ma giao dich: "<<ma<<" || Ngay giao dich: "<<ngay<<" || So tien: "<<tien;
		}
};
class Ngoaite:public Giaodich{
	private:
		long long soluong,tygia;
		string loaitien;
	public:
		Ngoaite(){
		}
		
		Ngoaite(long long soluong, long long tygia, string loaitien){
			this->soluong=soluong;
			this->tygia=tygia;
			this->loaitien=loaitien;
		}
		long long getsoluong(){
			return soluong;
		}
		long long gettygia(){
			return tygia;
		}
		string getloaitien(){
			return loaitien;
		}
		
		bool operator == (Ngoaite a)
		{
			return (this->getloaitien() == a.getloaitien());
		}
		
		void NhapNT(){
			Nhap();
			cout<<"Nhap so luong: "; cin>>soluong;
			cout<<"Nhap ty gia: "; cin>>tygia;
			cout<<"Nhap loai tien: "; cin.ignore();
			getline(cin,loaitien);
		}
		//thanh tien = soluong * tygia
		
		long long setThanhtien(){
			long long tt=0;
			tt=soluong * tygia;
			return tt;
		}
		
		void HienthiNT(){
			Hienthi();
			cout<<" || So luong: "<<soluong<<" || Ty gia: "<<tygia<<" || Loai tien: "<<loaitien<<" || Thanh tien: "<<setThanhtien();
		}
		
};

class Quanly{
	private:
		Ngoaite a[50];
		int n;
	public:
		void QlNhap(){
			do{
				cout<<"\nNhap so luong: "; cin>>n;
			}while(n>50);
			
			for(int i=0;i<n;i++)
				a[i].NhapNT();			
		}
		
		void Sum(){
			cout<<"\n\n----- Tong So Tien Giao Dich Cua Tung Loai Tien -----\n";
			long long sum=0;
			string lt=a[0].getloaitien();
			for(int i=0;i<n-1;i++)
				for(int j=i+1;j<n;j++)
					if(a[i].getloaitien() > a[j].getloaitien())
						swap(a[i],a[j]);
			
			for(int i=0;i<n;i++){
				if(a[i].getloaitien() == lt)
					a[i].HienthiNT();
				else{
					lt=a[i].getloaitien();
					a[i].HienthiNT();
				}
			}
					
				
						
		}
		
		void Giaodich1ty(){
			cout<<"\n\n------ Giao dich co so tien tren 1 ty -----\n";
			for(int i=0;i<n;i++)
				if(a[i].setThanhtien() >= 1000000000)
					a[i].HienthiNT();
					
		}
		
		void Sapxep(){
			cout<<"\n\n---- Danh sach giam dan theo Thanh Tien ----\n";
			for(int i=0;i<n-1;i++)
				for(int j=i+1;j<n;j++)
					if(a[i].setThanhtien() < a[j].setThanhtien())
						swap(a[i],a[j]);
			for(int i=0;i<n;i++)
				a[i].HienthiNT();
		}
};

int main()
{
	Quanly ql;
	ql.QlNhap();
	ql.Sum();
	ql.Giaodich1ty();
	ql.Sapxep();
}















