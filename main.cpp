/******************************************************************************

Bridget Naylor
Date: 10/21/2020
CECS 328 Section 7
Lab 3 Quick Select 
*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter a pos num: ";
    cin>>n;
    if ( k < n )
    {
        cout<<"Bad number selected"<<endl;
    }
    int a[n];
    //generate random numbers between -100 to 100 and save to an array a
    
    int k;
    cout<<"Enter a num between 1 and "<<n;
    cin>>k;
    if ( k < 1 || k > n )
    {
        cout<<"Bad number selected"<<endl;
    }
    //call quickselect and print the kth least element

    return 0;
}
