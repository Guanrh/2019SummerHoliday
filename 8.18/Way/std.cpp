#include<cstdio>
#include<iostream>
#include<cstring>;
#include<algorithm>
using namespace std;
unsigned long long k[110],hash[110],g[110],temp;
char a[110],b[200010];
int f[200010][52],e[110],len1,len2,l,w,ans,cd;
int main()
{
	scanf("%s",a+1);
	len1=strlen(a+1);
	hash[0]=1;
	for (int i=1;i<=len1;i++) hash[i]=hash[i-1]*13331;
	for (int i=1;i<=len1;i++)
		if (a[i]=='*')
		{
			if (i>1&&a[i-1]!='*') 
			{
				k[++l]=temp; //第l段的哈希值 
				e[l]=cd; //第l段的长度 
				temp=cd=0; //初始化，准备计算下一段的数值 
			}
		}
		else 
		{
			temp+=(a[i]-'a'+1)*hash[cd++]; //正在计算当前这段的哈希值 
		}
	if (a[len1]!='*') //可能会漏掉最后一段，现在补上 
	{
		k[++l]=temp;
		e[l]=cd;
		temp=cd=0;
	}
	scanf("%s",b+1);
	len2=strlen(b+1);
	if (!l) //特判一下全是"*"的情况 
	{
		printf("%d",len2);
		return 0;
	}
	for (int i=1;i<=len2;i++) b[len2+i]=b[i]; //复制一遍字符串,构成循环同构串 
	for (int i=1;i<=l;i++) f[len2*2+1][i]=f[len2*2+2][i]=len2*2+1;//超出边界
	for (int i=len2*2;i;i--) //枚举B串中其他子串的起始位置 （与A串匹配）
	{
		memset(g,-1,sizeof(g));
		g[0]=0; //枚举其他相同的哈希值,g[i]表示当前这一层枚举到的长度为i的哈希值 
		for (int j=0;j<len1;j++) //保证枚举每一种情况 
			if (i+j<=2*len2) g[j+1]=g[j]+(b[i+j]-'a'+1)*hash[j]; //正在计算当前哈希值
		for (int j=1;j<=l;j++) //枚举a串中的每一段 
		{
			f[i][j]=f[i+1][j]; //因为在后缀中查找,且i的后缀包含有i + 1的后缀，
							  //如果i + 1的后缀有相同子串,那么i的后缀中一定也会有,以此转移
			if (g[e[j]]==k[j]) f[i][j]=i+e[j]-1; //这里显然可以看出f数组存的是相同的串的结尾位置
												//此处可以直接转移方程的原因:i是从后往前枚举的,
											   //所以后面枚举到的串的起始位置，一定在之前所有枚举
											  // 到的串的前面 
		}
	}
	int j,p;
	for (int i=1;i<=len2;i++) //枚举每一个b的循环重构串的起始位置 
	{
		bool flag=true;
		for (j=len1;j && a[j]!='*';j--) //先处理掉a串末尾不是"*"的那一段,如发现"*"即刻退出 
			if(a[j]!=b[i+len2-1-(len1-j)]) //逐位匹配 
			{
				flag=false;
				break;
			}
		if (flag==false||j==0&&len1!=len2) continue;
		for (p=1,w=i;p<=l-(a[len1]!='*');p++) //枚举每一段 
		{
			if (p==1&&a[1]!='*'&&f[i][1]+1!=i+e[1]) break; //再处理掉开头不是"*"的这一段 
			w=f[w][p]+1; //w表示当前匹配到b串的第几位 
		}
		if (p>l-(a[len1]!='*')&&w<=i+len2-(len1-j)) ans++; //末尾不是"*"的那一段在前面已经处理完了 
	}	
	printf("%d",ans); //输出 
	return 0;
} //大功告成