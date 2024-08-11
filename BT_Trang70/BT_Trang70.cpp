#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100
#define FILE_NAME "sinhvien.txt"

// Khai báo cấu trúc sinh viên
typedef struct {
    int stt;
    char maSV[15]; 
    char hoTen[100]; 
    float diemTieuLuan; 
    float diemThi; 
    float diemTongKet; 
} SinhVien;

// Hàm nhập danh sách sinh viên
void nhapDanhSachSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        ds[i].stt = i + 1;
        printf("Ma so sinh vien: ");
        scanf("%s", ds[i].maSV);
        printf("Ho ten sinh vien: ");
        getchar();
        fgets(ds[i].hoTen, sizeof(ds[i].hoTen), stdin);
        ds[i].hoTen[strcspn(ds[i].hoTen, "\n")] = '\0';
        printf("Diem tieu luan: ");
        scanf("%f", &ds[i].diemTieuLuan);
        printf("Diem thi ket thuc mon: ");
        scanf("%f", &ds[i].diemThi);
        ds[i].diemTongKet = 0.3 * ds[i].diemTieuLuan + 0.7 * ds[i].diemThi;
    }
}

// Hàm xuất danh sách sinh viên
void xuatDanhSachSinhVien(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        printf("S%d - Ma SV: %s - Ho ten: %s - Diem TL: %.2f - Diem Thi: %.2f - Diem TK: %.2f\n",
            ds[i].stt, ds[i].maSV, ds[i].hoTen, ds[i].diemTieuLuan, ds[i].diemThi, ds[i].diemTongKet);
    }
}

// Hàm tìm sinh viên có điểm tổng kết cao nhất
SinhVien sinhVienMax(SinhVien ds[], int n) {
    SinhVien max = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTongKet > max.diemTongKet) {
            max = ds[i];
        }
    }
    return max;
}

// Hàm tìm sinh viên có điểm tổng kết thấp nhất
SinhVien sinhVienMin(SinhVien ds[], int n) {
    SinhVien min = ds[0];
    for (int i = 1; i < n; i++) {
        if (ds[i].diemTongKet < min.diemTongKet) {
            min = ds[i];
        }
    }
    return min;
}

// Hàm đếm số sinh viên đạt và không đạt
void demSinhVienDatVaKhongDat(SinhVien ds[], int n, int* dat, int* khongDat) {
    *dat = 0;
    *khongDat = 0;
    for (int i = 0; i < n; i++) {
        if (ds[i].diemTongKet >= 5.0) {
            (*dat)++;
        }
        else {
            (*khongDat)++;
        }
    }
}

// Hàm chuyển đổi điểm từ hệ 10 sang hệ 4
float chuyenDiemH10SangH4(float diemH10) {
    if (diemH10 >= 9.0) return 4.0;
    if (diemH10 >= 8.0) return 3.7;
    if (diemH10 >= 7.0) return 3.3;
    if (diemH10 >= 6.5) return 3.0;
    if (diemH10 >= 6.0) return 2.7;
    if (diemH10 >= 5.5) return 2.3;
    if (diemH10 >= 5.0) return 2.0;
    if (diemH10 >= 4.0) return 1.0;
    return 0.0;
}

// Hàm xuất điểm hệ 4 của sinh viên
void xuatDiemH4(SinhVien ds[], int n) {
    for (int i = 0; i < n; i++) {
        float diemH4 = chuyenDiemH10SangH4(ds[i].diemTongKet);
        printf("S%d - Ma SV: %s - Ho ten: %s - Diem TK: %.2f - Diem H4: %.2f\n",
            ds[i].stt, ds[i].maSV, ds[i].hoTen, ds[i].diemTongKet, diemH4);
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết tăng dần
void sapXepTangDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].diemTongKet > ds[j + 1].diemTongKet) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết giảm dần
void sapXepGiamDan(SinhVien ds[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ds[j].diemTongKet < ds[j + 1].diemTongKet) {
                SinhVien temp = ds[j];
                ds[j] = ds[j + 1];
                ds[j + 1] = temp;
            }
        }
    }
}

// Hàm tính điểm trung bình của tất cả sinh viên
float tinhDiemTrungBinh(SinhVien ds[], int n) {
    float tong = 0.0;
    for (int i = 0; i < n; i++) {
        tong += ds[i].diemTongKet;
    }
    return n > 0 ? tong / n : 0.0;
}

// Hàm ghi danh sách sinh viên vào file
void ghiDanhSachSinhVienVaoFile(SinhVien ds[], int n) {
    FILE* file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "S%d - Ma SV: %s - Ho ten: %s - Diem TL: %.2f - Diem Thi: %.2f - Diem TK: %.2f\n",
            ds[i].stt, ds[i].maSV, ds[i].hoTen, ds[i].diemTieuLuan, ds[i].diemThi, ds[i].diemTongKet);
    }
    fclose(file);
}

// Hàm đọc danh sách sinh viên từ file
int docDanhSachSinhVienTuFile(SinhVien ds[]) {
    FILE* file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Khong the mo file.\n");
        return 0;
    }
    int n = 0;
    while (fscanf(file, "S%d - Ma SV: %s - Ho ten: %99[^\n] - Diem TL: %f - Diem Thi: %f - Diem TK: %f\n",
        &ds[n].stt, ds[n].maSV, ds[n].hoTen, &ds[n].diemTieuLuan, &ds[n].diemThi, &ds[n].diemTongKet) != EOF) {
        n++;
    }
    fclose(file);
    return n;
}

void main() {
    SinhVien ds[MAX_SIZE];
    int n;
    int dat, khongDat;

    // Nhap so luong sinh vien
    printf("Nhap so luong sinh vien (n <= 100): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX_SIZE) {
        printf("So luong sinh vien khong hop le.\n");
        return;
    }

    // Nhap danh sach sinh vien
    nhapDanhSachSinhVien(ds, n);

    // Xuat danh sach sinh vien
    printf("Danh sach sinh vien:\n");
    xuatDanhSachSinhVien(ds, n);

    // Tinh diem tong ket cao nhat va thap nhat
    SinhVien max = sinhVienMax(ds, n);
    SinhVien min = sinhVienMin(ds, n);
    printf("Sinh vien co diem tong ket cao nhat:\n");
    xuatDanhSachSinhVien(&max, 1);
    printf("Sinh vien co diem tong ket thap nhat:\n");
    xuatDanhSachSinhVien(&min, 1);

    // Dem so sinh vien dat va khong dat
    demSinhVienDatVaKhongDat(ds, n, &dat, &khongDat);
    printf("So sinh vien dat: %d\n", dat);
    printf("So sinh vien khong dat: %d\n", khongDat);

    // Xuat diem he 4
    printf("Diem he 4 cua cac sinh vien:\n");
    xuatDiemH4(ds, n);

    // Sap xep danh sach sinh vien theo diem tong ket
    sapXepTangDan(ds, n);
    printf("Danh sach sinh vien sau khi sap xep tang dan:\n");
    xuatDanhSachSinhVien(ds, n);

    sapXepGiamDan(ds, n);
    printf("Danh sach sinh vien sau khi sap xep giam dan:\n");
    xuatDanhSachSinhVien(ds, n);

    // Tinh diem trung binh
    float diemTrungBinh = tinhDiemTrungBinh(ds, n);
    printf("Diem trung binh cua cac sinh vien: %.2f\n", diemTrungBinh);

    // Ghi danh sach sinh vien vao file
    ghiDanhSachSinhVienVaoFile(ds, n);
    printf("Danh sach sinh vien da duoc ghi vao file %s\n", FILE_NAME);

    // Doc danh sach sinh vien tu file
    int soSinhVienDocTuFile = docDanhSachSinhVienTuFile(ds);
    printf("Danh sach sinh vien doc tu file:\n");
    xuatDanhSachSinhVien(ds, soSinhVienDocTuFile);
}
