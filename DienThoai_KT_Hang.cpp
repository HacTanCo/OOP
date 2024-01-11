#include<bits/stdc++.h>
using namespace std;
class Hang
{
	private:
		string mh;
		int sl;
		float gb;
	public:
		Hang(){}
		Hang(string mh,int sl,float gb)
		{
			this->mh=mh;
			this->sl=sl;
			this->gb=gb;
		}
		string get_mh()
		{
			return mh;
		}
		int get_sl()
		{
			return sl;
		}
		float get_gb()
		{
			return gb;
		}
		void set_mh(string mh)
		{
			this->mh=mh;
		}
		void set_sl(int sl)
		{
			this->sl=sl;
		}
		void set_gb(float gb)
		{
			this->gb=gb;
		}
		void input()
		{
			cout<<"\nNhap ma hang: ";getline(cin,mh);
			cout<<"Nhap so luong: ";cin>>sl;
			cout<<"Nhap gia ban: ";cin>>gb;cin.ignore();
		}
		void show()
		{
			cout<<mh<<" | "<<sl<<" | "<<tgtcmh()<<" | ";
		}
		float tgtcmh()
		{
			return get_gb()*get_sl();
		}
};
class Dienthoai : public Hang
{
	private:
		string mdt,hsx;
		int month;
	public:
		Dienthoai(){}
		Dienthoai(string mdt,string hsx,int month)
		{
			this->mdt=mdt;
			this->hsx=hsx;
			this->month=month;
		}
		string get_mdt()
		{
			return mdt;
		}
		string get_hsx()
		{
			return hsx;
		}
		int get_month()
		{
			return month;
		}
		void set_mdt(string mdt)
		{
			this->mdt=mdt;
		}
		void set_hsx(string hsx)
		{
			this->hsx=hsx;
		}
		void set_month(int month)
		{
			this->month=month;
		}
		void input_dt()
		{
			input();
			cout<<"Nhap mau dien thoai: ";getline(cin,mdt);
			cout<<"Nhap hang san xuat: ";getline(cin,hsx);
			cout<<"Nhap thoi gian bao hanh (tinh theo thang): ";cin>>month;cin.ignore();
		}
		void show_dt()
		{
			cout<<mdt<<" | "<<hsx<<" | "<<get_sl()<<" | "<<get_gb()<<" | "<<month<<endl;	
		}
		bool operator <(Dienthoai x)
		{
			return get_gb()<x.get_gb();
		}
};
class Quanly
{
	private:
		Dienthoai a[50];
		int n;
	public:
		void input_ql()
		{
			cout<<"Nhap so luong danh sach dien thoai: ";cin>>n;cin.ignore();
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();
			}
			for(int i=0;i<n;i++)
			{
				a[i].input_dt();
			}
		}
		void giatritunghang()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i].get_hsx()>a[j].get_hsx())
					{
						Dienthoai x;
						x= a[i];
						a[i]=a[j];
						a[j]=x;
					}
				}
			}
			float sum=0;
			cout<<"\nTong gia tri cua tung hang san xuat !!!";
			cout<<"\n----------------------------------------\n";
			for(int i=0;i<n;i++)
			{
				sum+=a[i].tgtcmh();
				if(a[i].get_hsx()!=a[i+1].get_hsx())
				{
					cout<<a[i].get_hsx()<<" : "<<sum<<endl;
					sum=0;
				}
			}
			cout<<"----------------------------------------\n";
		}
		void top1baohanh()
		{
			int x=a[0].get_month();
			for(int i=0;i<n;i++)
			{
				if(x<a[i].get_month())
				{
					x=a[i].get_month();
				}
			}
			cout<<"\nDanh sach cac dien thoai co thoi gian bao hanh dai nhat !!!\n";
			cout<<"----------------------------------------\n";
			for(int i=0;i<n;i++)
			{
				if(a[i].get_month()==x)
				{
					a[i].show_dt();
				}
			}
			cout<<"----------------------------------------\n";
		}
		void sortgiam()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i]<a[j])
					{
						swap(a[i],a[j]);
					}
				}
			}
			cout<<"\nDanh sach sau khi sap xep giam dan !!!";
			cout<<"\n----------------------------------------\n";
			for(int i=0;i<n;i++)
			{
				a[i].show_dt();
			}
			cout<<"----------------------------------------\n";
		}
};
int main()
{
	Quanly x;
	x.input_ql();
	x.giatritunghang();
	x.top1baohanh();
	x.sortgiam();
}
