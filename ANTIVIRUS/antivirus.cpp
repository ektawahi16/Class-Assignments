#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<regex>

using namespace std;

void infinite_loop_detection(string str)
{
regex r("while(1)+");
string words[10];
int counter = 0;
for(int i=0;i<str.length();i++){
    words[counter] += str[i];
    if(str[i] == ';'){
        counter++;
        }
}
//for(int i=0;i<10;i++)
//{ cout<<words[i]<<endl;
//}
if(words[1]==";") //there is no test condition
    cout<<"An infinite loop Virus found "<<endl;
else{
 smatch m;
 regex_search(str,m,r);
 cout<<"An infinite loop Virus found"<<endl;
}
}

void systemcall_detection(string str)
{  string words[10];
   int counter = 0;
   for(int i=0;i<str.length();i++){
    words[counter] += str[i];
    if(str[i] == '('){
        counter++;
        }
}

if(words[0]=="system(")
{
    cout<<"A file is trying to open another file,Virus detected"<<endl;
}
}
void removecall_detection(string str)
{  string words[10];
   int counter = 0;
    for(int i=0;i<str.length();i++){
    words[counter] += str[i];
    if(str[i] == '('){
        counter++;
        }
}

if(words[0]=="remove(")
{
    cout<<"A file is trying to remove another file,Virus detected"<<endl;
}
}

int main()
{ ifstream obj1("file1.txt");
  ifstream obj2("file2.txt");
  ifstream obj3("file3.txt");
  ifstream obj4("file4.txt");
  ifstream obj5("file5.txt");

     string str1;
     string str2;
     string str3;
     string str4;
     string str5;

   while(getline(obj1,str1)){ }
   while(getline(obj2,str2)){ }
   while(getline(obj3,str3)){ }
   while(getline(obj4,str4)){ }
   while(getline(obj5,str5)){ }

  infinite_loop_detection(str1);
  infinite_loop_detection(str2);
  infinite_loop_detection(str3);
  systemcall_detection(str4);
  removecall_detection(str5);


return 0;
}

