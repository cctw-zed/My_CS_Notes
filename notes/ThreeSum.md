# ThreeSum
统计一个数组中和为0的三元组数量

##  1.  暴力法
```c++
class Solution{
public:
  int ThreeSum(vector<int> nums)
  {
    int len = nums.size();
    int cnt = 0;
    for ( int i = 0; i < len; i++ ){
      for ( int j = i+1; j < len; j++ ){
        for ( int k = j+1; k < len; k++ ){
          if ( nums[i] + nums[j] + nums[k] == 0 )
            cnt++;
        }
      }
    }
    return cnt;
  }
}
```
时间复杂度: O(n^3)

##  2.  二分查找法
```c++
class Solution{
public:
  int ThreeSum(vector<int> nums)
  {
    int cnt = 0;
    int len = nums.size();
    vector<int>::iterator it = nums.begin();
    sort(it,it+len);  //  先进行排序，然后先选两个数进行相加，二分查找第三个
    for ( int i = 0; i < len; i++ ){
      for ( int j = i+1; j < len; j++ ){
        int sum = -nums[i] - nums[j];
        int idx = binarySearch(nums,sum);
        if ( idx > j )
          cnt++;
      }
    }
    return cnt;
  }

private:
  int binarySearch(vector<int> nums, int target)
  {
    int len = nums.size();
    int l = 0, h = nums.size()-1;
    while(l < h){
      int m = l + ( h - l ) / 2;
      if ( target == nums[m] )  return m;
      else if ( target > nums[m] )
        l = m + 1;
      else
        h = m - 1;
    }
  }
}

```
时间复杂度: O(N^2logN)


##  3.  双指针法
```c++
//  遍历一遍数组，每趟均采用双指针法寻找
class Solution{
public:
  int ThreSum(vector<int> nums)
  {
    int cnt = 0;
    int len = nums.size();
    for ( int i = 0; i < len; i++ ){
      int l = i + 1, h = len - 1;
      while(l < h){
        int sum = nums[i] + nums[l] + nums[h];
        if ( sum == 0 ){
          cnt++;
          l++;
          h--;
        }else if ( sum > 0 )  h--;
        else  l++;
    }
    return cnt;
  }
}
```
时间复杂度: O(N^2)

