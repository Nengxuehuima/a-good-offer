核心思想
装饰者设计模式（Decorator Design Pattern）是一种结构型设计模式，用于动态地给对象添加额外的职责，
同时不改变其原始类的结构。装饰者模式通过将对象包装在一个装饰者类中，然后逐层地添加装饰者，从而实现对对象的透明扩展。
主要组成部分
1）抽象构件（Component）：定义了原始对象和装饰者共同的接口。
2）具体构件（Concrete Component）：实现了抽象构件的接口，表示原始对象。
3）抽象装饰者（Decorator）：装饰者的抽象类或接口，包含一个指向抽象构件的引用。
4）具体装饰者（Concrete Decorator）：具体的装饰者类，继承自抽象装饰者，通过对抽象构件进行装饰。
特点
1）动态扩展：可以动态地给对象添加新功能，不改变原始类的结构。
2）灵活性高：可以组合多个装饰者，以实现复杂的功能扩展。
3）遵循开闭原则：对扩展开放，对修改封闭。


#include <iostream>
using namespace std;

//抽象构件
class Component{
public:
  virtual void operation() = 0;
};

//具体构件
class ConcreteComponent : public Component{
public:
  void operation() override{
    cout<<"执行具体构件的操作"<<endl;
  }
};

//抽象装饰者
class Decorator : public Component{
protected:
  Componnet* component;

public:
  Decorator(Component* component) : component(component) {}
  
  void operation() override{
    if(component != nullptr)
    {
      component->operation();
    }
  }
};

//具体装饰者A
class ConcreteDecoratorA : public Decorator{
public:
  ConcreteDecoratorA(Component* component) ： Decorator(component) {}
  
  void operation() override{
    addBehavior();//在调用被装饰对象的原本行为之前（或之后），添加额外功能。也就是“装饰”的本质。
    Decorator::operation();//调用父类（即基础装饰）的 operation()
  }
  
  void addBehavior(){
    cout<<"具体装饰者A的附加操作"<<end;
  }
};

//具体装饰者B
class ConcreteDecoratorB : public Decorator{
public:
  ConcreteDecoratorB(Component* component) : Decorator(component){}

  void operation() override{
    addBehavior();
    Decorator::operation();
  }  
  void addBehavior(){
    cout<<"具体装饰者B的附加操作"<<end;
  }
};

int main()
{
  Component* component = new ConcreteComponent();

  Component* decoratorA = new ConcreteDecoratorA(component);
  decoratorA->operation();

  Component* decoratorB = new ConcreteDecoratorB(decoratorA);
  decoratorB->operation();

  delete decoratorB;
  delete decoratorA;
  delete component;

  return 0;
}
