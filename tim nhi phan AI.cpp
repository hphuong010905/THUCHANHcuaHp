#include <stdio.h>

// Hàm ð?m s? l?n xu?t hi?n c?a ph?n t? x trong m?ng
int demSoLanXuatHien(int arr[], int n, int x) {
    int trai = 0;
    int phai = n - 1;
    int viTriDauTien = -1;
    int viTriCuoiCung = -1;

    // T?m v? trí xu?t hi?n ð?u tiên c?a x
    while (trai <= phai) {
        int giua = trai + (phai - trai) / 2;
        if (arr[giua] == x) {
            viTriDauTien = giua;
            phai = giua - 1; // Ti?p t?c t?m bên trái
        } else if (arr[giua] < x) {
            trai = giua + 1;
        } else {
            phai = giua - 1;
        }
    }

    // T?m v? trí xu?t hi?n cu?i cùng c?a x
    trai = 0;
    phai = n - 1;
    while (trai <= phai) {
        int giua = trai + (phai - trai) / 2;
        if (arr[giua] == x) {
            viTriCuoiCung = giua;
            trai = giua + 1; // Ti?p t?c t?m bên ph?i
        } else if (arr[giua] < x) {
            trai = giua + 1;
        } else {
            phai = giua - 1;
        }
    }

    // S? l?n xu?t hi?n c?a x
    if (viTriDauTien != -1 && viTriCuoiCung != -1) {
        return viTriCuoiCung - viTriDauTien + 1;
    } else {
        return 0;
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;

    int ketQua = demSoLanXuatHien(arr, n, x);
    printf("S? l?n xu?t hi?n c?a %d trong m?ng là: %d\n", x, ketQua);

    return 0;
}

