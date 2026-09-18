#include <iostream>

int main() {
    int N, K;
    std::cout << "Masukkan jumlah astronot (N): ";
    std::cin >> N;
    std::cout << "Masukkan nilai awal K: ";
    std::cin >> K;

    if (N <= 0) {
        std::cout << "Jumlah astronot harus lebih dari 0." << std::endl;
        return 0;
    }

    int astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int jumlah = N;
    int current_idx = 0;

    std::cout << "\nUrutan astronot yang dieliminasi:\n";
    while (jumlah > 1) {
        int elim_idx = (current_idx + K - 1) % jumlah;
        int eliminated = astronot[elim_idx];
        std::cout << eliminated << " ";

        for (int i = elim_idx; i < jumlah - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        jumlah--;

        if (eliminated % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        if (jumlah > 0) {
            current_idx = elim_idx % jumlah;
        }
    }

    std::cout << "\n\nAstronot terakhir yang bertahan: " << astronot[0] << std::endl;
    return 0;
}