long long sum(int *a, int n) {
	long long ret = 0;
	for (int i=0; i<n; i++)
		ret += a[i];
	return ret;
}