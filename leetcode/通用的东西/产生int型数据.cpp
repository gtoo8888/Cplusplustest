#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#define digit 10
using namespace std;
string LLMax="9223372036854775807";
string IntMax="2147483647";
string RandomInt()
{
    int n=rand()%digit+1;//接下来生成n位数
    string s;
    if(n==digit)//特殊处理，因为int型要在[-2^31,2^31-1]之内
    {
        s+=rand()%2+1+'0';
        for(int i=1;i<n;i++)
        {
            int temp=rand()%10;
            while(temp>IntMax[i]-'0') temp=rand()%10;
            s+=temp+'0';
        }
        return s;
    }
    if(n==1) s+=rand()%10+'0';//
    else s+=rand()%9+1+'0';//第一位为1-9之间的数
    for(int i=2;i<=n;i++) s+=rand()%10+'0';//随机产生第2-n位上的数字
    if(rand()%2==1) s='-'+s;//产生负数
    return s;
}
int main()
{
    int m=0;
    ofstream in("int_in.txt");
    srand((unsigned)time(NULL));
    for(int i=0;i<100;i++)
        in<<RandomInt()<<endl;
    return 0;
}