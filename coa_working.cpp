#include <bits/stdc++.h>
 
using namespace std;

class edge{
public:
	int32_t source;
	int32_t destination;
	double weight;
	
	edge(int32_t src,int32_t dst,double wt)
	: source(src),destination(dst),weight(wt){}
};

class vertex{
public:
	int32_t number;
	vector<edge> neighbours;
	
    vertex(){
        number = -1;
    }
    
	vertex(int32_t num): number(num){}
	
	void add_edge(edge& Edge){
		neighbours.push_back(Edge);
	}
};

class graph{
public:
	int32_t total_vertices;
	int32_t total_edges;
	unordered_map<int32_t,vertex> vertices;
	vector<edge> edges;
	
	void store(vector<vector<pair<int32_t,int32_t>>>& adj){
		int32_t total_vertices = adj.size();
		total_edges = 0;
		for(int32_t i=0;i<total_vertices;i++){
			vertex v(i);
			for(int32_t j=0;j<adj[i].size();j++){
				edge e(i,adj[i][j].first,adj[i][j].second);
				v.add_edge(e);
				edges.push_back(e);
				total_edges++;
			}
            vertices[i] = v;
		}
	}
	
	vector<edge> getNeighbours(int32_t V){
        vertex w = vertices[V];
		return w.neighbours;
	}
};
