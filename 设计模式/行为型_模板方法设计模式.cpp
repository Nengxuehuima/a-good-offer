模板方法设计模式（Template Method Pattern）是一种行为型设计模式，用于定义一个算法的骨架，而将一些步骤的具体实现延迟到子类中。
这种模式允许在不改变算法结构的情况下，通过子类重写或扩展某些步骤来定制算法的行为。
(1)核心思想
模板方法模式将一个算法的步骤模板化，定义在一个抽象的基类中，其中一些步骤由抽象方法或默认方法实现，而其他步骤则由具体子类实现。
(2)主要组成部分
模板类（Abstract Class）：定义了算法的骨架，通常包含一个或多个抽象方法，代表算法中的不同步骤。同时，也可以包含具体的方法来处理一些通用的逻辑。
具体子类（Concrete Subclasses）：继承自模板类，实现模板中的抽象方法，以完成特定步骤的具体实现。每个具体子类可以定制算法的不同部分。
(3)特点
定义了一个算法的框架，具体步骤由子类实现。
遵循开闭原则，即允许在不修改模板代码的情况下扩展和变化算法的某些部分。
促使代码重用，将通用行为提取到模板方法中。
假设开发一个烹饪应用程序，其中有不同的食谱，如制作咖啡和茶。你可以使用模板方法模式来定义一个通用的烹饪算法：

#include <iostream>

//模板类-食谱
class Recipe{
piblic:
  //模板方法，定义烹饪算法的骨架
  void cook(){
    boilWater();
    brew();
    pourInCup();
    if(customerWantsCondiments()){
      addCondiments();
    }
  }
  
  //抽象方法,由子类实现
  virtual void brew() = 0;
  virtual void addCondiments() = 0;
  
  //钩子方法，子类可以选择性地覆盖
  vitual bool customerWantsCondiments(){
    return ture;
  }
  
  //具体方法 通用逻辑
  void boilWater(){
    std::cout<<"烧开水"<<std::endl;
  }
  
  void pourInCup(){
    std::cout<<"倒入杯中"<<std::endl;
  }
};

//具体子类-制作咖啡
class CoffeeRecipe : public Recipe{
public:
  void brew() override{
  std::cout<<"冲泡咖啡"<<std::endl;
  }
  void addCondiments() override{
    std::cout<<"加入糖和牛奶"<<std::endl;
  }

};

//具体子类-制作茶
class TeaRecipe : public Recipe{
public:
  void brew() override{
    std::cout<<"浸泡茶叶"<<std::endl;
  }
  
  void addCondiments() override{
    std::cout<<"加入柠檬"<<std::endl;
  }
};

int main(){
  Recipe* coffee = new CoffeeRecipe();
  coffee->cook();

  Recipe* tea = new TeaRecipe();
  tea->cook();

  delete coffee;
  delete tea;

  return 0;
}
