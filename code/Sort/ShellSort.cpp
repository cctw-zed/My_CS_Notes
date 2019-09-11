#include <iostream>
using namespace std;

void ShellSort(int nums[], int len)
{
  int h = 1;
  while(h < len / 3)
    h = 3 * h + 1;
  while(h >= 1)       //  插入排序
  {
    for(int i = h; i < len; i++)
    {
      for(int j = i; j >= h && arr[j] < arr[j-h]; j -= h)
      {
        swap(arr[j],arr[j-h]);
      }
    }
    h = h / 3;
  }
}
