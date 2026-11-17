#include <string.h>

int match(char *haystack, char *needle, int start, int length) {
	for (int i = start; i < start + length; i++) {
		if (haystack[i] != needle[i - start]) {
			return 0;
		}
	}

	return 1;
}

int strStr(char* haystack, char* needle) {
	char firstChar = needle[0];
	int haystackLength = strlen(haystack);
	int needleLength = strlen(needle);

	if (haystackLength == needleLength) {
		if (strcmp(haystack, needle) == 0) {
			return 0;
		} else {
			return -1;
		}
	}

	for (int i = 0; i < haystackLength - (needleLength - 1); i++) {
		if (haystack[i] != firstChar) {
			continue;
		}

		if (!match(haystack, needle, i, needleLength)) {
			continue;
		}

		return i;
	}

	return -1;
}
