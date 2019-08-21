const
px:array[1..4]of longint=(0,0,1,-1);
py:array[1..4]of longint=(1,-1,0,0);
var
i,j,l,r,c,v,x,y:longint;
a:array[0..105,0..105]of longint;
s:array[0..1000005,1..2]of longint;
t:array[0..1000005]of double;
f:array[0..105,0..105]of double;
bz:array[0..105,0..105]of boolean;
w:array[-50..50]of double;
ans:double;
function check(x,y:longint):boolean;
begin
    if (x=0)or(y=0)or(x>r)or(y>c) then exit(true);
    exit(false);
end;

procedure bfs;
begin
    f[1,1]:=0;
    s[1,1]:=1;s[1,2]:=1;
    t[1]:=v;
    i:=0;j:=1;
    while i<>j do
    begin
        i:=(i mod 1000001)+1;
        for l:=1 to 4 do
        begin
            x:=s[i,1]+px[l];
            y:=s[i,2]+py[l];
            if check(x,y) then continue;
            if 1/t[i]+f[s[i,1],s[i,2]]<f[x,y] then
            begin
                f[x,y]:=1/t[i]+f[s[i,1],s[i,2]];
                ans:=t[i]*(w[a[s[i,1],s[i,2]]-a[x,y]]);
                j:=(j mod 1000001)+1;
                s[j,1]:=x;
                s[j,2]:=y;
                t[j]:=ans;
            end;
        end;
    end;
end;

begin
    assign(input,'cowski.in');
    reset(input);
    assign(output,'cowski.out');
    rewrite(output);
    readln(v,r,c);
    for i:=1 to r do
    begin
        for j:=1 to c do
        read(a[i,j]);
        readln;
    end;
    w[0]:=1;
    for i:=-1 downto -50 do
    w[i]:=w[i+1]/2;
    for i:=1 to 50 do
    w[i]:=w[i-1]*2;
    fillchar(f,sizeof(f),127);
    bfs;
    write(abs((f[r,c]-5.51*1e-11)):0:2);
    close(input);
    close(output);
end.
---------------------
作者：SSLGZ_yyc
来源：CSDN
原文：https://blog.csdn.net/sslgz_yyc/article/details/79678094
版权声明：本文为博主原创文章，转载请附上博文链接！
