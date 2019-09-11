#include <iostream>
#include <algorithm>
using namespace std;

void max_heapify(int arr[], int start, int end)
{
  int dad = start;
  int son = start * 2 + 1;    //  下标从0开始
  while(son <= end)           //  子节点指标在范围内才作比较
  {
    if(son+1<=end && arr[son] < arr[son+1]) son++;      //  选择较大的子节点
    if(arr[dad] > arr[son]) return;                     //  如果父节点大于子节点说明调整完毕
    else
    {
      swap(arr[dad],arr[son]);
      dad = son;
      son = dad * 2 + 1;
    }
  }
}

void HeapSort(int arr[], int len)
{
  //  初始化，i从最后一个父节点开始
  for(int i = len / 2 - 1; i >= 0; i--)
    max_heapify(arr,i,len-1);
  //  将堆顶元素与当前最后一个元素交换，再调整堆
  for(int i = len - 1; i > 0; i--)
  {
    swap(arr[0],arr[i]);
    max_heapify(arr,0,i-1);
  }
}
