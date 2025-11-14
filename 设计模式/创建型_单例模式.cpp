单例设计模式旨在确保一个类只有一个实例，并提供全局访问点以访问该实例。在单例模式中，有两种常见的实现方式，即饿汉式和懒汉式。
它们的主要区别在于实例的创建时间和线程安全性。
饿汉式单例模式
在饿汉式中，实例在类加载时就被创建，不管是否需要使用它。这意味着无论何时引用该类，都会返回相同的实例。
主要特点：
1）线程安全：在多线程环境中，由于实例在类加载时创建，所以不会存在竞态条件，是线程安全的。
2）简单：实现简单，但可能会浪费内存，因为无论是否需要，实例都会创建。

class Singleton{
private:
  static Singleton* instance;
  Singleton() {}//私有构造函数，禁止外部实例化
public:
  static Singleton* getInstance()
  {
    return instance;
  }
};

//静态成员初始化
Singleton* Singleton::instance = new Singleton();

懒汉式单例模式
在懒汉式中，实例在第一次被请求时创建。这意味着实例的创建是延迟的，直到需要使用它时才会创建。
主要特点：
1）延迟加载：实例的创建是延迟的，只有在需要时才会创建。
2）非线程安全：在多线程环境中，多个线程可能同时访问getInstance()方法，导致创建多个实例。需要额外的同步措施来保证线程安全。
class Singleton{
private:
  static Singleton* instance;
  Singleton() {}//私有化构造函数，禁止外部实例化
public:
  static Singleton* getInstance()
  {
    if(instance==nullptr)
    {
      instance = new Singleton();
    }
    return instance;
  }
};
//静态成员初始化
Singleton* Singleton::instance = nullptr;

线程安全的懒汉式单例模式：
双重检查锁定（Double-Checked Locking）是一种用于实现懒汉式单例模式的常见线程安全技术。
它的目的是在多线程环境下延迟实例化对象，同时确保只有一个实例被创建。这种技术通常用于需要考虑性能的情况下，
因为它在绝大多数情况下避免了不必要的锁定操作。
双重检查锁定的基本思想：
首先检查实例是否已经创建，如果已经创建，则直接返回实例。如果实例尚未创建，才进行锁定操作。在锁定的情况下再次检查实例是否已经创建，
以防止其他线程在等待锁定时已经创建了实例。如果实例仍未创建，才创建并返回实例。

#include <iostream>
#include <mutex>

class Singleton{
private;
  static Singleton* instance;
  static std::metux mtx;//用于线程安全的锁

  Singleton() {}//私有化构造函数，防止外部实例化。
public:
  static Singleton* getIntance()
  {
    //检查实例是否已经创建
    if(intance==nullptr)
      std::lock_guard<std::mutex> lock(mtx); //加锁
    //第二次检查实例是否创建，防止其他线程在等待锁定时创建实例
    if(instance==nullptr)
      intance = new Singleton();
  }
  return instance;
};

//静态成员变量初始化
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mtx;














