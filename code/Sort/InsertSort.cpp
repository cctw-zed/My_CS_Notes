#include <iostream>
using namespace std;

void InsertSort(int * nums, int l, int h)
{
  for(int i = l; i < h; i++)
  {
    int j = i;
    int tmp = nums[j];
    while(j > 0 && nums[j] < nums[j-1])
    {
      nums[j] = nums[j-1];
      j--;
    }
    nums[j] = tmp;
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
