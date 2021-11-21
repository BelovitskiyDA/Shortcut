#include "utils.h"

void algorithmFloyd(vector<vector <double>> matrix, int startPoint, int endPoint)
{
	vector<vector <double>> copyMatrix = matrix;

	int n = matrix.size();
	for (int i = 0; i < n; i++)      
		for (int j = 0; j < n; j++)
		{
			if (i != j && matrix[i][j] == 0)
				matrix[i][j] = std::numeric_limits<double>::infinity();
		}

	auto start = chrono::system_clock::now();

	/*cout << "algorithmFloyd" << endl;*/
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (matrix[i][k] < std::numeric_limits<double>::infinity() && matrix[k][j] < std::numeric_limits<double>::infinity()) {
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
					if (matrix[i][i] < 0) {
						cout << "Floyd: error" << '\t';
						/*cout << "Floyd's algorithm does not work correctly in the presence of a negative weight cycle" << endl;*/
						return;
					}
				}
	/*printMatrix(matrix);*/
	/*cout << "Answer= " << matrix[startPoint][endPoint] << endl;*/
	cout << "Floyd: " << matrix[startPoint][endPoint] << '\t';
	
	auto finish = chrono::system_clock::now();
	auto duration = chrono::duration_cast<chrono::nanoseconds>(finish - start).count(); //milliseconds nanoseconds
	cout << "time(nanoseconds) : " << duration << '\t';
	/*cout << duration << endl;*/

	findWay(copyMatrix, matrix[startPoint], startPoint, endPoint);
}