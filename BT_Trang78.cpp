#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Hàm kiểm tra chữ số đầu của số nguyên
int chuSoDau(int x) {
    while (x >= 10) {
        x /= 10;
    }
    return x;
}

// Hàm tính tổng các phần tử có chữ số đầu là chữ số lẻ
int tongSoLeDau(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int dau = chuSoDau(abs(a[i][j]));
            if (dau % 2 != 0) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Hàm kiểm tra số hoàn thiện
bool laSoHoanThien(int n) {
    if (n <= 1) return false;
    int tong = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            tong += i;
        }
    }
    return tong == n;
}

// Hàm liệt kê các số hoàn thiện trong ma trận
void lietKeSoHoanThien(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    printf("Cac so hoan thien trong ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoHoanThien(a[i][j])) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

// Hàm tính tổng các phần tử lớn hơn trị tuyệt đối của phần tử liền sau nó
int tongLonHonTuyetDoiSau(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] > abs(a[i][j + 1])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

// Hàm tính tổng giá trị trên dòng k
int tongTrenDongK(int a[MAX_SIZE][MAX_SIZE], int m, int n, int k) {
    if (k < 0 || k >= m) {
        printf("Chi so dong k khong hop le.\n");
        return 0;
    }
    int tong = 0;
    for (int j = 0; j < n; j++) {
        tong += a[k][j];
    }
    return tong;
}

// Hàm tính tổng các giá trị nằm trên biên của ma trận
int tongBien(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int tong = 0;
    // Tính tổng hàng đầu và hàng cuối
    for (int j = 0; j < n; j++) {
        tong += a[0][j];
        if (m > 1) {
            tong += a[m - 1][j];
        }
    }
    // Tính tổng cột đầu và cột cuối
    for (int i = 1; i < m - 1; i++) {
        tong += a[i][0];
        if (n > 1) {
            tong += a[i][n - 1];
        }
    }
    return tong;
}

// Hàm đếm tần suất xuất hiện của giá trị x
int demTanSuat(int a[MAX_SIZE][MAX_SIZE], int m, int n, int x) {
    int dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == x) {
                dem++;
            }
        }
    }
    return dem;
}

#include <stdbool.h>

// Hàm kiểm tra số nguyên tố
bool laSoNguyenTo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm đếm số lượng các phần tử là số chẵn, số lẻ, số âm, số dương, số nguyên tố
void demPhanTu(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int chan = 0, le = 0, am = 0, duong = 0, nguyenTo = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 == 0) {
                chan++;
            }
            else {
                le++;
            }
            if (a[i][j] < 0) {
                am++;
            }
            else if (a[i][j] > 0) {
                duong++;
            }
            if (laSoNguyenTo(abs(a[i][j]))) {
                nguyenTo++;
            }
        }
    }

    printf("So luong so chan: %d\n", chan);
    printf("So luong so le: %d\n", le);
    printf("So luong so am: %d\n", am);
    printf("So luong so duong: %d\n", duong);
    printf("So luong so nguyen to: %d\n", nguyenTo);
}

void main() {
    int a[MAX_SIZE][MAX_SIZE];
    int m, n;

    // Nhập kích thước ma trận
    printf("Nhap so hang m: ");
    scanf("%d", &m);
    printf("Nhap so cot n: ");
    scanf("%d", &n);

    // Nhập ma trận
    printf("Nhap ma tran:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Bài 1
    int tong = tongSoLeDau(a, m, n);
    printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tong);

    // Bài 2
    lietKeSoHoanThien(a, m, n);

    // Bài 3
    tong = tongLonHonTuyetDoiSau(a, m, n);
    printf("Tong cac phan tu lon hon tri tuyet doi cua phan tu lien sau: %d\n", tong);

    // Bài 4
    int k;
    printf("Nhap chi so dong k: ");
    scanf("%d", &k);
    tong = tongTrenDongK(a, m, n, k);
    printf("Tong gia tri tren dong k: %d\n", tong);

    // Bài 5
    tong = tongBien(a, m, n);
    printf("Tong cac gia tri nam tren bien cua ma tran: %d\n", tong);

    // Bài 6
    int x;
    printf("Nhap gia tri x: ");
    scanf("%d", &x);
    int tanSuat = demTanSuat(a, m, n, x);
    printf("Tan suat xuat hien cua gia tri %d: %d\n", x, tanSuat);

    // Bài 7
    demPhanTu(a, m, n);
}
