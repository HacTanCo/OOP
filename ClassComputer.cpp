#include<bits/stdc++.h>
using namespace std;

class Computer{
	private:
		string mamt, hsx;
		float giaban,namsx;
	public:
		Computer(){
		}
		Computer(string mamt, string hsx, float giaban, float namsx){
			this->mamt=mamt;
			this->hsx=hsx;
			this->giaban=giaban;
			this->namsx=namsx;
		}
		string get_mamt(){
			return mamt;
		}
		string get_hsx(){
			return hsx;
		}
		float get_namsx(){
			return namsx;
		}
		float get_giaban(){
			return giaban;
		}
		void Nhap(){
			cout<<"\nNhap ma may: "; cin.ignore();
			getline(cin, mamt);

			cout<<"Nhap hang san xuat: "; 
			getline(cin, hsx);

			cout<<"Nhap nam sx: "; cin>>namsx;

			cout<<"Nhap gia ban: "; cin>>giaban;

		}

		void Hienthi(){
			cout<<"\n|| Ma: "<<mamt<<" || Hang san xuat: "<<hsx<<" || Nam san xuat: "<<namsx<<" || Gia ban: "<<giaban;
		}
};

class Laptop:public Computer{
	private:
		string hdh;
		float can, doday, kichthuoc;
	public:
		Laptop(){}
		Laptop(string hdh, float can,float doday, float kichthuoc){
			this->hdh=hdh;
			this->can=can;
			this->doday=doday;
			this->kichthuoc=kichthuoc;
		}
		
		string get_hdh(){
			return hdh;
		}
		float get_can(){
			return can;
		}
		float get_doday(){
			return doday;
		}
		float get_kichthuoc(){
			return kichthuoc;
		}		

		bool operator > (Laptop a){
			return (this->Tinhgtcl() > a.Tinhgtcl());
		}
			
		void NhapLT(){
			Nhap();
			cout<<"Nhap can nang (gram): "; cin>>can;
			cout<<"Nhap do day (mm): "; cin>>doday;
			cout<<"Nhap kich thuoc man hinh (inch): "; cin>>kichthuoc;
			cout<<"Nhap He dieu hanh: "; cin>>hdh;
		}
		
		long TinhNamsd(){
			long namsd=2023-get_namsx();
			return namsd;
		}
		
		long Tinhgtcl(){
			float gtcl=0;
			if(get_hdh()=="Windows" or get_hdh()=="windows"){				
				gtcl=get_giaban() - TinhNamsd()*0.1*get_giaban();
				return gtcl;
			}
			else{
				gtcl=get_giaban()  - TinhNamsd()*0.05*get_giaban();
				return gtcl;
			}
			
		}
		void HienthiLT(){
			Hienthi();
			cout<<"|| Can nang: "<<can<<" || Do day: "<<doday<<" || Kich thuoc man hinh: "<<kichthuoc<<" || So nam su dung: "<<TinhNamsd()<<" || Gia tri con lai: "<<Tinhgtcl();

		}	
};

class Quanly{
	int n;
	Laptop a[50];
	public:
		void QlNhap(){
			do{
				cout<<"Nhap so luong: "; cin>>n;
			}while(n>50);
			for(int i =0;i<n;i++)
				a[i].NhapLT();
		}

		void Sapxep(){
			cout<<"\n---- Sap xep tang dan theo tieu chi gia tri con lai ----\n";
			
			for(int i=0;i<n-1;i++)
				for(int j=i+1;j<n;j++)
					if(a[i].Tinhgtcl() > a[j].Tinhgtcl())					
						swap(a[i],a[j]);					
				
			for(int i=0;i<n;i++)
				a[i].HienthiLT();
		}

		void namsdMax(){
			cout<<"\n\n---- Nam su dung nhieu nhat -----\n";
			float max=a[0].TinhNamsd();
			for(int i=0;i<n;i++)
				if(a[i].TinhNamsd() > max)
					max=a[i].TinhNamsd();
					
			for(int i=0;i<n;i++)
				if(a[i].TinhNamsd() == max)
					a[i].HienthiLT();
			
		}
};

int main(){
	Quanly ql;
	ql.QlNhap();
	ql.Sapxep();
	ql.namsdMax();
}