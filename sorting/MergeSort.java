package sorting;

public class MergeSort {
    public static void sort(int[] nums) {
        int[] aux = new int[nums.length];
        auxSort(nums, aux, 0, nums.length - 1);
    }

    private static void auxSort(int[] nums, int[] aux, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        auxSort(nums, aux, l, mid);
        auxSort(nums, aux, mid + 1, r);
        merge(nums, aux, l, mid, r);
    }

    private static void merge(int[] nums, int[] aux, int l, int mid, int r) {
        int i = l, j = mid + 1, k = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) aux[k++] = nums[i++];
            else aux[k++] = nums[j++];
        }

        while (i <= mid) aux[k++] = nums[i++];
        while (j <= r) aux[k++] = nums[j++];

        System.arraycopy(aux, l, nums, l, (r - l) + 1);
    }
}
