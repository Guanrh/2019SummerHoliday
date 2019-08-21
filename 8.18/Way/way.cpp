#include <cstdio>
#include <cstring>
#include <algorithm>
#define ull unsigned long long

using namespace std;

ull k[110],hash[110],g[110],val;
char a[110],b[210000];
int f[210000][55],len[110],lena,lenb,Len,wz,tot,ans;

void predo()
{
    hash[0]=1;
    for (int i=1;i<=lena;i++) hash[i]=hash[i-1]*13331;
}

int main()
{
    scanf("%s",a+1);
    scanf("%s",b+1);
    lenb=strlen(b+1);
    lena=strlen(a+1);
    for (int i=1;i<=lenb;i++) b[lenb+i]=b[i];
    predo();
    for (int i=1;i<=lena;i++)
        if (a[i]=='*')
        {
            if (i>1 && a[i-1]!='*')
            {
                k[++tot]=val;
                len[tot]=Len;
                Len=val=0;
            }
        }
        else
            val+=(a[i]-'a'+1)*hash[Len++];
    if (a[lena]!='*')
    {
        k[++tot]=val;
        len[tot]=Len;
    }
    if (!l)
    {
        printf("%d\n",lenb);
        return 0;        
    }
    for (int i=1;i<=tot;i++) f[lenb+2+1][i]=f[lenb*2+2][i]=lenb*2+1;

    for (int i=lenb*2;i>=1;i--)
    {
        memset(g,0,sizeof g);
        for (int j=0;j<lena;j++)
            if (i+j<=lenb*2) g[j+1]=g[j]+(b[i+j]-'a'+1)*hash[j];
        for (int j=1;j<=tot;j++)
        {
            f[i][j]=f[i+1][j];
            if (g[len[j]]==k[j]) f[i][j]=i+len[j]-1;
        }
    }
}