#pragma G++ optimize(3)
#pragma GCC optimize(3)
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cctype>
#include<cmath>
using namespace std;
int a[11],x[11],c[5]={3,1,0,0,0},n,ans;
void dg(int l,int r){
	if (a[l]>x[l] || a[r]>x[r]) return;
	if (x[l]-a[l]>3*(n-r+1)) return;
	if (x[r]-a[r]>3*(n-l+1)) return;
	if (l==n){
		ans++;
		return;
	}
	if (r==n){
		int temp=x[l]-a[l];
		if (temp==2) return;
		a[r]+=c[temp];
		dg(l+1,l+2);
		a[r]-=c[temp];
		return;
	}
	a[l]++;
	a[r]++;
	dg(l,r+1);
	a[l]--;
	a[r]--;
	a[l]+=3;
	dg(l,r+1);
	a[l]-=3;
	a[r]+=3;
	dg(l,r+1);
	a[r]-=3;
}
bool cmp(int x,int y) {
    return x>y;
}
int main(){
	//freopen("match.in","r",stdin);
	//freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	sort(x+1,x+n+1,cmp);
	dg(1,2);
	printf("%d",ans);
	return 0;
}