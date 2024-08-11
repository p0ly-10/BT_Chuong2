#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

// Hàm tính tổng các phần tử nằm trên đường chéo chính
int tongDuongCheoChinh(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][i];
    }
    return tong;
}

// Hàm tính tổng các phần tử nằm trên đường chéo phụ
int tongDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        tong += a[i][n - 1 - i];
    }
    return tong;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo chính
int tongPhiaTrenDuongCheoChinh(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
int tongPhiaTrenDuongCheoPhu(int a[MAX_SIZE][MAX_SIZE], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            tong += a[i][j];
        }
    }
    return tong;
}

// Hàm xuất ma trận
void xuatMaTran(int a[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE];
    int n;

    // Nhập kích thước ma trận
    printf("Nhap so dong/so cot (n): ");
    scanf("%d", &n);

    // Nhập ma trận
    printf("Nhap ma tran (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Xuất ma trận
    printf("Ma tran:\n");
    xuatMaTran(a, n);

    // Bài 1: Tính tổng các phần tử nằm trên đường chéo chính
    int tongChinh = tongDuongCheoChinh(a, n);
    printf("Tong cac phan tu nam tren duong cheo chinh: %d\n", tongChinh);

    // Bài 2: Tính tổng các phần tử nằm trên đường chéo phụ
    int tongPhu = tongDuongCheoPhu(a, n);
    printf("Tong cac phan tu nam tren duong cheo phu: %d\n", tongPhu);

    // Bài 3: Tính tổng các phần tử nằm phía trên đường chéo chính
    int tongTrenChinh = tongPhiaTrenDuongCheoChinh(a, n);
    printf("Tong cac phan tu nam phia tren duong cheo chinh: %d\n", tongTrenChinh);

    // Bài 4: Tính tổng các phần tử nằm phía trên đường chéo phụ
    int tongTrenPhu = tongPhiaTrenDuongCheoPhu(a, n);
    printf("Tong cac phan tu nam phia tren duong cheo phu: %d\n", tongTrenPhu);

    return 0;
}
