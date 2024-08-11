#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#define MAX 100

// Hàm kiểm tra số nguyên tố
bool KTraSNT(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố
bool KTraMang(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (!KTraSNT(arr[i])) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có đối xứng không
bool KTTraMangDoiXung(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        if (arr[i] != arr[size - i - 1]) return false;
    }
    return true;
}

// Hàm kiểm tra mảng có tăng dần, giảm dần hay không tăng không giảm
void KTraMangTangGiam(int arr[], int size) {
    bool tangdan = true, giamdan = true;

    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) tangdan = false;
        if (arr[i] < arr[i + 1]) giamdan = false;
    }

    if (tangdan) printf("Mang tang dan.\n");
    else if (giamdan) printf("Mang giam dan.\n");
    else printf("Mang khong tang khong giam.\n");
}

int main() {
    int size;

    // Nhập kích thước mảng
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &size);

    // Khai báo mảng với kích thước nhập vào
    int arr[MAX];

    // Nhập các phần tử của mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < size; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Xuất mảng
    printf("Mang vua nhap:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Kiểm tra mảng có chứa toàn bộ số nguyên tố
    if (KTraMang(arr, size)) {
        printf("Mang chua toan bo so nguyen to.\n");
    }
    else {
        printf("Mang khong chua toan bo so nguyen to.\n");
    }

    // Kiểm tra mảng có đối xứng không
    if (KTTraMangDoiXung(arr, size)) {
        printf("Mang doi xung.\n");
    }
    else {
        printf("Mang khong doi xung.\n");
    }

    // Kiểm tra mảng có tăng dần, giảm dần hay không tăng không giảm
    KTraMangTangGiam(arr, size);

    return 0;
}
