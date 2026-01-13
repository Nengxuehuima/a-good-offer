#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
vector<vector<int>> generate(int numRows){
  vector<vector<int>> triangle;

  //如果行数为0，直接返回空结果
  if(numRows == 0) return triangle;

  //逐行生成杨辉三角
  for(int i = 0;i < numRows;i++)
    {
      //当前行一共有i+1个元素
      vector<int> row(i+1,1);//默认全部初始化为1
      //填充中间元素
      for(int j = 1;j < i;j++){
        row[j] = triangle[i -1][j -1] + triangle[i - 1][j];
      }
      //将当前行加入结果
      triangle.push_back(row);
    }
  return triangle;
}
};
