核心思想
备忘录模式通过将对象的状态封装在备忘录对象中，实现了状态的保存和恢复。通过备忘录模式，可以在不破坏对象封装性的情况下，实现对对象状态的保存和恢复。
组成部分
原发器（Originator）：需要保存状态的对象，它可以创建备忘录对象，将当前状态保存到备忘录中，或从备忘录中恢复之前的状态。
备忘录（Memento）：用于保存原发器状态的对象，它提供了访问原发器状态的接口，但不允许其他对象修改备忘录的状态。
负责人（Caretaker）：用于管理备忘录对象的对象，它保存了多个备忘录对象，并提供了对备忘录的管理操作，例如保存备忘录、获取备忘录等。

#include <iostream>
#include <string>

//备忘录类
class Memento{
private:
  std::string state;

public:
  Memento(const std::string& state) : state(state){}
  std::string getState() const{
    return state;
  }
};

//原发器类
class Originator{
private:
  std::string state;

public:
  void setState(const std::string& state)
  {
    this->state = state;
  }
  
  std::string getState() const{
    return state;
  }
  
  Menento* createMenento() const{
    return new Menento(state);
  }
  
  void restoreMenento(const Memento* memento)
  {
    state = memento->getState();
  }
};

//负责人类
class Caretaker{
private:
Memento* memento;

public:
void saveMemento(Memento* memento)
{
  this->memento = memento;
}

Memento* getMemento() {
  return memento;
}
};

int main(){
  Originator originator;
  Caretaker caretaker;

  //设置初始状态
  originator.setState("State 1");
  std::cout<<"Current state"<<originator.getState()<<std::endl;

  //保存备忘录
  caretaker.saveMemento(originator.createMemto());

  //修改状态
  originator.setState("State 2");
  std::cout<<"Current state:"<<originator.getState()<<std::endl;

  //恢复到之前状态
  originator.restoreMemento(caretaker.getMemento());
  std::cout<<"Current state:"<<originator.getState()<<std::endl;

  return 0;
}
