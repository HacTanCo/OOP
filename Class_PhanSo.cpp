#include<bits/stdc++.h>
using namespace std;
class phanso
{
	private:
		int tu,mau;
	public:
		void nhap();
		void xuat();
		phanso cong(phanso s2);
		phanso tru(phanso s2);
		phanso nhan(phanso s2);
		phanso chia(phanso s2);
		void tg()
		{
			float gcd=__gcd(tu, mau);
			tu /= gcd;
			mau /= gcd;
		}
		bool operator ==(phanso p)
		{
			return tu*p.mau == p.tu*mau;
		}
		bool operator !=(phanso p)
		{
			return tu*p.mau != p.tu*mau;
		}
		bool operator <(phanso p)
		{
			return tu*p.mau < p.tu*mau;
		}
		bool operator >(phanso p)
		{
			return tu*p.mau > p.tu*mau;
		}
		bool operator <=(phanso p)
		{
			return tu*p.mau <= p.tu*mau;
		}
		bool operator >=(phanso p)
		{
			return tu*p.mau >= p.tu*mau;
		}
		phanso operator +=(phanso p)
		{
			tu = tu*p.mau + p.tu*mau;
			mau = mau * p.mau;
			tg();
			return *this;
		}
		phanso operator -=(phanso p)
		{
			tu = tu*p.mau - p.tu*mau;
			mau = mau * p.mau;
			tg();
			return *this;
		}
		phanso operator *=(phanso p)
		{
			tu = tu *p.tu;
			mau = mau *p.mau;
			tg();
			return *this;
		}
		phanso operator /=(phanso p)
		{
			tu = tu *p.mau;
			mau = p.tu * mau;
			tg();
			return *this;
		}
		
};
void phanso::nhap()
{
	cout<<"Nhap tu so: ";
	cin>>tu;
	cout<<"Nhap mau so: ";
	cin>>mau;
	while(mau==0)
	{
		cout<<"Nhap lai mau so: ";
		cin>>mau;
	}
	
}
void phanso::xuat()
{
	cout<<"Ket qua: "<<tu<<"/"<<mau<<"\n\n";
}
phanso phanso::cong(phanso s2)
{
	phanso sum;
	sum.tu = tu*s2.mau + s2.tu*mau;
	sum.mau = mau*s2.mau;
	float gcd=__gcd(sum.tu, sum.mau);
	sum.tu /= gcd;
	sum.mau /= gcd;
	return sum;
}
phanso phanso::tru(phanso s2)
{
	phanso tru;
	tru.tu = tu*s2.mau - s2.tu*mau;
	tru.mau = mau*s2.mau;
	float gcd=__gcd(tru.tu,tru.mau);
	tru.tu /= gcd;
	tru.mau /= gcd;
	return tru;
}
phanso phanso::nhan(phanso s2)
{
	phanso nhan;
	nhan.tu = tu*s2.tu;
	nhan.mau = mau*s2.mau;
	float gcd=__gcd(nhan.tu, nhan.mau);
	nhan.tu /= gcd;
	nhan.mau /= gcd;
	return nhan;
}
phanso phanso::chia(phanso s2)
{
	phanso chia;
	chia.tu = tu*s2.mau;
	chia.mau = s2.tu*mau;
	float gcd=__gcd(chia.tu, chia.mau);
	chia.tu /= gcd;
	chia.mau /= gcd;
	return chia;
}
int main()
{
//	phanso s1,s2;
//	s1.nhap();
//	s1.xuat();
//	s2.nhap();
//	s2.xuat();
//	
//	s1.cong(s2).xuat();
//	s1.tru(s2).xuat();
//	s1.nhan(s2).xuat();
//	s1.chia(s2).xuat();

	phanso a,b;
	a.nhap();
	b.nhap();
//	cout<<"\nXet == || != : ";
//	if(a==b) cout<<"a == b\n";
//	else if(a!=b) cout<<"a != b\n";
//	cout<<"\nXet > || <: ";
//	if(a<b) cout<<"a < b\n";
//	else if(a>b) cout<<"a > b\n";
//	else if(a==b) cout<<"Khong xet a==b trong truong hop nay !!!\n";
//	cout<<"\nXet >= || <=: ";
//	if(a<=b) cout<<"a <= b\n";
//	else if(a>=b) cout<<"a >= b\n";
	phanso gan,gan1,gan2,gan3;
	gan = gan1 = gan2 = gan3 = a;
	gan += b;
	cout<<"Cong hai phan so: ";
	gan.xuat();
	gan1 -= b;
	cout<<"Tru hai phan so: ";
	gan1.xuat();
	gan2 *= b;
	cout<<"Nhan hai phan so: ";
	gan2.xuat();
	gan3 /= b;
	cout<<"Chia hai phan so: ";
	gan3.xuat();
	
}



