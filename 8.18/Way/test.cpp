#include <cstdio>
#include <cstring>

using namespace std;

int a[10];

int main()
{
    memset(a,-1,sizeof a);
    printf("%d",a[3]);
}