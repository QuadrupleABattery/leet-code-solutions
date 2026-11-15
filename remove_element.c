void swap(int *nums, int i1, int i2) {
	int buffer = nums[i1];

	nums[i1] = nums[i2];
	nums[i2] = buffer;
}

int findFreeSpace(int *nums, int start, int exclude) {
	for (int i = start; i > 0; i--) {
		if (nums[i] == exclude) {
			continue;
		}

		return i;
	}

	return 0;
}

int removeElement(int* nums, int numsSize, int val) {
	if (numsSize == 0) {
		return 0;
	}

	if (numsSize == 1) {
		return (nums[0] != val);
	}

	int k = 0;
 	int back = numsSize - 1;   
	
	for (int i = 0; i < numsSize; i++) {
		int currentNum = nums[i];

		if (currentNum != val) {
			k++;
			continue;
		}

		if (i == back) {
			break;
		}

		int freeSpace = findFreeSpace(nums, back, val);
		
		if (freeSpace <= i) {
			break;
		}
		
		swap(nums, i, freeSpace);
		
		k++;
		back--;
	}

	return k;
}
