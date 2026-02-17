#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <thread>
#include <cmath>
#include <unordered_set>
#include <chrono>
using namespace std;

void refreshScreen();

long long Faktorial(int n);

long long Combination(int n, int r);

void ReadFileToArray(const string &filename, vector<string> &isiFile, int *returnArraySize);

void MakeArrayIntoSet(vector<string> &isiFile, set<char> &SetBaru, int *returnSizeSet);

vector<pair<int, int>> bruteForceAlgorithm(vector<string> &isiFile, int N, int totalWarna, long long &countIterasi);

void printTiles(vector<string> &isiFile, vector<pair<int, int>> &QueenPositions, int N);

bool nextCombination(vector<int> &strava, int N);

bool isValid(vector<pair<int, int>> &QueenPositions, int N, vector<string> &isiFile);

void saveSolutionToFile(vector<string> &isiFile, vector<pair<int, int>> &solusi, int N, const string &outputFilename);
// Extra Functions

/*
void printMap
void BruteForceAlgorithm
bool isValid -> ngecek kombinasi present sesuai atau gak sama aturannya
bool nextCombination -> ngecek trackernya terus langsung ke kombinasi setelahnya


*/

/*
Array that stores the lines of the map -> Normal Dynamic Array (Vector)
Array that stores the Colors -> ADT Set
Integer that represents the size (N x N) of the map -> function baru (Integer) atau gak tiap getline nanti length tambah 1
A function that reads the file.txt and stores it in the array -> Function baru
*/

/*
Logic flow of the program :
jadi yang pertama itu kita generate dulu kombinasi pertama terus nanti ada array yang ngestore history kita udah ada di kombinasi ke berapa

*/