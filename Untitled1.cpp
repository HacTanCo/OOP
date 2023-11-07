//#include <iostream>
//using namespace std;
//
//class Date {
//private:
//    int D, M, Y; //ngày, tháng, nam
//public:
//    int nhuan(); //kiem tra nam nhuan
//    int ngaythang(); //tra ve so ngay trong thang
//    void nhap(); //co kiem tra du lieu
//    void xuat();
//    Date cong_1(); //cong 1 ngay vao doi tuong
//    Date cong_k(int k);
//    int ngaynam(); //tra ve so ngay cua nam
//    int khoangcach(Date d2);
//};
//
//int Date::nhuan() {
//    return ((Y % 4 == 0 && Y % 100 != 0) || (Y % 400 == 0));
//}
//
//int Date::ngaythang() {
//    if (M == 4 || M == 6 || M == 9 || M == 11)
//        return 30;
//    else if (M == 2)
//        return 28 + nhuan();
//    else
//        return 31;
//}
//
//void Date::nhap() {
//    int S;
//    int k;
//    do {
//        cout << "\nNhap vao ngay thang nam : " << endl;
//        cin >> D >> M >> Y;
//
//        S = ngaythang();
//        if ((D > 0) && (D <= S) && (M >= 1) && (M <= 12) && Y > 0)
//            k = 1; //hop le
//        else {
//            cout << "\nSai ngay! Hay nhap lai. " << endl;
//            k = 0; //khong hop le
//        }
//    } while (k == 0);
//}
//
//void Date::xuat() {
//    cout << D << '/' << M << '/' << Y << endl;
//}
//
//Date Date::cong_1() {
//    int S;
//    S = ngaythang();
//    if (++D > S) {
//        D = 1;
//        if (++M > 12) {
//            M = 1;
//            Y = Y + 1;
//        }
//    }
//    return *this; //doi tuong ma this tro toi
//}
//
//Date Date::cong_k(int k) {
//    Date t;
//    t.D = D;
//    t.M = M;
//    t.Y = Y;
//    for (int i = 1; i <= k; i++)
//        t.cong_1();
//    return t;
//}
//
//int Date::ngaynam() {
//    return nhuan() ? 366 : 365;
//}
//
//int Date::khoangcach(Date d2) {
//    Date d;
//    int s1 = 0, s2 = 0, T = 0;
//    for (d.M = 1, d.Y = Y; d.M < M; d.M++)
//        s1 += d.ngaythang();
//    s1 += D;
//
//    for (d2.Y++; d2.Y < Y; ++d2.Y)
//        T += d2.ngaynam();
//
//    for (d2.M = 1; d2.M < M; d2.M++)
//        s2 += d2.ngaythang();
//    s2 += d2.D;
//
//    if (d2.Y == Y) // X-----------d2---d1--------X, vd d1 = 20/10/2021, d2 = 15/7/2021
//        T = s1 - s2;
//    else //X-------d2----X--------------X------d1-------X
//    {
//        T += s1 + s2;
//    }
//    return T;
//}
//
//int main() {
//    Date d;
//    int k;
//    cout << "\n Nhap doi tuong ob: ";
//    d.nhap();
//    cout << "\n Du lieu cua doi tuong: ";
//    d.xuat();
//    d.cong_1();
//    cout << "\n Sau khi tang 1 ngay: ";
//    d.xuat();
//
//    Date d1, d2;
//    cout << "\n Nhap ngay thu nhat";
//    d1.nhap();
//    cout << "\n Nhap ngay thu hai";
//    d2.nhap();
//    cout << "\n Khoang cach giua d1 va d2 la: " << d1.khoangcach(d2);
//    return 0;
//}
//#include<bits/stdc++.h>
//using namespace std;
//class date
//{
//	private:
//		int d,m,y;
//	public:
//		void nhap();
//		void xuat();
//		int check();
//		void tang1();
//		void tangk();
//		void kc();
//};
//void date::nhap()
//{
//	cout<<"\nNhap ngay thang nam: ";
//	cin>>this->d>>this->m>>this->y;
//	while(check()==0)
//	{
//		cout<<"\nNgay thang nam ban vua nhap khong hop le vui long nhap lai: ";cin>>d>>m>>y;
//	}
//}
//void date::xuat()
//{
//	cout<<"\nXuat ngay thang nam: "<<d<<"/"<<m<<"/"<<y<<endl;
//	
//}
//int date::check()
//{ 
//	if( (d<=0 || d>31) || (m<=0 || m>12) || (y<=0) )
//	{
//		return 0;
//	}
//	else
//	{
//		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
//		{
//			return d<=31;
//		}
//		else if(m==4 || m==6 || m==9 || m==11)
//		{
//			return d<=30;
//		}
//		else if(m==2)
//		{
//			if( y%4==0 and (y%400==0 or y%100!=0) )
//			{
//				return d <= 29;
//			}
//			else
//			{
//				return d <= 28;
//			}
//		}
//	}
//	
//}
//void date::tang1()
//{
//	d++;
//	{
//		if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
//		{
//			if(d>31)
//			{
//				d=1;
//				m++;
//			}
//			
//		}
//		if(m==4 || m==6 || m==9 || m==11)
//		{
//			if(d>30)
//			{
//				d=1;
//				m++;
//			}
//		}
//		if(m==2)
//		{
//			if( y%4==0 and (y%400==0 or y%100!=0) )
//			{
//				if(d>29)
//				{
//					d=1;
//					m++;
//				}
//			}
//			else
//			{
//				if(d>28)
//				{
//					d=1;
//					m++;
//				}
//			}
//		}
//		
//		if(m>12)
//		{
//			m=1;
//			y++;
//		}
//		
//	}
//	
//}
//void date::tangk()
//{
//	int k;
//	cout<<"\nNhap so ngay ban muon tang len: ";cin>>k;
//	for(int i=0;i<k;i++)
//	{
//		tang1();
//	}
//}
//
//int main()
//{
//	date a;
//    a.nhap();
//    if(a.check()==0)
//    {
//    	cout<<"khong co ngay thang nam ban vua nhap!!!!!"<<endl;
//	}
//	else
//	{
//		a.xuat();
//		cout<<"\nSau khi tang len 1 ngay la !!!\n";
//		a.tang1();
//		a.xuat();
//		a.nhap();
//		cout<<"\nSau khi tang len k ngay la !!!\n";
//		a.tangk();
//		a.xuat();
//	}
//}
#include <bits/stdc++.h>
using namespace std;
class Date{
	private:
		int ngay,thang,nam;
		int A[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	public:
		bool namnhuan(int nam){
			if (nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) return true;
			return false;
		}
		void nhap(){
			while(1){
				cout<<"Nhap ngay thang nam ngan cach boi khoang trang: ";
				cin>>ngay>>thang>>nam;	
				if (namnhuan(nam)) A[2] = 29;  
				if (ngay > 0 && ngay <= A[thang] && thang > 0 && thang <= 12 && nam > 0){
					break;
				}
				else {
					cout<<"Ngay thang nam khong hop le vui long nhap lai\n";
				}
			}	
		}
		void xuat(){
			cout<<"Ngay-Thang-Nam: "<<ngay<<"-"<<thang<<"-"<<nam<<"\n";
		}
		void cong1ngay(){
			if (namnhuan(nam) ) A[2] = 29;
			else A[2] = 28;
			ngay+= 1;
			if (ngay > A[thang]) {
				thang += 1;
				ngay = 1;
			}
			if (thang > 12) {
				nam+=1;
				thang=1;
			}
		}
		
		void congkngay(){
			int k ;
			cout<<"Nhap k ngay can tang: ";
			cin>>k;
			for (int i = 1 ; i <= k ; i++) cong1ngay();
			cout<<"Sau khi tang "<<k<<" ngay ";
			xuat();
		}
		int sosanh(Date b){
			if (nam == b.nam && thang == b.thang && ngay == b.ngay) return 0;
			else if (nam > b.nam ||nam == b.nam && thang > b.thang 
				|| nam == b.nam && thang == b.thang && ngay > b.ngay ) return 1;
			else return -1;
		}
		Date tra_Date(){
			Date a;
			a.ngay = ngay;
			a.thang = thang;
			a.nam = nam;
			return a;
		}
		void kcngay(Date b){
			int khoangcach = 0;
			Date a1 = tra_Date();
			Date a2 = b;
			if (a1.sosanh(a2) == 1){
				while (a1.sosanh(a2) != 0){
					khoangcach++;
					a2.cong1ngay();
				}
			}
			else {
				while (a1.sosanh(a2) != 0){
					khoangcach++;
					a1.cong1ngay();
				}
			}
			cout<<"Khoang cach cua Date \n";
			tra_Date().xuat();
			cout<<"Va\n";
			b.xuat();
			cout<<"la: "<<khoangcach<<" Ngay";
		}
};
int main(){
	Date A,B;
	A.nhap();
	A.cong1ngay();
	cout<<"Sau khi cong 1 ngay ";
	A.xuat();
	A.congkngay();
	cout<<"Nhap Date can tinh khoang cach\n";
	B.nhap();
	A.kcngay(B);
}
