﻿#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void printMainMenu()
{
	cout << "....................." << endl
		<< "[1] Load weights matrix" << endl
		<< "[2] Create weights matrix" << endl
		<< "[3] Save weights matrix" << endl
		<< "[4] Print weights matrix" << endl
		<< "[5] Finding shortcut" << endl
		<< "[0] Exit" << endl
		<< "Choose action: ";
}

void printAlgorithmMenu()
{
	cout << "....................." << endl
		<< "Choose algorithm:" << endl
		<< "[1] Dijkstra algorithm" << endl
		<< "[2] Ford - Bellman algorithm" << endl
		<< "[3] Floyd algorithm" << endl;
}

void clearStream()
{
	cin.clear();
	cin.ignore(10000, '\n');
}

int inputNumber(int min, int max)
{
	int x = 0;
	while (true)
	{
		cin >> x;
		if (!cin.fail() && cin.peek() == '\n' && (min <= x && x <= max))
		{
			return x;
		}
		else 
		{
			cout << "input number from " << min << " to " << max << ": ";
			clearStream();
		}
	}
}

string inputFileName()
{
	string fileName;
	cin >> ws;
	getline(cin, fileName);

	return fileName;
}

vector<vector <int>> loadMatrix(ifstream& fin)
{
	int n;
	fin >> n;
	vector<vector <int>> matrix(n, vector <int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fin >> matrix[i][j];
		}

	return matrix;
}

void saveMatrix(const vector<vector <int>>& matrix, ofstream& fout)
{
	int n = size(matrix);
	fout << n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fout << matrix[i][j];
		}

}

void printMatrix(const vector<vector <int>> &matrix)
{
	int n = size(matrix);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << '\n';
	}	
}

vector<vector <int>> createMatrix()
{
	int n;
	cout << "input size n of matrix: ";
	n = inputNumber(1, INT_MAX);
	vector<vector <int>> matrix(n, vector <int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Element [" << i+1 << "][" << j+1 << "]: ";
			matrix[i][j] = inputNumber(INT_MIN, INT_MAX);
		}

	return matrix;
}

int main()
{
	vector<vector <int>> matrix;

	while (true)
	{
		printMainMenu();
		switch (inputNumber(0, 5))
		{
		case 1:
		{
			cout << "File name of the weights matrix load: ";
			string fileName = inputFileName();
			ifstream fin;
			fin.open("matrix base\\" + fileName, ios::in);
			if (fin.is_open())
			{
				matrix = loadMatrix(fin);
				cout << "Successfull load" << endl;
			}
			else
			{
				cout << "Error of weights matrix load." << endl;
			}
			fin.close();

			break;
		}
		case 2:
		{
			matrix = createMatrix();

			break;
		}
		case 3:
		{
			if (size(matrix))
			{
				cout << "File name of the weights matrix save: ";
				string fileName = inputFileName();
				ofstream fout;
				fout.open("matrix base\\" + fileName, ios::out);
				if (fout.is_open())
				{
					saveMatrix(matrix, fout);
					cout << "Successfull save" << endl;
				}
				else
				{
					cout << "Error of weights matrix save." << endl;
				}
				fout.close();
				
			}
			else
			{
				cout << "Error: matrix not create" << endl;
			}
			break;
		}
		case 4:
		{
			if (size(matrix))
			{
				printMatrix(matrix);
			}
			else
			{
				cout << "Error: matrix not create" << endl;
			}
			break;
		}
		case 5:
		{

			break;
		}
		case 0:
		{
			return 0;
		}
		default:
		{
			cout << "Wrong action" << endl;
			clearStream();
			break;
		}
		}	
	}

	return 0;
}