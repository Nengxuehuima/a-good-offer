核心思想
桥接模式旨在将一个对象的抽象部分与具体实现部分分离，使得它们可以独立地变化。
通过这种方式，系统的抽象层和实现层可以独立进行扩展，而不会相互影响，从而提高系统的灵活性和可扩展性。
主要组成部分
1）抽象部分（Abstraction）：定义了抽象接口，并包含一个对实现部分的引用。
2）具体抽象部分（Concrete Abstraction）：抽象部分的具体实现，通常是抽象部分的子类。
3）实现部分（Implementor）：定义了实现接口，提供基本的操作。
4）具体实现部分（Concrete Implementor）：实现部分的具体实现，通常是实现部分的子类。
特点
1）解耦抽象与实现：通过引入桥接接口，将抽象部分和实现部分分离，允许它们独立地变化和扩展。
2）提高灵活性：可以动态地切换不同的实现部分，实现更灵活的系统行为。
3）处理多个变化维度：将每个变化维度抽象成抽象部分和实现部分，灵活地组合不同的变化维度。

#include <iostream>

//实现部分
class Implementor{
public:
  virtual void operationImpl() = 0;
};

//具体实现部分A
class ConcreteImplementorA : public Implementor{
public:
  void operationImpl() override{
    std::cout<<"具体实现部分A的操作"<<std::endl;
  }
};

//具体实现部分B
class ConcreteImplementorB : public Implementor{
public:
  void operationImpl() override {
    std::cout<<"具体实现部分B的操作"<<std::endl;
  }
};

//抽象部分
class Abstraction{
proteced:
  Implementor* implementor;
public:
  Abstraction(Implementor* implementor) : implementor(implementor) {}
  virtual void operation() = 0;
};

//具体抽象部分A
class ConcreteAbstractionA : public Abstraction{
public:
  ConcreteAbstrationA(Implementor* implementor) : Abstraction(implementor) {}

  void operation() override {
    std::cout<<"具体抽象部分A的操作"<<std::endl;
    implementor->operationImpl();
  }
};

//具体抽象部分B
class ConcreteAbstractionB : public Abstraction{
public:
  ConcreteAbstrationB(Implementor* implementor) : Abstraction(implementor) {}

  void operation() override {
    std::cout<<"具体抽象部分B的操作"<<std::endl;
    implementor->operationImpl();
  }
};

int main()
{
  Implementor* implementorA = new ConcreteImplementorA();
  Abstraction* abstractionA = new ConcreteAbstractionA(implemenntorA);
  abstractionA->operation();

  Implementor* implementorB = new ConcreteImplementorB();
  Abstraction* abstractionB = new ConcreteAbstractionB(implemenntorB);
  abstractionB->operation();

  delete implementorA;
  delete abstractionA;
  delete implementorB;
  delete abstractionB;

  return 0;
}
