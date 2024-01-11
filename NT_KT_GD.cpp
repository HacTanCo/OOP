#include<bits/stdc++.h>
using namespace std;
class Date
{
	public:
		int d,m,y;
		int checknn()
		{
			if((y%4==0 and y%100!=0) or (y%400==0)) return 1;
			else return 0;
		}
		int dmy()
		{
			if( (d<=0 || d>31) || (m<=0 || m>12) || y<=0) return 0;
			if( m==4 || m==6 || m==9 || m==11) return d<=30;
			else if(m==2) return d<=28+checknn();
			else return d<=31;
		}
		void fill()
		{
			cout<<"Nhap ngay thang nam: ";cin>>d>>m>>y;
			fflush(stdin);
			while(dmy()==0)
			{
				cout<<"Nhap lai ngay thang nam: ";cin>>d>>m>>y;
				fflush(stdin);
			}
		}
		void show()
		{
			cout<<"Ngay thang nam : "<<d<<"/"<<m<<"/"<<y;
		}
		
};
class Giaodich
{
	private:
		string mgd;
		Date ngaygd;
		float stgd;
	public:
		Giaodich(){}
		Giaodich(string mgd,int d,int m,int y,float stgd)
		{
			this->mgd = mgd;
			this->ngaygd.d = d;
			this->ngaygd.m = m;
			this->ngaygd.y = y;
			this->stgd = stgd;
		}
		
		void set_mgd(string mgd)
		{
			this->mgd = mgd;
		}
		string get_mgd()
		{
			return mgd;
		}
		
		void set_ngaygd_d(int d)
		{
			ngaygd.d = d;
		}
		int get_ngaygd_d()
		{
			return ngaygd.d;
		}
		
		void set_ngaygd_m(int m)
		{
			ngaygd.m = m;
		}
		int get_ngaygd_m()
		{
			return ngaygd.m;
		}
		
		void set_ngaygd_y(int y)
		{
			ngaygd.y = y;
		}
		int get_ngaygd_y()
		{
			return ngaygd.y;
		}
		
		float set_stgd(float stgd)
		{
			this->stgd = stgd;
		}
		float get_stgd()
		{
			return stgd;
		}
		void input()
		{
			cout<<"\nNhap ma giao dich: ";getline(cin,mgd);
			cout<<"Nhap ngay giao dich !!!\n";
			ngaygd.fill();
		}
		void show()
		{
			cout<<"Ma giao dich: "<<mgd<<endl;
			cout<<"Ngay giao dich !!!"<<endl;
			ngaygd.show();
			
		}
};
class Ngoaite : public Giaodich
{
	private:
		long long sl,tg;
		string lt;	
	public:
		Ngoaite(){}
		Ngoaite(int sl,int tg,string lt)
		{
			this->sl = sl;
			this->tg = tg;
			this->lt = lt;
		}
		void set_sl(int sl)
		{
			this->sl = sl;
		}
		int get_sl()
		{
			return sl;
		}
		
		void set_tg(int tg)
		{
			this->tg = tg;
		}
		int get_tg()
		{
			return tg;
		}
		
		void set_lt(int tg)
		{
			this->lt = lt;
		}
		string get_lt()
		{
			return lt;
		}
		float thanhtien()
		{
			return (int)get_sl()*get_tg();
		}
		void input_nt()
		{
			input();
			cout<<"Nhap so luong tien: ";cin>>sl;
			cout<<"Nhap ty gia cua loai tien: ";cin>>tg;cin.ignore();
			cout<<"Nhap loai tien can giao dich: ";getline(cin,lt);
		}
		void show_nt()
		{
			cout<<"\n----------------------------------------";
			show();
			cout<<"\nSo luong tien giao dich: "<<sl<<endl;
			cout<<"Ty gia cua loai tien: "<<tg<<endl;
			cout<<"Loai tien giao dich: "<<thanhtien()<<endl;
			cout<<"----------------------------------------\n";
		}
		bool operator ==(Ngoaite a)
		{
			return lt == a.lt;
		}
};
class Quanly
{
	private:
		Ngoaite a[50];
		int n;
	public:
		void input_ql()
		{
			cout<<"Nhap so luong giao dich: ";cin>>n;cin.ignore();
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();
			}
			for(int i=0;i<n;i++)
			{
				a[i].input_nt();
			}
		}
		void tongtien()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i].get_lt()>a[j].get_lt())
					{
						swap(a[i],a[j]);
					}
				}
			}
			long long sum=0;
			cout<<"\nTong tien theo tung loai tien !!!\n";
			for(int i=0;i<n;i++)
			{
				sum += a[i].thanhtien();
				if(a[i].get_lt()!=a[i+1].get_lt())
				{
					cout<<a[i].get_lt()<<" : "<<sum<<endl;
					sum=0;
				}
			}
		}
		void tren1ty()
		{
			cout<<"\nDanh sach cac giao dich tren 1 ty !!!\n";
			for(int i=0;i<n;i++)
			{
				if(a[i].thanhtien()>1000000000)
				{
					a[i].show();
				}
			}
		}
	
};
int main()
{
	Quanly x;
	x.input_ql();
	x.tongtien();
	x.tren1ty();
}
