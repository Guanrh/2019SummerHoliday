#include <bits/stdc++.h>
#define mo 1000000007
#define ll long long

using namespace std;

char S[110000],T[110000];
ll ans,jc[110000],cf[110000],e[110000];
int n,k,c[110000];

long long poww(long long a,long long b){
    long long ans=1,base=a;
    while(b!=0){
        if(b&1!=0)
        	ans=(ans*base)%mo;
        base=(base*base)%mo;
        b>>=1;
 	}
    return ans;  
}   

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	e[0]=1;
	for (int i=1;i<=100010;i++) e[i]=(e[i-1]*25)%mo;
	jc[0]=cf[0]=1;
	for (int i=1;i<=100010;i++) jc[i]=(jc[i-1]*i)%mo,cf[i]=poww(jc[i],mo-2);
	scanf("%d%d",&n,&k);
	scanf("%s",S+1);
	scanf("%s",T+1);
	for (int i=1;i<=n;i++) c[i]=c[i-1]+(S[i]!=T[i]);
	for (int i=1;i<=n;i++)
		for (int j='a';j<=T[i]-1;j++)
		{
			long long P=k-c[i-1];
			if (S[i]!=j) P--;
			ans+=jc[n-i]*cf[P]%mo*cf[n-i-P]%mo*e[P];
			ans%=mo;
		}
	printf("%lld\n",ans+1);
}
