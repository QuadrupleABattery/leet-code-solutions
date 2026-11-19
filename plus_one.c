#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
	int carry = 1;  
	int *value = malloc(sizeof(int) * (digitsSize + 1));

	for (int i = digitsSize; i > 0; i--) {
		int curDigit = digits[i - 1];

		if (!carry) {
			value[i] = curDigit; continue;
		}
		
		int newDigit = curDigit + 1;

		if (newDigit == 10) {
			value[i] = 0;
		} else {
			value[i] = newDigit;
			carry = 0;
		}
	}

	if (!carry) {
		for (int i = 1; i < digitsSize + 1; i++) {
			value[i - 1] = value[i];
		}
		*returnSize = digitsSize;
	} else {
		*returnSize = digitsSize + 1;
		value[0] = 1;
	}

	return value;
}
