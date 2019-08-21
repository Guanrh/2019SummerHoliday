#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

int max(int x,int y){return x>y?x:y;}
int min(int x,int y){return x<y?x:y;}

struct node
{
	int p,n;
}x[110000];

int n,f[110000],a[410000],low,pre[110000],bz[110000],mx;

void predo()
{
	memset(bz,0,sizeof bz);
	for (int i=1;i<=n;i++)
	{
		if (bz[x[i].p]) pre[i]=bz[x[i].p];
		bz[x[i].p]=i;
	}
}

inline char nextchar() {
  static char buf[100000], *p1 = buf, *p2 = buf;
  return (p1 == p2) &&
    (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
} 

inline void read(int& x) {
  x = 0;
  char ch = 0;
  bool sign = false;
  while (!isdigit(ch)) { sign |= (ch == '-'); ch = nextchar(); }
  while (isdigit(ch)) { x = x * 10 + (ch ^ 48); ch = nextchar(); }
  x = sign ? -x : x;
}


int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	scanf("%d",&n);
	for (register int i=1;i<=n;i++) //scanf("%d%d",&x[i].p,&x[i].n);
		read(x[i].p),read(x[i].n);
	predo();

	low=1;
	memset(f,127,sizeof f);
	f[0]=0;
	for (register int i=1;i<=n;i++)
	{
		low=max(low,pre[i]+1);
		mx=x[i].n;
		for (register int j=i;j>=low;j--)
		{
			mx=max(mx,x[j].n);
			f[i]=min(f[i],f[j-1]+mx);
		}
	}
	printf("%d\n",f[n]);
}
