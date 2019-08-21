#include <bits/stdc++.h>
#define N 1000000007

using namespace std;

long long x;
int cnt,ans;

int main()
{
	scanf("%lld",&x);
	while (x%N!=0) x=(x*2+1)%N,cnt++;
	ans=cnt/3;
	cnt-=ans*3;
	if (cnt) ans++;
	printf("%d\n",ans);
}