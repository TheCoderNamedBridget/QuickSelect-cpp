
/******************************************************************************

Bridget Naylor
Date: 10/21/2020
CECS 328 Section 7
Lab 3 Quick Select 
*******************************************************************************/
#include <stdlib.h>     /* srand, rand */
#include <iostream>
using namespace std;

//returns index of the partition value
int partition( int a[], int start, int end, int size)
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
    // for ( int p = 0; p < size; p++)
    // {
    //     cout<<"frontin partition "<<a[p]<<endl;
    // }
    // cout<<"left INDEX "<<leftPivIndex<<endl;
    // cout<<"right INDEX "<<rightPivIndex<<endl;
    for ( int k = start; k < end; k ++ )
    {
        //cout<<"Herefor"<<endl;
        if ( leftPivIndex < start )
        {
            //cout<<"Hereleft"<<endl;
            //do stuff for left side
            goLeft = false;
        }
        //cout<<"rightPivIndex "<<rightPivIndex<<endl;
        //cout<<"leftPivIndex "<<leftPivIndex<<endl;
        if ( rightPivIndex > end  )
        {
            //cout<<"Hereright"<<endl;
            //do stuff for left side
            goRight = false;
        }
        if ( goLeft && goRight && a[leftPivIndex] > piv && a[rightPivIndex] < piv )//if emlent on left and right need switching switch
        {
            //cout<<"double switch"<<endl;
            int temp = a[leftPivIndex];
            a[leftPivIndex] = a[rightPivIndex];
            a[rightPivIndex] = temp;
        }
        else if ( goRight && (a[rightPivIndex] < piv) )//only switch right
        {
            cout<<"right switch"<<endl;
            cout<<"piv index "<<midIndex<<" piv value "<<piv<<endl;
            cout<<"element index "<<midIndex + 1<<" element value "<<a[midIndex + 1]<<endl;
            //switches element to right of piv with other right element < piv
            int pivPlusOne = a[midIndex + 1];
            a[midIndex + 1] = a[rightPivIndex];
            a[rightPivIndex] = pivPlusOne;
            
            //switches piv and element to the right of piv
            int pivValue = a[midIndex];
            a[midIndex] = a[midIndex + 1];
            a[midIndex + 1] = pivValue;
            
            midIndex++;
            
        }
        else if ( goLeft && (a[leftPivIndex] > piv) )//only switch left
        {
            //cout<<"left switch"<<endl;
            //switches element to left of piv with other left element <> piv
            int pivMinusOne = a[midIndex - 1];
            a[midIndex - 1] = a[leftPivIndex];
            a[leftPivIndex] = pivMinusOne;
            
            //switches piv and element to the right of piv
            int pivValue = a[midIndex];
            a[midIndex] = a[midIndex - 1];
            a[midIndex - 1] = pivValue;
            
            midIndex--;
        }
        cout<<"11piv index "<<midIndex<<" piv value "<<piv<<endl;
        cout<<"11element index "<<midIndex + 1<<" element value "<<a[midIndex + 1]<<endl;
        cout<<"goRight"<<goRight<<endl;
        cout<<"(a[rightPivIndex] < piv) "<<(a[rightPivIndex] < piv)<<endl;
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    for ( int i = start; i < end + 1; i++)
    {
        cout<<"in partition "<<a[i]<<endl;
    }
    return midIndex;
}

//TESTING for QuickSelect
//base case k = pivIndex + 1
//k > pivIndex + 1
//int a[] = { 1, 2, 5, 6, 7, 8, 1};
//cout<<"QuickSelect: "<<quickSelect( a, 0, size - 1, k, size );
//k < pivIndex + 1
//int a[] = { 10, 2, 5, 6, 7, 8, 1};
//cout<<"QuickSelect: "<<quickSelect( a, 0, size - 1, k, size );
int quickSelect( int a[], int s, int e, int k, int size )
{
    int n = e + 1;//size
    int pivIndex = partition( a, s, e, size );
    cout<<"Partition piv index = "<<pivIndex<<" Value = "<<a[pivIndex]<<endl;
    cout<<"s "<<s<<" e "<<e<<endl;
    if ( k == pivIndex + 1 )
    {
        return a[pivIndex];
    }
    else if ( k > pivIndex + 1 )//k is to right of piv index
    {
        quickSelect( a, pivIndex + 1, e, k, size );
    }
    else if ( k < pivIndex + 1 )//k is to left of piv index
    {
        quickSelect( a, s, pivIndex - 1, k, size );
    }
    
    return -666;
}


int main()
{
    int size = 0;
    int k = 0;
    while ( size < 1)
    {
        cout<<"Enter a positive non zero integer: ";
        cin >> size;
    }
    
    int a[size];
    
    while ( k < 1 || k > size )
    {
        cout<<"Enter a number between 1 and "<<size<<" ";
        cin>>k;
    }
    
    srand (time(NULL));
    for ( int i = 0; i < size; i++ )
    {
        int posOrNeg = rand() % 2 + 1;
        int posNum = rand() % 101;//0 - 100
        int negNum = rand() % 101 -100;//-100 - -1
        //cout<<"posOrNeg "<<posOrNeg<<endl;
        //cout<<"posNum "<<posNum<<endl;
        //cout<<"negNum "<<negNum<<endl;
        if ( posOrNeg == 2 )//posOrNeg = 2 +> do pos
        {
            a[i] = posNum;
        }
        else//do neg
        {
            a[i] = negNum;
        }
    }
    for ( int j = 0; j < size; j++)
    {
        cout<<"a[j] in main "<<a[j]<<endl;
    }

    partition( a, 0, 10 - 1, 10 );
    // cout<<"QuickSelect: "<<quickSelect( a, 0, size - 1, k, size );
   
    return 0;
}


//TESTING for partition
//size == 0, 1, 2, 3
//size is even
//size is odd

//all elements same
//int a[size] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 };
    
//testing left switch
//int a[size] = { 5, 11, 10, 6, 7, 9, 6, 8, 77, 33 };
    
//testing right switch
//int a[size] = { 5, 1, 1, 2, 2, 3, 2, 1, 1, 0};
    
//testing double swap;





//int a[size] = { 5, 10, 89, 6, 9, 3, 1, 0, 3, 2};
