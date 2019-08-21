#include<cstdio>
#include<iostream>
#define maxn 202020
using namespace std;
 
int n,m,a,b,r[maxn],l[maxn],DP[maxn];
int que[maxn],head,tail;
 
int main(){
    scanf("%d%d",&n,&m);
     
    for(int i = 1;i <= n+1;i++) r[i] = i-1;
     
    for(int i = 1;i <= m;i++){
        scanf("%d%d",&a,&b);
        r[b] = min(r[b],a-1);
        l[b+1] = max(l[b+1],a);
    }
     
    for(int i = n;i;i--)
        r[i] = min(r[i],r[i+1]);
     
    for(int i = 2;i <= n+1;i++)
        l[i] = max(l[i],l[i-1]);
     
    for(int i = 1;i <= n+1;i++){
        for(int k = l[i];k <= r[i];k++){
            while(tail < head && DP[que[head]] <= DP[k]) head--;
            que[++head] = k;
        }
         
        while(tail < head && que[tail+1] < l[i]) tail++;
         
        if(tail == head) DP[i] = -1e9;
        else DP[i] = DP[que[tail+1]] +1;
    }
     
//  for(int i = 0;i <= n+1;i++) printf("%d ",DP[i]);
//  cout << endl;
     
    if(DP[n+1] >= 0) printf("%d\n",DP[n+1]-1);
    else printf("-1\n");
     
    return 0;
}

