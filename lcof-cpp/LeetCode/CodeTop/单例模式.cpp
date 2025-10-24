
//这段代码在 C++11 及以上标准中是线程安全的，即使没有显式加锁（如std::mutex）。
//核心原因是 C++11 标准对局部静态变量的初始化做了线程安全保证：当多个线程同时调用GetInstance()时，
//局部静态变量instance的初始化过程会被编译器自动加锁保护，确保只有一个线程能完成初始化，其他线程会阻塞等待初始化完成，最终只会创建一个实例。


#include <iostream>
// 单例类：保证全局唯一实例，提供统一访问接口
class Singleton {
public:
    // 1. 全局唯一访问点：返回单例实例（C++11后局部静态变量初始化线程安全）
    static Singleton& GetInstance() {
        static Singleton instance; // 局部静态变量，首次调用时初始化，程序结束自动析构
        return instance;
    }

    // 3. 业务函数：单例类的实际功能（示例：打印实例地址，验证唯一性）
    void PrintInstanceAddr() {
        std::cout << "Singleton Instance Address: " << this << std::endl;
    }

private:
    // 2. 禁用默认构造、拷贝构造、赋值运算符（核心：阻止外部创建新实例）
    Singleton() = default; // 私有默认构造：外部无法直接new
    Singleton(const Singleton&) = delete; // 禁用拷贝构造
    Singleton& operator=(const Singleton&) = delete; // 禁用赋值运算符
};

// 测试：多线程调用也能保证实例唯一（此处简化为单线程测试，实际多线程场景同样适用）
int main() {
    // 通过GetInstance()获取实例，无法通过其他方式创建
    Singleton& s1 = Singleton::GetInstance();
    Singleton& s2 = Singleton::GetInstance();
    
    s1.PrintInstanceAddr(); // 打印地址1
    s2.PrintInstanceAddr(); // 打印地址2（与地址1完全相同，证明实例唯一）
    
    return 0;
}




//懒汉模式，线程安全（加锁）
#include <iostream>
#include <mutex> // 引入互斥锁头文件

class Singleton {
public:
    static Singleton* GetInstance() {
        // 第一重检查：先判断实例是否已存在，避免不必要的加锁（优化性能）
        if (instance_ == nullptr) {
            // 加锁：保证同一时间只有一个线程进入临界区
            std::lock_guard<std::mutex> lock(mutex_);
            // 第二重检查：进入临界区后再次判断，防止多线程等待锁时重复创建
            if (instance_ == nullptr) {
                instance_ = new Singleton();
            }
        }
        return instance_;
    }

    // （可选）手动释放单例实例（避免内存泄漏，尤其在动态库场景）
    static void ReleaseInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance_ != nullptr) {
            delete instance_;
            instance_ = nullptr;
        }
    }

    void PrintAddr() {
        std::cout << "Singleton Address: " << this << std::endl;
    }

private:
    // 私有构造、拷贝构造、赋值运算符：禁止外部创建实例
    Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* instance_; // 静态指针存储单例实例
    static std::mutex mutex_;    // 静态互斥锁保证线程安全
};

// 静态成员变量类外初始化
Singleton* Singleton::instance_ = nullptr;
std::mutex Singleton::mutex_;

// 测试：多线程环境下验证（此处用简单调用演示，实际多线程调用结果一致）
int main() {
    Singleton* s1 = Singleton::GetInstance();
    Singleton* s2 = Singleton::GetInstance();
    
    s1->PrintAddr(); // 地址相同
    s2->PrintAddr(); // 地址相同

    Singleton::ReleaseInstance(); // 手动释放
    return 0;
}




/*
单例模式是 C++ 中最基础的设计模式之一，核心是保证一个类在程序中只有一个实例对象，并提供全局唯一的访问方式，常考场景包括线程安全的单例实现、饿汉 / 懒汉模式的区别等
饿汉模式：程序启动时创建实例，线程安全但可能浪费内存。
懒汉模式：首次调用时创建，默认线程不安全但节省内存，懒汉模式未加保护时，多线程并发调用可能创建多个实例，需掌握线程安全的解决方案。
*/
