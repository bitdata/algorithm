#include <bits/stdc++.h>
#include <assert.h>
using namespace std;

const int WHITE=0;
const int GRAY=1;
const int BLACK=2;

struct Vertex{
    int id; // 仅用于调试输出
    int color;
    int d;
    int f;
    Vertex* pi;
};

struct Graph{
    vector<Vertex> V;
    map<Vertex*,vector<Vertex*> > Adj;
};

int dfs_time=0;

list<Vertex*> topological_list;

void dfs_visit(Graph& G, Vertex& u){
    dfs_time=dfs_time+1;
    u.d=dfs_time;
    u.color=GRAY;
    for(Vertex* p:G.Adj[&u]){
        Vertex& v=*p;
        if(v.color==WHITE){
            v.pi=&u;
            dfs_visit(G,v);
        }
    }
    u.color=BLACK;
    dfs_time=dfs_time+1;
    u.f=dfs_time;
    topological_list.push_front(&u);
}

void dfs(Graph& G){
    for(Vertex& u:G.V){
        u.color=WHITE;
        u.pi=NULL;
    }
    dfs_time=0;
    for(Vertex& u:G.V){
        if(u.color==WHITE){
            dfs_visit(G,u);
        }
    }
}

void initialize(Graph& G,int n){
    G.V.resize(n);
    for(int i=0;i<G.V.size();i++){
        Vertex& v=G.V[i];
        v.id=i+1;
        vector<Vertex*> array;
        G.Adj[&v]=array;
    }
}

Vertex& get_vertex(Graph& G,int id){
    return G.V[id-1];
}

void add_edge(Graph& G,int id1,int id2){
    Vertex& u=get_vertex(G,id1);
    Vertex& v=get_vertex(G,id2);
    G.Adj[&u].push_back(&v);
}

void test(){
    Graph G;
    initialize(G,6);
    add_edge(G,1,2);
    add_edge(G,1,3);
    add_edge(G,2,3);
    add_edge(G,3,4);
    add_edge(G,4,2);
    add_edge(G,5,4);
    add_edge(G,5,6);

    dfs(G);
    for(Vertex* p:topological_list){
        printf("%d\r\n",p->id);
    }
}

int main(){
  test();
  return 0;  
}