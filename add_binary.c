#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
	int lenA = strlen(a);
	int lenB = strlen(b);

	int lenLarger;
	int lenSmaller;
	int carry = 0;
	
	char *larger;
	char *smaller;

	if (lenA > lenB) {
		lenLarger = lenA;
		lenSmaller = lenB;
		larger = a;
		smaller = b;
	} else {
		lenLarger = lenB;
		lenSmaller = lenA;
		larger = b;
		smaller = a;
	}

    char *result = malloc(lenLarger + 2);

	result[0] = 'a';
    result[lenLarger + 1] = '\0';

	for (int i = 0; i < lenLarger; i++) {
		int sum = carry;
        int smallIndex = lenSmaller - i - 1;

		carry = 0;
		sum += (larger[lenLarger - i - 1] == '1');
        
        if (smallIndex >= 0) {
		    sum += (smaller[lenSmaller - i - 1] == '1');
        }

		switch (sum) {
			case 0:
				result[lenLarger - i] = '0';
				break;
			case 1:
				result[lenLarger - i] = '1';
				break;
			case 2:
				result[lenLarger - i] = '0';
                carry = 1;
				break;
			case 3:
				result[lenLarger - i] = '1';
				carry = 1;
				break;
		}
	}

    if (carry) {
        result[0] = '1';
    }

	if (result[0] == 'a') {
		for (int i = 0; i < lenLarger; i++) {
			result[i] = result[i + 1];
		}

		result[lenLarger] = '\0';
	}

	return result;
}
