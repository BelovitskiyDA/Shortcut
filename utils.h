#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>
#include <chrono>

using namespace std;

void printMainMenu();
void printAlgorithmMenu(int startPoint, int endPoint);
void clearStream(istream& in = cin);

string inputFileName();
vector<vector <double>> loadMatrix(ifstream& fin);
void saveMatrix(const vector<vector <double>>& matrix, ofstream& fout);
void printMatrix(const vector<vector <double>>& matrix);
vector<vector <double>> createMatrix();
int selectStartPoint(int size);
int selectEndPoint(int size);
void algorithmFloyd(vector<vector <double>> matrix, int startPoint, int endPoint);
int findShortcut(const vector<vector <double>>& matrix);
void algorithmFord(vector<vector <double>> matrix, int startPoint, int endPoint);
void algorithmDijkstra(vector<vector <double>> matrix, int startPoint, int endPoint);
double findmin(vector<double> array);

