#include "utils.h"

using namespace std;

void algorithmFord(vector<vector <double>> matrix, int startPoint, int endPoint)
{
	cout << "algorithmFord" << endl;

	int n = matrix.size();  // число вершин в графе
	

	for (int i = 0; i < n; i++)      // подготовка матрицы: изменение нулей на бесконечность.
		for (int j = 0; j < n; j++)
		{
			if (i != j && matrix[i][j] == 0)
				matrix[i][j] = INFINITY;
		}

	printMatrix(matrix);

	//vector <vector <int>> way(n, vector<int> (n));  // массив кротчайшего пути
	vector<double> labels(n);  // массив длин путей из каждой вершины в конкретную
	vector<double> lambdas(n);  // массив кротчайших расстояний
	vector<double> lambdasnew(n);  // массив кротчайших расстояний для присваивания
	for (int j = 0; j < n; j++)
		lambdas[j] = INFINITY;
	lambdas[startPoint] = 0.0;

	for (int k = 1; k <= n - 1; k++) {
		for (int i = 0; i <= n-1; i++) {
			for (int j = 0; j <= n-1; j++) {
				labels[j] = lambdas[j] + matrix[j][i];
			}
			lambdasnew[i] = findmin(labels);
		}
		for (int i = 0; i < n; i++) {
			lambdas[i] = lambdasnew[i];
		}
	}
	if (lambdas[endPoint] == INFINITY)
		cout << "There is no way between point " << startPoint << " and point " << endPoint << endl;
	else
	cout << "The shortest path from point " << startPoint << " to point " << endPoint << " is " << lambdas[endPoint] << endl;
}

double findmin(vector<double> array)
{
	double min = INFINITY;
	for (int i = 0; i < array.size(); i++)
	{
		if (min > array[i])
			min = array[i];
	}
	return min;
}