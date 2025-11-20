命令设计模式（Command Design Pattern）是一种行为型设计模式，用于将请求封装成一个对象，从而可以在不同的上下文中使用、传递和操作请求。
  它将请求的发送者和接收者解耦，使得发送者只需知道如何发送请求，而不需要知道请求是如何被执行和处理的。
核心思想
  命令模式将请求封装成一个对象，使得请求可以被参数化、存储、日志记录以及撤销和重做等操作。
  同时，通过命令对象，可以实现请求的解耦，使发送者和接收者独立变化。
主要组成部分
  1）命令接口（Command）：一个抽象接口，用于声明执行命令的方法。
  2）具体命令（Concrete Command）：命令接口的具体实现，绑定了一个接收者对象和一组操作。
  3）请求者（Invoker）：负责发送命令的对象，持有一个命令对象，并在需要时调用命令对象的执行方法。
  4）接收者（Receiver）：执行命令的对象，实现了具体的操作逻辑，并在接收到命令时执行相应的操作。


#include <iostream>
#include <string>

//命令接口
class Command{
public:
  virtual ~Command() {}
  virtual void execute() = 0;
};

class Receiver;//前向声明

//具体命令
class ConcreteCommand : public Command{
private:
  std::string messsage;
  Receiver* receiver;

public:
  ConcreteCommand(Receiver* r，const std::string& message) : receiver(r),message(message) {}
  
  void execute() override{
    std::cout<<"Executeing command:"<<message<<std::endl;
     if (receiver) {
            receiver->performAction(message);
        }
      
    }
  }
};

//请求者
class Invoker{
private:
  Command* command;

public:
  void setCommand(COmmand* command){
    this->command = command;
  }
  
  void executeCommand(){
    command->execute();
  }
};

//接收者
class Receiver{
public:
  void performAction(const std::string& message) {
    std::cout<<"Performing action"<<meaasge<<std::endl;
    //执行接收者的具体操作
  }
};

int main(){
  Invoker invoker;
  Receiver receiver;
  Command* command = new ConcreteCommand("Do something");

  //设置命令
  invoker.setCommand(command);

  //执行命令
  invoker.executeCommand();

  //执行接收者操作
  receiver.performAction();

  delete command;

  return 0;
}
