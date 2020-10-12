/*
*
*   set integer array t
*   fill t with 2 numbers
*   loop
*       if t consist less than 20 values then add 2 last t's values
*       else stop loop
*   print all t's value
*
*/

#include <iostream>
using namespace std;

int main () {
    int t[20], a;
    cout<<"Type in the number you want to start the Fibonacci sequence below."<<endl<<"Type in the first number: ";
    cin>>t[0];
    cout<<"Type in the second number: ";
    cin>>t[1];
    cout<<endl<<"Fibonacci Equation Sequence :"<<endl;
    for (a=2; a<=19; a++) {
        if(a==2){
            t[a]=t[0]+t[1];
            cout<<a-1<<". "<<t[0]<<" + "<<t[1]<<" = "<<t[a]<<endl;
        } else {
            t[a]=t[a-2]+t[a-1];
            cout<<a-1<<". "<<t[a-2]<<" + "<<t[a-1]<<" = "<<t[a]<<endl;
        }
    }
    cout<<endl<<"Fibonacci Sequence :"<<endl;
    for (a=2; a<=19; a++) {
        if(a==2){
            t[a]=t[0]+t[1];
            cout<<t[0]<<", "<<t[1]<<", "<<t[a]<<", ";
        } else if (a==19) {
            t[a]=t[a-2]+t[a-1];
            cout<<t[a];
        } else {
            t[a]=t[a-2]+t[a-1];
            cout<<t[a]<<", ";
        }
    }
    cout<<endl<<endl;
    system("pause");

    return 0;
}