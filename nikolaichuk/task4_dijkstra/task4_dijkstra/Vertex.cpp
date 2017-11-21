#include "stdafx.h"
#include "Vertex.h"


Vertex::Vertex()
{
}


Vertex::~Vertex()
{
}

void Vertex::addEdge(int vertexNum, int distance)
{
	this->distances.push_back(std::pair<int, int>(vertexNum, distance));
}

void Vertex::addEdge(std::pair<int, int> vertDist)
{
	this->distances.push_back(vertDist);
}

std::vector<std::pair<int, int>> Vertex::getDistances()
{
	return this->distances;
}
