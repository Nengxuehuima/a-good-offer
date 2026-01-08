#inlcude <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution{
double findMedianSortedArrays(vector<int>& A,vector<int>& B){
  if(A.size() > B.size()) return findMedianSortedArrays(B,A);

  int m = A.size(),n = B.size();
  int left = 0,right = m;

  while(left <= right){
    int i = (left + right) / 2;
    int j = (m + n + 1) / 2 - i;

    int Aleft = (i == 0) ? INT_MIN : A[i - 1];
    int Aright = (i == m) ? INT_MAX : A[i];

    int Bleft = (j == 0) ? INT_MIN : B[j - 1];
    int Bright = (j == n) ? INT_MAX : B[j];

    if(Aleft <= Bright && Bleft <= Aright){
      if((m + n) % 2 == 1)
        return max(Aleft,Bleft);
      else
        return (max(Aleft,Bleft) + min(Aright,Bright)) / 2.0;
    }
    else if(Aleft > Bright)
      right = i - 1;
    else
      left = i + 1;
  }
  return 0.0;
}
};
