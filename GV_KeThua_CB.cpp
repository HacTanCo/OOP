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
class Canbo
{
	private:
		string mcb,ht;
		Date nvcc;
	public:
		Canbo(){}
		Canbo(string mcb, string ht, Date nvcc)
		{
			this->mcb = mcb;
			this->ht = ht;
			this->nvcc = nvcc;
		}
		void set_mcb(string mcb)
		{
			this->mcb = mcb;
		}
		void set_ht(string ht)
		{
			this->ht = ht;
		}
		void set_date(Date nvcc)
		{
			this->nvcc = nvcc;
		}
		
		string get_mcb()
		{
			return mcb;
		}
		string get_ht()
		{
			return ht;
		}
		Date get_nvcc()
		{
			return nvcc;
		}
		void fillcb()
		{
			cout<<"\nNhap ma can bo: ";getline(cin,mcb);
			cout<<"Nhap ho ten: ";getline(cin,ht);
			nvcc.fill();
		}
		void showcb()
		{
			cout<<"\n--------------------------------\n";
			cout<<"Ma can bo: "<<mcb<<endl;
			cout<<"Ho ten: "<<ht<<endl;
			nvcc.show();
			
		}
		bool operator >(Canbo a)
		{
			if(nvcc.y != a.nvcc.y)
			{
				return nvcc.y > a.nvcc.y;
			}
			if(nvcc.m != a.nvcc.m )
			{
				return nvcc.m > a.nvcc.m;
			}
			if(nvcc.d != a.nvcc.d)
			{
				return nvcc.d > a.nvcc.d;
			}
			return false;
		}
};
class Giangvien : public Canbo
{
	private:
		string dv;
		float hsl,pccv;
	public:
		Giangvien(){}
		Giangvien(string dv,float hsl, float pccv)
		{
			this->dv = dv;
			this->hsl = hsl;
			this->pccv = pccv;
		}
		void set_dv(string dv)
		{
			this->dv = dv;
		}
		void set_hsl(float hsl)
		{
			this->hsl = hsl;
		}
		void set_pccv(float pccv)
		{
			this->pccv = pccv;
		}
		string get_dv()
		{
			return dv;
		}
		float get_hsl()
		{
			return hsl;
		}
		float get_pccv()
		{
			return pccv;
		}
		float tienluong()
		{
			return hsl * 1490000 + pccv;
		}
		void fillgv()
		{
			fillcb();
			cout<<"Nhap don vi: ";getline(cin,dv);
			cout<<"Nhap he so luong: ";cin>>hsl;
			cout<<"Nhap phu cap chuc vu: ";cin>>pccv;
			fflush(stdin);	
		}
		void showgv()
		{
			showcb();
			cout<<"\nDon vi: "<<dv<<endl;
			cout<<"He so luong: "<<hsl<<endl;
			cout<<"Phu cap chuc vu: "<<(int)pccv<<endl;
			cout<<"Tien luong: "<<(int)tienluong();
			cout<<"\n--------------------------------\n";			
		}
};
class Quanly
{
	private:
		Giangvien a[50];
		int n;
	public:
		void check_mcb()
		{
//			bool check;
//			for(int i=0;i<n;i++)
//			{
//				do
//				{
//					check=false;
//					a[i].fillgv();
//					for(int j=0;j<i;j++)
//					{
//						if(a[i].get_mcb() == a[j].get_mcb())
//						{
//							cout<<"\nMa can bo bi trung, vui long nhap lai !!!\n";
//							check = true;
//							break;
//						}
//					}
//				} while(check == true);	
//			}
			bool check;
			for(int i=0;i<n;i++)
			{
				while(1)
				{
					check = false;
					a[i].fillgv();
					for(int j=0;j<i;j++)
					{
						if(a[i].get_mcb() == a[j].get_mcb())
						{
							cout<<"\nMa can bo bi trung, vui long nhap lai !!!\n";
							check = true;
							break;
						}
					}
					if(!check) break;
				}
			}
		}
		void fillds()
		{
			cout<<"\nNhap so luong giang vien: ";cin>>n;
			fflush(stdin);
			while(n>50 or n<=0)
			{
				cout<<"Nhap lai: ";cin>>n;
				fflush(stdin);
			}
			check_mcb();
		}
		void sorttang()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i] > a[j])
					{
						Giangvien tam;
						tam = a[i];
						a[i] = a[j];
						a[j] = tam;
					}
				}
			}
			cout<<"\nDanh sach tang dan theo ngay vao co quan !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].showgv();
			}
		}
		void avg()
		{
			float sum=0;
			for(int i=0;i<n;i++)
			{
				sum += a[i].tienluong();
			}
			cout<<"\n--------------------------------------------------\n";
			cout<<"Luong trung binh cua "<<n<<" giang vien: "<<int(sum);
			cout<<"\n--------------------------------------------------\n";
		}
		void inbangluong()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i].get_dv()>a[j].get_dv())
					{
						swap(a[i],a[j]);
					}
				}
			}
			string donvi;
			donvi = a[0].get_dv();
			cout<<"\nBang luong cua don vi: "<<donvi<<endl;
			for(int i=0;i<n;i++)
			{
				if(a[i].get_dv() == donvi)
				{
					a[i].showgv();
				}
				else
				{
					donvi=a[i].get_dv();
					cout<<"\nBang luong cua don vi: "<<donvi<<endl;
					a[i].showgv();
				}
			}
		}
		void tongtiencuamoidonvi()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i].get_dv()>a[j].get_dv())
					{
						swap(a[i],a[j]);
					}
				}
			}
			long long sum=0;
			cout<<"\nTong tien theo tung don vi !!!\n";
			cout<<"\n--------------------------------\n";
			for(int i=0;i<n;i++)
			{
				sum += a[i].tienluong();
				if(a[i].get_dv() != a[i+1].get_dv())
				{
					
					cout<<a[i].get_dv()<<" : "<<sum<<endl;
				}
			}
			cout<<"--------------------------------";
		}
		void xoa()
		{
			string x;cout<<"\nNhap ma can bo can xoa: ";getline(cin,x);
			int i=0;
			while(i<n)
			{
				if(a[i].get_mcb() == x)
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
			cout<<"\nDanh sach sau khi xoa can bo "<<x<<" la !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].showgv();
			}
		}

		void them()
		{
			Giangvien x;
			cout<<"\nNhap can bo can them !!!\n";
			x.fillgv();
			for(int i=0;i<n;i++)
			{
				if(x.get_mcb() == a[i].get_mcb())
				{
					cout<<"\nMa can bo da ton tai trong danh sach, vui long nhap lai !!!\n";
					check_mcb();
				}
				if(n==50)
				{
					cout<<"\nDanh sach da day, khong them bo sung them duoc nua !!!";return;
				}
			}
			a[n]=x;
			n++;
			cout<<"\nDanh sach sau khi them la !!!\n";
			for(int i=0;i<n;i++)
			{
				a[i].showgv();
			}
		}
		void timkiemhotronghoten()
		{
			string x;cout<<"\nNhap ho can tim: ";getline(cin,x);
			cout<<"\nDanh sach giang vien co ho: "<<x<<" !!!\n";
			for(int i=0;i<n;i++)
			{
				if(a[i].get_ht().find(x) != string::npos)
				{
					a[i].showgv();
				}
			}
		}
};
int main()
{
	Quanly a;
	a.fillds();
	a.sorttang();
	a.avg();
	a.inbangluong();
	a.tongtiencuamoidonvi();
	a.xoa();
	a.them();
	a.timkiemhotronghoten();
}
