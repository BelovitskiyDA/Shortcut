#include "utils.h"

using namespace std;

void algorithmFord(vector<vector <double>> matrix, int startPoint, int endPoint)
{
	cout << "algorithmFord" << endl;

	int n = matrix.size();  // the number of vertices in the graph
	

	for (int i = 0; i < n; i++)      // matrix preparation: changing zeros to infinity.
		for (int j = 0; j < n; j++)
		{
			if (i != j && matrix[i][j] == 0)
				matrix[i][j] = std::numeric_limits<double>::infinity();
		}

	vector<double> labels(n);  // array of path lengths from each vertex to a specific one
	vector<double> lambdas(n);  // array of shortest distances
	vector<double> lambdasnew(n);  // array of shortest distances to assign
	
	for (int j = 0; j < n; j++)
		lambdas[j] = std::numeric_limits<double>::infinity();
	lambdas[startPoint] = 0.0;  // assigned the shortest distances to infinity other than the starting one

	for (int k = 1; k <= n; k++) {
		for (int i = 0; i <= n-1; i++) {
			for (int j = 0; j <= n-1; j++) {
				labels[j] = lambdas[j] + matrix[j][i];
			}
			lambdasnew[i] = findmin(labels);
		}
		if (k != n)
		for (int i = 0; i < n; i++) {
			lambdas[i] = lambdasnew[i];
		}
	}
	// I check the graph for negative weight cycles: I check the last and penultimate iterations,
	bool flag = 1;    // if at least 1 path has become shorter, then there is such a cycle.
	for (int i = 0; i < n; i++)            
		if (lambdasnew[i] < lambdas[i]) {
			flag = 0;
			break;
		}
	if (lambdas[endPoint] == std::numeric_limits<double>::infinity() && flag)
		cout << "There is no way between point " << startPoint << " and point " << endPoint << endl;
	else if (flag)
	cout << "The shortest path from point " << startPoint << " to point " << endPoint << " is " << lambdas[endPoint] << endl;
	else if (!flag)
	cout << "The graph has a negative weight cycle." << endl;
}

double findmin(vector<double> array)
{
	double min = std::numeric_limits<double>::infinity();
	for (int i = 0; i < array.size(); i++)
	{
		if (min > array[i])
			min = array[i];
	}
	return min;
}