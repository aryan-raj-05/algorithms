package divide_and_conquer;

/*
    Inversion: For a given input of array A, let i, j be two numbers 
    such that i < j, then an inversion is when A[i] > A[j]

    In a sorted array the number of inversions in 0, the minimum number
    of inversions.

    And the maximum number of inversions an array of length n can have
    is nC2 = n(n-1)/2. Which will happen when the array is in descending 
    order
*/
public class CountInversions {
    public static long bruteForce(int[] nums) {
        long count = 0L;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] > nums[j]) count++;
            }
        }
        return count;
    }

    public static long optimized(int[] nums) {
        return auxCount(nums, 0, nums.length - 1);
    }

    private static long auxCount(int[] nums, int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        long leftInv = auxCount(nums, l, mid);
        long rightInv = auxCount(nums, mid + 1, r);
        long splitInv = countSplitInvAndMerge(nums, l, mid, r);
        return leftInv + splitInv + rightInv;
    }

    private static long countSplitInvAndMerge(int[] nums, int l, int mid, int r) {
        int leftSize = mid - l + 1; // mid included here
        int rightSize = r - mid;

        int[] left = new int[leftSize];
        int[] right = new int[rightSize];

        for (int i = 0; i < leftSize; i++)
            left[i] = nums[i + l];
        for (int i = 0; i < rightSize; i++)
            right[i] = nums[i + mid + 1];

        long invCount = 0L;
        int i = 0, j = 0, k = l;

        while (i < leftSize && j < rightSize) {
            if (left[i] > right[j]) {
                nums[k++] = right[j++];
                // since every number after i will be greater that right
                // due to both left and right being sorted arrays
                // for element i there would be (leftSize - i) inversions
                invCount += (long) (leftSize - i);
            } else {
                nums[k++] = left[i++];
            }
        }

        while (i < leftSize) nums[k++] = left[i++];
        while (j < rightSize) nums[k++] = right[j++];

        return invCount;
    }
}
