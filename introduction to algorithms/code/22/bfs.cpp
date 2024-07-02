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
    Vertex* pi;
};

struct Graph{
    vector<Vertex> V;
    map<Vertex*,vector<Vertex*> > Adj;
};

void bfs(Graph& G, Vertex& s){
    for(Vertex& u:G.V){
        if(&u==&s){
            continue;
        }
        u.color=WHITE;
        u.d=INT_MAX;
        u.pi=NULL;
    }
    s.color=GRAY;
    s.d=0;
    s.pi=NULL;
    queue<Vertex*> Q;
    Q.push(&s);
    while(!Q.empty()){
        Vertex& u=*Q.front();
        Q.pop();
        for(Vertex* p:G.Adj[&u]){
            Vertex& v=*p;
            if(v.color==WHITE){
                v.color=GRAY;
                v.d=u.d+1;
                v.pi=&u;
                Q.push(&v);
            }
        }
        u.color=BLACK;
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
    G.Adj[&v].push_back(&u);
}

void print_path(Vertex& u){
    Vertex* p=&u;
    while(p->pi!=NULL){
        printf("%d->",p->id);
        p=p->pi;
    }
    printf("%d\r\n",p->id);
}

void test(){
    Graph G;
    initialize(G,8);
    add_edge(G,1,2);
    add_edge(G,1,3);
    add_edge(G,3,4);
    add_edge(G,4,5);
    add_edge(G,4,6);
    add_edge(G,5,6);
    add_edge(G,5,7);
    add_edge(G,6,7);
    add_edge(G,6,8);
    add_edge(G,7,8);

    bfs(G,get_vertex(G,3));
    for(Vertex& u:G.V){
        print_path(u);
    }
}

int main(){
  test();
  return 0;  
}