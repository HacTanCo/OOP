#include<bits/stdc++.h>
using namespace std;
class Computer
{
	private:
		string mmt,hsx;
		int nsx;
		float gb;
	public:
		Computer(){}
		Computer(string mmt,string hsx,int nsx,float gb)
		{
			this->mmt=mmt;
			this->hsx=hsx;
			this->nsx=nsx;
			this->gb=gb;
		}
		string get_mmt()
		{
			return mmt;
		}
		string get_hsx()
		{
			return hsx;
		}
		int get_nsx()
		{
			return nsx;
		}
		float get_gb()
		{
			return gb;
		}
		void fillPC()
		{
			cout<<"\nNhap ma may tinh: ";getline(cin,mmt);
			cout<<"Nhap hang san xuat: ";getline(cin,hsx);
			cout<<"Nhap nam san xuat: ";cin>>nsx;
			cout<<"Nhap gia ban: ";cin>>gb;
		}
		void showPC()
		{
			cout<<"\n-----------------------------\n";
			cout<<"Ma may tinh: "<<mmt<<endl;
			cout<<"Hang san xuat: "<<hsx<<endl;
			cout<<"Nam san xuat: "<<nsx<<endl;
			cout<<"Gia ban: "<<(int)gb;
			
		}
		
};
class Laptop : public Computer
{
	private:
		float kt;
		int cn,dd;
		string hdh;
	public:
		Laptop(){}
		Laptop(float cn,float dd,float kt,string hdh)
		{
			this->cn=cn;
			this->dd=dd;
			this->kt=kt;
			this->hdh=hdh;
		}
		string get_hdh()
		{
			return hdh;
		}
		int get_cn()
		{
			return cn;
		}
		int get_dd()
		{
			return dd;
		}
		float get_kt()
		{
			return kt;
		}
		int snsd()
		{
			return 2023-get_nsx();
		}
		float gtcl()
		{
			string gan;
			for(int i=0;i<hdh.size();i++)
			{
				gan += tolower(hdh[i]);
			}
			if(gan=="windows")// 19.000.000 - 3 * 0.1 * 19.000.000 = 13.300.000
			{
				return get_gb() - snsd() * 0.1 * get_gb();
			}
			else // 29.000.000 - 7 * 0.1 * 29.000.000 == 8.700.000
			{
				return get_gb() - snsd() * 0.05 *get_gb();
			}
		}
		bool operator >(Laptop a)
		{
			return gtcl() > a.gtcl();
		}
		void fillLap()
		{
			fillPC();
			cout<<"Nhap can nang: ";cin>>cn;
			cout<<"Nhap do day: ";cin>>dd;
			cout<<"Nhap kich thuoc: ";cin>>kt;fflush(stdin);
			cout<<"Nhap he dieu hanh: ";getline(cin,hdh);
		}
		void showLap()
		{
			showPC();
			cout<<"\nCan nang: "<<cn<<endl;
			cout<<"Do day: "<<dd<<endl;
			cout<<"Kich thuoc thuoc man hinh: "<<kt<<endl;
			cout<<"So nam su dung: "<<snsd()<<endl;
			cout<<"Gia tri con lai: "<<(int)gtcl()<<endl;
			cout<<"\n-----------------------------\n";
		}
};
class Quanly
{
	private:
		Laptop a[50];
		int n;
	public:
		void fillQl()
		{
			cout<<"Nhap so luong may tinh xach tay: ";cin>>n;
			fflush(stdin);
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;
				fflush(stdin);
			}
			for(int i=0;i<n;i++)
			{
				a[i].fillLap();
			}
		}
		void sorttang()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i].gtcl() > a[j].gtcl())
					{
						Laptop tam;
						tam = a[i];
						a[i] = a[j];
						a[j] = tam;
					}
				}
			}
			cout<<"\nDanh sach sau khi sap xep tang dan !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].showLap();
			}
		}
		void top1nsd()
		{
			int max=a[0].snsd();
			for(int i=0;i<n;i++)
			{
				if(max<a[i].snsd())
				{
					max = a[i].snsd();
				}
			}
			cout<<"\nDanh sach may tinh xach tay co so nam su dung nhieu nhat !!!\n";
			for(int i=0;i<n;i++)
			{
				if(a[i].snsd()==max)
				{
					a[i].showLap();
				}
			}
		}
		void xoahsx()
		{
			string nhaphsx;
			cout<<"\nNhap hang san xuat can xoa: ";getline(cin,nhaphsx);
			string gan;
			for(int i=0;i<nhaphsx.size();i++)
			{
				gan += tolower(nhaphsx[i]);
			}
			int i=0;
			while(i<n)
			{
				if(a[i].get_hsx() == gan)
				{
					for(int j=i;j<n-1;j++)
					{
						a[j] = a[j+1];
					}
					n--;
				}
				else
				{
					i++;
				}
			}
//			for(int i=0;i<n;i++)
//			{
//				if(a[i].get_hsx() == gan)
//				{
//					for(int j=i;j<n-1;j++)
//					{
//						a[j] = a[j+1];
//					}
//					n--;
//				}
//			}
			cout<<"\nDanh sach laptop sau khi xoa lap top "<<nhaphsx<<" !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].showLap();
			}
		}
		
};
int main()
{
	Quanly a;
	a.fillQl();
	a.sorttang();
	a.top1nsd();
	a.xoahsx();
}
