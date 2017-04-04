#include<iostream>
#include<fstream>
using namespace std;

long long count = 0;

void merge(int *ar,int low,int mid,int high)
{
	int i=low, j=mid+1, k=0;
	int *temp = new int[high-low+1];
	while(i<=mid && j<=high)
	{
		if(ar[i]<=ar[j])
			temp[k++] = ar[i++];
		else
		{
			temp[k++] = ar[j++];
			count += mid - i + 1;
		}
	}
	
	while(i<=mid)
		temp[k++] = ar[i++];
	
	while(j<=high)
		temp[k++] = ar[j++];
	
	for(i=low,j=0;j<k;i++,j++)
		ar[i] = temp[j];
}

void invCount(int *ar,int low,int high)
{
	if(low<high)
	{
		int mid = (low+high)/2;
		invCount(ar,low,mid);
		invCount(ar,mid+1,high);
		merge(ar,low,mid,high);
	}
}

int main()
{
	ifstream infile; 
   	infile.open("integerArray.txt");
   	int i=0;
   	int size;
   	infile>>size;
   	int *ar = new int[size];
	while(infile >> ar[i++])
	{}
	invCount(ar,0,size-1);
	cout<<count;
	return 0;
}
