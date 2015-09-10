#include<bits/stdc++.h>
using namespace std;

class graph{
	public:
	int v,e,ct;
	list<int> *adj;
	graph(int,int);
	void addEdge(int,int);
	void dfs();
	void dfs_util(int,bool*,stack<int>&);
};

graph::graph(int v,int e){
	this->v=v;
	this->e=e;
	ct=0;
	adj=new list<int>[v];
}

void graph::addEdge(int a,int b){
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void graph::dfs_util(int u,bool* vi,stack<int> &st){
	vi[u]=true;
	st.push(u);
	for(list<int>::iterator i=adj[u].begin();i!=adj[u].end();i++){
		if(!vi[*i])
			dfs_util(*i,vi,st);
	}
}

void graph::dfs(){
	bool* vi=new bool[this->v];
	stack<int> st;
	for(int i=0;i<this->v;i++){
		vi[i]=false;
	}
	for(int i=0;i<this->v;i++){
		if(!vi[i]){
			ct++;
			dfs_util(i,vi,st);
			while(!st.empty()){
				printf("%d ",st.top());
				st.pop();
			}
			printf("\n");
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int v,e;
		scanf("%d",&v);
		scanf("%d",&e);
		graph g(v,e);
		for(int i=0;i<e;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			g.addEdge(a,b);
		}
		g.dfs();
		printf("%d\n",g.ct);
	}
	
return 0;	
}
