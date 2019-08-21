const int N=100010;
multiset<int> t;
int n,L[N],p[N],v[N],pr[N];
int S=1,T,pos[N],data[N],sum[N],f[N];
signed main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		p[i]=read(),v[i]=read();
		L[i]=max(L[i-1],pr[p[i]]+1);
		pr[p[i]]=i;
	}
	for(int i=1,k=0;i<=n;k=i++)
	{
		while(S<T&&pos[S+1]<L[i])
		  t.erase(t.find(sum[S++]));
		while(S<=T&&v[i]>data[T])
		  k=pos[T],
		  t.erase(t.find(sum[T--]));
		pos[++T]=k,data[T]=v[i];
		if(S^T)
		{
			t.erase(t.find(sum[S]));
			sum[T]=f[pos[T]]+data[T];
			t.insert(sum[T]);
		}
		sum[S]=f[L[i]-1]+data[S];
		t.insert(sum[S]);
		f[i]=*t.begin();
	}
	printf("%d",f[n]);
	return 0;
}