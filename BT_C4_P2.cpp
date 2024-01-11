#include<bits/stdc++.h>
using namespace std;
class sinhvien
{
	private:
		string msv,hd,ten;
		int d,m,y;
	public:
		friend istream & operator >>(istream &in, sinhvien &a)
		{
			cout<<"\nNhap ma sinh vien: ";in>>a.msv;
			fflush(stdin);
			cout<<"Nhap ho dem: ";getline(in,a.hd);
			fflush(stdin);
			cout<<"Nhap ten: ";in>>a.ten;
			cout<<"Nhap ngay thang nam: ";in>>a.d>>a.m>>a.y;
			return in;
		}
		friend ostream &operator <<(ostream &out,sinhvien &a)
		{
			out<<"\nMa sinh vien: "<<a.msv<<endl;
			out<<"Ho dem: "<<a.hd<<endl;
			out<<"Ten: "<<a.ten<<endl;
			out<<"Ngay thang nam: "<<a.d<<"/"<<a.m<<"/"<<a.y<<endl;
			return out;
		}
		bool operator <=(sinhvien a)
		{
			if(y<a.y)
			{
				return true;
			}
			else if(y==a.y)
			{
				if(m<a.m)
				{
					return true;
				}
				else if(m==a.m)
				{
					return d<=a.d;
				}
			}
			return false;
		}
		bool operator >=(sinhvien a)
		{
			if(ten > a.ten)
			{
				return ten > a.ten;
			}
			else if(ten == a.ten)
			{
				return hd >= a.hd;
			}
			return false;
		}
		
};
class quanly
{
	private:
		sinhvien ds[100];
		int n;
	public:
		void nhap_ds()
		{
			cout<<"\nNhap so sinh vien: ";cin>>n;
			for(int i=0;i<n;i++)
			{
				in>>ds[i];	
			}
		}
		void sortdmy()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(ds[j]<=ds[i])
					{
						swap(ds[i],ds[j]);
					}
				}
			}
			cout<<"\nDanh sach sinh vien sau khi sort ngay sinh giam dan !!!\n";
			for(int i=0;i<n;i++)
			{
				cout<<ds[i]<<endl;
			}
		}
		void sortfullname()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(!(ds[i]>=ds[j]))
					{
						swap(ds[i],ds[j]);
					}
				}
			}
			cout<<"\nDanh sach sinh vien sau khi sort full name tang dan !!!\n";
			for(int i=0;i<n;i++)
			{
				cout<<ds[i]<<endl;
			}
		}
};
int main()
{

	quanly a;
	a.nhap_ds();
	a.sortfullname();
	a.sortdmy();
}
