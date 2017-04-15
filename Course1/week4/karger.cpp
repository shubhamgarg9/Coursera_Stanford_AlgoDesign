#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<limits.h>
using namespace std;

int karger(vector<pair<int,int> > edges)
{
	int ans = 0;
	int count = 0;
	while(1)
	{
		if(count == 198 || count == 199)
			break;
		int flag=1,a,b;
		for(vector<pair<int,int> >::iterator it=edges.begin();it!=edges.end();it++)
		{
			if( it->first == -1 && it->second == -1 )
				continue;
			else if( flag == 1 )
			{
				flag=0;
				a = it->first;
				b = it->second;
				if( a != -1 )
					count++;
				if( b != -1 )
					count++;
			}
			if(it->first == a || it->first ==b)
				it->first = -1;
			if(it->second == a || it->second == b)
				it->second = -1;				
		}
	}
	int temp = 1,a;
	if(count == 198)
		for(vector<pair<int,int> >::iterator it=edges.begin();it!=edges.end();it++)
		{
			if(it->first == -1 && it->second == -1)
				continue;
			else if(temp==1)
			{
				temp = 0;
				if(it->first !=-1)
					a = it->first;
				else
					a = it->first;
			}
			if(it->first == a)
				it->first = -1;
			if(it->second == a)
				it->second = -1;
		}
	for(vector<pair<int,int> >::iterator it=edges.begin();it!=edges.end();it++)
		if(it->second != -1)
			ans++;
	
	return ans;
}


int main()
{
	vector<pair<int,int> >edges,copy;
	ifstream infile;
	infile.open("kargerMinCut.txt", ios::in);
	int num,i=1;
	infile>>num;
	while(i<201)
	{
		infile>>num;
		if(num==-1)
		{
			i++;
			continue;
		}
		edges.push_back(make_pair(i,num));
	}
	
//	ofstream ot;
//	ot.open("temp2.txt",ios::out);
//	for(vector<pair<int,int> >::iterator j= edges.begin(); j!=edges.end() ; j++)
//		ot<<j->first<<' '<<j->second<<endl;
	
	int lowest = INT_MAX;
	for(i=0;i<500;i++)
	{
		random_shuffle(edges.begin(),edges.end());
		int temp = karger(edges);
		if(temp<lowest)
			lowest = temp;
	}
	cout<<lowest;
	return 0;
}
