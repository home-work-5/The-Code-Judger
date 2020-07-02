# include <stdio.h>


long long int Variance(int n, int start, int scale, int bais, int mod) {

	long long int a = start;
	long long int sum = 0;
	double someOfPower2 = 0;
	double avrage = 0;
	double variance = 0;

	for (int i = 0; i < n; i++) {
		a = (a * scale + bais) % mod;
		//printf("%d\t", a);
		sum += a;
		////someOfPower2 += (double)a * a;
	}
	avrage = (double)sum / n;

	a = start;
	for (int i = 0; i < n; i++) {
		a = (a * scale + bais) % mod;
		someOfPower2 += (a - avrage) * (a - avrage);

	}


	
	//variance = (((someOfPower2) / n) - avrage * avrage);
	variance = (((someOfPower2) / (double)(n)));
	//printf("%f\n", variance);

	long long int var = (long long int)variance;
	//printf("%lld\n", var);

	return var;


}




int main() {
	int testCases = 0;
	long long int variance = 0;
	scanf("%d", &testCases);
	int n = 0, start = 0, scale = 0, bais = 0, mod = 0;
	for (int i = 0; i < testCases; i++) {
		scanf("%d %d %d %d %d", &n, &start, &scale, &bais, &mod);
		//printf("%d %d %d %d %d", n, start, scale, bais, mod);
		variance = Variance(n, start, scale, bais, mod);
		printf("Case Study #%d: %lld\n", i + 1, variance);
	}

	return 0;
}