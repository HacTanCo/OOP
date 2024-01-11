#include<bits/stdc++.h>
using namespace std;
class Sach
{
	private:
		string ts,tg;
		int st,gb;
	public:
		void fill()
		{
			cout<<"\nNhap ten sach: ";getline(cin,ts);
			cout<<"Nhap tac gia: ";getline(cin,tg);
			cout<<"Nhap so trang: ";cin>>st;
			cout<<"Nhap gia ban: ";cin>>gb;fflush(stdin);
		}
		void show()
		{
			cout<<"Ten sach: "<<ts<<endl;
			cout<<"Tac gia: "<<tg<<endl;
			cout<<"So trang: "<<st<<endl;
			cout<<"Gia ban: "<<gb<<endl;
		}
};
class Bia : public Sach
{
	private:
		string mha;
		int tv;
	public:
		void fill()
		{
			Sach::fill();
			cout<<"Nhap ma hinh anh: ";getline(cin,mha);
			cout<<"Nhap tien ve: ";cin>>tv;fflush(stdin);
		}
		void show()
		{
			Sach::show();
			cout<<"Ma hinh anh: "<<mha<<endl;
			cout<<"Tien ve: "<<tv<<endl;
		}
};
class Hoasy 
{
	private:
		string ht,dc;
	public:
		void fill_hs()
		{
			cout<<"Nhap ho ten cua hoa sy: ";getline(cin,ht);
			cout<<"Nhap dia chi cua hoa sy: ";getline(cin,dc);
		}
		void show_hs()
		{
			cout<<"Ho ten cua hoa sy: "<<ht<<endl;
			cout<<"Dia chi cua hoa sy: "<<dc<<endl;
		}
};
class Sachvebia : public Bia,public Hoasy
{
	public:
		void fill()
		{
			Bia::fill();
			fill_hs();
		}
		void show()
		{
			Bia::show();
			show_hs();
		}
};
class Quanly
{
	private:
		int n,m;
		Sach a1[100];
		Sachvebia a2[100];
	public:
		void fillandshow()
		{
			cout<<"\nNhap so luong sach khong bia: ";cin>>n;cin.ignore();
			while(n<=0 or n>100)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();
			}
			for(int i=0;i<n;i++)
			{
				a1[i].fill();
			}
			cout<<"\nDanh sach khong bia !!!\n";
			for(int i=0;i<n;i++)
			{
				a1[i].show();
			}
			cout<<"\nNhap so luong sach co bia: ";cin>>m;cin.ignore();
			while(m<=0 or m>100)
			{
				cout<<"Nhap lai: ";cin>>m;cin.ignore();
			}
			for(int i=0;i<m;i++)
			{
				a2[i].Sachvebia::fill();
			}
			cout<<"\nDanh sach co bia !!!\n";
			for(int i=0;i<m;i++)
			{
				a2[i].Sachvebia::show();
			}
			
		}
};
int main()
{
	Quanly x;
	x.fillandshow();
}



