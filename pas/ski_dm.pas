var i,j,n:longint;

begin
        randomize;
        assign(output,'cowskii.in');rewrite(output);
        read(n);
        writeln('256 ',n,' ',n);
        for i:=1 to n do
        begin
                for j:=1 to n do
                        write(random(50)-25,' ');
                writeln;
        end;
end.