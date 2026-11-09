#include <math.h>

typedef int bool;

int reverseNumber(int x) {
	int reverse = 0;
	int remainder = 0;
	int count = 0;
	
	int stack[10];

	while (remainder != x) {
		long power = pow(10, count);
		remainder = x % (power * 10); 
		stack[count] = remainder / power;

		count++;
	}

	for (int i = 0; i < count; i++) {
		reverse += stack[i] * (long)pow(10, count - i - 1);
	}

	return reverse;
}

bool isPalindrome(int x) {
	if (x < 0) {
		return 0;
	}

	return x == reverseNumber(x);
}
