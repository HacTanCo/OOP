#include<bits/stdc++.h>
using namespace std;
class mang
{
	private:
		int n;
		int *a;
	public:
		void nhap();
		void xuat();
		mang cong(mang s2);
};
void mang::nhap()
{
	cout<<"Nhap so phan tu: ";cin>>n;
	a = new int [n];
	for(int i=0;i<n;i++)
	{
		cout<<"a["<<i+1<<"] : ";
		cin>>a[i];
	}
}
void mang::xuat()
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
mang mang::cong(mang s2)
{
	mang s;
	if(n != s2.n)
	{
		cout<<"2 mang nay khac kich thuoc";
		exit(1);
	}
	s.n=n;
	s.a=new int [n];
	for(int i=0;i<n;i++)
	{
		s.a[i] = a[i]+s2.a[i];
	}
	int sum =0;
	for(int i=0;i<n;i++)
	{
		sum += s.a[i];
	}
	cout<<sum<<endl;
}
int main()
{
	mang b,c,d;
	cout<<"Mang 1"<<endl;
	b.nhap();
	b.xuat();
	cout<<"Mang 2"<<endl;
	c.nhap();
	c.xuat();
	cout<<"Tong 2 mang la: ";
	b.cong(c);
	
		
}
