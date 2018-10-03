    /*
      An Optimized program to find if a given number(n) is prime or not.
      Time Complexity of the code comes out to be square_root(n).
    */

#include<iostream>
#include<stdio.h>

using namespace std;

bool is_prime(int n){
    /*
       Objective- To check if a given number number is prime or not.
       Input- A number n which is to be checked.
       Output- true,if the number is prime.
               false,if the number is not prime.

    */

    /*

      Approach-If a number is indivisible by i,it will also be indivisible by (i*i).
               Using this to optimize the time complexity from O(n) to O(square_root(n)).

    */
  if(n<2) return false;
  else if(n==2||n==3) return true;
  else if(n%2==0) return false;
  else{
     for(int i=3;i*i<n;i=i+2)
    {
        if(n%i==0) return false;
    }
      }return true;

}


int main()
   {
       int n;
       cout<<"Enter the number to be checked";
       cin>>n;
       int c=is_prime(n);
       if(c==1)                                           //is_prime(n) returns true.
          cout<<n<<" "<<"is a prime number";
       else                                              //is_prime(n) returns false.
          cout<<n<<" "<<"is not a prime number";

     return 0;
   }
