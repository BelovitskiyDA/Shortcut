#include <cfloat>
#include <cmath>
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
		<< "[6] Run the database" << endl
		<< "[7] Generation the database" << endl
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

void clearStream(istream& in)
{
	in.clear();
	in.ignore(10000, '\n');
}

template <typename T>
T inputNumber(T min, T max)
{
	T x = 0;
	while (true)
	{
		cin >> x;
		bool a = !cin.fail();
		bool b = cin.peek() == '\n';
		bool c = (min <= x);
		bool d = (x <= max);
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

vector<vector <double>> loadMatrix(ifstream& fin)
{
	int n;
	fin >> n;
	double x = 0;
	vector<vector <double>> matrix(n, vector <double>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fin >> x;
			matrix[i][j] = x;
		}

	return matrix;
}

void saveMatrix(const vector<vector <double>>& matrix, ofstream& fout)
{
	int n = matrix.size();
	fout << n << endl;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fout << matrix[i][j] << endl;
		}

}

void printMatrix(const vector<vector <double>>&matrix)
{
	int n = matrix.size();
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

	cout << "If there is no way from i to j, then enter 0" << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 0;
				cout << "Element [" << i << "][" << j << "]: " << matrix[i][j] << endl;
			}
			else
			{
				cout << "Element [" << i << "][" << j << "]: ";
				matrix[i][j] = inputNumber(-DBL_MAX, DBL_MAX);
			}
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

using Algorithm = void(*)(vector<vector <double>> matrix, int startPoint, int endPoint);

void startAlgorithm(Algorithm f, vector<vector <double>> matrix, int startPoint, int endPoint)
{
	auto start = chrono::system_clock::now();

	f(matrix, startPoint, endPoint);

	auto finish = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(finish - start).count(); //milliseconds nanoseconds
	cout << "Function time(nanoseconds) : " << duration << endl;

	/*cout << "Algorithm running time (milliseconds): " << duration << endl;*/
}

int findShortcut(const vector<vector <double>>& matrix)
{
	int n = matrix.size();
	int startPoint = selectStartPoint(n);
	int endPoint = selectEndPoint(n);

	while (true)
	{
		printAlgorithmMenu(startPoint, endPoint);
		switch (inputNumber(0, 5))
		{
		case 1:
		{
			startAlgorithm(algorithmDijkstra, matrix, startPoint, endPoint);
			break;
		}
		case 2:
		{
			startAlgorithm(algorithmFord, matrix, startPoint, endPoint);
			break;
		}
		case 3:
		{
			startAlgorithm(algorithmFloyd, matrix, startPoint, endPoint);
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

void startAllAlgorithm(vector<vector <double>> matrix, int startPoint, int endPoint)
{
	startAlgorithm(algorithmDijkstra, matrix, startPoint, endPoint);
	startAlgorithm(algorithmFord, matrix, startPoint, endPoint);
	startAlgorithm(algorithmFloyd, matrix, startPoint, endPoint);
}

int main()
{
	vector<vector <double>> matrix;

	while (true) 
	{
		printMainMenu();
		switch (inputNumber(0, 7))
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
			if (matrix.size())
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
			if (matrix.size())
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
			if (matrix.size())
			{
				findShortcut(matrix);
			}
			else
			{
				cout << "Error: matrix not create" << endl;
			}
			break;
		}
		case 6:
		{
			int i = 0;
			ifstream fin;
			bool flag = true;

			while (flag)
			{
				string fileName = "matrix base\\" + to_string(++i);
				fin.open(fileName, ios::in);
				if (fin.is_open())
				{
					flag = fin.is_open();
					cout << "file: " << fileName << "................................................................." << endl;
					matrix = loadMatrix(fin);
					startAllAlgorithm(matrix, 0, matrix.size()-1);
				}
				else
				{
					cout << "Error of weights matrix load from file:" << i << endl;
					flag = false;
				}
				fin.close();
			}

			break;
		}
		case 7:
		{
			ofstream fout;

			for (int k = 4; k <= 80; k++)
			{
				int n = k;
				vector<vector <double>> matrix(n, vector <double>(n));
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
					{
						if (i == j)
						{
							matrix[i][j] = 0;
						}
						else
						{
							matrix[i][j] = rand();
						}
					}

				
				fout.open("matrix base\\" + to_string(k+3), ios::out);
				if (fout.is_open())
				{
					saveMatrix(matrix, fout);
					cout << k << " Successfull save" << endl;
				}
				else
				{
					cout << k <<  " Error of weights matrix save." << endl;
				}
				fout.close();
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