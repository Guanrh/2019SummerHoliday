#include <bits/stdc++.h>

using namespace std;

int A,B,ans,f[10],target,flag,h[11000000];

int num()
{
	return f[1]*100000+f[2]*10000+f[3]*1000+f[4]*100+f[5]*10+f[6];
}

int sum()
{
	return f[1]+f[2]+f[3]+f[4]+f[5]+f[6];
}

void dg(int x,int sum)
{
	if (flag) return;
	if (x>6)
	{
		if (sum==target)
		{
			flag=1;
		}
		return;
	}
	dg(x+1,sum);
	if (sum+f[x]<=target) dg(x+1,sum+f[x]);
}

int check()
{
	flag=0;
	target=sum()/2;
	dg(1,0);
	return flag;
}

int main()
{
	//freopen("count.out","w",stdout);
	scanf("%d%d",&A,&B);
	if (B==10000000) B=999999; 
	for (f[1]=0;f[1]<=9;f[1]++)
		for (f[2]=0;f[2]<=9;f[2]++)
			for (f[3]=0;f[3]<=9;f[3]++)
				for(f[4]=0;f[4]<=9;f[4]++)
					for (f[5]=0;f[5]<=9;f[5]++)
						for (f[6]=0;f[6]<=9;f[6]++)
						{
							if (num()==0) continue;
							if (num()>B) break;
							if (sum()%2) continue;
							if (check())
							{
								//printf("%d\n",num());
								h[num()]++;
							}
						}
	for (int i=1;i<=B;i++) h[i]+=h[i-1];
	//for (int i=A;i<=B;i++) printf("%d : %d\n",i,h[i]);
	printf("%d\n",h[B]-h[A-1]);
}
