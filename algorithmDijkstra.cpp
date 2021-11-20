//
// Created by Евгений Беляков on 20.11.2021.
//
#include "utils.h"
#include <queue>

void algorithmDijkstra(std::vector<std::vector <double>> matrix, int startPoint, int endPoint){
    std::cout << "Dijkstra's algorithm start: " << std::endl;
    std::size_t n = matrix.size();
    std::vector<double> min_weight(n, numeric_limits<double>::infinity());
    min_weight[startPoint] = 0;
    for (std::size_t i = 0; i < n; ++i){
        for (std::size_t j = 0; j < n; ++j){
            if (matrix[i][j] < 0){
                std::cout << "Dijkstra's algorithm works only for graphs without edges of negative weight" << std::endl;
                return;
            }else if(matrix[i][j] == 0){
                matrix[i][j] = numeric_limits<double>::infinity();
            }
        }
    }
    priority_queue<pair <double, int>> q_vertices;
    q_vertices.push({0, startPoint});
    while(!q_vertices.empty()){
        double len = -q_vertices.top().first;
        int vertex = q_vertices.top().second;
        q_vertices.pop();
        if (len > min_weight[vertex]){
            continue;
        }
        for (std::size_t i = 0; i < n; ++i){
            size_t to = i;
            double length_vert_to = matrix[vertex][to];
            if (min_weight[to] > min_weight[vertex] + length_vert_to){
                    min_weight[to] = min_weight[vertex] + length_vert_to;
                    q_vertices.push({-min_weight[to], to});
            }
        }
    }
    cout << "Answer = " << min_weight[endPoint] << endl;
}
