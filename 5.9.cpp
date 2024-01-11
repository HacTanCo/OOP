#include<bits/stdc++.h>
using namespace std;
class Date
{
	public:
		int d,m,y;
		int checknn()
		{
			if((y%4==0 and y%100!=0) or (y%400==0)) return 1;
			else return 0;
		}
		int dmy()
		{
			if( (d<=0 || d>31) || (m<=0 || m>12) || y<=0) return 0;
			if( m==4 || m==6 || m==9 || m==11) return d<=30;
			else if(m==2) return d<=28+checknn();
			else return d<=31;
		}
		void fill()
		{
			cout<<"Nhap ngay thang nam: ";cin>>d>>m>>y;
			cin.ignore();
			while(dmy()==0)
			{
				cout<<"Nhap lai ngay thang nam: ";cin>>d>>m>>y;
				cin.ignore();
			}
		}
		void show()
		{
			cout<<"Ngay thang nam : "<<d<<"/"<<m<<"/"<<y;
		}
		
};
class Canbo
{
	private:
		string mcb,mdv,ht;
		Date ngaysinh;
	public:
		void fill_cb()
		{
			cout<<"\nNhap ma can bo: ";getline(cin,mcb);
			cout<<"Nhap ma don vi: ";getline(cin,mdv);
			cout<<"Nhap ho ten: ";getline(cin,ht);
			cout<<"Nhap ngay sinh cua can bo !!!"<<endl;
			ngaysinh.fill();
		}
		void show_cb()
		{
			cout<<"\nMa can bo: "<<mcb<<endl;
			cout<<"Ma don vi: "<<mdv<<endl;
			cout<<"Ho ten: "<<ht<<endl;
			cout<<"Ngay sinh cua can bo !!!"<<endl;
			ngaysinh.show();
		}
		string get_mdv()
		{
			return mdv;
		}
	
};
class Luong : public Canbo
{
	private:
		double pc,hsl,bh;
	public:
		void fill()
		{
			fill_cb();
			cout<<"Nhap phu cap: ";cin>>pc;
			cout<<"Nhap he so luong: ";cin>>hsl;
			cout<<"Nhap bao hiem: ";cin>>bh;cin.ignore();
		}
		float luong()
		{
			return hsl * 1350000 + pc - bh;
		}
		void show()
		{
			show_cb();
			cout<<"\nLuong: "<<(int)luong()<<endl;
			
		}
};
class Quanly
{
	private:
		Luong a[50];
		int n;
	public:
		void fill_ql()
		{
			cout<<"Nhap so luong can bo: ";cin>>n;cin.ignore();
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();
			}
			for(int i=0;i<n;i++)
			{
				a[i].Luong::fill();
			}
		}
		void show_ql()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i].get_mdv()>a[j].get_mdv())
					{
						Luong tam = a[i];
						a[i] = a[j];
						a[j] = tam;
					}
				}
			}
			string donvi;
			donvi = a[0].get_mdv();
			cout<<"\nBang luong cua don vi: "<<donvi<<endl;
			for(int i=0;i<n;i++)
			{
				if(donvi == a[i].get_mdv())
				{
					a[i].Luong::show();
				}
				else
				{
					donvi = a[i].get_mdv();
					cout<<"\nBang luong cua don vi: "<<donvi<<endl;
					a[i].Luong::show();
				}
			}
		}
};
int main()
{
	Quanly x;
	x.fill_ql();
	x.show_ql();
}
