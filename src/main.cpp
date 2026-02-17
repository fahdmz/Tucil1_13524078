#include "helperfunctions.hpp"

int main()
{
    while (true)
    {
        refreshScreen();
        string inputFile;
        cout << "Masukkan nama file : ";
        cin >> inputFile;
        string namaFileInput = "../test/" + inputFile;
        vector<string> isiFile;
        int N;
        ReadFileToArray(namaFileInput, isiFile, &N);

        set<char> setHuruf;
        for (const string &line : isiFile)
        {
            for (char c : line)
            {
                setHuruf.insert(c);
            }
        }
        int jumlahWarna = setHuruf.size();

        long long iterasiCount = 0;

        cout << "Ukuran papan: " << N << "x" << N << endl;
        cout << "Jumlah warna: " << jumlahWarna << endl;
        cout << "Jumlah kombinasi yang akan dicoba: " << Combination(N * N, jumlahWarna) << endl;
        cout << "\nTekan ENTER untuk mulai...";
        cin.get();

        auto start = chrono::high_resolution_clock::now();

        vector<pair<int, int>> solusi = bruteForceAlgorithm(
            isiFile, N, jumlahWarna, iterasiCount);

        auto end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);

        cout << "\n==================================" << endl;
        if (!solusi.empty())
        {
            cout << "Solusi Ditemukan!" << endl;
            printTiles(isiFile, solusi, N);
        }
        else
        {
            cout << "Solusi Tidak ada" << endl;
        }

        cout << "\nWaktu pencarian: " << duration.count() << " ms" << endl;
        cout << "Banyak kasus yang ditinjau: " << iterasiCount << " kasus" << endl;
        cout << "==================================" << endl;

        if (!solusi.empty())
        {
            cout << "\nApakah Anda ingin menyimpan solusi? (y/n): ";
            char jawab;
            cin >> jawab;

            if (jawab == 'y' || jawab == 'Y')
            {
                string outputFilename;

                size_t dotPos = namaFileInput.find_last_of(".");
                string baseName = (dotPos != string::npos) ? namaFileInput.substr(0, dotPos) : namaFileInput;

                outputFilename = baseName + "_solution.txt";

                saveSolutionToFile(isiFile, solusi, N, outputFilename);
            }
        }

        cout << "Apakah Anda ingin mencoba test file yang lain, atau quit?" << endl;
        cout << "1. Lanjut" << endl;
        cout << "2. Quit" << endl;
        int pilihan;
        cout << "Pilihan : ";
        cin >> pilihan;
        if (pilihan == 2)
        {
            cout << "Program Selesai. Terima Kasih!" << endl;
            break;
        }
    }

    return 0;
}