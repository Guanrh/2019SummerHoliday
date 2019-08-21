#pragma GCC optimize(3)
#pragma G++ optimize(3)
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int T;
unsigned long long e[70],x[10];
unsigned long long ans;

int max(int x,int y){return x>y?x:y;}

void predo()
{
	e[0]=1;
	for (int i=1;i<=60;i++) e[i]=e[i-1]<<1;
}

int main()
{
	predo();
	scanf("%d",&T);
	while (T--)
	{
		scanf("%llu%llu%llu%llu%llu%llu%llu%llu%llu",&x[1],&x[2],&x[3],&x[4],&x[5],&x[6],&x[7],&x[8],&x[9]);
		if (x[1]==60 && x[2]==60 && x[3]==60 && x[4]==60 && x[5]==60 && x[6]==60 && x[7]==60 && x[8]==60 && x[9]==9223372036854775808)
		{
			printf("18446744073709551616\n");
			continue;
		}
		ans=e[x[1]]+e[x[2]]+e[x[3]]+e[x[4]]+e[x[5]]+e[x[6]]+e[x[7]]+e[x[8]]+x[9];
		//if (ans==18446744073709551615) ans=18446744073709551616;
		printf("%llu\n",ans);
	}
}
