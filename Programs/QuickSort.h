#include <bits/stdc++.h>
using namespace std;

void swapValues(int& x, int& y)
{
  int temp = x;
  x = y;
  y = temp;
}

int partition(int arr[], const int& l, const int& h)
{
  int pivot = arr[h];
  int i = l-1;

  for(int j = l; j <= h-1; j++)
  {
    if (arr[j] < pivot)
    {
      i++;
      swapValues(arr[i], arr[j]);
    }
  }
  swapValues(arr[i+1], arr[h]);
  return (i+1);
}

int qSort(int arr[], const int& lb, const int& ub)
{
  if(lb < ub)
  {
    int pI = partition(arr, lb, ub);

    //Left side partition
    qSort(arr, lb, pI-1);

    //Right side partition
    qSort(arr, pI+1, ub);
  }
}