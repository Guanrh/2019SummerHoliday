#include<bits/stdc++.h>

using namespace std;

int cnt,k,r;

int main()
{
	for (k=6;cnt<10000;k+=6)
	{
		cnt+=k;
		r++;
	}
	printf("%d %d\n",r,cnt);
}