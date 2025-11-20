迭代器设计模式（Iterator Design Pattern）是一种行为型设计模式，用于提供一种统一的方式来访问集合对象中的元素，而无需暴露集合的内部表示。
主要组成部分
  1）迭代器接口（Iterator）：定义了访问和遍历集合元素的方法。
  2）具体迭代器（ConcreteIterator）：实现了迭代器接口中的方法，并维护了一个指向集合中当前元素的指针。
  3）聚合接口（Aggregate）：定义了获取迭代器的方法。
  4）具体聚合（ConcreteAggregate）：实现了聚合接口中的方法，并返回一个具体迭代器的实例。
特点
  提供一种统一的方式来访问集合对象中的元素。
  隐藏集合的内部表示。
  支持多种遍历方式或遍历顺序。


#include <iostream>
#include <vector>

//迭代器接口
template<class T>
class Iterator{
public:
  virtual bool hasNext() = 0;
  virtual T next() = 0;
};

//具体迭代器
template<class T>
class ConcreteIterator : public Iterator<T> {
private:
  std::vector<T>& collection;
  int index = 0;

public:
  ConcreteIterator(std::vector<T>& collection) : collection(collection) {}

  bool hasNext() override{
    return index < colletion.size();
  }

  T next() override{
    return collection[index++];
  }
};

//聚合接口
template<class T>
class Aggregate{
public:
  virtual Iterator<T>* createIterator() = 0;
};

//具体聚合
template<class T>
class ConcreteAggregate : public Aggregate<T> {
private:
  std::vector<T> collection;

public:
  void add(T item){
    collection.push_back(item);
  }

  Iterator<T>* createIterator() override{
    return new ConcreteIterator<T> (collection);
  }
};

int main()
{
  ConcreteAggregate<int> aggregate;
  aggretege.add(1);
  aggregete.add(2);
  aggregate.add(3);

  Iterator<int>* iterator = aggregate.createIterator();

  while(iterator->hasNext())
    {
      std::cout<<iterator->next()<<" ";
    }

  delete iterator;
  return 0;
}
