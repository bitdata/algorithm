#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

const int WHITE=0;
const int GRAY=1;
const int BLACK=2;

struct Vertex{
    int id; 
    int color;
    int d;
    int f;
    int pi;
};

struct Graph{
    vector<Vertex> V;
    map<int,Vertex*> M;
    map<int,vector<int> > Adj;
};

int dfs_time=0;

list<int> topological_list;

Vertex& get_vertex(Graph& G,int id){
    return *G.M[id];
}

void dfs_visit(Graph& G, Vertex& u){
    dfs_time=dfs_time+1;
    u.d=dfs_time;
    u.color=GRAY;
    for(int id:G.Adj[u.id]){
        Vertex& v=get_vertex(G,id);
        if(v.color==WHITE){
            v.pi=u.id;
            dfs_visit(G,v);
        }
    }
    u.color=BLACK;
    dfs_time=dfs_time+1;
    u.f=dfs_time;
    topological_list.push_front(u.id);
}

void dfs(Graph& G){
    for(Vertex& u:G.V){
        u.color=WHITE;
        u.pi=0;
    }
    dfs_time=0;
    for(auto & u:G.V){
        if(u.color==WHITE){
            dfs_visit(G,u);
        }
    }
}

void initialize(Graph& G,list<int> L){
    for(int id:L){
        Vertex v;
        v.id=id;
        G.V.push_back(v);
        vector<int> array;
        G.Adj[id]=array;
    }
    for(auto & v:G.V){
        G.M[v.id]=&v;
    }
}

void add_edge(Graph& G,int id1,int id2){
    G.Adj[id1].push_back(id2);
}

void strongly_connected_components(Graph& G){
    dfs(G);

    Graph Gt;
    // 节点按DFS完成时间排序
    initialize(Gt,topological_list);
    // 矩阵转置
    for(auto& kv:G.Adj){
        int id1=kv.first;
        for(int id2:kv.second){
            add_edge(Gt,id2,id1);
       }
    }
    
    for(auto & u:Gt.V){
        u.color=WHITE;
        u.pi=0;
    }
    dfs_time=0;
    for(auto & u:Gt.V){
        if(u.color==WHITE){
            topological_list.clear();
            dfs_visit(Gt,u);
            for(int id:topological_list){
                printf("%d ",id);
            }
            printf("\r\n");
        }
    }

}

void test(){
    Graph G;
    list<int> L;
    for(int i=0;i<8;i++){
        L.push_back(i+1);
    }
    initialize(G,L);
    add_edge(G,1,2);
    add_edge(G,2,3);
    add_edge(G,3,4);
    add_edge(G,4,3);
    add_edge(G,5,1);
    add_edge(G,2,5);
    add_edge(G,2,6);
    add_edge(G,3,7);
    add_edge(G,4,8);
    add_edge(G,5,6);
    add_edge(G,6,7);
    add_edge(G,7,6);
    add_edge(G,7,8);

    strongly_connected_components(G);
}

int main(){
  test();
  return 0;  
}