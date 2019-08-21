#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
unsigned long long c[110],p[110],g[110],temp;
char a[110],b[200010];
int f[200010][52],d[110],n,m,t,i,j,k,l,ans;
int main()
{
 freopen("journey.in","r",stdin);
 freopen("journey.out","w",stdout);
 scanf("%s",a+1);
 n=strlen(a+1);
 for(p[0]=i=1;i<=n;i++) p[i]=p[i-1]*13331;
 for(i=1;i<=n;i++)
  if(a[i]=='*')
   if(i>1&&a[i-1]!='*') c[++t]=temp,d[t]=j,temp=j=0; else;
  else temp+=(a[i]-'a'+1)*p[j++];
 if(a[n]!='*') c[++t]=temp,d[t]=j,temp=j=0;
 scanf("%s",b+1);
 m=strlen(b+1);
 if(!t) {cout<<m<<endl; return 0;}
 for(i=1;i<=m;i++) b[m+i]=b[i];
 for(j=1;j<=t;j++) f[m*2+1][j]=f[m*2+2][j]=m*2+1;
 for(i=m*2;i;i--)
 {
  memset(g,-1,sizeof(g));
  g[0]=0;
  for(j=0;j<n;j++)
   if(i+j<=2*m) g[j+1]=g[j]+(b[i+j]-'a'+1)*p[j];
  for(j=1;j<=t;j++)
  {
   f[i][j]=f[i+1][j];
   if(g[d[j]]==c[j]) f[i][j]=i+d[j]-1;
  }
 }
 for(i=1;i<=m;i++)
 {
  bool flag=true;    
  for(j=n;j&&a[j]!='*';j--)
   if(a[j]!=b[i+m-1-(n-j)]) {flag=false; break;} 
  if(!flag||j==0&&n!=m) continue;
  for(k=1,l=i;k<=t-(a[n]!='*');k++)
  {
   if(k==1&&a[1]!='*'&&f[i][k]+1!=i+d[1]) break;
   l=f[l][k]+1;
  }
  if(k>t-(a[n]!='*')&&l<=i+m-(n-j)) ans++;
 }
 cout<<ans<<endl;
 return 0;
}
