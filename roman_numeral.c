#include <string.h>

int toValue(char numeral) {
	switch (numeral) {
		case 'I':
			return 1;
		case 'V':
			return 5;
		case 'X':
			return 10;
		case 'L':
			return 50;
		case 'C':
			return 100;
		case 'D':
			return 500;
		case 'M':
			return 1000;
	}

	return 0;
}

int digraph_value(char first, char second, char target, char target2) {
	if (second == target || second == target2) {
		return toValue(second) - toValue(first);
	} else {
		return 0;
	}	
}

int process_numerals(char first, char second) {
	switch (first) {
		case 'I':
			return digraph_value(first, second, 'V', 'X');	

		case 'X':
			return digraph_value(first, second, 'L', 'C');	
		case 'C':
			return digraph_value(first, second, 'D', 'M');	
	}

	return 0;
}

int romanToInt(char* s) {
 	int value = 0;   
	int strLength = strlen(s);
	int skip = 0;

	for (int i = 0; i < strLength; i++) {
		char currentNumeral = s[i];
		
		if (skip) {
			skip = 0; continue;
		}

		skip = 0;

		if (i == strLength - 1) {
			value += toValue(currentNumeral); continue;
		}
		
		int numeralValue = process_numerals(currentNumeral, s[i + 1]);

		if (numeralValue == 0) {
			value += toValue(currentNumeral);
		} else {
			value += numeralValue;
			skip = 1;
		}
	}

	return value;
}
