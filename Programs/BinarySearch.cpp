#include <bits/stdc++.h>
using namespace std;

//Recursive Implementation

template<class T>
int binSrch(T container[], T x, int lb, int ub){
  if (ub >= 1)
  {
    int midpoint = lb + (ub - 1) / 2;

    if(container[midpoint] == x)
    {
      return midpoint;
    }

    if(container[midpoint] > x)
    {
      binSrch(container, x, lb, midpoint-1);
    }else{
      binSrch(container, x, midpoint+1, ub);
    }
  }
  return -1;
}


int main()
{
  int arr[1];
  int x = 1;
  binSrch(arr, x, 0, sizeof(arr)-1);
  return 0;
}