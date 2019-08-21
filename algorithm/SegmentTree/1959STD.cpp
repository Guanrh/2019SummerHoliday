#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#pragma GCC optimize(2)
#define MAXN 1000001
int Sum[MAXN*4],a[MAXN+10],n,x,y,z,m;
int max(int x,int y){return x>y ? x:y;}
void PushUp(int rt){Sum[rt]=max(Sum[rt<<1],Sum[rt<<1|1]);}
void Build(int l,int r,int rt){
	if (l==r){
		Sum[rt]=a[l];
		return;
	}
	int m=(l+r)>>1;
	Build(l,m,rt<<1);
	Build(m+1,r,rt<<1|1);
	PushUp(rt);
}
void Update(int L,int C,int l,int r,int rt){
	if (l==r){
		Sum[rt]=C;
		return;
	}
	int m=(l+r)>>1;
	if (L<=m) Update(L,C,l,m,rt<<1);
	else	Update(L,C,m+1,r,rt<<1|1);
	PushUp(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(L<=l && r<=R) return Sum[rt];
	int m=(l+r)>>1;
	int mx=0;
	if (L<=m) mx=max(mx,query(L,R,l,m,rt<<1));
	if (R>m) mx=max(mx,query(L,R,m+1,r,rt<<1|1));
	return mx;
}
int main(){
	//freopen("max.in","r",stdin);
	//freopen("max.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	Build(1,n,1);
	//printf("%d %d %d %d %d %d %d %d %d\n",Sum[1],Sum[2],Sum[3],Sum[4],Sum[5],Sum[6],Sum[7],Sum[8],Sum[9]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&z,&x,&y);
		if (z==1){
			Update(x,y,1,n,1);
			//printf("%d %d %d %d %d %d %d %d %d\n",Sum[1],Sum[2],Sum[3],Sum[4],Sum[5],Sum[6],Sum[7],Sum[8],Sum[9]);
		}
		else
		{
			int ans=query(x,y,1,n,1);
			printf("%d\n",ans);
		}
	}
}