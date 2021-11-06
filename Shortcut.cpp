#include "utils.h"

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

void printAlgorithmMenu(int startPoint, int endPoint)
{
	cout << "....................." << endl
		<< "Start point: " << startPoint << ". End point: " << endPoint << endl
		<< "Choose algorithm:" << endl
		<< "[1] Dijkstra algorithm" << endl
		<< "[2] Ford - Bellman algorithm" << endl
		<< "[3] Floyd algorithm" << endl
		<< "[4] Change start point" << endl
		<< "[5] Change end point" << endl
		<< "[0] Back to menu" << endl
		<< "Choose action: ";
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

double inputNumber(double min, double max)
{
	double x = 0;

	while (true)
	{
		cin >> x;
		if(!cin.fail() && cin.peek() == '\n' && (min <= x && x <= max))
		{
			return x;
		}
		else
		{
			return HUGE_VAL;
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

vector<vector <double>> loadMatrix(ifstream& fin)
{
	int n;
	fin >> n;
	vector<vector <double>> matrix(n, vector <double>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fin >> matrix[i][j];
		}

	return matrix;
}

void saveMatrix(const vector<vector <double>>& matrix, ofstream& fout)
{
	int n = size(matrix);
	fout << n << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fout << matrix[i][j] << endl;
		}

}

void printMatrix(const vector<vector <double>>&matrix)
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

vector<vector <double>> createMatrix()
{
	int n;
	cout << "input size n of matrix: ";
	n = inputNumber(1, INT_MAX);
	vector<vector <double>> matrix(n, vector <double>(n));

	//need prompt about inf
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Element [" << i << "][" << j << "]: ";
			matrix[i][j] = inputNumber(DBL_MIN, DBL_MAX);
		}

	return matrix;
}

int selectStartPoint(int size)
{
	cout << "Select starting point (from 0 to " << size - 1 << "): ";
	return inputNumber(0, size - 1);
}

int selectEndPoint(int size)
{
	cout << "Select end point (from 0 to " << size - 1 << "): ";
	return inputNumber(0, size - 1);
}

int findShortcut(const vector<vector <double>>& matrix)
{
	int n = size(matrix);
	int startPoint = selectStartPoint(n);
	int endPoint = selectEndPoint(n);

	while (true)
	{
		printAlgorithmMenu(startPoint, endPoint);
		switch (inputNumber(0, 5))
		{
		case 1:
		{
			auto start = chrono::system_clock::now();

			//algorithmDijkstra(matrix, startPoint, endPoint);

			auto finish = chrono::system_clock::now();
			auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
			cout << "Algorithm running time (milliseconds): " << duration << endl;
			break;
		}
		case 2:
		{
			auto start = chrono::system_clock::now();

			//algorithmFord(matrix, startPoint, endPoint);

			auto finish = chrono::system_clock::now();
			auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
			cout << "Algorithm running time (milliseconds): " << duration << endl;
			break;
		}
		case 3:
		{
			auto start = chrono::system_clock::now();

			//algorithmFloyd(matrix, startPoint, endPoint);

			auto finish = chrono::system_clock::now();
			auto duration = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
			cout << "Algorithm running time (milliseconds): " << duration << endl;
			break;
		}
		case 4:
		{
			startPoint = selectStartPoint(n);
			break;
		}
		case 5:
		{
			endPoint = selectEndPoint(n);
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
}

int main()
{
	vector<vector <double>> matrix;

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
			if (size(matrix))
			{
				findShortcut(matrix);
			}
			else
			{
				cout << "Error: matrix not create" << endl;
			}
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