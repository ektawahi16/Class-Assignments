#include<iostream>
#include<fstream>
#include<cstdlib>                               
#include<time.h>

using namespace std;
long insert;
long merges;
long quick;
int i_sort(int ar[], int n)
{int j;
	int key,insert=0;
	for(int i=1;i<n-1;i++)
	{		key=ar[i];
		for( j=i-1;j>=0 && ar[j]>=key;j--)
	       {
			ar[j+1]=ar[j];
			insert++;
	       }
	       ar[j+1]=key;
	}
return insert;
}

void merge(int *a, int low, int high, int mid)
{
	int i, j, k, temp[200];
	i = low;
	k = 0;
	j = mid + 1;

	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
			merges++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
 while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i-low];
	}
}

void m_sort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		m_sort(a, low, mid);
		m_sort(a, mid+1, high);

	
		merge(a, low, high, mid);
	}
}
void q_sort(int arr[], int left, int right) 
{
	int i = left, j = right;
	int temp,pivot;
	pivot = arr[(left + right) / 2];    
	while (i <= j) 
	{
		quick++;
		while (arr[i] < pivot)
		{
			quick;
			i++;
		}
		while (arr[j] > pivot)
		{
			quick++;
			j--;
		}
	if (i <= j) 
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
		}
	}
	if (left < j)
		q_sort(arr, left, j);
	
	if (i < right)
		q_sort(arr, i, right);

}

int main()
{	int size=20;
	long total_I = 0;
	long total_Q = 0;
	long total_M = 0;
   	long double average_I[size];									
	long double average_Q[size];									
	long double average_M[size];
	
	int arr_size;                        
 
	for(int i=0;i<size;i++)                 
	{   int j;	
	j=(i+1)*10;
		arr_size=j;
		int arr[arr_size];                   		     
		
		for(int n=0;n<30;n++)
		{   insert=0;
			 quick=0;
			 merges=0;
			srand (time(NULL));       
			for(int k=0; k<arr_size; k++)
			{ 
				 arr[k] = rand()%100;                  
			}
			insert=i_sort(arr,arr_size);
		    q_sort(arr,0,arr_size-1);
			m_sort(arr, 0, arr_size - 1);
  		    total_I+=insert;
   			total_Q+=quick;
   			total_M+=merges;
			}
	    average_I[i] = (total_I/20.00);
		average_Q[i] = (total_Q/20.00);
	    average_M[i] = (total_M/20.00);
		}
cout<<"number of comparisons for insertion sort are"<<endl;
for(int k=0;k<20;k++)
{		
cout<<average_I[k]<<endl;
}
cout<<"number of comparisons for quick sort are"<<endl;
for(int k=0;k<20;k++)
{			
cout<<average_Q[k]<<endl;
}
cout<<"number of comparisons for merge sort are"<<endl;
for(int k=0;k<20;k++)
{		
cout<<average_M[k]<<endl;
}
	ofstream obj("abc.csv"); 
	double ins,qui,mer;
	obj<<","<<"n"<<","<<"insertion"<<","<<"quick"<<","<<"merge";
	obj<<endl; 

	for(int x=0 ; x<20 ; x++ )  
	{  
	
	    ins=average_I[x];
	    qui=average_Q[x];
		mer=average_M[x];
	  		obj<<","<<((x+1)*10)<<","<<ins<<","<<qui<<","<<mer;   
	  		obj<<endl; 
	  		
		}
		
	obj.close();
	system("graphs.xlsx");	
	return 0;
}
