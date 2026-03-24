#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    public:
    Graph(int v){
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void BFS(int s){
        queue<int> q;
        vector<bool> visited(V,false);

        visited[s] = true; 
        q.push(s);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();

            cout << node << " ";
            for(int nebg : l[node]){
                if(!visited[nebg]){
                    visited[nebg] = true;
                    q.push(nebg);
                }
            }
        }
        cout << endl;
    }
    void DFSHelper(int s,vector<bool> &vec){
        cout <<s << " ";
        vec[s] = true;

        for(int nebg : l[s]){
            if(!vec[nebg]){
                DFSHelper(nebg,vec);
            }
        }
    }

    void DFS(int s){
        vector<bool> vis(V,false);
        DFSHelper(s,vis);

    }
};
int main(){
    Graph s(8);
    s.addEdge(0,1);
    s.addEdge(0,2);
    s.addEdge(0,3);
    s.addEdge(3,4);
    s.addEdge(3,5);
    s.addEdge(3,6);
    s.addEdge(5,7);
    cout << "BFS TRAVERSAL: ";
    s.BFS(0);

    
    cout << "DFS Traversal: ";
    s.DFS(0);
    return 0;
}