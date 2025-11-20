责任链设计模式（Chain of Responsibility Design Pattern）是一种行为型设计模式，用于将请求的发送者和接收者解耦，
并使多个对象都有机会处理该请求。请求沿着对象链进行传递，直到有一个对象能够处理它为止。
核心思想
  责任链模式将请求发送者和接收者解耦，每个处理器都有一个指向下一个处理器的引用。
  当请求到达处理器时，它可以选择处理请求并结束，或者将请求传递给下一个处理器。这样，请求会依次在处理器链中传递，直到有一个处理器能够处理它。
主要组成部分
  抽象处理器（Handler）：定义了处理请求的接口和一个指向下一个处理器的引用。
  具体处理器（Concrete Handler）：实现了处理请求的具体逻辑。
  客户端（Client）：负责创建处理器链并发送请求。

#include <iostream>
//抽象处理器
class Handler{
protected:
  Handler* nextHandler;

public:
  Handler() : nextHandler(nullptr) {}

  void setNextHandler(Handler* handler) {
    nextHandler = handler;
  }

  virtual void handleRequest(int requeset) = 0;
};

//具体处理器A
class ConcreteHandlerA : public Handler{
public:
  void handleRequest(int request) override{
    if(request >= 0 && request < 10)
    {
      std::cout<<"具体处理器A处理请求"<<request<<std::endl;
    }
    else if(nextHandler != nullptr)
    {
      nextHandler->handleRequest(request);
    }
  }
};

//具体处理器B
class ConcreteHandlerB : public Handler{
public:
  void handleRequest(int request) override{
    if(request >= 10 && request < 20)
    {
      std::cout<<"具体处理器B处理请求"<<request<<std::endl;
    }
    else if(nextHandler != nullptr)
    {
      nextHandler->handleRequest(request);
    }
  }
};

//具体处理器C
class ConcreteHandlerC : public Handler{
public:
  void handleRequest(int request) override
  {
    if(request >= 20 && request < 30)
    {
      std::cout<<"具体处理器C处理请求"<<request<<std::endl;
    }
    else if(nextHandler != nullptr)
    {
      nextHandler->handleRequest(request);
    } 
  }
};

int main()
{
  Handler* hanclerA = new ConcreteHandlerA();
  Handler* hanclerB = new ConcreteHandlerB();
  Handler* hanclerC = new ConcreteHandlerC();

  handlerA->setNextHandler(handlerB);
  handlerB->setNextHandler(handlerC);

  handlderA->handleRequest(5);
  handlderA->handleRequest(15);
  handlderA->handleRequest(25);

  delete handlerA;
  delete handlerB;
  delete handlerC;

  return 0;
}
