#pragma once
#include<cstdlib>
#include<iostream>
#include<vector>
int* AdjencyGraph(int vert, const int edges);
void ShowGraph(int* adjMat, int vert);

class Graph
{
	int numberOfVertices;
	std::vector<std::pair<int, int>> numberOfEdges;
	std::vector<int>* adgcList;
	void AddEdge(int u, int v);
public:
	Graph(int vert, std::vector<std::pair<int, int>>& edge);
	~Graph();
	void PrintGraph();
};