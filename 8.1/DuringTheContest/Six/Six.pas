var
	mp:array[-1000..1000,-1000..1000] of integer;
	a:array[1..110000] of longint;
	bz:array[0..5] of Boolean;
	cnt:array[1..5] of longint;
	i,j,n,tot,cas:longint;
function choose(x,y:longint):longint;
var i,mn,mncnt:longint;
begin
	bz[1]:=true;bz[2]:=true;bz[3]:=true;
	bz[4]:=true;bz[5]:=true;
	bz[mp[x+1][y-1]]:=false;
	bz[mp[x-1][y+1]]:=false;
	bz[mp[x+1][y+1]]:=false;
	bz[mp[x-1][y-1]]:=false;
	bz[mp[x][y+2]]:=false;
	bz[mp[x][y-2]]:=false;
	mncnt:=111111111;
	for i:=1 to 5 do
		if (bz[i]) then
			if (cnt[i]<mncnt) then
			begin
				mncnt:=cnt[i];
				mn:=i;
			end;
	exit(mn);
end;
procedure dfs(sx,sy,tx,ty:longint);
var xx,yy:longint;
begin
	if (tot>10000) then exit;
	xx:=sx;yy:=sy;

	inc(tot);
	mp[xx][yy]:=choose(xx,yy);
	a[tot]:=mp[xx][yy];
	inc(cnt[a[tot]]);

	while (mp[xx-1][yy+1]<>0) do
	begin
		yy:=yy+2;
		inc(tot);
		mp[xx][yy]:=choose(xx,yy);
		a[tot]:=mp[xx][yy];
		inc(cnt[a[tot]]);
	end;
	while (mp[xx-1][yy-1]<>0) do
	begin
		xx:=xx-1;
		yy:=yy+1;
		inc(tot);
		mp[xx][yy]:=choose(xx,yy);
		a[tot]:=mp[xx][yy];
		inc(cnt[a[tot]]);
	end;
	while (mp[xx][yy-2]<>0) do
	begin
		xx:=xx-1;
		yy:=yy-1;
		inc(tot);
		mp[xx][yy]:=choose(xx,yy);
		a[tot]:=mp[xx][yy];
		inc(cnt[a[tot]]);
	end;
	while (mp[xx+1][yy-1]<>0) do
	begin
		yy:=yy-2;
		inc(tot);
		mp[xx][yy]:=choose(xx,yy);
		a[tot]:=mp[xx][yy];
		inc(cnt[a[tot]]);
	end;
	while (mp[xx+1][yy+1]<>0) do
	begin
		xx:=xx+1;
		yy:=yy-1;
		inc(tot);
		mp[xx][yy]:=choose(xx,yy);
		a[tot]:=mp[xx][yy];
		inc(cnt[a[tot]]);
	end;
	while (mp[xx][yy+2]<>0) do
	begin
		xx:=xx+1;
		yy:=yy+1;
		inc(tot);
		mp[xx][yy]:=choose(xx,yy);
		a[tot]:=mp[xx][yy];
		inc(cnt[a[tot]]);
		if (xx=tx)and(yy=ty) then break;
	end;
	dfs(xx+1,yy+1,xx+1,yy-1);
end;
begin
	//assign(input,'six.in');reset(input);
	//assign(output,'six.out');rewrite(output);
	tot:=1;
        cnt[1]:=1;
	mp[0,0]:=1;
	a[1]:=1;
	dfs(1,1,1,-1);
	read(cas);
	for i:=1 to cas do
	begin
		read(n);
		writeln(a[n]);
	end;
end.
