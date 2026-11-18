int searchInsert(int* nums, int numsSize, int target) {
	int previous;

 	for (int i = 0; i < numsSize; i++) {
		int value = nums[i];

		if (value == target) {
			return i;
		}

		previous = value;

	}   

	return -1;
}
