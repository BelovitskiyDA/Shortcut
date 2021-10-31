#include <iostream>
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
		<< "[4] Finding shortcut" << endl
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
			cout << "Element [" << i << "][" << j << "]: ";
			matrix[i][j] = inputNumber(INT_MIN, INT_MAX);
		}

	return matrix;
}

int main()
{
	vector<vector <int>> matrix;

	while (true)
	{
		cout << "File name of the weights matrix load: ";
		string fileName = inputFileName();
		ifstream fin;
		fin.open("matrix base\\" + fileName, ios::in);
		if (fin.is_open())
		{
			matrix = loadMatrix(fin);
			printMatrix(matrix);

			cout << "Successfull load" << endl;
		}
		else
		{
			cout << "Error of weights matrix load. Try again." << endl;
		}
		fin.close();
	}

	return 0;
}