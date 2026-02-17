#include "helperfunctions.hpp"
using namespace std;

void refreshScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

long long Faktorial(int n)
{
    long long hasil = 1;
    for (int i = 2; i <= n; i++)
    {
        hasil *= i;
    }
    return hasil;
}

long long Combination(int n, int r)
{
    if (r > n || r < 0)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (r > n / 2)
        r = n - r;

    long long result = 1;
    for (int i = 0; i < r; i++)
    {
        result = result * (n - i) / (i + 1);
    }
    return result;
}

void ReadFileToArray(const string &filename, vector<string> &isiFile, int *returnArraySize)
{
    ifstream file(filename);
    string line;
    int size = 0;
    if (file.is_open())
    {
        while (getline(file, line))
        {
            isiFile.push_back(line);
            size++;
        }
        file.close();
        *returnArraySize = size;
    }
    else
    {
        cout << "Can't found any files!" << endl;
    }
}

void MakeArrayIntoSet(vector<string> &isiFile, set<char> &SetBaru, int *returnSizeSet)
{
    for (const string &line : isiFile)
    {
        for (char c : line)
        {
            SetBaru.insert(c);
        }
    }
    *returnSizeSet = SetBaru.size();
}

vector<pair<int, int>> bruteForceAlgorithm(vector<string> &isiFile, int N, int totalWarna, long long &countIterasi)
{
    const int totalSel = N * N;
    vector<int> strava(totalWarna);

    for (int i = 0; i < totalWarna; i++)
    {
        strava[i] = i;
    }

    vector<pair<int, int>> QueenPositions;
    QueenPositions.reserve(totalWarna);

    auto printTime = chrono::high_resolution_clock::now();
    const int print_interval_ms = 5000;

    while (true)
    {
        countIterasi++;

        QueenPositions.clear();

        for (const int idx : strava)
        {
            QueenPositions.emplace_back(idx / N, idx % N);
        }

        auto currentTime = chrono::high_resolution_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(currentTime - printTime);

        if (elapsed.count() >= print_interval_ms)
        {
            refreshScreen();
            cout << "  Mencari solusi..." << endl;
            cout << "  Iterasi: " << countIterasi << endl;
            printTiles(isiFile, QueenPositions, N);
            printTime = currentTime;
        }

        if (isValid(QueenPositions, N, isiFile))
        {
            refreshScreen();
            cout << "\nSolusi Ditemukan di Iterasi- " << countIterasi << "!" << endl;
            return QueenPositions;
        }

        if (!nextCombination(strava, totalSel))
        {
            break;
        }
    }

    return {};
}

void printTiles(vector<string> &isiFile, vector<pair<int, int>> &QueenPositions, int N)
{
    vector<vector<bool>> hasQueen(N, vector<bool>(N, false));
    for (const auto &[r, c] : QueenPositions)
    {
        hasQueen[r][c] = true;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (hasQueen[i][j])
            {
                cout << "# ";
            }
            else
            {
                cout << isiFile[i][j] << " ";
            }
        }
        cout << endl;
    }
}

bool nextCombination(vector<int> &strava, const int N)
{
    const int track = strava.size();

    for (int i = track - 1; i >= 0; i--)
    {
        if (strava[i] < N - track + i)
        {
            strava[i]++;

            for (int j = i + 1; j < track; j++)
            {
                strava[j] = strava[j - 1] + 1;
            }
            return true;
        }
    }
    return false;
}

bool isValid(vector<pair<int, int>> &QueenPositions, int N, vector<string> &isiFile)
{
    const size_t size = QueenPositions.size();

    bool colorUsed[26] = {false}; // color
    vector<bool> rowUsed(N, false);
    vector<bool> colUsed(N, false);

    for (size_t i = 0; i < size; i++)
    {
        const int baris = QueenPositions[i].first;
        const int kolom = QueenPositions[i].second;
        const char warna = isiFile[baris][kolom];

        const int colorIdx = warna - 'A';
        if (colorUsed[colorIdx])
            return false;
        colorUsed[colorIdx] = true;

        if (rowUsed[baris])
            return false;
        rowUsed[baris] = true;

        if (colUsed[kolom])
            return false;
        colUsed[kolom] = true;
    }

    for (int i = 0; i < size; i++)
    {
        const int baris1 = QueenPositions[i].first;
        const int kolom1 = QueenPositions[i].second;

        for (int j = i + 1; j < size; j++)
        {
            const int baris2 = QueenPositions[j].first;
            const int kolom2 = QueenPositions[j].second;

            if (abs(baris1 - baris2) <= 1 && abs(kolom1 - kolom2) <= 1)
            {
                return false;
            }
        }
    }

    return true;
}

void saveSolutionToFile(vector<string> &isiFile, vector<pair<int, int>> &solusi, int N, const string &outputFilename)
{
    vector<vector<bool>> hasQueen(N, vector<bool>(N, false));

    for (const auto &[r, c] : solusi)
    {
        hasQueen[r][c] = true;
    }

    ofstream outputFile(outputFilename);

    if (!outputFile.is_open())
    {
        cout << "Tidak bisa membuat filenya!" << endl;
        return;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (hasQueen[i][j])
            {
                outputFile << "# ";
            }
            else
            {
                outputFile << isiFile[i][j] << " ";
            }
        }
        outputFile << endl;
    }
    outputFile.close();
    cout << "Solusi berhasil disimpan ke: " << outputFilename << endl;
}

/*
Array that stores the lines of the map -> Normal Dynamic Array (Vector)
Array that stores the Colors -> ADT Set
Integer that represents the size (N x N) of the map -> function baru (Integer) atau gak tiap getline nanti length tambah 1
A function that reads the file.txt and stores it in the array -> Function baru
*/

/*
Ketentuan  Untuk Queen :
dalam satu baris tidak boleh ada lebih dari satu queen
dalam satu kolom tidak boleh ada lebih dari satu queen
diagonal tidak boleh ada lebih dari satu queen
*/