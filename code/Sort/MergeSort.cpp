#include <iostream>
using namespace std;

//  迭代版
void MergeSort1(int nums[], int len)
{
  int * a = nums;
  int * b = new int[len];     //  动态分配内存
  for(int seg = 1; seg < len; seg += seg)
  {
    for(int start = 0; start < len; start += seg + seg)
    {
      int low = start, mid = min(start+seg, len), high = min(start+seg+seg, len);
      int k = low;
      int start1 = low, end1 = mid;
      int start2 = mid, end2 = high;
      while(start1<end1 && start2<end2)
        b[k++] = a[start1]<a[start2]?a[start1++]:a[start2++];
      while(start1<end1)
        b[k++] = a[start1++];
      while(start2<end2)
        b[k++] = a[start2++];
    }
    int * t = a;
    a = b;
    b = t;
  }
  if(a != nums){
    for(int i = 0; i < len; i++)
      b[i] = a[i];
    b = a;
  }
  delete[] b;
}

//  递归版
void MergeSortRecursive(int arr[], int reg[], int start, int end)
{
  if(start >= end)  return;
  int mid = start + (end-start)/2;
  int start1 = start, end1 = mid;
  int start2 = mid+1, end2 = end;
  int k = start;
  MergeSortRecursive(arr,reg,start1,end1);
  MergeSortRecursive(arr,reg,start2,end2);
  while(start1<=end1 && start2<=end2)
    reg[k++] = arr[start1]<arr[start2]?arr[start1++]:arr[start2++];
  while(start1 <= end1)
    reg[k++] = arr[start1++];
  while(start2 <= end2)
    reg[k++] = arr[start2++];
  for(k = start; k <= end; k++)
    arr[k] = reg[k];
}

void MergeSort2(int nums[], int len)
{
  int reg[len];
  MergeSortRecursive(nums,reg,0,len-1);
}


int main()
{
  int nums[] = {9,1,5,0,2,4,9,4,1,5};
  MergeSort2(nums,10);
  for(int i : nums)
    cout << i << endl;
  return 0;
}
