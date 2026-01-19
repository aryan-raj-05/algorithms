package sorting;

public class HeapSort {
    public static void sort(int[] nums) {
        // max heap construction
        int n = nums.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(nums, n, i);
        }

        // sorting
        for (int i = n - 1; i > 0; i--) {
            swap(nums, 0, i);
            heapify(nums, i, 0);
        }
    }
    
    private static void heapify(int[] nums, int n, int i) {
        while (true) {
            int left = i * 2 + 1;
            int right = i * 2 + 2;

            int largest = i;

            if (left < n && nums[left] > nums[largest]) 
                largest = left;
            if (right < n && nums[right] > nums[largest])
                largest = right;
            if (largest == i) break;

            swap(nums, largest, i);
            i = largest;
        }
    }

    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
