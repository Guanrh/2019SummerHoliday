#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=200005;
ll a[maxn],n,i,t,j,k,l,r,mid,x,y;
int main(){
    //freopen("linear.in","r",stdin);freopen("linear.out","w",stdout);
    scanf("%lld",&n);
    for (i=1;i<=n;i++)
        scanf("%lld%lld",&a[i],&a[i+n]);
    n*=2;
    sort(a+1,a+n+1);
    t=n/2;
    printf("%lld %lld\n",a[t],a[t+1]);
}