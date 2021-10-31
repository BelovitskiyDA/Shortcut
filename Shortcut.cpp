#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void printMenu()
{
	cout << "....................." << endl
		<< "[1] Load weights matrix" << endl
		<< "[2] Dijkstra algorithm" << endl
		<< "[3] Ford - Bellman algorithm" << endl
		<< "[4] Floyd algorithm" << endl

		<< "[5] Edit CS" << endl
		<< "[6] Save" << endl
		<< "[7] Load" << endl
		<< "[8] Search" << endl
		<< "[0] Exit" << endl
		<< "Choose action: ";
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