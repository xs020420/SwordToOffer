#include <iostream>
using namespace std;
//为类型CMyString添加赋值运算函数（运算符重载）

class CMyString
{
public:
    CMyString(char* pData = nullptr)；
    CMyString(const CMyString &str )；
    ~CMyString(void)；

private：
    char* m_pData;
};


int main(int argc,char* argv[])
{
    A a = 10;
    a.Print();
}
