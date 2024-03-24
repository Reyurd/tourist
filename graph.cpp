#include<iostream>
#include"data_struct.h"

#include <vector>

// 生成邻接矩阵的函数
std::vector<std::vector<int>> generateAdjacencyMatrix(int nodes, const std::vector<std::pair<int, int>>& edges) {
    std::vector<std::vector<int>> adjacencyMatrix(nodes, std::vector<int>(nodes, 0));

    for (const auto& edge : edges) {
        int from = edge.first;
        int to = edge.second;

        // 无向图，所以我们需要在矩阵中标记两次
        adjacencyMatrix[from][to] = 1;
        adjacencyMatrix[to][from] = 1;
    }

    return adjacencyMatrix;
}

int main() {
    // 图的节点数
    int nodes = 5;
    // 图的边，每对数字代表一条边连接的两个节点
    std::vector<std::pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};

    auto matrix = generateAdjacencyMatrix(nodes, edges);

    // 打印邻接矩阵
    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
