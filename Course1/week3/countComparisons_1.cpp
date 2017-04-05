#include<iostream>
#include<fstream>
using namespace std;

long long count = 0;

int pivot(int *ar,int low,int high)
{
	return low;
}

int partitioning(int *ar,int low,int high,int pivotPos)
{
	int temp = ar[pivotPos];
	ar[pivotPos] = ar[low];
	ar[low] = temp;
	
	int i=low+1,j=i;
	
	while(j<=high)
	{
		if(ar[j]<=ar[low])
		{
			int temp = ar[j];
			ar[j] = ar[i];
			ar[i] = temp;
			i++;
		}
		j++;
	}
	i--;
	temp = ar[low];
	ar[low] = ar[i];
	ar[i] = temp;
	return i;
}

void quickSortComparisonCount(int *ar,int low,int high)
{
	if(low<high)
	{
		int pivotPos = pivot(ar,low,high);
		pivotPos = partitioning(ar,low,high,pivotPos);
		quickSortComparisonCount(ar,low,pivotPos-1);
		count += pivotPos - low;
		quickSortComparisonCount(ar,pivotPos+1,high);
		count += high - pivotPos;
	}
}

int main()
{
	ifstream infile; 
   	infile.open("quicksort.txt");
   	int i=0;
   	int size;
   	infile>>size;
   	int *ar = new int[size];
	while(infile >> ar[i++])
	{}
//	cin>>size;
//	int *ar = new int[size];
//	for(int i=0;i<size;i++)
//		cin>>ar[i];

	quickSortComparisonCount(ar,0,size-1);
//	for(int i=0;i<size;i++)
//		cout<<ar[i]<<' ';
	cout<<count;
	return 0;
}
