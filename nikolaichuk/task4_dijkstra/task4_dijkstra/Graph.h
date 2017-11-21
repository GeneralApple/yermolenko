#pragma once
#include <string>
#include "Vertex.h"

class Graph
{
private:
	std::vector<Vertex> vertices;
	int verticesNum;
public:
	Graph();
	Graph(std::string filename);
	~Graph();

	void addVertex(Vertex vertex);
	void loadFromFile(std::string filename);
	void printGraph();

	std::vector<int> findMinDistances(int fromVertex = 0);
};

