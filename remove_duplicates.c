int removeDuplicates(int* nums, int numsSize) {
	int k = 0;
	int smallest = nums[0];
	int sorted[201] = {};

	for (int i = 0; i < 201; i++) {
		sorted[i] = -101;
	}

	for (int i = 0; i < numsSize; i++) {
		int n = nums[i];
		
		if (sorted[n + 100] == n) {
			continue;
		}

		sorted[n + 100] = n;
		k++;
	}
	
	int sortedQuantity = 0;

	for (int i = smallest + 100; i < 201; i++) {
		if (sortedQuantity == k) {
			break;
		}

		if (sorted[i] == -101) {
			continue;
		}
		
		nums[sortedQuantity] = sorted[i];
		sortedQuantity++;
	}

	return k;
}
