核心思想
享元设计模式是一种结构型设计模式，旨在通过共享对象来最小化内存使用和提高性能。
该模式适用于需要创建大量细粒度对象的情况，通过共享相同的对象实例来减少内存占用。
内部状态与外部状态
1）内部状态（Intrinsic State）：对象共享的部分，不会随着外部环境的改变而改变。
2）外部状态（Extrinsic State）：对象特定的部分，会随着外部环境的改变而改变。
结构
1）抽象享元类（Flyweight）：定义享元对象的接口。
2）具体享元类（ConcreteFlyweight）：实现抽象享元接口，并定义内部状态。
3）享元工厂类（FlyweightFactory）：用于创建和管理享元对象，确保享元对象的共享。

  
#include <iostream>
#include <unordered_map>
using namespace std;

//抽象享元类
class Flyweight{
public:
  vitural void operation(int extrinsicState) = 0;
};

//具体享元类
class ConcreteFlyweight : public Flyweight{
  void operation(int extrinsicState) override{
    cout<<"具体享元对象，外部状态为"<<extrinsicState<<endl;
  }
};

//享元工厂类
class FlyweightFactory{
private:
  unordered_map<int,Flyweight*> flyweights;

public:
  Flyweight* getFlyweight(int key)
  {
    if(flyweights.find(key)==flyweights.end())
    {
      flyweights[key] = new ConcreteFlyweight();
    }
    return flyweight[key];
  }
  
  ~FlyweightFactory() {
    for(auto& pair:flyweights)
      {
        delete pair.second;
      }
  }
};

int main()
{
  FlyweightFactory factory;
  
  FLyweight* flaweight1 = factory.getFlyweight(1);
  flyweight1->operation(100);

  FLyweight* flaweight2 = factory.getFlyweight(2);
  flyweight2->operation(200);

  FLyweight* flaweight3 = factory.getFlyweight(1);
  flyweight3->operation(300);

  return 0;
}
