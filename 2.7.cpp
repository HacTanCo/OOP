#include<bits/stdc++.h>
using namespace std;
struct sv
{
	char msv[10],ht[20],lop[10];
	float avg;
};
void nhap(sv *a,int n)
{
	fflush(stdin);
	for(int i=0;i<n;i++)
	{
		cout<<"Sinh vien thu: "<<i+1<<endl;
		cout<<"Nhap ma sinh vien: ";gets(a[i].msv);
		cout<<"Nhap ho ten: ";gets(a[i].ht);
		cout<<"Nhap Lop: ";gets(a[i].lop);
		cout<<"Nhap diem trung binh: ";cin>>a[i].avg;
		fflush(stdin);
		cout<<endl;
	}
}
void xuat(sv *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Sinh vien thu: "<<i+1<<endl;
		cout<<"Ma sinh vien: "<<a[i].msv<<endl;
		cout<<"Ho ten: "<<a[i].ht<<endl;
		cout<<"Lop: "<<a[i].lop<<endl;
		cout<<"Diem trung binh: "<<a[i].avg<<endl<<endl;
	}
}
void sort(sv *a,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].avg<a[j].avg)
			{
				sv tam = a[i];
				a[i]=a[j];
				a[j]=tam;
			}
		}
		
	}
}
int main()
{
	int n;
	cout<<"So sinh vien can nhap la: ";cin>>n;
	cout<<endl; 
	sv *a=new sv[n];
	if (a == NULL) 
	{
		cout<<"\nLoi cap phat bo nho";
		exit(1);
	}
	nhap(a,n);
	sort(a,n);
	cout<<"\nSinh vien sau khi sap sep theo diem trung binh !!!\n\n";
	xuat(a,n);
	delete [] a;
}

