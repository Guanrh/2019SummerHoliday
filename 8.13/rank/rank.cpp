#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

inline void read(int& x) {
  x = 0;
  char ch = 0;
  bool sign = false;
  while (!isdigit(ch)) { sign |= (ch == '-'); ch = getchar(); }
  while (isdigit(ch)) { x = x * 10 + (ch ^ 48); ch = getchar(); }
  x = sign ? -x : x;
}

int n,k,a[5100000];
int main()
{
	scanf("%d%d",&n,&k);
	for (register int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+1+n);
	for (register int i=1;i<=k;i++) printf("%d ",a[i]);
}