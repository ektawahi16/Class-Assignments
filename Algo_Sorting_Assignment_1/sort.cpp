#include<iostream>
#include<fstream>   //for writing values to csv file
#include<cstdlib>   //for random value generation
#include<time.h>

using namespace std;

/*long i_sort(int*,int)
 Objective-to sort the values using insertion sort algorithm
 Input-an unsorted array and it's size
 Output-a sorted array and number of comparisons done in sorting
  */
long i_sort(int ar[], int n)
{   int j;
	int key,inserts=0;
	for(int i=1;i<n-1;i++)
	{		key=ar[i];
		for( j=i-1;j>=0 && ar[j]>=key;j--)
	       {
			ar[j+1]=ar[j];
			inserts++;
	       }
	       ar[j+1]=key;
	}
return inserts;   //number of comparisons returned
}

/* void(int *,int,int,long &)
 Objective-merge the segmented components formed by m_sort to form a sorted array
 Input-segmented array,indices of the array,number of comparisons for merge sort
 Output-sorted array and number of comparisons done in sorting
 */
void merge(int *a, int low, int high, int mid,long &merges)
{
	int i, j, k, temp[1000];
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

/* void m_sort(int *,int,int,long&)
 Objective-recursively segment the array
 Input-an unsorted array,it's indices and number of comparisons
 Output-a segmented array of numbers
 */
void m_sort(int *a, int low, int high,long &merges)
{
	int mid;
	if (low < high)
	{
		mid=(low+high)/2;
		m_sort(a, low, mid,merges);
		m_sort(a, mid+1, high,merges);


		merge(a, low, high,mid,merges);
	}
}

/* void m_sort(int *,int,int,long&)
 Objective-recursively sort the array to merge it using quick sort algorithm
 Input-an unsorted array,it's indices and number of comparisons
 Output-a sorted array of numbers,number of comparisons done
 */
void q_sort(int arr[], int left, int right,long &quick)
{
	int i = left, j = right;
	int temp,pivot;
	pivot = arr[(left + right) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
		{
			quick++;
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
    {
		q_sort(arr, left, j,quick);
    }

	if (i < right)
		{
		    q_sort(arr, i, right,quick);
		}
}


/*void print_averages(double*,double*,double*)
Objective:to print the three arrays containing the averages of the number of comparisons
Input:average_I[],average_M[],average_Q[]
Output:all the three arrays on screen
*/
void print_averages(double average_I[],double average_M[],double average_Q[])
{   cout<<"number of comparisons for merge sort are"<<endl;
    for(int k=0;k<100;k++)
    {
        cout<<average_M[k]<<endl;
    }

    cout<<"number of comparisons for quick sort are"<<endl;
    for(int k=0;k<100;k++)
  {
        cout<<average_Q[k]<<endl;
    }


    cout<<"number of comparisons for insertion sort are"<<endl;
    for(int k=0;k<100;k++)
    {
        cout<<average_I[k]<<endl;
    }
}

int main()
{
    long inserts;      //number of comparisons for insertion sort
    long merges;       //number of comparisons for merge sort
    long quick;        //number of comparisons for quick sort
    int size=100;      //size for the arrays to store averages of all comparisons
	double total_I = 0.0;  //total no. of comparisons for insertion sort
	double total_Q = 0.0;  //total no. of comparisons for quick sort
	double total_M = 0.0;  //total no. of comparisons for merge sort
    double average_I[size];   //array to store averages of number of comparisons for insertion sort
    double average_Q[size];   //array to store averages of number of comparisons for quick sort
    double average_M[size];   //array to store averages of number of comparisons for merge sort

	int arr_size;
    ofstream obj("abc.csv");   //to store values of the returned averages
     obj<<","<<"n"<<","<<"insertion"<<","<<"quick"<<","<<"merge";  //writing values into the csv file
	  obj<<endl;

	for(int i=0;i<size;i++)
	{   int j;
	j=(i+1)*10;
		arr_size=j;
		int ar1[arr_size],ar2[arr_size],ar3[arr_size];
		total_I=0;
		total_M=0;
		total_Q=0;
		for(int n=0;n<30;n++)   //computing the number of comparisons for 20 iterations and then taking their average
		{    inserts=0;          //initializing number of comparisons to zero for each size
			 quick=0;
			 merges=0;
			srand((int)time(0));
			for(int k=0; k<arr_size; k++)
			{
				 ar1[k]=ar2[k]=ar3[k] =(rand()%1000)+1;  //creating a random array with numbers in the range of 1-1000
			}
			inserts=i_sort(ar1,arr_size);
		    q_sort(ar2,0,arr_size-1,quick);
			m_sort(ar3, 0, arr_size - 1,merges);
  		    total_I+=inserts;
   			total_Q+=quick;
   			total_M+=merges;
			}
        //cout<<total_M<<"\t"<<((total_M)/20.0)<<"\n";
	    average_I[i] = ((total_I)/20.0);
		average_Q[i] = ((total_Q)/20.0);
	    average_M[i] = ((total_M)/20.0);

	  		obj<<","<<((i+1)*10)<<","<<average_I[i]<<","<<average_Q[i]<<","<<average_M[i]<<endl;
		}
    //print_averages(average_I,average_M,average_Q);
    obj.close();

    system("graphs.xlsx");   //system call to open the excel file containing the graph
   return 0;
}
