观察者设计模式（Observer Design Pattern）是一种行为型设计模式，用于建立对象之间的一对多依赖关系，
当一个对象的状态发生变化时，所有依赖它的对象都会得到通知并自动更新。
主要组成部分
  主题（Subject）：被观察的对象，它维护一个观察者列表，并提供添加、删除和通知观察者的方法。
  观察者（Observer）：一个抽象类或接口，定义了一个或多个接收主题通知的方法。
  具体观察者（Concrete Observer）：观察者的具体实现类，实现了接收通知并做出相应处理的方法。
特点
  实现了对象之间的松耦合。
  可以动态地添加和移除观察者。
  观察者和主题之间的交互通过接口进行，增加了系统的灵活性和可扩展性。

#include <iostream>
#include <vector>

class Observer;

//主题抽象类
class Subject{
public:
virtual void attach(Observer* observer) = 0;
virtual void datach(Observer* observer) = 0;
virtual void notify()  = 0;
};

//观察者抽象类
class Observer{
public:
  virtual void update() = 0;
};

//具体观察者类A
class ConcreteObserverA : public Observer{
public:
  void update() override{
    std::cout<<"具体观察者A接收到通知并做出响应"<<std::endl;
  }
};

//具体观察者类B
class ConcreteObserverB : public Observer{
public:
  void update() override{
    std::cout<<"具体观察者B收到通知并作出响应"<<std::endl;
  }
};

//具体主题类
class ConcreteSubject : public Subject{
private:
  std::vector<Observer*> observers;

public:
  void attach(observer* observer) override{
    observers.push_back(observer);
  }
  
  void detach(Observer* observer) override{
    for(auto it = observers.begin();it != observers.end();it++)//it 是一个迭代器，指向容器中元素的指针
      {
        if(*it == observer)//* 是 解引用运算符，*it 就是这个迭代器指向的元素，也就是一个 Observer*
        {
          observers.erase(it);
          break;
        }
      }
  
    void notify() override{
      for(auto observer : observers)
        {
          observer->update();
        }
        
    }
  }
};

int main()
{
  ConcreteSubject subject;

  Observer* observerA = new ConcreteObserverA();
  Observer* observerB = new ConcreteObserverB();

  subject.attach(observerA);
  subject.attach(observerB);

  subject.notify(); // 输出：具体观察者A收到通知并作出响应，具体观察者B收到通知并作出响应

  subject.detach(observerA);

  subject.notify(); // 输出：具体观察者B收到通知并作出响应

  delete obeserverA;
  delete observerB;

  return 0;
}
