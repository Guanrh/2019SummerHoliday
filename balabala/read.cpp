inline int read()
{
	int x=0;char c=getchar();
	while(c<'0' || c>'9')c=getchar();
	while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x;
}