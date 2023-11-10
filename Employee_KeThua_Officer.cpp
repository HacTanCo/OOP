#include<bits/stdc++.h>
using namespace std;
class Date
{
	public:
		int d,m,y;
		int checknn()
		{
			if( (y%4==0 and y%100!=0) or (y%400==0)) return 1;
			else return 0;
		}
		int dmy()
		{
			if( (d<=0 or d>31) or (m<=0 or m>12) or y<=0) return 0;
			if(m==4 or m==6 or m==9 or m==11) return d<=30;
			else if(m==2) return d <= 28 + checknn();
			else return d<=31; 
		}
		void filldate()
		{
			cout<<"Nhap Ngay thang nam: ";cin>>d>>m>>y;fflush(stdin);
			while(dmy()==0)
			{
				cout<<"Nhap lai: ";cin>>d>>m>>y;fflush(stdin);
			}
		}
		void showdate()
		{
			cout<<"\nNgay hop dong: "<<d<<"/"<<m<<"/"<<y;
		}
};
class Officer
{
	private:
		string mcb,ht,dv;
		float hsl,bh;
	public:
		void fillof()
		{
			cout<<"\nNhap ma can bo: ";getline(cin,mcb);
			cout<<"Nhap ho ten: ";getline(cin,ht);
			cout<<"Nhap don vi: ";getline(cin,dv);
			cout<<"Nhap he so luong: ";cin>>hsl;
			cout<<"Nhap bao hiem: ";cin>>bh;
		}
		void showof()
		{
			cout<<"\n----------------------------\n";
			cout<<"Ma can bo: "<<mcb<<endl;
			cout<<"Ho ten: "<<hsl<<endl;
			cout<<"Don vi: "<<dv<<endl;
			cout<<"He so luong: "<<hsl<<endl;
			cout<<"Bao hiem: "<<(int)bh<<endl;
			cout<<"Luong: "<<(int)luong();
		}
		float luong()
		{
			return hsl * 1350000 - bh;
		}
		string get_dv()
		{
			return dv;
		}
};
class Employee : public Officer
{
	private:
		Date nhd;
	public:
		void fillem()
		{
			fillof();
			nhd.filldate();
		}
		void showem()
		{
			showof();
			nhd.showdate();
			cout<<"\n----------------------------\n";
		}
		bool operator >(Employee a)
		{
			if(nhd.y > a.nhd.y) return true;
			else if(nhd.y == a.nhd.y)
			{
				if(nhd.m > a.nhd.m) return true;
				else if(nhd.m == a.nhd.m)
				{
					return nhd.d > a.nhd.d;
				}
			}
			return false;
		}
};
class quanly
{
	private:
		Employee a[50];
		int n;
	public:
		void fillds()
		{
			cout<<"\nNhap so luong doi tuong: ";cin>>n;
			fflush(stdin);
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;
				fflush(stdin);
			}
			for(int i=0;i<n;i++)
			{
				a[i].fillem();
			}
		}
		void sorttang()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if( !(a[i]>a[j]) )
					{
						swap(a[i],a[j]);
					}
				}
			}
			cout<<"\nDanh sach tang dan theo ngay hop dong !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].showem();
			}
		}
		void bangluong()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(!(a[i].get_dv() < a[j].get_dv()))
					{
						swap(a[i],a[j]);
					}
				}
			}
			string donvi;
			donvi = a[0].get_dv();
			cout<<"\nDanh sach bang luong theo tung don vi: "<<donvi<<endl;
			for(int i=0;i<n;i++)
			{
				if(a[i].get_dv() == donvi)
				{
					a[i].showem();
				}
				else
				{
					donvi = a[i].get_dv();
					cout<<"\nDanh sach bang luong theo tung don vi: "<<donvi<<endl;
					a[i].showem();
				}
			}
		}
};
int main()
{
	quanly a;
	a.fillds();
	a.sorttang();
	a.bangluong();
	
}
