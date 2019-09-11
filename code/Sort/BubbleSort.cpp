#include <iostream>
using namespace std;

void Bubblesort(int * nums, int l, int h)
{
  for(int i = h-1; i > l; i--)
  {
    bool flag = 0;
    for(int j = l; j < h-1; j++)
    {
      if(nums[j] > nums[j+1])
      {
        int tmp = nums[j];
        nums[j] = nums[j+1];
        nums[j+1] = tmp;
        flag = 1;
      }
    }
    if(flag == 0)
      break;
  }
  return;
}

int main()
{
  int nums[10] = {9,8,7,5,6,4,3,1,2,10};
  Bubblesort(nums,0,10);
  for(auto i : nums)
    cout << i << endl;
  return 0;
}
