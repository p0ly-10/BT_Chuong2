#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "BTMang1.h"
#define MAX 100


void main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int a[MAX];
    nhapMang(a, n);

    printf("Mang vua nhap: ");
    xuatMang(a, n);

    int max = timMax(a, n);
    int min = timMin(a, n);
    printf("Gia tri lon nhat cua mang: %d\n", max);
    printf("Gia tri nho nhat cua mang: %d\n", min);

    int soChan = demChan(a, n);
    int soLe = demLe(a, n);
    printf("So phan tu chan: %d\n", soChan);
    printf("So phan tu le: %d\n", soLe);

    int x;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &x);

    // Tìm kiếm tuyến tính
    int viTri = timKiemTuyenTinh(a, n, x);
    if (viTri != -1) {
        printf("(Tim kiem tuyen tinh)\nGia tri %d duoc tim thay o vi tri %d.\n", x, viTri);
    }
    else {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }

    // Tìm kiếm nhị phân
    viTri = timKiemNhiPhan(a, n, x);
    if (viTri != -1) {
        printf("(Tim kiem nhi phan)\nGia tri %d duoc tim thay o vi tri %d.\n", x, viTri);
    }
    else {
        printf("Gia tri %d khong ton tai trong mang.\n", x);
    }

    int soLan = demSoLanXuatHien(a, n, x);
    printf("Gia tri %d xuat hien %d lan trong mang.\n", x, soLan);

    int soLonHonX = demLonHonX(a, n, x);
    printf("So luong phan tu lon hon % trong mang: %d\n", x, soLonHonX);

    int tong = tongMang(a, n);
    printf("Tong cac phan tu trong mang: %d\n", tong);

    xuatSNT(a, n);
    xuatSoHoanThien(a, n);
    xuatViTriChan(a, n);
    xuatViTriLe(a, n);
    xuatMaxMinViTri(a, n);

   /* char m;
    printf("Nhap so luong phan tu cua mang b: ");
    scanf("%c", &m);
    int b[MAX];
    printf("Nhap mang b theo thu tu tang dan:\n");
    nhapMang(b, m);

    char s;
    printf("Nhap so luong phan tu cua mang c: ");
    scanf("%c", &s);
    int c[MAX];
    printf("Nhap mang b theo thu tu tang dan:\n");
    nhapMang(c, s);

    int* merged = (int*)malloc((m + s) * sizeof(int));
    if (merged == NULL) {
        printf("Khong the cap phat bo nho\n");
        return;
    }
    ghepMang(b, m, c, s, merged);

    printf("Mang sau khi ghep: ");
    xuatMang(merged, m + s);*/
}

//Câu 1
// Hàm nhập mảng
void nhapMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &a[i]);
    }
}

// Hàm xuất mảng
void xuatMang(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Câu 2
// Hàm tìm giá trị lớn nhất của mảng
int timMax(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

// Hàm tìm giá trị nhỏ nhất của mảng
int timMin(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    return min;
}

// Câu 3
// Hàm đếm số phần tử chẵn trong mảng
int demChan(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

// Hàm đếm số phần tử lẻ trong mảng
int demLe(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

// Câu 4
// Hàm tìm kiếm tuyến tính
int timKiemTuyenTinh(int a[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            return i; // Trả về vị trí đầu tiên tìm thấy
        }
    }
    return -1; // Không tìm thấy
}

// Hàm tìm kiếm nhị phân (yêu cầu mảng đã được sắp xếp)
int timKiemNhiPhan(int a[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] == x) {
            return mid;
        }
        else if (a[mid] < x) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Không tìm thấy
}

// Câu 5
// Hàm đếm số lần xuất hiện của phần tử x trong mảng
int demSoLanXuatHien(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            count++;
        }
    }
    return count;
}

//Câu 6
// Hàm đếm số phần tử lớn hơn x trong mảng
int demLonHonX(int a[], int n, int x) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > x) {
            count++;
        }
    }
    return count;
}

//Câu 7
// Hàm tính tổng các phần tử của mảng
int tongMang(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

//Câu 8
// Hàm kiểm tra số nguyên tố
bool KTraSNT(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm xuất các số nguyên tố trong mảng
void xuatSNT(int a[], int n) {
    printf("Cac so nguyen to trong mang: ");
    for (int i = 0; i < n; i++) {
        if (KTraSNT(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

//Câu 9
// Hàm kiểm tra số hoàn thiện
bool KTraSoHoanThien(int n) {
    if (n < 1) return false;
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

// Hàm xuất các số hoàn thiện trong mảng
void xuatSoHoanThien(int a[], int n) {
    printf("Cac so hoan thien trong mang: ");
    for (int i = 0; i < n; i++) {
        if (KTraSoHoanThien(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}

//Câu 10
// Hàm xuất các phần tử ở vị trí chẵn trong mảng
void xuatViTriChan(int a[], int n) {
    printf("Cac phan tu o vi tri chan trong mang: ");
    for (int i = 0; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Hàm xuất các phần tử ở vị trí lẻ trong mảng
void xuatViTriLe(int a[], int n) {
    printf("Cac phan tu o vi tri le trong mang: ");
    for (int i = 1; i < n; i += 2) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//Câu 11
// Hàm xuất giá trị max/min kèm vị trí của giá trị đó trong mảng
void xuatMaxMinViTri(int a[], int n) {
    int max = a[0], min = a[0];
    int maxP = 0, minP = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
            maxP = i;
        }
        if (a[i] < min) {
            min = a[i];
            minP = i;
        }
    }
    printf("Gia tri lon nhat trong mang: %d, vi tri: %d\n", max, maxP);
    printf("Gia tri nho nhat trong mang: %d, vi tri: %d\n", min, minP);
}

//Câu 12
// Hàm ghép hai mảng b và c thành mảng a theo thứ tự tăng dần
//void ghepMang(int b[], int m, int c[], int s, int a[]) {
//    int i = 0, j = 0, k = 0;
//    while (i < m && j < s) {
//        if (b[i] < c[j]) {
//            a[k++] = b[i++];
//        }
//        else {
//            a[k++] = c[j++];
//        }
//    }
//    while (i < m) {
//        a[k++] = b[i++];
//    }
//    while (j < s) {
//        a[k++] = c[j++];
//    }
//}