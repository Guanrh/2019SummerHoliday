#include <cstdio>
#include <cstring>

using namespace std;

char p[1100000],s[1100000];
int next[1100000],lenp,lens;

void GetNext()
{
    next[1]=0;
    int j=1,k=0;
    while (j<=lenp)
    {
        if (k==0 || p[j]==p[k])
            next[++j]=++k;
        else
            k=next[k];
    }
}

void Find()
{
    int i=1,j=1;
    while (i<=lens)
    {
        if (j==0 || s[i]==p[j]) 
        {
            i++,j++;
            if (j==lenp + 1) printf("%d\n",i-lenp);
        }
        else 
            j=next[j];
    }
}

int main()
{
    scanf("%s",s+1);lens=strlen(s+1);
    scanf("%s",p+1);lenp=strlen(p+1);
    GetNext();
    Find();
    for (int i=2;i<=lenp+1;i++) printf("%d ",next[i] - 1);
}