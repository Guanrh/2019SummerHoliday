#define MAXN 200010

int DP[MAXN];
int RMN[MAXN];
int RMX[MAXN];

template <class T>
struct max_queue {
	explicit max_queue(size_t sz) : X(sz), Y(sz), a(0), b(0), va(0), vb(0) {
	}

	void push(const T& v) {
		while(va < vb && X[vb - 1] <= v) vb--;
		X[vb] = v;
		Y[vb++] = b++;
	}

	void pop() {
		va += a++ == Y[va];
	}

	T max() {
		return X[va];
	}

	vector<T> X;
	vector<size_t> Y;
	size_t a, b, va, vb;
};

int main() {
	freopen("photo.in", "r", stdin);
	freopen("photo.out", "w", stdout);

	int N, M; scanf("%d%d", &N, &M);
	fill(RMN, RMN + N + 1, N + 2);
	for(int i = 0; i < M; i++) {
		int lft, rht; scanf("%d%d", &lft, &rht);
		RMN[lft] = min(RMN[lft], rht + 1);
		RMX[lft] = max(RMX[lft], rht + 1);
	}

	/* Precompute the DP query ranges. */
	RMN[N + 1] = N + 2;
	for(int i = N - 1; i >= 0; i--) {
		RMN[i] = min(RMN[i], RMN[i + 1]);
	}
	for(int i = 1; i <= N; i++) {
		RMX[i] = max(RMX[i], RMX[i - 1]);
	}
	DP[N + 1] = 0;

	int j_lo = N;
	int j_hi = N;
	max_queue<int> mq(N);
	for(int i = N; i >= 0; i--) {
		/* Calcualte the DP range interval. */
		int r_least = max(i + 1, RMX[i]);
		int r_most = RMN[i + 1];

		/* Push newly accessible DP values. */
		for(; r_least <= j_lo; j_lo--) {
			mq.push(DP[j_lo]);
		}

		/* Pop no longoer accessible DP values. */
		for(; j_lo < j_hi && r_most <= j_hi; j_hi--) {
			mq.pop();
		}

		/* Compute the maximum reachable substate.  If nothing is reachable the
		 * value for this state is -1.  If we're not at the beginning and it's not
		 * impossible to place a cow here increment by 1. */
		DP[i] = r_least < r_most ? mq.max() : -1;
		if(i && DP[i] != -1) {
			DP[i]++;
		}
	}

	printf("%d\n", DP[0]);
	return 0;
}