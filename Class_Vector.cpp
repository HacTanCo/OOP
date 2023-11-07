#include<bits/stdc++.h>
using namespace std;
class Vector
{
	private:
		int n;
		int *a;
	public:
		void nhap()
		{
			cout<<"Nhap kich thuoc cua vector: ";cin>>n;
			a = new int [n];
			if( a == NULL)
			{
				cout<<"Loi cap phat bo nho\n";
				return;
			}
			for(int i=0;i<n;i++)
			{
				cout<<"Nhap a["<<i+1<<"] = ";cin>>a[i];
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
		int tvh(Vector b)
		{
			if( n != b.n)
			{
				cout<<"Hai mang k cung kich thuoc\n";
			}
			int sum=0;
			for(int i=0;i<n;i++)
			{
				sum += a[i] * b.a[i];
			}
			return sum;
		}
		int modun()
		{
			double sum=0;
			for(int i=0;i<n;i++)
			{
				sum += pow(a[i],2);
			}
			return sqrt(sum);
		}
		
};
int main()
{
	Vector a,b;
	cout<<"Vector 1!!!\n";
	a.nhap();
	a.xuat();
	cout<<"Vector 2!!!\n";
	b.nhap();
	b.xuat();
	int c;
	c=a.tvh(b);
	cout<<"Tich vo huong cua 2 vecto la: "<<c<<endl;
	double d,f;
	d=a.modun();
	f=b.modun();
	cout<<"Modun cua hai vecto lan luot la: "<<d<<" "<<f<<endl;
	
}
