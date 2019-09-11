#include <iostream>
using namespace std;

void CountingSort(int arr[], int len)
{
  //  找出最大值与最小值
  int minValue = arr[0], maxValue = arr[0];
  for(int i = 0; i < len; i++){
    minValue = min(minValue,arr[i]);
    maxValue = max(maxValue,arr[i]);
  }
  //  新建一个大小为size的数组并初始化
  int size = maxValue - minValue + 1;
  int B[size];
  for(int i = 0; i < size; i++)
    B[i] = 0;
  for(int i = 0; i < len; i++){
    B[arr[i]-minValue]++;
  }
  //  根据数组B来排序
  int idx = 0;
  for(int i = 0; i < size; i++){
    while(B[i]--){
      arr[idx++] = i+minValue;
    }
  }
}

int main()
{
  int arr[] = {10,6,7,2,5,6};
  CountingSort(arr,6);
  for(auto i : arr)
    cout << i << endl;
  return 0;
}
