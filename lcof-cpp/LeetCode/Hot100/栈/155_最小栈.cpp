核心思想
用“两个栈”，一个存数据，一个专门存“最小值”


class MinStack{
private:
stack<int> dataStack;
stack<int> minStack;

public:
MinStack() {}
void push(int val){
  dataStack.push(val);
  if(minStack.empty() || val <= minStack.top()){
    minStack.push(val);
  }
}

void pop(){
  if(dataStack.top() == minStack.top()){
    minStack.pop();
  }
  dataStack.pop();
}

int top(){
  return dataStack.top();
}

int getMin(){
  return minStack.top();
}
};
