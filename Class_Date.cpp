#include<bits/stdc++.h>
using namespace std;
class date
{
	private:
		int d,m,y;
	public:
		void nhap();
		void xuat();
		int check();
		void tang1d();
		void tangkd();
		int dofy;
		bool operator ==(date ss)
		{
			return y==ss.y and m==ss.m and d==ss.d;
		}
		bool operator !=(date ss)
		{
			return y!=ss.y or m!=ss.m or d!=ss.d;
		}
		date operator +=(int k)
		{
			for(int i=0;i<k;i++)
			{
				tang1d();
			}
		}
		bool operator <(date ss)
		{
			if(y<ss.y) 
			{
				return true;
			}
			else if(y==ss.y)
			{
				if(m<ss.m) 
				{
					return true;
				}
				else if(m==ss.m)
				{
					if(d<ss.d) 
					{
						return true;
					}
				}
			}
			return false;
		}
		bool operator >(date ss)
		{
			if(y>ss.y) 
			{
				return true;
			}
			else if(y==ss.y)
			{
				if(m>ss.m) 
				{
					return true;
				}
				else if(m==ss.m)
				{
					if(d>ss.d) 
					{
						return true;
					}
				}
			}
			return false;
		}
		bool operator <= (date ss)
		{
			if(y<ss.y) 
			{
				return true;
			}
			else if(y==ss.y)
			{
				if(m<ss.m) 
				{
					return true;
				}
				else if(m==ss.m)
				{
					if(d<=ss.d) 
					{
						return true;
					}
				}
			}
			return false;
		}
		bool operator >= (date ss)
		{
			if(y>ss.y) 
			{
				return true;
			}
			else if(y==ss.y)
			{
				if(m>ss.m) 
				{
					return true;
				}
				else if(m==ss.m)
				{
					if(d>=ss.d) 
					{
						return true;
					}
				}
			}
			return false;
		}
};

void date::nhap()
{
	cout<<"\nNhap ngay thang nam: ";cin>>d>>m>>y;
	while(check()==0)
	{
		cout<<"\nNgay thang nam ban vua nhap k hop le, nhap lai: ";cin>>d>>m>>y;
	}
}
void date::xuat()
{
	cout<<"\nXuat ngay thang nam sau khi thay doi: "<<d<<"/"<<m<<"/"<<y<<endl;;
}
int date::check()
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
void date::tang1d()
{
	d++;
	{
		if(m==4 || m==6 || m==9 || m==11)
		{
			if(d>30)
			{
				d=1;
				m++;
			}
		}
		else if(m==2)
		{
			if( (y%4==0 and y%100!=0) || y%400==0 )
			{
				if(d>29)
				{
					d=1;
					m++;
				}
			}
			else
			{
				if(d>28)
				{
					d=1;
					m++;
				}
			}
		}
		else
		{
			if(d>31)
			{
				d=1;
				m++;
			}
		}
		
		if(m>12)
		{
			m=1;
			y++;
		}
	}
}
void date::tangkd()
{
	int k;
	cout<<"\nNhap so ngay ban muon tang: ";cin>>k;
	for(int i=0;i<k;i++)
	{
		tang1d();
	}
}
int main()
{
//	date a;
//	a.nhap();
//	cout<<"\nSau khi tang 1 ngay la: ";
//	a.tang1d();
//	a.xuat();
//	a.nhap();
//	a.tangkd();
//	cout<<"\nSau khi tang k ngay la: ";
//	a.xuat();
	date a,b,gana;
	a.nhap();
	b.nhap();
	cout<<"\nSo sanh a and b: ";
	if(a==b) cout<<"a == b\n";
	else cout<<"a != b\n";
	
	int k;
	cout<<"\nNhap so ngay muon tang: ";cin>>k;
	gana = a;
	gana += k;
	cout<<"\na sau khi tang len "<<k<<" ngay: ";
	gana.xuat();
	
	cout<<"\nSo sanh < and > : ";
	if(a>b) cout<<"a > b\n";
	else if (a<b) cout<<"a < b\n";
	else if(a==b) cout<<"Do a==b nen khong xet trong truong hop nay !!!\n";
	
	cout<<"\nSo sanh >= and <= : ";
	if(a>=b) cout<<"a >= b\n";
	else cout<<"a <= b\n";
}
