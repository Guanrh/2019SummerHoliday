#include <cstdio>

using namespace std;

int n,siz,a[31000],x;

void swap(int &a,int &b){int tmp=a;a=b;b=tmp;}

int get()
{
	int now=1,res=a[1],next;
	a[1]=a[siz--];
	while (now<<1<=siz)
	{
		next=now<<1;
		if (next<siz && a[next+1]<a[next]) next++;
		if (a[now]<=a[next]) break;
		swap(a[now],a[next]);
		now=next;
	}
	return res;
}

void put(int d)
{
	int now;
	a[++siz]=d;
	now=siz;
	while (now>1)
	{
		if (a[now]>=a[now>>1]) break;
		swap(a[now],a[now>>1]);
		now>>=1;
	}
}

int main()
{
	siz=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&x),put(x);
	int num1,num2,ans=0;
	for (int i=1;i<=n-1;i++)
	{
		num1=get();
		num2=get();
		ans+=num1+num2;
		put(num1+num2);
	}
	printf("%d\n",ans);
}