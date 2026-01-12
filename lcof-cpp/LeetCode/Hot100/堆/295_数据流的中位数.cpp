#include <bits/stdc++.h>
using namespace std;

class MedianFinder{
private:
//大根堆，存较小的一半
priority_queue<int> maxHeap;
//小根堆，存较大的一半
priority_queue<int,vector<int>,greater<int>> minHeap;

public:
MedianFinder(){}

void addNum(int num){
  //1.放入合适的堆
  if(maxHeap.empty() || num <= maxHeap.top()){
    maxHeap.push(num);
  } else {
    minHeap.push(num);
  }

  //2.平衡两个堆
  if(maxHeap.size() > minHeap.size() + 1){
    minHeap.push(maxHeap.top());
    maxHeap.pop();
  } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
}

double findMedian(){
  if(maxHeap.size() > minHeap.size()){
    return maxHeap.top();
  }
  return (maxHeap.top() + minHeap.top()) / 2.0;
}
};
