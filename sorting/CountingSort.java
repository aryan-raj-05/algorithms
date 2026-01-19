package sorting;

// Time Complexity: O(n + m)
// Space Complexity: O(m)
// where, m = max value in array
public class CountingSort {
    // Not stable but, can be made stable through prefix sums
    public static void unstable(int[] nums) {
        int max = nums[0];
        for (int num: nums) max = Math.max(max, num);

        int[] freqTable = new int[max + 1];
        for (int num: nums) {
            freqTable[num]++;
        }

        int k = nums.length - 1;
        for (int i = freqTable.length - 1; i >= 0; i--) {
            if (freqTable[i] <= 0) continue;
            while (freqTable[i] > 0) {
                nums[k--] = i;
                freqTable[i]--;
            }
        }
    }

    public static void stable(int[] nums) {
        int max = nums[0];
        for (int num: nums) max = Math.max(max, num);

        int[] prefix = new int[max + 1];
        for (int num: nums) prefix[num]++;
        for (int i = 1; i <= max; i++) {
            prefix[i] += prefix[i - 1];
        }

        int[] output = new int[nums.length];
        for (int i = nums.length - 1; i >= 0; i--) {
            output[--prefix[nums[i]]] = nums[i];
        }

        System.arraycopy(output, 0, nums, 0, nums.length);
    }
}
