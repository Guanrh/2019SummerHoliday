var
        ans:int64;
        i,j,n,m,d,t,h,o,p:longint;
        x,y,z,a,b,s:array[0..1000000] of longint;
        f:array[1..1000000,1..2] of longint;
procedure kp(l,r:longint);
var
        i,j,m,h:longint;
begin
        i:=l;
        j:=r;
        m:=x[(l+r) div 2];
        repeat
                while x[i]<m do
                        inc(i);
                while x[j]>m do
                        dec(j);
                if i<=j then
                begin
                        h:=x[i];
                        x[i]:=x[j];
                        x[j]:=h;
                        h:=y[i];
                        y[i]:=y[j];
                        y[j]:=h;
                        h:=z[i];
                        z[i]:=z[j];
                        z[j]:=h;
                        inc(i);
                        dec(j);
                end;
        until i>j;
        if l<j then
                kp(l,j);
        if i<r then
                kp(i,r);
end;
begin
        read(n,m);
        for i:=1 to m do
        begin
                read(x[i],y[i],z[i]);
                x[m+i]:=y[i];
                y[m+i]:=x[i];
                z[m+i]:=z[i];
        end;
        kp(1,2*m);
        for i:=1 to 2*m do
                if x[i]<>x[i-1] then
                        a[x[i]]:=i;
        d:=maxlongint;
        ans:=1;
        t:=1;
        h:=0;
        f[1,1]:=1;
        f[1,2]:=0;
        for i:=2 to n do
                b[i]:=d;
        repeat
                inc(h);
                o:=f[h,1];
                p:=f[h,2];
                i:=a[o];
                while x[i]=o do
                begin
                        if p+z[i]=b[y[i]] then
                                inc(s[y[i]]);
                        if p+z[i]<b[y[i]] then
                        begin
                                b[y[i]]:=p+z[i];
                                s[y[i]]:=1;
                                inc(t);
                                f[t,1]:=y[i];
                                f[t,2]:=p+z[i];
                        end;
                        inc(i);
                end;
        until t=h;
        for i:=2 to n do
                ans:=ans*s[i] mod d;
        for i:=2 to n do writeln(s[i]);
        write(ans);
end.