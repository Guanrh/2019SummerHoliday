const mo = 1000000007;
type
    ar = array[0..100,0..100] of int64;
var
    a,b,c:ar;
    n,m:int64;
    i,j:longint;

procedure mul(a,b:ar);
var
    i,j,k:longint;

begin
    fillchar(c,sizeof(c),0);
    for i := 1 to n do
        for j := 1 to n do
            for k := 1 to n do
                c[i][j] := (c[i][j] + a[i][k] * b[k][j]) mod mo;
end;

procedure update(var a:ar;b:ar);
var
    i,j:longint;

begin
    for i := 1 to n do
        for j := 1 to n do
            a[i][j] := b[i][j];
end;

procedure pow(p:int64);
var
    i,j,k:longint;

begin
    if p = 0 then
    begin
        for i := 1 to n do a[i][i] := 1;
        exit;
    end;
    pow(p >> 1);
    mul(a,a);
    update(a,c);
    if p mod 2 = 1 then
    begin
        mul(a,b);
        update(a,c);
    end;
end;

begin
    readln(n,m);
    for i := 1 to n do
    begin
        for j := 1 to n do
            read(b[i][j]);
        readln;
    end;
    pow(m);
    for i := 1 to n do
    begin
        for j := 1 to n do write(a[i][j],' ');
        writeln;
    end;
end.