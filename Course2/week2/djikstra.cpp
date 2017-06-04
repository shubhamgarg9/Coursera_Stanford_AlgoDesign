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
	vector<P> g[201];
	ifstream infile; 
   	infile.open("dijkstraData2.txt");

	int a,b,w;

	while(infile >> a >> b >> w)
		g[a].push_back(P(b,w));
		
	dijkstra(g);
	cout<<D[7]<<'\n';
	cout<<D[37]<<'\n';
	cout<<D[59]<<'\n';
	cout<<D[82]<<'\n';
	cout<<D[99]<<'\n';
	cout<<D[115]<<'\n';
	cout<<D[133]<<'\n';
	cout<<D[165]<<'\n';
	cout<<D[188]<<'\n';
	cout<<D[197]<<'\n';
	return 0;
}
