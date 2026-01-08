class Solution{
public:
bool searchMatrix(vector<vector<int>>& matrix,int target){
  //边界检查
  if(matrix.empty() || matrix[0].empty())   return false;

  int m = matrix.size();//行数
  int n = matrix[0].size();//列数

  int left = 0;
  int right = m * n - 1;

  //二分查找
  while(left <= right){
    int mid = left + (right - left) / 2;
    //一维坐标转二维坐标
    int row = mid / n;
    int col = mid % n;

    int value = matrix[row][col];

    if(value == target){
      return true;
    }else if(value < target){
      left = mid + 1;
    }else {
      right = mid - 1;
    }
  }
  return false;
}
};
