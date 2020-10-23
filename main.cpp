/******************************************************************************

Bridget Naylor
Date: 10/21/2020
CECS 328 Section 7
Lab 3 Quick Select 
*******************************************************************************/
#include <stdio.h>
#include <iostream>
using namespace std;



#include <iostream>
using namespace std;

void partition( int a[], int size)
{
    int pivIndex = 0;
    int midIndex = (size - 1)/2;

    bool goLeft = true;
    bool goRight = true;
    
    int piv = a[pivIndex];
    a[0] = a[midIndex];
    a[midIndex] = piv;
    int leftPivIndex = midIndex - 1;
    int rightPivIndex = midIndex + 1;
    for ( int p = 0; p < size; p++)
    {
        cout<<"frontin partition "<<a[p]<<endl;
    }
    cout<<"left INDEX "<<leftPivIndex<<endl;
    cout<<"left INDEX "<<rightPivIndex<<endl;
    for ( int k = 0; k < size; k ++ )
    {
        //cout<<"Herefor"<<endl;
        if ( leftPivIndex < 0 )
        {
            cout<<"Hereleft"<<endl;
            //do stuff for left side
            goLeft = false;
        }
        cout<<"rightPivIndex "<<rightPivIndex<<endl;
        cout<<"leftPivIndex "<<leftPivIndex<<endl;
        if ( rightPivIndex > size - 1 )
        {
            cout<<"Hereright"<<endl;
            //do stuff for left side
            goRight = false;
        }
        // cout<<"go left "<<goLeft<<endl;
        // cout<<"go right "<<goRight<<endl;
        // cout<<"a[leftPivIndex] > piv "<<(a[leftPivIndex] > piv)<<endl;
        // cout<<"a[leftPivIndex] "<<a[leftPivIndex]<<" piv "<<piv<<endl;
        // cout<<"a[rightPivIndex] < piv "<<(a[rightPivIndex] < piv)<<endl;
        // cout<<"a[rightPivIndex] "<<a[rightPivIndex]<<" piv "<<piv<<endl;
        // cout<<" WHATS WRONG "<< ( goLeft && goRight && a[leftPivIndex] > piv && a[rightPivIndex] < piv )<<endl;
        if ( goLeft && goRight && a[leftPivIndex] > piv && a[rightPivIndex] < piv )//if emlent on left and right need switching switch
        {
            cout<<"double switch"<<endl;
            int temp = a[leftPivIndex];
            a[leftPivIndex] = a[rightPivIndex];
            a[rightPivIndex] = temp;
        }
        else if ( !goLeft && goRight && (a[rightPivIndex] < piv) )//only switch right
        {
            cout<<"right switch"<<endl;
            //switches
            int pivPlusOne = a[midIndex + 1];
            a[midIndex + 1] = a[rightPivIndex];
            a[rightPivIndex] = pivPlusOne;
            
        }
        cout<<"!goLeft && goRight "<<(!goLeft && goRight)<<endl;
        cout<<"!goLeft "<<(!goLeft)<<endl;
        cout<<"goRight "<<(goRight)<<endl;
        cout<<"(a[rightPivIndex] ) "<<(a[rightPivIndex])<<" piv "<<piv<<endl;
        cout<<"(a[rightPivIndex] < piv) "<<(a[rightPivIndex] < piv)<<endl;
        // else if ( goleft && !goRight )//only switch left
        // {
            
        // }
        
        leftPivIndex --;
        rightPivIndex ++;
        //a[k] = 5;
        
        //else if only one element needs switching switch element with piv
        //if element not immediately next to piv needs switching, switch element with element next to piv then switch piv and that element
        //if left index or right index are out of bounds stop going left or right 
    //     if ( a[k] < piv )//go left
    //     {
            
    //     }
    //     if ( a[k] > piv )//go right
    //     {
            
    //     }
    //     if ( a[k] == piv )//go to left or right one space
    //     {
            
    //     }
    }

    
    for ( int i = 0; i < size; i++)
    {
        cout<<"in partition "<<a[i]<<endl;
    }
    
}


int main()
{
    int size = 10;
    int a[size] = { 5, 10, 89, 6, 9, 3, 1, 0, 3, 2};
    //9, 10, 7, 3, 5, 6, 89, 10, 3, 2
    // int itr = 0;
    // for ( int j = size - 1; j > -1 ; j-- )
    // {
    //     a[itr] = j;
    //     cout<<"in main "<<a[j]<<endl;
    //     itr ++;
    // }
    partition( a, size );
   
    return 0;
}
