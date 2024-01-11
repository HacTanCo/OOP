#include<bits/stdc++.h>
using namespace std;
class airship
{
	private:
		int khtd,hhtd;
	public:
		void fill()
		{
			cout<<"Nhap so luong khach hang toi da: ";cin>>khtd;
			cout<<"Nhap trong luong hang hoa toi da: ";cin>>hhtd;
			fflush(stdin);
		}
		void show()
		{
			cout<<"\nSo luong khach hang toi da: "<<khtd<<endl;
			cout<<"Trong luong hang hoa toi da: "<<hhtd<<endl;
		}
};
class airplane : public airship
{
	private:
		string kdc;
	public:
	void fillap()
	{
		cout<<"\nNhap kieu dong co (dong co canh quat || dong co phan luc): ";getline(cin,kdc);
		string gan;
		for(int i=0;i<kdc.size();i++)
		{
			gan += tolower(kdc[i]);
		}
		while(gan!="dong co canh quat" and gan!="dong co phan luc")
		{
			cout<<"Nhap lai: ";getline(cin,kdc);
			gan="";
			for(int i=0;i<kdc.size();i++)
			{
				gan += tolower(kdc[i]);	
			}	
		}			
	}
	void showap()
	{
		cout<<"Kieu dong co: "<<kdc<<endl;	
	}	
};
class balloon : public airship
{
	private:
		string nl;
	public:
		void fillbl()
		{
			cout<<"\nNhap loai nhien lieu (hydrogen || helium): ";getline(cin,nl);
			string gan;
			for(int i=0;i<nl.size();i++)
			{
				gan += tolower(nl[i]);
			}
			while(gan!="hydrogen" and gan!="helium")
			{
				cout<<"Nhap lai: ";getline(cin,nl);
				gan="";
				for(int i=0;i<nl.size();i++)
				{
					gan += tolower(nl[i]);
				}
			}
		}
		void showbl()
		{
			cout<<"Loai nhien lieu: "<<nl<<endl;
		}
};
int main ()			
{
	airship x;
	x.fill();
	x.show();
	airplane y;
	y.fillap();
	y.showap();
	balloon z;
	z.fillbl();
	z.showbl();
}
