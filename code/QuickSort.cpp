#include <iostream>
using namespace std;


//  递归
void QuickSort(int nums[], int l, int r)
{
  if(l >= r)  return;
  int tmp = nums[l];
  int low = l, high = r;
  while(low<high)
  {
    while(low < high && nums[high] > tmp) high--;
    nums[low] = nums[high];
    if(low < high)  low++;
    while(low < high && nums[low] <= tmp)  low++;
    nums[high] = nums[low];
    if(low < high)  high--;
  }
  nums[low] = tmp;
  QuickSort(nums,l,low-1);
  QuickSort(nums,low+1,r);
}


//  迭代
struct Range{
  int start, end;
  Range(int s = 0, int e = 0):start(s),end(e){};
};
void QuickSort1(int nums[], int len)
{
  if(len <= 0)  return;
  Range r[len];
  int p = 0;
  r[p++] = Range(0, len-1); //  模拟堆栈
  while(p)
  {
    Range range = r[--p];
    if(range.start >= range.end)  continue; //  表示该部分已经排序好
    int mid = nums[range.end];
    int low = range.start, high = range.end;
    while(low < high)
    {
      while(low<high && nums[low] < mid)  low++;
      nums[high] = nums[low];
      if(low<high)  high--;
      while(low<high && nums[high] >= mid)  high--;
      nums[low] = nums[high];
      if(low<high)  low++;
    }
    nums[low] = mid;
    r[p++] = Range(range.start,low-1);
    r[p++] = Range(low+1,range.end);
  }
}



int main()
{
  int nums[] = {10,5,7,4,2,1,4,8};
  QuickSort1(nums,8);
  for(int i : nums)
    cout << i << endl;
  return 0;
}
