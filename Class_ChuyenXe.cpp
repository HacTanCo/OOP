#include<bits/stdc++.h>
using namespace std;
class chuyenxenoithanh
{
	private:
		string msc,htts,soxe;
		int sotuyen;
		float dt,km;
	public:
		void nhap();
		void xuat();
		float get_dt()
		{
			return dt;
		}
};
class chuyenxengoaithanh
{
	private:
		string msc,htts,soxe,noiden;
		int songaydidc;
		float dt;
	public:
		void nhap();
		void xuat();
		float get_dt()
		{
			return dt;
		}
};

void chuyenxenoithanh::nhap()
{
	cout<<"\nNhap ma so chuyen: ";
	getline(cin,msc);
	cout<<"Nhap ho ten tai se: ";
	getline(cin,htts);
	cout<<"Nhap so xe: ";
	getline(cin,soxe);
	cout<<"Nhap so tuyen: ";
	cin>>sotuyen;
	cout<<"Nhap so km di duoc: ";
	cin>>km;
	cout<<"Nhap doanh thu: ";
	cin>>dt;
}
void chuyenxenoithanh::xuat()
{
	cout<<"\nMa so chuyen la: "<<msc<<endl;
	cout<<"Ho ten tai se la: "<<htts<<endl;
	cout<<"So xe la: "<<soxe<<endl;
	cout<<"So tuyen la: "<<sotuyen<<endl;
	cout<<"So km di duoc la: "<<km<<endl;
	cout<<"Doanh thu la: "<<dt<<endl;	
}


void chuyenxengoaithanh::nhap()
{
	cout<<"\nNhap ma so chuyen: ";
	getline(cin,msc);
	cout<<"Nhap ho ten tai se: ";
	getline(cin,htts);
	cout<<"Nhap so xe: ";
	getline(cin,soxe);
	cout<<"Nhap noi den: ";
	getline(cin,noiden);
	cout<<"Nhap so ngay di duoc: ";
	cin>>songaydidc;
	cout<<"Nhap doanh thu: ";
	cin>>dt;
}
void chuyenxengoaithanh::xuat()
{
	cout<<"\nMa so chuyen la: "<<msc<<endl;
	cout<<"Ho ten tai se la: "<<htts<<endl;
	cout<<"So xe la: "<<soxe<<endl;
	cout<<"Noi den la: "<<noiden<<endl;
	cout<<"So ngay di duoc la: "<<songaydidc<<endl;
	cout<<"Doanh thu la: "<<dt<<endl;
}
int main()
{
	int n;
	cout<<"Nhap so luong chuyen xe ngoai thanh: ";cin>>n;
	chuyenxengoaithanh ngoaithanh[n];
	fflush(stdin);
	
	for(int i=0;i<n;i++)
	{
		ngoaithanh[i].nhap();
		fflush(stdin);
	}
	float sum=0;
	for(int i=0;i<n;i++)
	{
		sum += ngoaithanh[i].get_dt();	
	}
	cout<<"\n\nSo luong chuyen xe sau khi nhap la !!!\n\n";
	for(int i=0;i<n;i++)
	{
		ngoaithanh[i].xuat();
	}
	
	int m;
	cout<<"\n\nNhap so luong chuyen so noi thanh: ";cin>>m;
	chuyenxenoithanh noithanh[m];
	fflush(stdin);
	
	for(int i=0;i<m;i++)
	{
		fflush(stdin);
		noithanh[i].nhap();
	}
	float s=0;
	for(int i=0;i<m;i++)
	{
		s += noithanh[i].get_dt();
	}
	cout<<"\n\nSo luong chuyen xe sau khi nhap la !!!\n\n";
	for(int i=0;i<m;i++)
	{
		noithanh[i].xuat();
	}
	
	cout<<"\nnDoanh thu cua chuyen xe ngoai thanh la: "<<sum<<endl;
	cout<<"Doanh thu cua chuyen xe noi thanh la: "<<s<<endl;
	cout<<"Tong doanh thu cua chuyen xe ngoai thanh va noi thanh la: "<<sum+s;
}





