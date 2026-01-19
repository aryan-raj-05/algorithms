package searching;

import java.util.Arrays;

/*

Selection Problem : for an input of an array of n elements, find
                    the ith order statistic, that is ith smallest 
                    element in the array

Two Ways of Solving the problem:
    1. Sort the Array and then return array[i]
    2. Similar to quicksort, by choosing a random pivot
        to partition the array and throw out the undesired half

*/
public class Select {
    // Reduction to sorting, Time Complexity: O(n logn)
    public int bruteSelect(int[] nums, int ord) { // ord is 1-indexed
        Arrays.sort(nums);
        return nums[ord - 1];
    }

    // Quick Select Algorithms, Time Complexity: O(n)
    public int quickSelect(int[] nums, int ord) {
        if (ord < 1 || ord > nums.length)
            throw new IllegalArgumentException();
        int[] auxNums = nums.clone();
        return helperRandomSelect(auxNums, ord, 0, nums.length - 1);
    }

    private int helperRandomSelect(int[] nums, int ord, int lo, int hi) {
        if (lo == hi) return nums[lo];

        int pivotIdx = partition(nums, lo, hi);
        int rank = pivotIdx - lo + 1;

        if (rank == ord)
            return nums[pivotIdx];
        else if (rank > ord)
            return helperRandomSelect(nums, ord, lo, pivotIdx - 1);
        else
            return helperRandomSelect(nums, ord - rank, pivotIdx + 1, hi);
    }

    private int partition(int[] nums, int lo, int hi) {
        int index = lo + (int) (Math.random() * (hi - lo + 1));
        swap(nums, lo, index);

        int pivot = nums[lo];
        int i = lo + 1;
        for (int j = lo + 1; j <= hi; j++) {
            if (nums[j] < pivot) 
                swap(nums, j, i++);
        }

        swap(nums, i - 1, lo);
        return i - 1;
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
