// Idea was to manually check every number less than x until n * n > x
// This would be really slow though so optimization strategy became find some function f(x) where f(x) < sqrt(x)
// We need to minimize sqrt(x) - f(x) since that is the number of checks we need to find floor(sqrt(x))
// No built in exponentiation is allowed but bit shifting can simulate it since x >> n = x * 2^n
// Messed around in desmos and found that n * (1/2)^log2(n) == sqrt(x)
// You cannot shift non integer bits so we ceil it for f(n) = n * (1/2)^ceil(log2(n))
// NVM LOG IS BANNED AS WELL
// Other idea was something similar to other "fast" algorithms where it's divide and conquer so recursively apply the same function on multiple smaller values of x
// This should cut down on the exponential growth
// Messed around in desmos a bit more and the series Σ((-1) ^ (n + 1)) * f(x / n) approaches some value near sqrt(x), if n is odd it'll be greater if n is even it'll be lower *except n = 2 because IDK
// NVM x2 it's way slower than the naive approace
// Been at this for an hour gonna just call it quits
// Looked at existing solutions and I approached this from the complete wrong direction haven't I
// Instead of trying to figure out how to find number quick I tried to reduce the amount of numbers you need to look through
// Binary search should have been obvious..


int mySqrt(int x) {
	if (x == 0) {
		return 0;
	}

	for (long i = 0; i < x; i++) {
		if (i * i <= x) {
			continue;
		}

		return i - 1;
	}

	return 1;
}
