#include<bits/stdc++.h>
using namespace std;
class dathuc
{
	private:
		int bac,heso[50]={0};
	public:
		void nhap();
		void xuat();
		dathuc cong(dathuc s2);
		dathuc tru(dathuc s2);
};
void dathuc::nhap()
{
	cout<<"Nhap bac cua da thuc: ";cin>>bac;
	while(bac<0)
	{
		cout<<"Nhap lai: ";cin>>bac;
	}
	for(int i=0;i<=bac;i++)
	{
		cout<<"Nhap he so thu "<<i<<" : ";cin>>heso[i];
	}
}
void dathuc::xuat()
{
	for(int i=bac;i>=0;i--)
	{
		cout<<heso[i]<<"x^"<<i;
		if(i==0)
		{
			cout<<""<<endl;
		}
		else
		{
			cout<<" + ";
		}
	}
	cout<<endl;
}
dathuc dathuc::cong(dathuc s2)
{
	dathuc s;
	s.bac=max(bac,s2.bac);
	for(int i=0;i<=s.bac;i++)
	{
		s.heso[i] = heso[i]+s2.heso[i];
	}
	return s;
}
dathuc dathuc::tru(dathuc s2)
{
	dathuc s;
	s.bac=max(bac,s2.bac);
	for(int i=0;i<=s.bac;i++)
	{
		s.heso[i]=heso[i]-s2.heso[i];
	}
	return s;
}
int main()
{
	dathuc a,b,c;
	a.nhap();
	a.xuat();
	b.nhap();
	b.xuat();
	cout<<"Tong: ";
	a.cong(b).xuat();
	cout<<"Hieu: ";
	a.tru(b).xuat();

}



















