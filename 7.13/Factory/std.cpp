#include <cstdio>
#include <utility>
#include <algorithm>
#define ls (p << 1)
#define rs (ls | 1)
using namespace std;
const int N = 5e5;
int n,c,q,a[N + 5];
int rev,rot;
struct node
{
    int cnt,lc,rc,tag;
} seg[(N << 2) + 10];
inline void push(int p)
{
    if(~seg[p].tag)
    {
        seg[ls].cnt = 1,seg[ls].lc = seg[ls].rc = seg[ls].tag = seg[p].tag;
        seg[rs].cnt = 1,seg[rs].lc = seg[rs].rc = seg[rs].tag = seg[p].tag;
        seg[p].tag = -1;
    }
}
void update(int l,int r,int k,int p,int tl,int tr)
{
    if(l <= tl && tr <= r)
    {
        seg[p].cnt = 1,seg[p].lc = seg[p].rc = seg[p].tag = k;
        return ;
    }
    push(p);
    int mid = tl + tr >> 1;
    l <= mid && (update(l,r,k,ls,tl,mid),1);
    r > mid && (update(l,r,k,rs,mid + 1,tr),1);
    seg[p].cnt = seg[ls].cnt + seg[rs].cnt - (seg[ls].rc == seg[rs].lc);
    seg[p].lc = seg[ls].lc,seg[p].rc = seg[rs].rc;
}
pair< int,pair<int,int> > query(int l,int r,int p,int tl,int tr)
{
    if(l <= tl && tr <= r)
        return make_pair(seg[p].cnt,make_pair(seg[p].lc,seg[p].rc));
    push(p);
    int mid = tl + tr >> 1;
    if(l <= mid && r > mid)
    {
        pair< int,pair<int,int> > left = query(l,r,ls,tl,mid);
        pair< int,pair<int,int> > right = query(l,r,rs,mid + 1,tr);
        return make_pair(left.first + right.first - (left.second.second == right.second.first),make_pair(left.second.first,right.second.second));
    }
    else if(l <= mid)
        return query(l,r,ls,tl,mid);
    else
        return query(l,r,rs,mid + 1,tr);
}
int query(int x,int p,int tl,int tr)
{
    if(tl == tr)
        return seg[p].lc;
    push(p);
    int mid = tl + tr >> 1;
    return x <= mid ? query(x,ls,tl,mid) : query(x,rs,mid + 1,tr);
}
inline int get(int x)
{
    rev && (x = (n - x + 2) % n),x = (x - rot + n) % n,!x && (x = n);
    return x;
}
inline void Rotate(int k)
{
    k %= n,rev ? rot = (rot - k + n) % n : rot = (rot + k) % n;
}
inline void Flip()
{
    rev ^= 1;
}
inline void Swap(int x,int y)
{
    x = get(x),y = get(y);
    int vx = query(x,1,1,n),vy = query(y,1,1,n);
    update(x,x,vy,1,1,n),update(y,y,vx,1,1,n);
}
inline void Paint(int l,int r,int v)
{
    l = get(l),r = get(r),rev && (swap(l,r),1);
    if(l > r)
        update(l,n,v,1,1,n),update(1,r,v,1,1,n);
    else
        update(l,r,v,1,1,n);
}
inline int Count()
{
    int ret = seg[1].cnt;
    ret = max(ret - (seg[1].lc == seg[1].rc),1);
    return ret;
}
inline int CountSegment(int l,int r)
{
    l = get(l),r = get(r),rev && (swap(l,r),1);
    if(l > r)
        return query(l,n,1,1,n).first + query(1,r,1,1,n).first - (seg[1].lc == seg[1].rc);
    else
        return query(l,r,1,1,n).first;
}
int main()
{
    scanf("%d%d",&n,&c);
    int x;
    for(register int i = 1;i <= n;++i)
        scanf("%d",&x),update(i,i,x,1,1,n);
    scanf("%d",&q);
    char op[5];
    int l,r;
    for(;q;--q)
    {
        scanf("%s",op + 1);
        if(op[1] == 'R')
            scanf("%d",&x),Rotate(x);
        else if(op[1] == 'F')
            Flip();
        else if(op[1] == 'S')
            scanf("%d%d",&l,&r),Swap(l,r);
        else if(op[1] == 'P')
            scanf("%d%d%d",&l,&r,&x),Paint(l,r,x);
        else if(op[1] == 'C' && op[2] == 'S')
            scanf("%d%d",&l,&r),printf("%d\n",CountSegment(l,r));
        else
            printf("%d\n",Count());
    }
}