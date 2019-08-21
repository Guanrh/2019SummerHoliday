//#pragma G++ optimize(3)
//#pragma GCC optimize(3)
#include <bits/stdc++.h>

using namespace std;

struct que
{
	int len,typ;
}q[110000];

int T,n,cnt1,cnt0,ans,num0,num1;
char ch;

inline int gcd(int a, int b){ return a == 0 ? b : gcd(b % a, a); }

inline void read(int& x) {
  x = 0;
  char ch = 0;
  bool sign = false;
  while (!isdigit(ch)) { sign |= (ch == '-'); ch = getchar(); }
  while (isdigit(ch)) { x = x * 10 + (ch ^ 48); ch = getchar(); }
  x = sign ? -x : x;
}

int main()
{
	freopen("silly.in","r",stdin);
	freopen("silly.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		read(n);
		num1=num0=0;
		ans=0;
		memset(q,0,sizeof q);
		for (int i=1;i<=n;i++)
		{
			read(q[i].len);
			do ch=getchar(); while (!isalpha(ch));
			q[i].typ=(ch=='B')?0:1;
			if (ch=='B')num0+=q[i].len;
			else num1+=q[i].len;
		}
		if (num0==0 || num1==0)
		{
			printf("%d\n",num0+num1);
			continue;
		}
		int tmp=gcd(num0,num1);
		num0/=tmp;
		num1/=tmp;
		cnt1=cnt0=0;
		
		for(int i=1;i<=n;i++){
            if(!q[i].typ){
                if(cnt1 && cnt1%num1==0 && cnt1/num1*num0<=cnt0+q[i].len && cnt0<=cnt1/num1*num0){
                    cnt0=q[i].len+cnt0-cnt1/num1*num0;cnt1=0;
                    ans++;
                }
                else cnt0+=q[i].len;
            }
            else{
                if(cnt0 && cnt0%num0==0 && cnt0/num0*num1<=cnt1+q[i].len && cnt1<=cnt0/num0*num1){
                    cnt1=q[i].len+cnt1-cnt0/num0*num1;cnt0=0;
                    ans++;
                }
                else cnt1+=q[i].len;
            }
        }
		printf("%d\n",ans);
	}
}