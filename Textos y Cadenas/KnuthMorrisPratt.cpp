#include <iostream>

using namespace std;

int main()
{//aabaabaaa
    string patron = "aabaabaaa";
    int n = patron.length();
    int fallo_neto[n];
    int j =0;
    
    for (int i = 0; i < n; i++)
    {
        fallo_neto[i]=0;
    }
    int i = 1;
    fallo_neto[0]=0;
    while(i<n){
    
        if(patron[j]==patron[i]){
            
            j++;
            fallo_neto[i]= j;
            i++;
        }  
        else{
            if(j!=0){
                j = fallo_neto[j-1];
            }
            else{
                fallo_neto[i]=0;
                i++;
            }
        }
    }


    for (int i = 0; i < n; i++)
    {
        cout<<patron[i];
    }
cout<<"\n fallo: \n";
    for (int i = 0; i < n; i++)
    {
        cout<<fallo_neto[i];
    }
    return 0;
}