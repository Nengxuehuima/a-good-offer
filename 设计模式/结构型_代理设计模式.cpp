核心思想
代理设计模式（Proxy Design Pattern）是一种结构型设计模式，用于在访问对象时提供一种代理，以控制对对象的访问。
代理模式通过引入一个代理对象来替代原始对象，从而可以在不改变原始对象的情况下增加额外的功能或控制访问。
主要组成部分
1）抽象主题（Subject）：定义了真实主题和代理的共同接口。
2）真实主题（Real Subject）：实际执行业务逻辑的对象。
3）代理（Proxy）：一个中间类，通过持有真实主题的引用并实现抽象主题的方法，将客户端的请求委派给真实主题。
特点
1）控制访问：代理模式可以控制对原始对象的访问。
2）增强功能：在不修改原始对象的情况下，通过代理对象增加额外功能。
3）远程代理：用于处理网络通信，隐藏底层的网络细节。
4）虚拟代理：延迟对象的创建，只有在需要时才创建真实对象。
5）保护代理：控制访问权限，确保安全性。


#include <iostream>
using namespace std；

//抽象主题
class Subject{
public:
  virtual void request() = 0;
};

//真实主题
class RealSubject : public Subject{
public:
  void request() override{
    cout<<"真实主题请求"<<endl;
  }
};

//代理
class Proxy : public Subject{
private:
  RealSubject* realSubject;

public:
  Proxy(){
    realSubject = new RealSubject();
  }
  
  ~Proxy(){
    delete realSubject;
  }

  void request() override{
    //在调用真实主题之前提议添加额外的处理逻辑
    cout<<"代理请求"<<endl;
    //委托给真实主题
    realSubjext->request();
  }
};

int main()
{
  Subject* proxy = new Proxy();
    proxy->request();
  
    delete proxy;
    return 0;
}
