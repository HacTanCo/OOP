#include<bits/stdc++.h>
using namespace std;
class Phuongtien
{
	private:
		string htnt,lx;
		int sgt;
	public:
		void input()
		{
			cout<<"\nNhap ho ten nguoi thue xe: ";getline(cin,htnt);
			cout<<"Nhap loai xe can thue: ";getline(cin,lx);
			cout<<"Nhap so gio thue xe: ";cin>>sgt;cin.ignore();
		}
		void show()
		{
			cout<<"\nHo ten nguoi thue xe: "<<htnt<<endl;
			cout<<"Loai xe duoc thue: "<<lx<<endl;
			cout<<"So gio thue xe: "<<sgt<<endl;
		}
		virtual int tienthuexe()
		{
			return 0;
		}
		int get_sgt()
		{
			return sgt;
		}
		string get_lx()
		{
			return lx;
		}
};
class Xedap : public Phuongtien
{
	public:
		void input_xedap()
		{
			input();
		}
		void show_xedap()
		{
			show();
		}
		int tienthuexe()
		{
			if(get_sgt()>0 and get_sgt()<=1)
			{
				return 30000;
			}
			else
			{
				return 30000 + ((get_sgt()-1)*20000);
			}
		}
};
class Xemay : public Phuongtien
{
	private:
		string bs;
	public:
		void input_xemay()
		{
			input();
		}
		void show_xemay()
		{
			show();
		}
		int tienthuexe()
		{
			if(get_lx()=="100 phan khoi")
			{
				return 15000*get_sgt();
			}
			else if(get_lx()=="250 phan khoi")
			{
				return 20000*get_sgt();
			}
		}
};
class Quanly
{
	private:
		int n,m;
		Xedap a[50];
		Xemay a1[50];
	public:
		void input_ql()
		{
			cout<<"Nhap so luong xe dap: ";cin>>n;cin.ignore();
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();
			}
			for(int i=0;i<n;i++)
			{
				a[i].input_xedap();
			}
			cout<<"\nNhap so luong xe may: ";cin>>m;cin.ignore();
			while(m<=0 or m>50)
			{
				cout<<"Nhap lai: ";cin>>m;cin.ignore();
			}
			for(int i=0;i<m;i++)
			{
				a1[i].input_xemay();
			}
			
		}
		void show_ql()
		{
			cout<<"\nDanh sach thong tin cac xe dap khach da thue !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].show_xedap();
				cout<<"Tien thue can thanh toan: "<<a[i].tienthuexe()<<endl;
			}
			cout<<"\nDanh sach thong tin cac xe may khach hang da thue !!!\n";
			for(int i=0;i<m;i++)
			{
				a1[i].show_xemay();
				cout<<"Tien thue can thanh toan: "<<a1[i].tienthuexe()<<endl;
			}
		}
};
int main()
{
	Quanly x;
	x.input_ql();
	x.show_ql();
}
