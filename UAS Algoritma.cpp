#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Barang {
    int id;
    std::string nama;
    int jumlah;
    double harga;
};

class InventarisasiGudang {
private:
    std::vector<Barang> barangList;

public:
    InventarisasiGudang() {
        barangList = {
            {1, "Laptop", 10, 15000.00},
            {2, "Mouse", 50, 200.00},
            {3, "Keyboard", 30, 350.00},
            {4, "Monitor", 20, 2500.00},
            {5, "Printer", 15, 1200.00},
            {6, "Scanner", 5, 1800.00},
            {7, "Hard Disk", 40, 750.00},
            {8, "Flash Drive", 100, 50.00},
            {9, "RAM", 60, 300.00},
            {10, "Motherboard", 8, 4000.00},
            {11, "CPU", 12, 5000.00},
            {12, "GPU", 6, 7000.00},
            {13, "Power Supply", 25, 1500.00},
            {14, "Cooling Fan", 30, 100.00},
            {15, "Webcam", 20, 600.00},
            {16, "Speaker", 10, 900.00},
            {17, "Microphone", 15, 400.00},
            {18, "Projector", 3, 5000.00},
            {19, "Router", 10, 700.00},
            {20, "Switch", 5, 1000.00}
        };
    }

    void tambahBarang() {
        Barang barangBaru;
        std::cout << "Input ID Barang: ";
        std::cin >> barangBaru.id;
        std::cin.ignore(); // mengabaikan newline setelah memasukkan ID
        std::cout << "Input Nama Barang: ";
        std::getline(std::cin, barangBaru.nama);
        std::cout << "Input Jumlah Barang: ";
        std::cin >> barangBaru.jumlah;
        std::cout << "Input Harga per Unit: ";
        std::cin >> barangBaru.harga;
        barangList.push_back(barangBaru);
        std::cout << "Barang berhasil ditambahkan.\n";
    }

    void hapusBarang() {
        std::cout << "Input ID Barang yang ingin dihapus: ";
        int id;
        std::cin >> id;
        auto it = std::remove_if(barangList.begin(), barangList.end(), [id](const Barang& barang) {
            return barang.id == id;
        });
        if (it != barangList.end()) {
            barangList.erase(it, barangList.end());
            std::cout << "Barang berhasil dihapus.\n";
        } else {
            std::cout << "Barang tidak ditemukan.\n";
        }
    }

    void cariBarang() const {
        std::cout << "Input ID Barang yang ingin dicari: ";
        int id;
        std::cin >> id;
        for (const auto& barang : barangList) {
            if (barang.id == id) {
                std::cout << "ID: " << barang.id 
                          << ", Nama: " << barang.nama 
                          << ", Jumlah: " << barang.jumlah 
                          << ", Harga: " << barang.harga << "\n";
                return;
            }
        }
        std::cout << "Barang tidak ditemukan.\n";
    }

    void editBarang() {
        std::cout << "Input ID Barang yang ingin diupdate: ";
        int id;
        std::cin >> id;
        for (auto& barang : barangList) {
            if (barang.id == id) {
                std::cin.ignore(); // mengabaikan newline setelah memasukkan ID
                std::cout << "Input Nama Barang baru: ";
                std::getline(std::cin, barang.nama);
                std::cout << "Input Jumlah Barang baru: ";
                std::cin >> barang.jumlah;
                std::cout << "Input Harga per Unit baru: ";
                std::cin >> barang.harga;
                std::cout << "Barang berhasil diupdate.\n";
                return;
            }
        }
        std::cout << "Barang tidak ditemukan.\n";
    }

    void tampilkanDataBarang() const {
        if (barangList.empty()) {
            std::cout << "Tidak ada barang di gudang.\n";
        } else {
            for (const auto& barang : barangList) {
                std::cout << "ID: " << barang.id 
                          << ", Nama: " << barang.nama 
                          << ", Jumlah: " << barang.jumlah 
                          << ", Harga: " << barang.harga << "\n";
            }
        }
    }
};

int main() {
    InventarisasiGudang gudang;
    int pilihan;

    do {
        std::cout << "\nMenu Inventarisasi Gudang:\n";
        std::cout << "1. Tambah Barang\n";
        std::cout << "2. Hapus Barang\n";
        std::cout << "3. Cari Barang\n";
        std::cout << "4. Edit Barang\n";
        std::cout << "5. Tampilkan Semua Barang\n";
        std::cout << "6. Keluar\n";
        std::cout << "Pilih opsi: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1:
                gudang.tambahBarang();
                break;
            case 2:
                gudang.hapusBarang();
                break;
            case 3:
                gudang.cariBarang();
                break;
            case 4:
                gudang.editBarang();
                break;
            case 5:
                gudang.tampilkanDataBarang();
                break;
            case 6:
                std::cout << "Keluar dari program.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan != 6);

    return 0;
}
