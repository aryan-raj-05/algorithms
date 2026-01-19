package sorting;

public class SelectionSort {
    public static void sort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            // find the min element from i to end
            int minIndex = i;
            for (int j = i; j < nums.length; j++) {
                if (nums[j] < nums[minIndex]) minIndex = j;
            }

            // swap
            int temp = nums[i];
            nums[i] = nums[minIndex];
            nums[minIndex] = temp;
        }
    }
}
