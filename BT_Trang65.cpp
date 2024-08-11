#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Khai báo cấu trúc phân số
typedef struct {
    int tu; // Tử số
    int mau; // Mẫu số
} PhanSo;


// Hàm nhập phân số
void nhapPhanSo(PhanSo* ps) {
    printf("Nhap tu so: ");
    scanf("%d", &ps->tu);
    do {
        printf("Nhap mau so (khac 0): ");
        scanf("%d", &ps->mau);
        if (ps->mau == 0) {
            printf("Mau so phai khac 0. vui long nhap lai !.\n");
        }
    } while (ps->mau == 0);
}

// Hàm xuất phân số
void xuatPhanSo(PhanSo ps) {
    if (ps.mau == 1) {
        printf("%d\n", ps.tu);
    }
    else {
        printf("%d/%d\n", ps.tu, ps.mau);
    }
}

// Hàm tìm ước số chung lớn nhất (ƯCLN)
int ucln(int a, int b) {
    if (b == 0) return a;
    return ucln(b, a % b);
}

// Hàm tối giản phân số
void toiGianPhanSo(PhanSo* ps) {
    int gcd = ucln(ps->tu, ps->mau);
    ps->tu /= gcd;
    ps->mau /= gcd;
}

// Hàm tính tổng của hai phân số
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau + ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính hiệu của hai phân số
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính tích của hai phân số
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.tu;
    ketQua.mau = ps1.mau * ps2.mau;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

// Hàm tính thương của hai phân số
PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2) {
    PhanSo ketQua;
    ketQua.tu = ps1.tu * ps2.mau;
    ketQua.mau = ps1.mau * ps2.tu;
    toiGianPhanSo(&ketQua);
    return ketQua;
}

void main() {
    PhanSo ps1, ps2, tong, hieu, tich, thuong;

    // Nhap hai phan so
    printf("Nhap phan so thu nhat:\n");
    nhapPhanSo(&ps1);
    printf("Nhap phan so thu hai:\n");
    nhapPhanSo(&ps2);

    // Xuat hai phan so
    printf("Phan so thu nhat: ");
    xuatPhanSo(ps1);
    printf("Phan so thu hai: ");
    xuatPhanSo(ps2);

    // Tinh va xuat tong
    tong = tongPhanSo(ps1, ps2);
    printf("Tong cua hai phan so: ");
    xuatPhanSo(tong);

    // Tinh va xuat hieu
    hieu = hieuPhanSo(ps1, ps2);
    printf("Hieu cua hai phan so: ");
    xuatPhanSo(hieu);

    // Tinh va xuat tich
    tich = tichPhanSo(ps1, ps2);
    printf("Tich cua hai phan so: ");
    xuatPhanSo(tich);

    // Tinh va xuat thuong
    thuong = thuongPhanSo(ps1, ps2);
    printf("Thuong cua hai phan so: ");
    xuatPhanSo(thuong);
}



