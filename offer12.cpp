//判断一个矩阵中，是否存在一条包含某字符串所有字符的路径
//回溯法
#include <iostream>
#include <stack>
using namespace std;
#include <exception>
#include <stdexcept>
#include <cstring>

bool HasPathCore(const char* matrix,int rows,int columns,int row,int column,
const char* str,int& pathLength,bool* visited);

bool HasPath(const char* matrix, int rows,int columns,const char* str)
{
    if(matrix == nullptr || rows <= 0 || columns <= 0 || str == nullptr)
        return false;
    bool*  visited=new bool[rows*columns];
    memset(visited,0,rows*columns);
    int pathLength=0;

    for(int row=0;row<rows;row++)
        for(int column=0;column<columns;column++)
        {

            if(HasPathCore(matrix,rows,columns,row,column,
            str,pathLength,visited) == true)
                return true;
        }
    delete[] visited;
    return false;
}

bool HasPathCore(const char* matrix,int rows,int columns,int row,int column,
const char* str,int& pathLength,bool* visited)
{
    if(str[pathLength] == '\0')
        return true;

    bool hasPath=false;

    if(matrix[row*columns+column] == str[pathLength] && visited[row*columns+column] == false)
    {
        pathLength++;
        visited[row*columns+column] = true;


        hasPath=HasPathCore(matrix,rows,columns,row-1,column,str,pathLength,visited)
            ||HasPathCore(matrix,rows,columns,row+1,column,str,pathLength,visited)
            ||HasPathCore(matrix,rows,columns,row,column-1,str,pathLength,visited)
            ||HasPathCore(matrix,rows,columns,row,column+1,str,pathLength,visited);

        if(hasPath != true)
            {
                pathLength--;
                visited[row*columns+column] = false;
            }
        }
        return hasPath;

}


// ====================测试代码====================

void Test(const char* testName, const char* matrix, int rows, int cols, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(HasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


void Test1()
{
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
    Test("Test1", (const char*) matrix, 3, 4, str, true);
}


int main(int argc,char* argv[])
{
    char a[5]="star";
    char* str=a;
    Test1();

}
