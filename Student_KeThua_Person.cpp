#include<bits/stdc++.h>
using namespace std;
class Person
{
	private:
		string hd,ten;
		int tuoi;
	public:
		Person(){}
		Person(string hd,string ten,int tuoi)
		{
			this->hd = hd;
			this->ten = ten;
			this->tuoi = tuoi;
		}
		//thieu ham set
		string get_hd()
		{
			return hd;
		}
		string get_ten()
		{
			return ten;
		}
		int get_tuoi()
		{
			return tuoi;
		}
		void input()
		{
			cout<<"\nNhap ho dem: ";getline(cin,hd);
			cout<<"Nhap ten: ";getline(cin,ten);
			cout<<"Nhap tuoi: ";cin>>tuoi;cin.ignore();
		}
		void show()
		{
			cout<<hd<<" "<<ten<<" | "<<tuoi<<" | ";
		}
		bool operator >(Person a)
		{
			if(ten != a.ten)
			{
				return ten > a.ten;
			}
			return hd > a.hd;
		}
};
class Student : public Person
{
	private:
		string msv,ndt;
		float avg;
	public:
		Student(){}
		Student(string msv,string ndt,float avg)
		{
			this->msv = msv;
			this->ndt = ndt;
			this->avg = avg;
		}
		// thieu set
		string get_msv()
		{
			return msv;
		}
		string get_ndt()
		{
			return ndt;
		}
		float get_avg()
		{
			return avg;
		}
		string xeploai()
		{
			if(get_avg()>=5.0 and get_avg()<=10.0)
			{
				return "dat";
			}
			else if(get_avg()>=0 and get_avg()<5.0)
			{
				return "khong dat";
			}	
		}
		void input_std()
		{
			input();
			cout<<"Nhap ma sinh vien: ";getline(cin,msv);
			cout<<"Nhap nganh dao tao: ";getline(cin,ndt);
			cout<<"Nhap diem trung binh cua sinh vien: ";cin>>avg;cin.ignore();
		}
		void show_std()
		{
			cout<<msv<<" | ";
			show();
			cout<<ndt<<" | ";
			cout<<avg<<" | ";
			cout<<xeploai()<<endl;
		}
};
class Quanly
{
	private:
		Student a[50];
		int n;
	public:
		void input_ql()
		{
			cout<<"Nhap so luong sinh vien (0 < n <= 50): ";cin>>n;cin.ignore();
			while(n<=0 or n>50)
			{
				cout<<"Nhap lai: ";cin>>n;cin.ignore();
			}
			for(int i=0;i<n;i++)
			{
				a[i].input_std();
			}
			//kiem tra msv
		}
		void sort()
		{
			for(int i=0;i<n-1;i++)
			{
				for(int j=i+1;j<n;j++)
				{
					if(a[i] > a[j])
					{
						Student x;
						x = a[i];
						a[i] = a[j];
						a[j] = x;
					}
				}
			}
			cout<<"\nDanh sach sinh vien tang dan theo ho ten !!!\n\n";
			for(int i=0;i<n;i++)
			{
				a[i].show_std();
			}
		}
		void top1_avg()
		{
			float max = a[0].get_avg();
			for(int i=0;i<n;i++)
			{
				if(max < a[i].get_avg()) 
				{
					max = a[i].get_avg();
				}
			}
			cout<<"\nDanh sach sinh vien co diem trung binh cao nhat !!!\n\n";
			for(int i=0;i<n;i++)
			{
				if(a[i].get_avg() == max)
				{
					a[i].show_std();
				}
			}
		}
		void age_avg()
		{
			float x=0,dem=0;
			for(int i=0;i<n;i++)
			{
				if(a[i].xeploai()=="dat")
				{
					x += a[i].get_tuoi();
					dem++;
				}
			}
			if(dem!=0)
			{
				cout<<"\nTuoi trung binh cua "<<dem<<" sinh vien xep loai dat la: "<<fixed<<setprecision(1)<<x/dem<<endl;
			}
			else
			{
				cout<<"\nKhong co sinh vien xep loai dat !!!"<<endl;
			}
		} 
		void nhap_ndt()
		{
			string x="ndt";
			int i=0;
			while(i<n)
			{
				if(a[i].get_ndt() == x)
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
			cout<<"\nDanh sach sau khi xoa Nganh Dao Tao: "<<x<<endl<<endl;
			for(int i=0;i<n;i++)
			{
				a[i].show_std();
			}
		}
};
int main()
{
	Quanly x;
	x.input_ql();
	x.sort();
	x.top1_avg();
	x.age_avg();
	x.nhap_ndt();
}
