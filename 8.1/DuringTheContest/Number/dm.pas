var 
	i,j:longint;
begin
	assign(output,'test.out');rewrite(output);
	writeln(10);
	for i:=1 to 10 do 
	begin
		writeln('999 1000');
		for j:=1 to 1000 do write('23647 ');
		writeln;
	end;
end.