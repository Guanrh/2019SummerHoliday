var 
	i,j:longint;
begin
	assign(output,'ratio.in');rewrite(output);
	randomize;
	writeln('15 8');
	for i:=1 to 15 do write(random(100)+3,' ');
	writeln;
	for i:=1 to 15 do
	begin
		for j:=1 to 15 do
			write(random(100)+3,' ');
		writeln;
	end;
end.