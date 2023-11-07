#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class KhachHang {
    string maSo, hoTen, diaChi;
    int soMetKhoi, ngay, thang, nam;
public:
    void nhap() {
        cout << "Nhap ma so: "; cin >> maSo;
        cin.ignore();
        cout << "Nhap ho ten: "; getline(cin, hoTen);
        cout << "Nhap dia chi: "; getline(cin, diaChi);
        cout << "Nhap so met khoi tieu thu: "; cin >> soMetKhoi;
        cout << "Nhap ngay/thang/nam thanh toan: "; cin >> ngay; cin.ignore(); cin >> thang; cin.ignore(); cin >> nam;
    }
    void xuat() {
        cout << left << setw(10) << maSo << setw(20) << hoTen << setw(40) << diaChi
             << setw(20) << soMetKhoi
             << setw(2) << ngay << "/" << setw(2) << thang << "/" << setw(6) << nam
             << setw(20) << tinhTien() << endl;
    }
    int tinhTien() {
        if (soMetKhoi <= 100) return soMetKhoi * 2000;
        else if (soMetKhoi > 100 && soMetKhoi <= 200) return 100 * 2000 + (soMetKhoi - 100) * 3000;
        else return 100 * 2000 + 100 * 3000 + (soMetKhoi - 200) * 5000;
    }
};

class QuanLy {
    KhachHang ds[100];
    int n;
public:
    void nhap() {
        cout << "Nhap so luong khach hang: "; cin >> n;
        for (int i = 0; i < n; i++) ds[i].nhap();
    }
    void xuat() {
        cout << left 
             << setw(10) << "Ma So" 
             << setw(20) << "Ho Ten" 
             << setw(40) << "Dia Chi"
             << setw(20) <<"So Met Khoi Tieu Thu"
             << setw(10) <<"Ngay Thanh Toan"
             << setw(20) <<"So Tien Phai Tra" 
             << endl;
        for (int i = 0; i < n; i++) ds[i].xuat();
    }
    
    void khachHangTienCaoNhat() {
        int maxTien = ds[0].tinhTien();
        for (int i = 1; i < n; i++)
            if (ds[i].tinhTien() > maxTien)
                maxTien = ds[i].tinhTien();
                
        cout<< "\nKhach hang co so tien phai tra cao nhat: \n";
        
        for (int i = 0; i < n; i++)
            if (ds[i].tinhTien() == maxTien)
                ds[i].xuat();
    }
};

int main() {
    QuanLy ql;
    ql.nhap();
    ql.xuat();
    
    ql.khachHangTienCaoNhat();
    
    return 0;
}

