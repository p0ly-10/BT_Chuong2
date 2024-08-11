#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "BT.h"

void main() {
    int intArr[] = { 5, 2, 9, 1, 5, 6 };
    float floatArr[] = { 2.5, 3.1, 1.4, 6.7 };
    char charArr[] = { 'z', 'a', 'e', 'b' };
    char strArr[4][100] = { "banana", "apple", "cherry", "date" };

    int nInt = sizeof(intArr) / sizeof(intArr[0]);
    int nFloat = sizeof(floatArr) / sizeof(floatArr[0]);
    int nChar = sizeof(charArr) / sizeof(charArr[0]);
    int nString = sizeof(strArr) / sizeof(strArr[0]);

    interchangeSortSonguyen(intArr, nInt);
    interchangeSortSoThuc(floatArr, nFloat);
    interchangeSortKytu(charArr, nChar);
    interchangeSortChuoiKyTu(strArr, nString);

    printf("Sap xep so nguyen tang dan: ");
    for (int i = 0; i < nInt; i++) {
        printf("%d ", intArr[i]);
    }
    printf("\n");

    printf("Sap xep so thuc tang dan: ");
    for (int i = 0; i < nFloat; i++) {
        printf("%.2f ", floatArr[i]);
    }
    printf("\n");

    printf("Sap xep ky tu tang dan: ");
    for (int i = 0; i < nChar; i++) {
        printf("%c ", charArr[i]);
    }
    printf("\n");

    printf("Sap xep chuoi ky tu tang dan: ");
    for (int i = 0; i < nString; i++) {
        printf("%s ", strArr[i]);
    }
    printf("\n");
}

// Hàm sắp xếp số nguyên tăng
void interchangeSortSonguyen(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp số thực tăng
void interchangeSortSoThuc(float arr[], int n) {
    int i, j;
    float temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp ký tự tăng
void interchangeSortKytu(char arr[], int n) {
    int i, j;
    char temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Hàm sắp xếp chuỗi ký tự tăng
void interchangeSortChuoiKyTu(char arr[][100], int n) {
    int i, j;
    char temp[100];
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
}


