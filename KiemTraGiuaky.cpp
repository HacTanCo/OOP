#include <iostream>
#define max 3 // nhap toi da 3 ngay , thang , nam 
using namespace std;

class Date
{
	private:
		int y, m, d;
	public:
		Date()
		{
			y = 1970;
			m = 1;
			d = 1;
		}
		Date(int y, int m, int d)		
		{
			this->y=y;
			this->m=m;
			this->d=d;
		}
		int daysln(int m)
		{
			if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
			if(m == 4 || m == 6 || m == 9 || m ==11) return 30;
			if(m == 2)
			{
				if(y % 4 == 0) return 29;
				else return 28;
			}
		}

			void insert(){
				for(int i = 0 ; i<max;i++){
			do
			{
				cout << "Nhap nam: ";cin >> y;
				if(y < 0) cout << "Error!";
			}while(y < 0);
			do
			{
				cout << "Nhap thang: ";cin >> m;
				if(m < 1 || m > 12) cout << "Error!	";
			}while(m < 1 || m > 12);
			do
			{
				cout << "Nhap ngay: ";cin >> d;
				if(d < 1 || d > daysln(d)) cout << "Error!";
			} while (d < 1 || d > daysln(d));
		}
		}
	
		void normalize()
		{
			if (m > 12)
			{
				y = y + m / 12;
				m = m % 12;
			}
			if (d > daysln(m))
			{
				cout << (m = m + d / daysln(m));
				d = d % daysln(m);
			}
		}
		void advance(int y, int m , int d)
		{
			this->y = this->y+y;
			this->m = this->m+m;
			this->d = this->d+d;
		}
		void reset(int y, int m , int d)
		{
			this->y=y;
			this->m=m;
			this->d=d;
		}
		
		void print()
		{
			for(int i=0; i<max;i++){
				cout << "Ngay: " << d << "\t" <<" Thang: " << m  << "  Nam: " << y << endl;
			}
		}
		
};
bool Date::compare(Date d2){
	if(nam>d2.nam){
		return true;
	}else if(nam<d2.nam){
		return false;
	}
	
	if(nam==d2.nam){
		if(thang>d2.thang){
			return true;
		}
		else if(thang < d2.thang){
			return false;
		}
	}
	if(thang==d2){
		if(ngay>d2.ngay) return true;
		else if(ngay<d2.ngay)
		return false;
	}
	
}
int main()
{
//	Date d;
//	d.insert();
//	d.print();
	int n;
	cout<<"nhap so phan tu:";
	cin>>n;
	date a[n];

	for (int i=0;i<n;i++){
		cout<<"ngay / thang / nam :  "<<i+1<<":\n";
		a[i].setdate();
}

		for (int i=0;i<n-1;i++)
			for (int j=i+1;j<n;j++)
				if (a[i].compare(a[j])==true)
						a[i].change(a[j]);
				cout<<" sau khi sap xep la:\n";
	for (int i=0;i<n;i++){
			a[i].print(); cout<<endl;
} 
	
	//Cau2
	int m;
	cout<<"nhap so nguyen (int) =";
	cin>>m;
	cout<<"ngay / thang / nam =  "<<m<<" :\n";
	for (int i=0;i<n;i++)
		if (a[i].getyear() == m){
				a[i].print(); cout<<endl;
	// Em con nhieu` loi can` debug mong thay thong cam
}
}
