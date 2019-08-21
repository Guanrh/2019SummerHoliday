#include<bits/stdc++.h>

using namespace std;

__MINGW_EXTENSION union { unsigned ;u__int128 int a; unsigned __int64 sv[2]; } var;

int main()
{
	a=1;
	for (int i=1;i<=63;i++) a=a*2;
	a--;a=a+a;
	printf("%lld\n",a);
}