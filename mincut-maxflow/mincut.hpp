// Residual Graph
#ifndef MINCUT_HPP_
#define MINCUT_HPP_
#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include <utility>
#include<queue>
#include<set>
#include<climits>
#include"../util/util.hpp"
#include"../spatial/Graph.hpp"
class minCut : public spatial::Graph{
public:
	bool BFS(int s, int t);
	int sendFlow(int s, int flow, int t, long long unsigned int ptr[]);
	int DinicMaxflow(int s, int t);
	int multiSinkTrans();
	int* level; // stores level of a node
	std::pair<std::set<int>,std::set<int>> MinCut(int s);
	minCut(int vNum)
	{
		adj = new std::vector<spatial::Edge>[vNum];
		this->vNum = vNum;
		level = new int[vNum];
	}
};

#endif 