#include"Graph.h"

int* AdjencyGraph(int vert, int edges)
{
	int* adjMat = (int*)malloc(vert * vert * sizeof(int));
	memset(adjMat, 0, vert * vert * sizeof(int));
	for (int i = 0; i < edges; i++)
	{
		int u, v;
		std::cin >> u >> v;
		if (u >= vert || u<0)
			std::cin >> u;
		if (v >= vert || v < 0)
			std::cin >> v;
		*(adjMat + (u * vert) + v) = 1;
		*(adjMat + (v * vert) + u) = 1;
	}
	return adjMat;
}

void ShowGraph(int* adjMat, int vert)
{
	std::cout << "  ";
	for (int j = 0; j < vert; j++)
	{
		std::cout << j << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < vert; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < vert; j++)
		{
			std::cout << *(adjMat + (i * vert) + j) << " ";
		}
		std::cout << std::endl;
	}
}

void Graph::AddEdge(int u, int v)
{
	adgcList[u].push_back(v);
	adgcList[v].push_back(u);
}

Graph::Graph(int vert, std::vector<std::pair<int, int>>& edge): numberOfVertices(vert), numberOfEdges(edge)
{
	adgcList = new std::vector<int>[numberOfVertices];
	for (auto x : numberOfEdges)
	{
		AddEdge(x.first, x.second);
	}
}

Graph::~Graph()
{
	delete[] adgcList;
}

void Graph::PrintGraph()
{
	for (int i = 0; i < numberOfVertices; i++)
	{
		std::cout << "Adjacency list of vertex " << i << " \n head ";
		for (auto x : adgcList[i])
		{
			std::cout << " -> " << x;
		}
		std::cout << std::endl;
	}
}