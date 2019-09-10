#include <iostream>
using namespace std;

void SelectSort(int * nums, int l, int h)
{
  int minidx;
  for(int i = l; i < h-1; i++)
  {
    minidx = i;
    for(int j = i; j < h; j++)
      minidx = nums[j]<nums[minidx]?j:minidx;
    int tmp = nums[i];
    nums[i] = nums[minidx];
    nums[minidx] = tmp;
  }
  return;
}


int main()
{
  int nums[10] = {10,9,8,6,7,5,2,3,4,1};
  SelectSort(nums,0,10);
  for(auto i : nums)
    cout << i << endl;
  return 0;
}
