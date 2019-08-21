#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e6+5;
bool flag[MAXN];///标记数组
int phi[MAXN];///欧拉函数值，i的欧拉函数值=phi[i]
int p[MAXN];///素因子的值
int cnt = 0;
void Get_phi()///筛法求欧拉函数
{
    cnt = 0;
    memset(flag, true, sizeof(flag));
    phi[1] = 1;
    for(int i=2; i<MAXN; i++)///线性筛法
    {
        if(flag[i])///素数
        {
            p[cnt++] = i;
            phi[i] = i-1;///素数的欧拉函数值是素数 - 1
        }
        for(int j=0; j<cnt; j++)
        {
            if(i*p[j] > MAXN)
                break;
            flag[i*p[j]] = false;///素数的倍数，所以i*p[j]不是素数
            if(i%p[j] == 0)///性质：i mod p == 0, 那么 phi(i * p) == p * phi(i)
            {
                phi[i*p[j]] = p[j] * phi[i];
                break;
            }
            else
                phi[i*p[j]] = (p[j]-1) * phi[i];///i mod p != 0, 那么 phi(i * p) == phi(i) * (p-1) 
        }
    }
}
int main()
{
    freopen("2.out","w",stdout);
    Get_phi();
    int m;
    for (int i=1;i<=10000;i++)printf("%d\n",phi[i]);
}