#pragma GCC optimize (3)
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int BUFF_SIZE = 1 << 20;
char BUFF[BUFF_SIZE],*BB,*BE;
#define gc() (BB == BE ? (BE = (BB = BUFF) + fread(BUFF,1,BUFF_SIZE,stdin),BB == BE ? EOF : *BB++) : *BB++)
template<class T>
inline void read(T &x)
{
	x = 0;
	char ch = 0,w = 0;
	for(;ch < '0' || ch > '9';w |= ch == '-',ch = gc());
	for(;ch >= '0' && ch <= '9';x = (x << 3) + (x << 1) + (ch ^ '0'),ch = gc());
	w && (x = -x);
}

const int N = 5e4;
const int M = 1e5;
int n,m,a[N + 5],block,pos[(N << 1) + 5];
int to[(N << 1) + 5],pre[(N << 1) + 5],first[N + 5];
inline void add(int u,int v)
{
	static int tot = 0;
	to[++tot] = v,pre[tot] = first[u],first[u] = tot;
}
int fa[N + 5],dep[N + 5],sz[N + 5],son[N + 5],top[N + 5];
int rk[(N << 1) + 5],st[N + 5],ed[N + 5];
void dfs1(int p)
{
	static int tot = 0;
	sz[p] = 1,st[rk[++tot] = p] = tot;
	for(register int i = first[p];i;i = pre[i])
		if(to[i] ^ fa[p])
		{
			fa[to[i]] = p,dep[to[i]] = dep[p] + 1,dfs1(to[i]),sz[p] += sz[to[i]];
			if(!son[p] || sz[to[i]] > sz[son[p]])
				son[p] = to[i];
		}
	ed[rk[++tot] = p] = tot;
}
void dfs2(int p)
{
	if(son[p])
		top[son[p]] = top[p],dfs2(son[p]);
	for(register int i = first[p];i;i = pre[i])	
		if(!top[to[i]])
			top[to[i]] = to[i],dfs2(to[i]);
}
inline int getlca(int x,int y)
{
	while(top[x] ^ top[y])
		dep[top[x]] > dep[top[y]] ? x = fa[top[x]] : y = fa[top[y]];
	return dep[x] < dep[y] ? x : y;
}
struct s_query
{
	int l,r,lca,u,v,id;
	inline bool operator<(const s_query &o) const
	{
		return pos[l] ^ pos[o.l] ? pos[l] < pos[o.l] : pos[l] & 1 ? r < o.r : r > o.r;
	}
} qry[M + 5];
int vis[N + 5],cnt[N + 5];
int cur,ans[M + 5];
inline void calc(int x)
{
	(vis[x] ^= 1) ? cur += !cnt[a[x]]++ : cur -= !--cnt[a[x]];
}
int main()
{
	read(n),read(m),block = n / sqrt(m * 2 / 3);
	for(register int i = 1;i <= n;++i)
		read(a[i]);
	int u,v;
	for(register int i = 1;i <= n;++i)
		read(u),read(v),u && v && (add(u,v),add(v,u),1);
	dep[1] = 1,top[1] = 1,dfs1(1),dfs2(1);
	for(register int i = 1;i <= n * 2;++i)
		pos[i] = (i - 1) / block + 1;
	int x,y;
	for(register int i = 1;i <= m;++i)
	{
		read(x),read(y),read(u),read(v);
		if(st[x] > st[y])
			swap(x,y);
		if(st[x] <= st[y] && ed[y] <= ed[x])
			qry[i] = (s_query){st[x],st[y],0,u,v,i};
		else
			qry[i] = (s_query){ed[x],st[y],getlca(x,y),u,v,i};
	}
	sort(qry + 1,qry + m + 1);
	for(register int i = 1,l = 1,r = 0;i <= m;++i)
	{
		while(r < qry[i].r)
			calc(rk[++r]);
		while(r > qry[i].r)
			calc(rk[r--]);
		while(l < qry[i].l)
			calc(rk[l++]);
		while(l > qry[i].l)
			calc(rk[--l]);
		if(qry[i].lca)
			calc(qry[i].lca);
		ans[qry[i].id] = cur - (cnt[qry[i].u] && cnt[qry[i].v] && qry[i].u ^ qry[i].v);
		if(qry[i].lca)
			calc(qry[i].lca);
	}
	for(register int i = 1;i <= m;++i)
		printf("%d\n",ans[i]);
}