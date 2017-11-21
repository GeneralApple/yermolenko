#include "stdafx.h"
#include "Graph.h"
#include <fstream>
#include <iostream>

const uint64_t MAX_DISTANCE = 1000000000;

Graph::Graph()
{
}

Graph::Graph(std::string filename)
{
	this->verticesNum = 0;
	this->loadFromFile(filename);
}


Graph::~Graph()
{
}

void Graph::loadFromFile(std::string fileName)
{
	std::ifstream inGraph("graph.txt");
	int totalVertices, vertexEdges, vertexInd, distance;
	inGraph >> totalVertices;
	this->verticesNum = totalVertices;

	for (int i = 0; i < totalVertices; i++) {
		inGraph >> vertexEdges;
		Vertex vertex;
		for (int j = 0; j < vertexEdges; j++) {
			inGraph >> vertexInd >> distance;
			vertex.addEdge(vertexInd, distance);
		}
		this->addVertex(vertex);
	}
}

void Graph::addVertex(Vertex vertex)
{
	this->vertices.push_back(vertex);
}

std::vector<int> Graph::findMinDistances(int fromVertex)
{
	std::vector<int> minDistances(this->verticesNum, MAX_DISTANCE);
	std::vector<bool> visited(this->verticesNum, false);
	int currVertex = fromVertex; bool end = false;
	int nextVertex; minDistances[currVertex] = 0;

	do {
		visited[currVertex] = true;
		int tempMin = MAX_DISTANCE;
		for (const auto& edge : this->vertices[currVertex].getDistances()) {
			// calc and refresh distance to connected
			int tentativeDist = minDistances[currVertex] + edge.second;
			if (tentativeDist < minDistances[edge.first] && !visited[edge.first]) {
				minDistances[edge.first] = tentativeDist;
			}
			// track closest vertex
			if (edge.second < tempMin && !visited[edge.first]) {
				tempMin = edge.second;
				nextVertex = edge.first;
			}
		}
		currVertex = nextVertex;
	} while (!visited[nextVertex]);

	return minDistances;
}

void Graph::printGraph()
{
	int size = this->vertices.size();
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Vertex number " << i << ". Connected to:\n";
		for (const auto& x : this->vertices[i].getDistances()) {
			std::cout << "\t" << x.first << ", edge length " << x.second << std::endl;
		}
	}
}
