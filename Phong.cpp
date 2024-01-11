#include<bits/stdc++.h>
using namespace std;
class Phong
{
	private:
		string lp;
		int nst;	
	public:
		int get_nst()
		{
			return nst;
		}
		void input()
		{
			cout<<"Nhap loai phong can thue: ";getline(cin,lp);
			cout<<"Nhap so ngay thue phong: ";cin>>nst;
			while(nst<=0)
			{
				cout<<"Nhap lai: ";cin>>nst;
			}
		}
		void show()
		{
			cout<<"\nLoai phong: "<<lp<<endl;
			cout<<"So ngay thue: "<<nst<<endl;
		}
		
		virtual int thanhtoan()
		{
			return 0;
		}
};
class PhongA : public Phong
{
	private:
		int tdv;
	public:
		void input()
		{
			Phong::input();
			cout<<"Nhap tien dich vu cua phong A: ";cin>>tdv;
		}
		void show()
		{
			Phong::show();
			cout<<"Tien dich vu: "<<tdv<<endl;
		}
		int thanhtoan()
		{
			if(get_nst()>5)
			{
				return ( 80*get_nst() ) - ( 80*get_nst()*0.1 ) + tdv;
			}
			else
			{
				return 80*get_nst()+tdv;
			}
		}
};
class PhongB : public Phong
{
	public:
		void input()
		{
			Phong::input();
		}
		void show()
		{
			Phong::show();
		}
		int thanhtoan()
		{
			if(get_nst() > 5)
			{
				return ( 60*get_nst() ) - ( 60*get_nst()*0.1 );
			}
			else
			{
				return 60*get_nst();
			}
		}
};
class PhongC : public Phong
{
	public:
		void input()
		{
			Phong::input();
		}
		void show()
		{
			Phong::show();
		}
		int thanhtoan()
		{
			return 40*get_nst();
		}
};
class Quanly
{
	private:
		Phong *a[50];
		int n;
	public:
		void input()
		{
			cout<<"Nhap so luong phong khach hang da thue: ";cin>>n;cin.ignore();
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();	
			}
			int x;
			for(int i=0;i<n;i++)
			{
				cout<<"\nNhap 1-PhongA, 2-PhongB, 3-PhongC: ";cin>>x;cin.ignore();
				if(x==1)
				{
					PhongA *p = new PhongA;
					p->input();
					a[i]=p;
				}
				else if(x==2)
				{
					PhongB *p = new PhongB;
					p->input();
					a[i]=p;
				}
				else if(x==3)
				{
					PhongC *p = new PhongC;
					p->input();
					a[i]=p;
				}
				
			}	
		}
		void show()
		{
			cout<<"\nDanh sach tong so tien khach hang phai tra !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i]->show();
				cout<<"Tien thanh toan: "<<a[i]->thanhtoan()<<endl;
			}
		}
		
		
};
int main()
{
	Quanly x;
	x.input();
	x.show();
}
