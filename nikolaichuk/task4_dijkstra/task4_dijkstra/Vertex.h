#pragma once
#include <vector>

class Vertex
{
private:
	std::vector<std::pair<int, int>> distances;
public:
	Vertex();
	~Vertex();

	void addEdge(int vertexNum, int distance);
	void addEdge(std::pair<int, int> vertDist);
	std::vector<std::pair<int, int>> getDistances();
};

