#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;

struct stack {
	char *data;
	size_t size;
	size_t capacity;
};

void push(struct stack *stack, char element) {
	if (stack -> size >= stack -> capacity - 1) {
		return;
	}

	stack -> data[stack -> size] = element;
	stack -> size++;
}

char pop(struct stack *stack) {
	if (stack -> size <= 0) {
		return '-';
	}

	char element = stack -> data[stack -> size - 1];
	stack -> size--;

	return element;
}

bool isOpen(char c) {
	return c == '(' || c == '[' || c == '{';
}

bool match(char c1, char c2) {
	bool matching = 0;

	switch (c1) {
		case ')':
			matching = c2 == '('; break;
		case ']':
			matching = c2 == '['; break;
		case '}':
			matching = c2 == '{'; break;
	}

	return matching;
}

bool isValid(char* s) {
	int stringSize = strlen(s);

	if (stringSize % 2 == 1) {
		return 0;
	}
	
	int matches = 0;
	char _data[stringSize + 1];

	struct stack stack = {
		.data = _data,
		.size = 0,
		.capacity = stringSize + 1,
	};

	for (int i = 0; i < stringSize; i++) {
		char current = s[i];
		
		if (isOpen(current)) {
			push(&stack, current); continue;
		}

		if (!match(current, pop(&stack))) {
			return 0;
		}
		
		matches += 1;
	}

	return matches == stringSize / 2;
}
