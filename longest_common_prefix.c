#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
	if (strsSize == 0) {
		return "";
	}

	if (strsSize == 1) {
		return strs[0];
	}

	char *prefix = strs[0];
	int prefixSize = strlen(prefix);

	for (int i = 1; i < strsSize; i++) {
		char *curStr = strs[i];
		int newPrefixSize = 0;

		for (int j = 0; j < prefixSize; j++) {
			if (prefix[j] != curStr[j]) {
				break;
			}
			newPrefixSize = j + 1;
		}

		if (newPrefixSize == 0) {
			return "";
		}

		prefixSize = newPrefixSize;
	}
	
	prefix[prefixSize] = 0;

	return prefix;
}
