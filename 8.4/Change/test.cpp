#include <cstdio>
#include <cstring>

using namespace std;

int ans;



int main()
{
	for (int i=1;i<=1000000;i++) ans+=(1000000/i)*(1000000/(i*(i+1)))+1;
	printf("%d\n",ans);
}