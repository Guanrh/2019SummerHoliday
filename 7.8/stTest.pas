var 
	i:char;
	s:array[1..1000000] of string;
	tot,j:longint;
procedure dg(t:Longint;st:string);
begin
	if t>4 then
	begin
		inc(tot);
		s[tot]:=st;
		exit;
	end;
	for i:='a' to 'z' do 
		dg(t+1,st+i);
end;
begin
	dg(1,'');
	for j:=1 to tot do writeln(s[j]);
	writeln(tot);
end.