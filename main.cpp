
/******************************************************************************

Bridget Naylor
Date: 10/21/2020
CECS 328 Section 7
Lab 3 Quick Select 
*******************************************************************************/
#include <stdlib.h>     /* srand, rand */
#include <iostream>
using namespace std;
//Part A
//returns index of the partition value
int partition( int a[], int start, int end)
{
    cout<<"start "<<start<<" end "<<end<<endl;
    if ( start == end )
    {
        return start;
    }
    
    //cout<<"parts "<<start<<" e "<<end<<endl;
    int pivIndex = start;
    int midIndex = start + (end - start)/2;

    bool goLeft = true;
    bool goRight = true;
    
    int piv = a[pivIndex];
    a[start] = a[midIndex];
    a[midIndex] = piv;
    int leftPivIndex = midIndex - 1;
    int rightPivIndex = midIndex + 1;
    for ( int k = start; k < end; k ++ )
    {
        //cout<<"Herefor"<<endl;
        if ( leftPivIndex < start )
        {
            //cout<<"Hereleft"<<endl;
            //do stuff for left side
            goLeft = false;
        }
        if ( rightPivIndex > end )
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
        // cout<<"11piv index "<<midIndex<<" piv value "<<piv<<endl;
        // cout<<"11element index "<<midIndex + 1<<" element value "<<a[midIndex + 1]<<endl;
        // cout<<"goRight "<<goRight<<endl;
        // cout<<"(a[rightPivIndex] < piv) "<<(a[rightPivIndex] < piv)<<endl;
        leftPivIndex --;
        rightPivIndex ++;
    }
    
    // for ( int i = 0; i < size; i++)
    // {
    //     cout<<"in partition "<<a[i]<<endl;
    // }
    
    return midIndex;
}

int quickSelect( int a[], int s, int e, int k)
{
    int n = e + 1;//size
    int pivIndex = partition( a, s, e );
    // cout<<"Partition piv index = "<<pivIndex<<" Value = "<<a[pivIndex]<<endl;
    // cout<<"s "<<s<<" e "<<e<<endl;
    // cout<<"s == e "<<(s == e)<<endl;
    // cout<<"k "<<k<<" pivot index "<< (pivIndex + 1)<<endl;
    if ( k - 1 == pivIndex -s)
    {
        //cout<<"basecase "<<endl;
        return a[pivIndex];
    }
    else if ( pivIndex - s > k - 1 )//k is to right of piv index
    {
        
        //cout<<"rightcase "<<endl;
        return quickSelect( a, s, pivIndex - 1, k );
    }
    //cout<<"leftcase "<<endl;
    return quickSelect( a, pivIndex + 1, e, k - pivIndex + s - 1 );
    
    
}

//Part B
int quickSelectIndexReturn( int a[], int s, int e, int k)
{
    int n = e + 1;//size
    int pivIndex = partition( a, s, e );
    // cout<<"Partition piv index = "<<pivIndex<<" Value = "<<a[pivIndex]<<endl;
    // cout<<"s "<<s<<" e "<<e<<endl;
    // cout<<"s == e "<<(s == e)<<endl;
    // cout<<"k "<<k<<" pivot index "<< (pivIndex + 1)<<endl;
    if ( k - 1 == pivIndex -s)
    {
        cout<<"basecase "<<endl;
        cout<<"pivIndex"<<pivIndex<<endl;
        return pivIndex;
    }
    else if ( pivIndex - s > k - 1 )//k is to right of piv index
    {
        
        //cout<<"rightcase "<<endl;
        return quickSelectIndexReturn( a, s, pivIndex - 1, k );
    }
    //cout<<"leftcase "<<endl;
    return quickSelectIndexReturn( a, pivIndex + 1, e, k - pivIndex + s - 1 );
    
    
}

void maxNums( int a[], int numLarge, int size )
{
    
    int index = size - numLarge;
    int pivIndex = quickSelectIndexReturn( a, 0, size - 1, index );
    cout<<"pivIndex"<<pivIndex<<" Largest Numbers: "<<endl;
    for ( int i = pivIndex + 1; i < size; i ++ )
    {
        cout<<"In "<<a[i]<<endl;
    }
}



int main()
{
    //PART A
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
    
    //cout<<"QuickSelect: "<<quickSelect( a, 0, size - 1, k)<<endl;
    
    //Part B
    int numLarge = 0;
    while ( numLarge < 1 )
    {
        cout<<"Enter desired number of largest elements: ";
        cin>>numLarge;
    }
    maxNums( a, numLarge, size );
    return 0;
}

//TESTING for QuickSelect
//base case k = pivIndex + 1
//k > pivIndex + 1
//int a[] = { 1, 2, 5, 6, 7, 8, 1};
//cout<<"QuickSelect: "<<quickSelect( a, 0, size - 1, k, size );
//k < pivIndex + 1
//int a[] = { 10, 2, 5, 6, 7, 8, 1};
//cout<<"QuickSelect: "<<quickSelect( a, 0, size - 1, k, size );

//TESTING for partition
//partition( a, 0, size - 1 );
    
//partition( a, 2, size - 5 );
//partition( a, 1, size - 2 );
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

