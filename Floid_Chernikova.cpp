#include "utils.h"
void algorithmFloyd(vector<vector <double>> matrix, int startPoint, int endPoint)
{
	int n = matrix.size();
	for (int i = 0; i < n; i++)      
		for (int j = 0; j < n; j++)
		{
			if (i != j && matrix[i][j] == 0)
				matrix[i][j] = std::numeric_limits<double>::infinity();
		}
	cout << "algorithmFloyd" << endl;
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][k] < std::numeric_limits<double>::infinity() && matrix[k][j] < std::numeric_limits<double>::infinity()) {
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
					if (matrix[i][i] < 0) {
						cout << "Floyd's algorithm does not work correctly in the presence of a negative weight cycle" << endl;
						return;
					}
				}
	printMatrix(matrix);
	cout << "Answer= " << matrix[startPoint][endPoint] << endl;
}