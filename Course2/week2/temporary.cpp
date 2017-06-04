#include<iostream>
#include<queue>
#include<vector>
#include<fstream>
#include<climits>
using namespace std;

typedef pair<int,int> P;
priority_queue<P, vector<P>,greater<P> > Q;
int D[201];


void dijkstra(vector<P> g[])
{
	fill_n(D,201,INT_MAX);
	D[1] = 0;
	Q.push(P(0,1));
	while(!Q.empty())
	{
		P top = Q.top();
		Q.pop();
		int d = top.first;
		int v = top.second;
		if(d<=D[v])
		{
			for(auto &j : g[v])
			{
				int v2 = j.first;
				int cost = j.second;
				if(D[v2] > D[v] + cost)
				{
					D[v2] = D[v] + cost;
					Q.push(P(D[v2],v2));
				}
			}
		}
	}
}

int main()
{
	int n;
	cin>>n;
	vector<P> g[n+1];
	int a,b,w;
	cin>>a>>b>>w;
	while(a!=-1)
	{
		g[a].push_back(P(b,w));
		g[b].push_back(P(a,w));
		cin>>a>>b>>w;
	}
	dijkstra(g);
	for(int i=1;i<=n;i++)
		cout<<D[i]<<'\n';
	return 0;
}
