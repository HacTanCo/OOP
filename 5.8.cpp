#include<bits/stdc++.h>
using namespace std;
class Hvuong
{
	private:
		float ddc;
	public:
		float get_ddc()
		{
			return ddc;
		}
		void fill()
		{
			cout<<"\nNhap do dai canh 1: ";cin>>ddc;
		}
		void show()
		{
			cout<<"Do dai canh 1: "<<ddc<<endl;
		}
		void dt()
		{
			cout<<"Dien tich hinh vuong: "<<ddc*ddc<<endl;
		}
		void cv()
		{
			cout<<"Chu vi hinh vuong: "<<ddc*4<<endl;
		}
};
class Chunhat : public Hvuong
{
	private:
		float x;
	public:
		void fill_cn()
		{
			fill();
			cout<<"Nhap do dai canh 2: ";cin>>x;
		}
		void show_cn()
		{
			show();
			cout<<"DO dai canh 2: "<<x<<endl;
		}
		void dt_cn()
		{
			cout<<"Dien tich hinh chu nhat: "<<get_ddc()*x<<endl;
		}
		void cv_cn()
		{
			cout<<"Chu vi hinh chu nhat: "<<(get_ddc()+x) * 2<<endl;
		}
};
int main()
{
	Hvuong x;
	x.fill();
	x.show();
	x.dt();
	x.cv();
	Chunhat y;
	y.fill_cn();
	y.show_cn();
	y.dt_cn();
	y.cv_cn();
}
