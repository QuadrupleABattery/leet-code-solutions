int searchInsert(int* nums, int numsSize, int target) {
	int previous = -10001;

	for (int i = 0; i < numsSize; i++) {
		int value = nums[i];

		if (value == target) {
			return i;
		}

		if (target > previous && target < value) {
			return i;
		}

		previous = value;

	}   

	return numsSize;
}
