#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 50


typedef struct {
    int tu; 
    int mau;
} PhanSo;


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

// Hàm nhập danh sách các phân số
void nhapDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan so thu %d:\n", i + 1);
        printf("Nhap tu so: ");
        scanf("%d", &ds[i].tu);
        do {
            printf("Nhap mau so (khac 0): ");
            scanf("%d", &ds[i].mau);
            if (ds[i].mau == 0) {
                printf("Mau so phai khac 0. Vui long nhap lai.\n");
            }
        } while (ds[i].mau == 0);
        toiGianPhanSo(&ds[i]); 
    }
}

// Hàm xuất một phân số
void xuatPhanSo(PhanSo ps) {
    if (ps.mau == 1) {
        printf("%d ", ps.tu);
    }
    else {
        printf("%d/%d ", ps.tu, ps.mau);
    }
}

// Hàm xuất danh sách các phân số
void xuatDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        xuatPhanSo(ds[i]);
    }
    printf("\n");
}

// Hàm tính giá trị của phân số dưới dạng số thực
double giaTriPhanSo(PhanSo ps) {
    return (double)ps.tu / ps.mau;
}

// Hàm tìm phân số có giá trị lớn nhất
PhanSo phanSoMax(PhanSo ds[], int n) {
    PhanSo max = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(ds[i]) > giaTriPhanSo(max)) {
            max = ds[i];
        }
    }
    return max;
}

// Hàm tìm phân số có giá trị nhỏ nhất
PhanSo phanSoMin(PhanSo ds[], int n) {
    PhanSo min = ds[0];
    for (int i = 1; i < n; i++) {
        if (giaTriPhanSo(ds[i]) < giaTriPhanSo(min)) {
            min = ds[i];
        }
    }
    return min;
}

// Hàm tính tổng của các phân số
PhanSo tongDanhSachPhanSo(PhanSo ds[], int n) {
    PhanSo tong = { 0, 1 };
    for (int i = 0; i < n; i++) {
        tong.tu = tong.tu * ds[i].mau + ds[i].tu * tong.mau;
        tong.mau = tong.mau * ds[i].mau;
        toiGianPhanSo(&tong);
    }
    return tong;
}

// Hàm tính tích của các phân số
PhanSo tichDanhSachPhanSo(PhanSo ds[], int n) {
    PhanSo tich = { 1, 1 };
    for (int i = 0; i < n; i++) {
        tich.tu = tich.tu * ds[i].tu;
        tich.mau = tich.mau * ds[i].mau;
        toiGianPhanSo(&tich);
    }
    return tich;
}

// Hàm xuất nghịch đảo giá trị của các phân số
void nghichDaoDanhSachPhanSo(PhanSo ds[], int n) {
    for (int i = 0; i < n; i++) {
        if (ds[i].tu == 0) {
            printf("Nghich dao cua phan so %d/%d la 0\n", ds[i].tu, ds[i].mau);
        }
        else {
            printf("Nghich dao cua phan so %d/%d la %d/%d\n", ds[i].tu, ds[i].mau, ds[i].mau, ds[i].tu);
        }
    }
}

// Hàm sắp xếp mảng phân số tăng dần theo phương pháp sắp xếp nổi bọt
void sapXepTangDan(PhanSo ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (giaTriPhanSo(ds[j]) > giaTriPhanSo(ds[j + 1])) {
                PhanSo temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp mảng phân số giảm dần theo phương pháp sắp xếp nổi bọt
void sapXepGiamDan(PhanSo ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (giaTriPhanSo(ds[j]) < giaTriPhanSo(ds[j + 1])) {
                PhanSo temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

void main() {
    PhanSo ds[MAX_SIZE];
    int n;

    printf("Nhap so luong phan so (n <= 50): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("So luong phan so khong hop le.\n");
        return;
    }

    // Nhap danh sach phan so
    nhapDanhSachPhanSo(ds, n);

    // Xuat danh sach phan so
    printf("Danh sach phan so:\n");
    xuatDanhSachPhanSo(ds, n);

    // Tim va xuat phan so co gia tri lon nhat
    PhanSo max = phanSoMax(ds, n);
    printf("Phan so co gia tri lon nhat: ");
    xuatPhanSo(max);

    // Tim va xuat phan so co gia tri nho nhat
    PhanSo min = phanSoMin(ds, n);
    printf("Phan so co gia tri nho nhat: ");
    xuatPhanSo(min);

    // Tinh va xuat tong cua cac phan so
    PhanSo tong = tongDanhSachPhanSo(ds, n);
    printf("Tong cua cac phan so: ");
    xuatPhanSo(tong);

    // Tinh va xuat tich cua cac phan so
    PhanSo tich = tichDanhSachPhanSo(ds, n);
    printf("Tich cua cac phan so: ");
    xuatPhanSo(tich);

    // Xuat nghich dao cua cac phan so
    printf("Nghich dao cua cac phan so:\n");
    nghichDaoDanhSachPhanSo(ds, n);

    // Sap xep danh sach phan so tang dan
    sapXepTangDan(ds, n);
    printf("Danh sach phan so sau khi sap xep tang dan:\n");
    xuatDanhSachPhanSo(ds, n);

    // Sap xep danh sach phan so giam dan
    sapXepGiamDan(ds, n);
    printf("Danh sach phan so sau khi sap xep giam dan:\n");
    xuatDanhSachPhanSo(ds, n);

}
