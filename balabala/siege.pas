uses math;
type arr=array[1..2,1..2] of int64;
const mo=10000;
var
	a,b,c:arr;
	i,j,k,cnt:longint;
	n:int64;
function multi(a,b:arr):arr;
var
	i,j,k:longint;
begin
	multi[1,1]:=0;
	multi[1,2]:=0;
	multi[2,1]:=0;
	multi[2,2]:=0;
	for i:=1 to 2 do
		for j:=1 to 2 do
			for k:=1 to 2 do
				multi[i][k]:=(multi[i,k]+a[i,j]*b[j,k])mod mo;
	inc(cnt);
	exit(multi);
end;
function get(n:int64):arr;
var
	temp:arr;
begin
	if n=1 then exit(a);
	if n mod 2=1 then exit(multi(get(n-1),a));
	if n mod 2=0 then
	begin
		temp:=get(n div 2);
		exit(multi(temp,temp));
	end;
end;
begin
	//assign(input,'siege.in');reset(input);
	//assign(output,'siege.out');rewrite(output);
	read(n);
	a[1][1]:=0;
	a[1][2]:=1;
	a[2][1]:=1;
	a[2][2]:=1;
	if n=1 then
	begin
		writeln(2);
		halt;
	end;
	if n=2 then
	begin
		writeln(3);
		halt;
	end;
	b:=get(n-1);
	a[1,1]:=2; a[1,2]:=3;
	for i:=1 to 1 do
		for j:=1 to 2 do
			for k:=1 to 2 do
				c[i,j]:=(c[i,j]+a[i,k]*b[k,j])mod mo;
	//writeln(cnt);
	writeln(c[1,1]);
end.
