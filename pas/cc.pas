const
        maxn=40000;
        maxm=40000;
var
        n,m:longint;
        maxlen:longint;
        i,j,l,k:longint;
        p,f:array[-1..maxn] of longint;
        last:array[0..maxm] of longint;
function min(a,b:longint):longint;
begin
        if(a<b)then exit(a) else exit(b);
end;
procedure init;
var
        i:longint;
begin
        readln(n,m);
        maxlen:=trunc(sqrt(n))+1;
end;
procedure work;
var
        x:longint;
        i,j:longint;
begin
        f[-1]:=100000000;
        readln(x);
        last[x]:=1;
        f[1]:=1;p[1]:=1;
        fillchar(last,sizeof(last),255);
        for i:=2 to n do
        begin
                readln(x);
                p[0]:=i;
                for j:=maxlen downto 1 do
                        if last[x]<p[j] then p[j]:=p[j-1];

                f[i]:=i;
                for j:=1 to maxlen do
                        f[i]:=min(f[i],f[p[j]-1]+j*j);

                last[x]:=i;
        end;
end;
procedure print;
begin
        writeln(f[n]);
end;
begin
        assign(input,'cleanup.in');reset(input);assign(output,'cleanup.out');rewrite(output);
        init;
        work;
        print;
        close(input);close(output);
end.
---------------------
作者：FarmerJohnLYH
来源：CSDN
原文：https://blog.csdn.net/FarmerJohnOfZS/article/details/51637067
版权声明：本文为博主原创文章，转载请附上博文链接！
