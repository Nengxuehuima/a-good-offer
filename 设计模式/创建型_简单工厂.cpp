(1)核心思想
将对象的创建过程封装在一个独立的工厂类中，客户端只需要通过工厂类来创建所需的对象，而不需要直接实例化具体的类。
(2)简单工厂的结构
工厂类（Factory）：负责创建具体对象的类，通常包含一个或多个创建对象的方法。
产品类（Product）：具体对象的抽象，由工厂类来创建，客户端与产品类进行交互。
示例：开发一个图形绘制应用程序，需要根据用户的选择创建不同类型的图形对象，如圆形（Circle）和矩形（Rectangle）。

#include <iostream>
#include <string>

//产品类：图形
class Shape{
public:
  virtual void draw() = 0;
  virtual ~Shape() = default;//确保基类有虚析构函数
};

//具体产品类：圆形
class Circle : public Shape{
public:
  void draw() override{
    std::cout<<"绘制圆形"<<std::endl;
  }
};

//绘制矩形
class Rectangle : public Shape{
public:
  void draw() override{
    std::cout<<"绘制矩形"<<std::endl;
  }
};

//工厂类
class ShapeFactory{
public:
  //根据类型创建图像对象
  static Shape* createShape(const std::string& type)
  {
    if(type=="Circle")
    {
      return new Circle();
    }
    else if(type=="Rectangle")
    {
      return new Rectangle();
    }
    else return nullptr;
  }
};

int main()
{
  //使用简单工厂创建图像对象
  Shape* shape1 = ShapeFactory::createShape("Circle");
  if(shape1)
  {
    shape1->draw();
    delete shape1;
  }
   Shape* shape2 = ShapeFactory::createShape("Rectangle");
  if(shape2)
  {
    shape2->draw();
    delete shape2;
  }
}
