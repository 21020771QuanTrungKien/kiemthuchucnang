#include <bits/stdc++.h>
using namespace std;

double tienTroCap(double base, int dependents, char ageGroup) {
    double trocap = 0.0;
    if (ageGroup == 't') {
        if (dependents < 0) {
            return -1;  // Trả về -1 nếu dependents là số âm
        }
        if (dependents == 0) {
            return 0;
        } else if (dependents == 1) {
            trocap = base + 0.3 * base;
        } else {
            trocap = base + 0.5 * base;
            if (dependents >= 3) {
                trocap += 0.3 * base;
            }
        }
    } else if (ageGroup == 'g') {
        if (dependents < 0) {
            return -1;  // Trả về -1 nếu dependents là số âm
        } else if (dependents == 0) {
            trocap = base * 0.3;
        } else if (dependents == 1) {
            trocap = base + 0.5 * base;
        } else {
            trocap = base + 0.8 * base;
            if (dependents >= 3) {
                trocap += 0.2 * base;
            }
        }
    }
    return trocap;
}

int main() {
    double base;
    int dependents;
    char age_group;
    double trocap;

    while (true) {  // Lặp lại việc nhập thông tin nếu trocap = -1
        cout << "Nhap muc tien tro cap co so (dolar): ";
        cin >> base;
        cout << "Nhap so nguoi phu thuoc: ";
        cin >> dependents;
        cout << "Nhap nhom tuoi (t/g): ";
        cin >> age_group;

        trocap = tienTroCap(base, dependents, age_group);

        if (trocap == -1) {
            cout << "Nhap lai thong tin. So nguoi phu thuoc khong the la so am." << endl;
        } else {
            break;  // Thoát khỏi vòng lặp nếu trocap không bằng -1
        }
    }

    if (trocap == 0) {
        cout << "Khong duoc tro cap (co lam thi moi co an)";
    } else {
        cout << "Tien tro cap duoc tinh la: " << trocap << " dolar" << endl;
    }

    return 0;
}
