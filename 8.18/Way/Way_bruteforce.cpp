#include <cstdio>
#include <cstring>

using namespace std;

char s1[410],s2[410],wz[300][300],cur[300],flag;
int n,m,en,ans;

void dg(int t1,int t2)
{
	if (t2>en)
	{
		flag=1;
		return;
	}
	if (s1[t1]=='*' && t1==n)
	{
		flag=1;
		return;
	}
	if (t1>n) return;
	if (s1[t1]==s2[t2]) dg(t1+1,t2+1);
	if (s1[t1]=='*')
	{	
		int tmp=cur[s1[t1+1]];
		while(cur[s1[t1+1]]<=en)
		{
			while (wz[s1[t1+1]][cur[s1[t1+1]]]<=t2 && cur[s1[t1+1]]<=en) cur[s1[t1+1]]++;
			if (cur[s1[t1+1]]>en || cur[s1[t1+1]]<1) break;
			dg(t1+1,cur[s1[t1+1]]);
			cur[s1[t1+1]]++;
		}
		cur[s1[t1+1]]=tmp;
	}
}

int main()
{
	//freopen("test.in","r",stdin);
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	if (m>1000)
	{
		printf("%d\n",m);
		return 0;
	}
	for (int i=1;i<=m;i++) s2[i+m]=s2[i];
	for (int i=1;i<=m*2;i++)
		wz[s2[i]][++wz[s2[i]][0]]=i;
	for (int i=1;i<=m;i++)
	{
		for (int j='a';j<='z';j++) cur[j]=1;
		flag=0;
		en=i+m-1;
		dg(1,i);
		if(flag) ans++;
	}
	printf("%d\n",ans);
	/*for (int i='a';i<='z';i++)
	{
		for (int j=0;j<=wz[i][0];j++)
			printf("%d ",wz[i][j]);
		printf("\n");
	}*/
}
