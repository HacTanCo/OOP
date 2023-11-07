#include<bits/stdc++.h>
using namespace std;
#define n 2
class Diem
{
	private:
		int a[n];
	public:
		void nhap()
		{
			for(int i=0;i<n;i++)
			{
				cout<<"a["<<i+1<<"] = ";cin>>a[i];
			}
		}
		void xuat()
		{
			for(int i=0;i<n;i++)
			{
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		double tkcg2d(Diem b)
		{
			double s=0;
			for(int i=0;i<n;i++)
			{
				s += pow(b.a[i]-a[i],2);
			}
			return sqrt(s);
		}
};
int main()
{
	Diem a,b;
	cout<<"Nhap diem 1!\n";
	a.nhap();
	a.xuat();
	cout<<"Nhap diem 2!\n";
	b.nhap();
	b.xuat();
	double c;
	c=a.tkcg2d(b);
	cout<<"Khoang cach giua 2 diem la: "<<fixed<<setprecision(9)<<c<<endl;
}
