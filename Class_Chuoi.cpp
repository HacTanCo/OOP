#include<bits/stdc++.h>
using namespace std;
class chuoi
{
	private:
		string a;
		int n;
	public:
		void nhap();
		void hienthi();
		void tvkt(int i);
		void noi2chuoi(chuoi s2);
};
void chuoi::nhap()
{
	cout<<"\nNhap chuoi: ";
	getline(cin,a);
}
void chuoi::hienthi()
{
	cout<<"Chuoi vua nhap la: "<<a;
	n=a.length();
	cout<<"\nDo dai cua chuoi la: "<<n<<endl;
}
void chuoi::tvkt(int i)
{
	if(i<0 || i>=n) cout<<"khong co vi tri nay!!!"<<endl;
	else cout<<"Phan tu thu i trong chuoi la: "<<a[i]<<endl;
}
void chuoi::noi2chuoi(chuoi s2)
{
	chuoi s;
	s.a = a+s2.a;
	cout<<s.a<<endl;
	cout<<"Do dai cua chuoi sau khi noi la: "<<s.a.length()<<endl;
}
int main()
{
	chuoi s1,s2,s3;
	s1.nhap();
	s1.hienthi();
	int x;
	cout<<"Nhap vi tri can tim trong chuoi (x>=0 and x<do dai chuoi): ";cin>>x;
	fflush(stdin);
	s1.tvkt(x);
	s2.nhap();
	s2.hienthi();
	cout<<"Nhap vi tri can tim trong chuoi (x>=0 and x<do dai chuoi): ";cin>>x;
	fflush(stdin);
	s2.tvkt(x);
	cout<<"Chuoi sau khi noi giua s1 va s2 la: ";
	s1.noi2chuoi(s2);
}
