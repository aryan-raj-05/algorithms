package sorting;

public class QuickSort {
    public static void sort(int[] nums) {
        auxSort(nums, 0, nums.length - 1);
    }

    private static void auxSort(int[] nums, int l, int r) {
        if (l >= r) return;
        int mid = part(nums, l, r);
        auxSort(nums, l, mid - 1);
        auxSort(nums, mid + 1, r);
    }

    // required that the pivot is at l
    // Lomuto-style partition
    private static int part(int[] nums, int l, int r) {
        findPivot(nums, l, r);

        int pivot = nums[l];
        int i = l, j = l + 1;

        for (; j <= r; j++) {
            if (nums[j] < pivot)
                swap(nums, ++i, j);
        }

        swap(nums, i, l);
        return i;
    }

    private static void findPivot(int[] nums, int l, int r) {
        int pivotIndex = l + (int) (Math.random() * (r - l + 1));
        swap(nums, pivotIndex, l);
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
