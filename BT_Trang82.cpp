#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <climits>


#define MAX_SIZE 100

// Hàm tính tổng các phần tử của một cột
int tongCot(int a[MAX_SIZE][MAX_SIZE], int m, int n, int cot) {
    int tong = 0;
    for (int i = 0; i < m; i++) {
        tong += a[i][cot];
    }
    return tong;
}

// Hàm liệt kê các cột có tổng nhỏ nhất
void lietKeCotTongNhoNhat(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int minTong = tongCot(a, m, n, 0);
    for (int j = 1; j < n; j++) {
        int tong = tongCot(a, m, n, j);
        if (tong < minTong) {
            minTong = tong;
        }
    }

    printf("Cac cot co tong nho nhat:\n");
    for (int j = 0; j < n; j++) {
        if (tongCot(a, m, n, j) == minTong) {
            printf("Cot %d\n", j);
        }
    }
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

// Hàm đếm số hoàn thiện trong một dòng
int demSoHoanThienTrongDong(int a[MAX_SIZE][MAX_SIZE], int m, int n, int dong) {
    int dem = 0;
    for (int j = 0; j < n; j++) {
        if (laSoHoanThien(a[dong][j])) {
            dem++;
        }
    }
    return dem;
}

// Hàm liệt kê các dòng có nhiều số hoàn thiện nhất
void lietKeDongNhieuSoHoanThienNhat(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int maxDem = demSoHoanThienTrongDong(a, m, n, 0);
    for (int i = 1; i < m; i++) {
        int dem = demSoHoanThienTrongDong(a, m, n, i);
        if (dem > maxDem) {
            maxDem = dem;
        }
    }

    printf("Cac dong co nhieu so hoan thien nhat:\n");
    for (int i = 0; i < m; i++) {
        if (demSoHoanThienTrongDong(a, m, n, i) == maxDem) {
            printf("Dong %d\n", i);
        }
    }
}

// Hàm kiểm tra xem một dòng có toàn giá trị chẵn không
bool toanChan(int a[MAX_SIZE][MAX_SIZE], int n, int dong) {
    for (int j = 0; j < n; j++) {
        if (a[dong][j] % 2 != 0) {
            return false;
        }
    }
    return true;
}

// Hàm liệt kê các dòng chứa toàn giá trị chẵn
void lietKeDongToanChan(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    printf("Cac dong chua toan gia tri chan:\n");
    for (int i = 0; i < m; i++) {
        if (toanChan(a, n, i)) {
            printf("Dong %d\n", i);
        }
    }
}


// Hàm đếm tần suất xuất hiện của một giá trị
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

// Hàm tìm giá trị xuất hiện nhiều nhất trong ma trận
void timGiaTriXuatHienNhieuNhat(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int maxTanSuat = 0;
    int giaTriMax = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int tanSuat = demTanSuat(a, m, n, a[i][j]);
            if (tanSuat > maxTanSuat) {
                maxTanSuat = tanSuat;
                giaTriMax = a[i][j];
            }
        }
    }
    printf("Gia tri xuat hien nhieu nhat: %d\n", giaTriMax);
}

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

// Hàm tìm số nguyên tố nhỏ nhất trong ma trận
void timSoNguyenToNhoNhat(int a[MAX_SIZE][MAX_SIZE], int m, int n) {
    int minNguyenTo = INT_MAX;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (laSoNguyenTo(a[i][j]) && a[i][j] < minNguyenTo) {
                minNguyenTo = a[i][j];
            }
        }
    }
    if (minNguyenTo == INT_MAX) {
        printf("Khong co so nguyen to trong ma tran.\n");
    }
    else {
        printf("So nguyen to nho nhat: %d\n", minNguyenTo);
    }
}

// Hàm tìm phần tử lớn nhất hoặc nhỏ nhất trong một dòng
void timPhanTuLonNhatNhoNhatTrongDong(int a[MAX_SIZE][MAX_SIZE], int n, int dong, bool timLonNhat) {
    if (dong < 0 || dong >= MAX_SIZE) {
        printf("Chi so dong khong hop le.\n");
        return;
    }
    int ketQua = a[dong][0];
    for (int j = 1; j < n; j++) {
        if (timLonNhat) {
            if (a[dong][j] > ketQua) {
                ketQua = a[dong][j];
            }
        }
        else {
            if (a[dong][j] < ketQua) {
                ketQua = a[dong][j];
            }
        }
    }
    printf("%s trong dong %d: %d\n", timLonNhat ? "Phan tu lon nhat" : "Phan tu nho nhat", dong, ketQua);
}

// Hàm tìm phần tử lớn nhất hoặc nhỏ nhất trong một cột
void timPhanTuLonNhatNhoNhatTrongCot(int a[MAX_SIZE][MAX_SIZE], int m, int cot, bool timLonNhat) {
    if (cot < 0 || cot >= MAX_SIZE) {
        printf("Chi so cot khong hop le.\n");
        return;
    }
    int ketQua = a[0][cot];
    for (int i = 1; i < m; i++) {
        if (timLonNhat) {
            if (a[i][cot] > ketQua) {
                ketQua = a[i][cot];
            }
        }
        else {
            if (a[i][cot] < ketQua) {
                ketQua = a[i][cot];
            }
        }
    }
    printf("%s trong cot %d: %d\n", timLonNhat ? "Phan tu lon nhat" : "Phan tu nho nhat", cot, ketQua);
}

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int m, n;

    // Nhập kích thước ma trận
    printf("Nhap so dong (m): ");
    scanf("%d", &m);
    printf("Nhap so cot (n): ");
    scanf("%d", &n);

    // Nhập ma trận
    printf("Nhap ma tran (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Gọi các hàm xử lý bài toán
    lietKeCotTongNhoNhat(a, m, n);
    lietKeDongNhieuSoHoanThienNhat(a, m, n);
    lietKeDongToanChan(a, m, n);
    timGiaTriXuatHienNhieuNhat(a, m, n);
    timSoNguyenToNhoNhat(a, m, n);
    timPhanTuLonNhatNhoNhatTrongDong(a, n, 0, true); // ví dụ với dòng 0, tìm phần tử lớn nhất
    timPhanTuLonNhatNhoNhatTrongCot(a, m, 0, false); // ví dụ với cột 0, tìm phần tử nhỏ nhất

    return 0;
}
