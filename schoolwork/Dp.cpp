#include <bits/stdc++.h>
#define N 100005
double sum[N];
int que[N],head,tail; 

double max(double x,double y){return x>y?x:y;}

int main(){
    int n,k;
    while(scanf("%d%d",&n,&k) != -1){
        int i,j;
        sum[0] = 0;
        for(i=1;i<=n;i++){
            int a;
            scanf("%d",&a);
            sum[i] = sum[i-1]+a*1.0;
        }
        head = tail = 0;
        que[0] = 0;
        double ans = 0.0;
        for(i=k;i<=n;i++){
            int now = i-k;
            while(head<tail){
                double y1 = sum[que[tail]] - sum[que[tail-1]];
                double x1 = que[tail] - que[tail-1];
                double y2 = sum[now] - sum[que[tail]];
                double x2 = now - que[tail];
                if(y1*x2>=y2*x1)tail--;
                else break;
            }
            que[++tail] = now;
            while(head<tail){
                double y1 = sum[que[head]] - sum[i];
                double x1 = que[head] - i;
                double y2 = sum[que[head+1]] - sum[i];
                double x2 = que[head+1] - i;
                if(y1*x2<=y2*x1)head++;
                else break;
            }
            double tmp = (sum[que[head]] - sum[i])/((que[head] - i)*1.0);
            ans = max(ans,tmp);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}