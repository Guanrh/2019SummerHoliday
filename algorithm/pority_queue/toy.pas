var
	i,j,n,l:longint;
	c,s,f,q:array[-1..50000]of int64;
	
Procedure init;
begin
	readln(n,l);
	s[0]:=-1;
	For i:=1 to n do begin
	readln(c[i]);
	s[i]:=s[i-1]+c[i]+1;
	end;
end;

Function t(x,y:longint):extended;
begin
	exit((f[x]-f[y]+(s[x]+s[y]+2*l+2)*(s[x]-s[y]))/(2*(s[x]-s[y])));
end;   
Procedure main;
Var st,en:longint;
	t,m:extended;
begin
	f[0]:=0;st:=1;st:=1;en:=1;q[1]:=0;
	For i:=1 to n do 
	begin
		while(st<=en-1)and(t(q[st],q[st+1])<=s[i])do
			inc(st);
		f[i]:=f[q[st]]+sqr(s[i]-s[q[st]]-l-1);
　		while(st<=en-1)and(t(q[en-1],q[en])>=t(q[en],i))do      
			dec(en);
		inc(en);
		q[en]:=i;
	end;
	writeln(f[n]);
end;
	
begin
	init;
	main;
end.
