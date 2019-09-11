#include <iostream>
using namespace std;

void InsertSort(int * nums, int l, int h)
{
  for(int i = l+1; i < h; i++)
  {
    for(int j = i; j > l && nums[j]<nums[j-1]; j-- )
    {
      swap(nums[j],nums[j-1]);
    }
  }
  return;
}

int main()
{
  int nums[10] = {10,8,6,9,7,5,2,3,4,1};
  InsertSort(nums,0,10);
  for(auto i : nums)
    cout << i << endl;
  return 0;
}
