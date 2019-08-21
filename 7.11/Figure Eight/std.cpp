#include<bits/stdc++.h>
using namespace std;

#define NMAX 200

int n;
bool grid[NMAX][NMAX];
int rowcmp[NMAX][NMAX];

short g[NMAX][NMAX][NMAX];
short f[NMAX][NMAX][NMAX];

short h[NMAX][NMAX][NMAX];

int main() {
	freopen("8.in","r",stdin);
	freopen("std.out","w",stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			do { c = fgetc(stdin); } while (c != '.' && c != '*');
			grid[i][j] = (c == '.');
		}
	}

	int rcmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!grid[i][j]) {
				rcmp++;
			}
			rowcmp[i][j] = rcmp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j1 = 0; j1 < n; j1++) {
			bool okay = grid[i][j1];
			for (int j2 = j1 + 1; j2 < n; j2++) 
			{
				okay = okay && grid[i][j2];
				if (grid[i][j1] && grid[i][j2]) 
				{
					if (i > 0 && f[i-1][j1][j2] != -1) 
					{
						f[i][j1][j2] = 1 + f[i-1][j1][j2];
					} 
					else 
					{
						f[i][j1][j2] = okay ? 0 : -1;
					}
				} 
				else {
					f[i][j1][j2] = -1;
				}
			}
		}
	}

	for (int i = n-1; i >= 0; i--) {
		for (int j1 = 0; j1 < n; j1++) {
			bool okay = grid[i][j1];
			for (int j2 = j1 + 1; j2 < n; j2++) {
				okay = okay && grid[i][j2];
				if (grid[i][j1] && grid[i][j2]) {
					if (i < n-1 && g[i+1][j1][j2] != -1) {
						g[i][j1][j2] = 1 + g[i+1][j1][j2];
					} else {
						g[i][j1][j2] = okay ? 0 : -1;
					}
				} else {
					g[i][j1][j2] = -1;
				}
			}
		}
	}

	long long ans = 0;

	for (int i = 0; i < n; i++) {
		for (int l = 1; l < n; l++) {
			for (int j1 = 0; j1 + l < n; j1++) 
			{
				int j2 = j1 + l;
				if (grid[i][j1] && grid[i][j2]) 
				{
					h[i][j1][j2] = (f[i][j1][j2] < 2 ? -1 :(f[i][j1][j2] - 1) * (j2 - j1 - 1));
					if (l > 1) 
					{
						h[i][j1][j2] = max(h[i][j1][j2],max(h[i][j1+1][j2], h[i][j1][j2-1]));
					}
				} 
				else 
				{
					h[i][j1][j2] = -1;
				}
				printf("%d\n",h[i][j1][j2]);

				if (rowcmp[i][j1] == rowcmp[i][j2] && h[i][j1][j2] != -1 &&g[i][j1][j2] >= 2) {
					ans = max(ans, (long long) h[i][j1][j2] * (long long)(g[i][j1][j2] - 1) * (long long) (j2 - j1 - 1));
				}
			}
		}
	}

	printf("%lld\n", ans);
}