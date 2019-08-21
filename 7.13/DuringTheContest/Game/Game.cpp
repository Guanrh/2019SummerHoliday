#include <bits/stdc++.h>

using namespace std;

int k,ans,w,T;
char s[1100];

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d\n",&T);
	while (T--)
	{
		scanf("%d",&k);
		ans=0;
		k++;
		scanf("%s",s+1);
		//printf("!%s!\n",s+1);
		int len=strlen(s+1);
		w=1;
		for (int i=len;i>=1;i--)
		{	
			ans=(ans+w*(s[i]-'0'))%k;
			w*=10;
			w%=k;
		}
		if (ans==0) printf("No\n");
		else printf("Yes\n");
	}
}
