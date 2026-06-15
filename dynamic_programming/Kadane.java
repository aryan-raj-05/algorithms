package dynamic_programming;

import java.util.HashMap;

public class Kadane {
    // Kadane's Algorithms
    // Bottom up version of memoized or recursive functions
    // Time: O(n), Space: O(1)
    public static int maxSubarraySum(int[] nums) {
        int currSum = nums[0];
        int maxSum = nums[0];

        for (int i = 1; i < nums.length; i++) {
            currSum = Math.max(currSum + nums[i], nums[i]);
            maxSum = Math.max(maxSum, currSum);
        }

        return maxSum;
    }

    // Memoized version
    // Time: O(n), Space: O(n)
    public static int maxSubarraySumMemo(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        int maxSum = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            maxSum = Math.max(
                maxSum,
                memoAux(nums, i, map)
            );
        }

        return maxSum;
    }

    private static int memoAux(
        int[] nums, 
        int i, 
        HashMap<Integer, Integer> map
    ) {
        if (i == 0) {
            map.putIfAbsent(0, nums[0]);
            return nums[0];
        }

        if (!map.containsKey(i)) {
            int sum = Math.max(
                memoAux(nums, i - 1, map) + nums[i],
                nums[i]
            );
            map.put(i, sum);
        }

        return map.get(i);
    }

    // The max sum for a subarray that ends on index i
    // is either nums[i] or dp(i - 1) + nums[i]
    // applying that for each index in array we can find the
    // maximum subarray sum

    // Time: O(n^2), Space: O(n)
    public static int maxSubarraySumRecursive(int[] nums) {
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            max = Integer.max(max, auxDp(nums, i));
        }
        return max;
    }

    private static int auxDp(int[] nums, int i) {
        if (i == 0) {
            return nums[0];
        }
        return Math.max(
            auxDp(nums, i - 1) + nums[i],
            nums[i]
        );
    }
}
