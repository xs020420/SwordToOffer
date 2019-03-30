//正则表达式匹配
//实现函数 用来匹配 '.'和'*'的正则表达式。
//'.'表达任何一个字符，'*'表示它前面的字符可以出现任意次数（包括0次）
//匹配是指字符串的所有字符匹配整个模式。

#include <iostream>
using namespace std;
#include <cstring>

bool MatchCore(char* str,char* pattern)
{
    if(*str == '\0' && *pattern == 0)
        return true;
    if(*str != '\0' && *pattern == 0)
        return false;
    if(*str == '\0' && *pattern != 0)
        return false;



    if(*(pattern+1 ) == '*')
    {
            return MatchCore(str+1,pattern+1)
                ||MatchCore(str+1,pattern)
                ||MatchCore(str,pattern+2);
    }

    if(*str == *pattern || *pattern == '.')
        return MatchCore(str+1,pattern+1);

    return false;
}


bool RegulationMatch(char* string, char* pattern)
{
    if(string == nullptr || pattern == nullptr)
        return false;
    return MatchCore(string,pattern);
}

int main()
{
    char* str="54y";
    char* pattern =".*5...";

    bool result = false;
    result = RegulationMatch(str,pattern);
    cout<<result<<endl;
}
