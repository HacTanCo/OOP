//Bai tap 3.8 trong giao trinh
#include <iostream>
using namespace std;

class Time
{
  private:	
	int h,m,s;  //h: gio, m:phut, s:giay
  public:
	//cac ham tao
	Time(); //ham tao mac dinh
	Time(int a,int b,int c); //ham tao co 3 tham so
	//ham nhap, xuat
	void nhap();
	void xuat();
	void chuanhoa(); //chuan hoa gio, phut va giay theo quy dinh
	void giatang(int a, int b, int c);//tang gio hien tai theo
									  //a: gio, b: phut, c:giay
	void dieuchinh(int a, int b,int c); //dieu chinh lai gio hien tai theo chuan hoa
	bool operator ==(Time ss)
	{
		return (h==ss.h and m==ss.m and s==ss.s);
	}
	bool operator !=(Time ss)
	{
		return (h!=ss.h || m!=ss.m || s!=ss.s);
	}
	bool operator +=(Time ss)
	{
		h += ss.h;
		m += ss.m;
		s += ss.s;
		chuanhoa();
	}
	bool operator <(Time ss)
	{
		return (h*3600+m*60+s) < (ss.h*3600+ss.m*60+ss.s);
	}

	bool operator<=(Time ss) 
	{
	    return (h*3600+m*60+s) <= (ss.h*3600+ss.m*60+ss.s);
	}
};

Time::Time()
{	h=m=s=0; }

Time::Time(int a,int b,int c)
{	h=a; m=b; s = c;}

void Time::nhap()
{
	while(1)
    {
        cout << "Nhap vao gio, phut va giay: ";
        cin>>h>>m>>s;
        if (h >= 0 and m >=0 and s>=0)
            break;
        cout << "Nhap sai! Hay nhap lai." << endl;
    }	
}

void Time::xuat()
{	cout<<h<<":"<<m<<":"<<s<<"\n"; }

/* cach 1
void Time::chuanhoa()
{
	if(s>=60)
	{	m = m+s/60;
		s = s%60; //chuan hoa giay
	}

	if(m>=60)
	{
		h = h+m/60;
		m = m%60;  //chuan hoa phut
	}
	
	if(h>=24)
	   h = h%24;	//chuan hoa gio
}
*/

//cach 2
void Time::chuanhoa()
{
    int tong = h*3600 + m*60 + s;  //tinh ra giay
    h = (tong/3600)%24;
    m = (tong/60)%60;
    s = tong%60;
}

void Time::giatang(int a, int b, int c)
{
	h=h+a;
	m=m+b;
	s=s+c;
    chuanhoa();  //goi phuong thuc chuanhoa
}

void Time::dieuchinh(int a, int b, int c)
  {
  	h = a;
  	m = b;
	s = c;
	chuanhoa();
	  
  }
int main()
{
//	Time ob1(25,65,75),ob2;
//	cout<<"\n Doi tuong ob1: ";
//	ob1.xuat();
//	cout<<"\n Sau khi chuan hoa ob1: ";
//	ob1.chuanhoa();//2:6:15
//	ob1.xuat();
//	
//	cout<<"\n Gia tang ob1: ";
//	ob1.giatang(20, 50, 70); //tang gio len 20, phut tang 50, giay tang 90
//	cout<<"\n ob1 sau khi gia tang: ";
//	ob1.xuat(); //22:57:25
//	
//	cout<<"\n Dieu chinh ob1: ";
//	ob1.dieuchinh(15, 70, 90);
//	cout<<"\n ob1 sau khi dieu chinh: ";
//	ob1.xuat(); //16:11:30
//		
//	cout<<"\n Nhap doi tuong ob2: \n ";
//	ob2.nhap();
//	cout<<"\n Doi tuong ob2: \n";
//	ob2.xuat();
//	cout<<"\n Sau khi chuan hoa ob2: ";
//	ob2.chuanhoa();
//	ob2.xuat();
	Time a,b,c;
	a.nhap();
	b.nhap();
	cout<<"So sanh a va b: ";
	if(a==b) cout<<"a == b\n";
	else if(a!=b) cout<<"a != b\n";
	
	c = a;
	c += b;
	cout<<"Qua tai toan tu ( += ): ";
	c.xuat();
	
	cout<<"Qua tai toan tu ( < ) and ( <= ): ";
	if(a<b) cout<<"a < b ";
	else if(b<a)  cout<<"b < a ";
	else cout<<"a and b == nen khong xet ( < ) ";
	if(a<=b) cout<<"and a <= b\n";
	else cout<<"and b <= a\n";
	return 0;
}
	
//thao luan: Viet them cac ham de thuc hien viec so sanh sanh hai doi tuong thoi gian
