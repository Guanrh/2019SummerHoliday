#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
inline const int Get_Int() {
    int num=0,bj=1;
    char x=getchar();
    while(x<'0'||x>'9') {
        if(x=='-')bj=-1;
        x=getchar();
    }
    while(x>='0'&&x<='9') {
        num=num*10+x-'0';
        x=getchar();
    }
    return num*bj;
}
long long n,m,Q[500005],f[500005],s[500005];
double Slope(long long j,long long k) { //求斜率 
    return double((f[j]+s[j]*s[j])-(f[k]+s[k]*s[k]))/(2*s[j]-2*s[k]);
}
int main() {
    scanf("%lld%lld",&n,&m);
        for(int i=1; i<=n; i++)s[i]=s[i-1]+Get_Int();
        int Left=1,Right=1;
        Q[1]=0;
        f[0]=0;
        for(int i=1; i<=n; i++) {
            while(Left<Right&&Slope(Q[Left],Q[Left+1])<=s[i])Left++; //维护队首（删除非最优决策） 
            int Front=Q[Left];
            f[i]=f[Front]+(s[i]-s[Front])*(s[i]-s[Front])+m; //计算当前f 
            while(Left<Right&&Slope(Q[Right-1],Q[Right])>=Slope(Q[Right],i))Right--; //维护队尾（维护下凸包性质） 
            Q[++Right]=i; //入队 
        }
        printf("%lld\n",f[n]);
    return 0;
}