#include<iostream>
#include<cstdlib>                 //for rand function
#include<time.h>
#include<math.h>                 //for sqrt() and pow() functions

using namespace std;


int initial_x,initial_y;         //initial coordinates of the Bee
int current_x,current_y;         //current Coordinates of the Bee
int final_x,final_y;             //final coordinates of the Bee
int direction;                   //the direction from (1-6)
int n=1000;                     //number of iterations
double sum=0;                   //to store the sum of displacements
double displacement[1000];      //displacement array
double expectation;
double deviation;
double Standard_deviation;
int main()
{ srand (time(NULL));
initial_x=rand()%100+1;       //random coordinates from 1 to 100;
initial_y=rand()%100+1;
\
int total_steps;
cout<<"Enter number of steps Bee can move";
cin>>total_steps;
       for(int i=0;i<n;i++)
    {      current_x=initial_x;
       current_y=initial_y;

    for(int x=0;x<total_steps;x++)
    {
    	direction=(rand()%6)+1;  //random directions from 1 to 6
    	if (direction==1)
		     current_y+=1;       // move north
	    else if(direction==2)
	    {
		    current_x+=(sqrt(3))*0.5;   //move north east
		    current_y+=0.5;
		}
	    else if(direction==3)
		{
		   current_x+=(sqrt(3))*0.5;    // move south east
		   current_y-=0.5;
	    }
	    else if(direction==4)
		{
		   current_y-=1;                //move south
		}

	    else if(direction==5)
		{
		   current_x-=(sqrt(3))*0.5;    //move south west
		   current_y-=0.5;
	    }
	else if(direction==6)
	    {
	     	current_x-=(sqrt(3))*0.5;     //move north west
		    current_y+=0.5;
	}
	}
          final_x=current_x;
          final_y=current_y;

               displacement[i]=sqrt(pow((initial_x-final_x),2)+pow((initial_y-final_y),2));  //shortest distance from final coordinates
               sum+=displacement[i];

     }
               expectation=sum/1000;     //expectation=sum of values/number of values
    for(int i = 0; i < 1000; i++)
      {
          deviation += pow(displacement[i] - expectation, 2);
      }


    Standard_deviation=sqrt(deviation/1000);
    cout<<"The Expectation for total steps= "<<total_steps<<" is "<<expectation<<endl;
    cout<<endl;
    cout<<"The Standard Deviation for total steps= "<<total_steps<<" is "<<Standard_deviation;
    return 0;
}
