//用两个栈实现一个队列
//队列申明如下类模板。实现函数appendTail，deleteHead。分别再队列尾部插入节点，队列头部删除节点
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>

template<typename T>class CQueue
{
public:
     CQueue(void){};
     ~CQueue(void){};
    void appendTail(const T& node);
    T deleteHead(void);
private:
    stack<T>stack1;
    stack<T>stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template<typename T> T CQueue<T>::deleteHead(void)
{
    if(stack2.size()<= 0)
    {
        while(stack1.size() > 0)
        {
            T& data=stack1.top();
            stack1.pop();
            stack2.push(data);
        }
    }




    if(stack2.size() == 0)//异常抛出
        {
        logic_error ex("invalid");
        throw  exception(ex);
        }
    T& head=stack2.top();
    stack2.pop();
    return head;
}
int test(int a){
    return a;
}
int main(int argc,char* argv[])
{
    int a=8;
    int& ri = a;
    CQueue<int> queue_a;
    queue_a.appendTail(ri);
    int deletedValue=queue_a.deleteHead();
    cout<<deletedValue<<endl;
    int b;
    b=ri;
    cout<<b<<endl;

    return 0;
}
