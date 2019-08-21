#include <cstdio>
#include <cstring>

using namespace std;

char s[410000];
int n,l,r;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		l=1,r=n-i+1;
		int flag=1;
		for (int j=1;j<=i;j++)
		{
			if (s[l]!=s[r])
			{
				flag=0;
				break;
			}
			l++,r++;
		}
		if (flag) printf("%d ",i);
	}
}
