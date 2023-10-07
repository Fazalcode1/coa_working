#include <iostream>
#include <vector>

class Graph
{
    using WeightTy = double;
    using VertexTy = std::size_t;
    VertexTy numVertices;
    
    std::vector<VertexTy> csrList;
    std::vector<WeightTy> csrWeights;
    std::vector<std::size_t> csrOffsets; 
public:
    Graph(VertexTy numVertices_, std::vector<VertexTy> &&csrList_, std::vector<WeightTy> &&csrWeights_) : 
    numVertices(numVertices_), csrList(std::move(csrList_)), csrWeights(std::move(csrWeights_))
    {
        csrOffsets.resize(numVertices_+1, 0);
        for(VertexTy i=0;i<csrList.size();i++){
            csrOffsets[csrList[i]+1]++;
        }
        for(VertexTy i=1;i<numVertices_+1;i++){
            csrOffsets[i]+=csrOffsets[i-1];
        }
    }
};

int main(){
    using std::cin;
    using WeightTy = double;
    using VertexTy = std::size_t;
    std::string s1,s2,s3,s4;
    VertexTy numNodes, numEdges;
    std::vector<VertexTy> csrList;
    std::vector<WeightTy> csrWeights;
    cin>>s1>>s2>>s3;
    cin>>numNodes;
    std::vector<std::vector<std::pair<VertexTy,WeightTy>>> adj(numNodes+1);
    cin>>s3;
    cin>>numEdges;
    for(VertexTy i=0;i<numEdges;i++){
        cin>>s4;
        VertexTy src,dest;
        WeightTy wt;
        cin>>src>>dest>>wt;
        adj[src-1].push_back({dest-1,wt});
        adj[dest-1].push_back({src-1,wt});
    }
    for(VertexTy i=0;i<numNodes;i++){
        for(auto x:adj[i]){
            csrList.push_back(x.first);
            csrWeights.push_back(x.second);
        }
    }
    Graph g(numNodes,std::move(csrList),std::move(csrWeights));
    
    // for(int i=0;i<g.csrOffsets.size();i++){
    //     std::cout<<g.csrOffsets[i]<<" ";
    // }

}
