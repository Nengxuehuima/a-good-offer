核心思想
组合模式允许你将对象组合成树形结构来表示“部分-整体”的层次结构。组合模式使得客户端对单个对象和组合对象的使用具有一致性。
通过组合模式，客户端可以统一地对待单个对象和对象组合，无需关注它们是单个对象还是组合对象。
主要组成部分
1）抽象组件类（Component）：定义了组合对象和叶子对象的共同接口或抽象类。
2）叶子组件类（Leaf）：表示树形结构中的叶子节点，叶子节点没有子节点。
3）组合组件类（Composite）：表示树形结构中的组合节点，组合节点可以包含叶子节点或其他组合节点。
特点
1）统一处理：客户端可以一致地处理单个对象和组合对象。
2）层次结构：通过树形结构表示对象之间的层次关系。
3）简化客户端代码：客户端无需区分单个对象和组合对象，简化了代码复杂性。


#include <iostream>
#include <vector>
using namespace std;

//抽象组件类
class Component{
public:
  virtual void operation() = 0;
  virtual ~Component() = default;
};

//叶子组件类
class Leaf : public Component{
public:
  void operation() override{
    cout<<"叶子组件的操作"<<endl;
  }
};

//组合组件类
class Composite : public Component{
private:
  vector<Component*> components;

public:
  void addComponent(Component* component)
  {
    components.push_back(components);
  }
  
  void operation() override{
    cout<<"组合组件操作"<<endl;
    for(Component* component : components)
      {
        component->operation();
      }
  }
  
  ~Component()
  {
    for(Component* component : components)
      {
        delete component;
      }
  }
};

int main()
{
  Component* leaf1 = new Leaf();
  Component* leaf2 = new Leaf();
  Compoment* composite = new Component();
  composite->addComponent(leaf1);
  composite->addComponent(leaf2);
  
  composite->operation();
 
  delete composite;
  return 0;
}
