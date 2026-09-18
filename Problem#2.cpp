#include <iostream>

int hitungPanjang(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char ubahKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    return c;
}

int main() {
    char pesan[1000];
    std::cout << "Masukkan pesan asli: ";
    std::cin >> pesan;

    int len = hitungPanjang(pesan);
    if (len == 0) return 0;

    char hasil[1000];
    hasil[0] = ubahKapital(pesan[0]);

    for (int i = 1; i < len; i++) {
        char prev = ubahKapital(pesan[i - 1]);
        char curr = ubahKapital(pesan[i]);

        if (curr >= 'A' && curr <= 'Z') {
            int shift = prev - 'A' + 1;
            int pos_awal = curr - 'A';
            int pos_baru = (pos_awal + shift) % 26;
            hasil[i] = 'A' + pos_baru;
        } else {
            hasil[i] = curr;
        }
    }
    hasil[len] = '\0';

    std::cout << "Pesan Sandi: " << hasil << std::endl;
    return 0;
}