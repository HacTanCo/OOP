// 5:16
#include<bits/stdc++.h>
using namespace std;
class Khachhang
{
	private:
		string ms,ht,dc;
		float n;
		int d,m,y;
	public:
		int check()
		{
			if( (d<=0 || d>31) || (m<=0 || m>12) || y<=0)
			{
				return 0;
			}
			if( m==4 || m==6 || m==9 || m==11)
			{
				return d<=30;
			}
			else if(m==2)
			{
				
				if( (y%4==0 and y%100!=0) || y%400==0 )
				{
					return d<=29;
				}
				else
				{
					return d<=28;
				}
			}
			else
			{
				return d<=31;
			}
		}
		void nhap()
		{
			cout<<"\nNhap ma so: ";getline(cin,ms);
			cout<<"Nhap ho ten: ";getline(cin,ht);
			cout<<"Nhap dia chi: ";getline(cin,dc);
			cout<<"Nhap so m khoi tieu thu: ";cin>>n;
			cout<<"Nhap ngay tinh tien: ";cin>>d>>m>>y;
			while(check()==0)
			{
				cout<<"Nhap lai ngay tinh tien: ";cin>>d>>m>>y;
			}
			fflush(stdin);
		}
		void xuat()
		{
			cout<<"--------------------"<<endl;
			cout<<"Ma so: "<<ms<<endl;
			cout<<"Ho ten: "<<ht<<endl;
			cout<<"Dia chi: "<<dc<<endl;
			cout<<"So m khoi tieu thu: "<<n<<endl;
			cout<<"Ngay tinh tien: "<<d<<"/"<<m<<"/"<<y<<endl;
			cout<<"So tien phai tra: "<<tien()<<endl;
			cout<<"--------------------"<<endl;
		}
		int tien()
		{
			float sum=0;
			int a=100*2000,b=100*3000;
			if(n>0 and n<101)
			{
				sum = n*2000;
			}
			else if(n>100 and n<201)
			{
				sum = (n-100)*3000 + a;
			}
			else
			{
				sum = (n-200)*5000 + a + b;
			}
			return sum;
		}
		bool ssngay(Khachhang a,Khachhang b)
		{
			if(a.y == b.y)
			{
				if(a.m == b.m)
				{
					return a.d > b.d;
				}
				return a.m > b.m;
			}
			return a.y > b.y;
		}
};
class Quanly
{
	private:
		Khachhang ds[100];
		int n;
	public:
		void nhap_kh()
		{
			cout<<"Nhap so luong khach hang (n<101): ";cin>>n;
			fflush(stdin);
			while(n>100)
			{
				cout<<"Nhap lai so luong khach hang: ";cin>>n;
			}
			for(int i=0;i<n;i++)
			{
				ds[i].nhap();
			}
		}
		void xuat_kh()
		{
			cout<<"\nDanh sach khach hang !!!"<<endl;
			for(int i=0;i<n;i++)
			{
				ds[i].xuat();
			}
		}
		void top1()
		{
			float max=ds[0].tien();
			for(int i=0;i<n;i++)
			{
				if(max < ds[i].tien())
				{
					max = ds[i].tien();
				}
			}
			cout<<"\nDanh sach khach hang tra tien cao nhat !!!\n";
			for(int i=0;i<n;i++)
			{
				if(ds[i].tien()==max)
				{
					ds[i].xuat();
				}
			}
		}
		
		void sort()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(ds[i].ssngay(ds[i],ds[j]))
					{
						swap(ds[i],ds[j]);
					}
				}
			}
			cout<<"\nDanh sach sau khi sap xep tang theo ngay !!!!\n";
			for(int i=0;i<n;i++)
			{
				ds[i].xuat();
			}
		}
};
int main()
{
	Quanly a;
	a.nhap_kh();
	a.xuat_kh();
	a.top1();
	a.sort();
}
