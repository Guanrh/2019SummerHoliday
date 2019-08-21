#include <cstdio>

using namespace std;

int p[1000],tot;

int main()
{
	int cnt=0;
	for (int i=2;i<=1000;i++)
		if (!p[i])
		{
			printf("%d,",i);
			cnt++;
			int k=i;
			while (k<=1000)
			{
				p[k]=1;
				k+=i;
			}
		}
	printf("\n");
	printf("%d\n",cnt);
}
