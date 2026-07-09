package data_structures;

public class DynamicArray {
    private int[] arr;
    private int size;

    public DynamicArray() {
        arr = new int[16];
        size = 0;
    }

    public void addLast(int x) {
        if (size == arr.length) {
            resize();
        }
        arr[size++] = x;
    }

    public int removeLast() {
        if (size == 0) {
            throw new IllegalStateException("Array is Empty");
        }

        return arr[--size];
    }

    public int get(int index) {
        indexCheck(index);
        return arr[index];
    }

    public void set(int index, int value) {
        indexCheck(index);
        arr[index] = value;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private void indexCheck(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
    }

    private void resize() {
        int[] newArr = new int[arr.length * 2];
        System.arraycopy(arr, 0, newArr, 0, size);
        arr = newArr;
    }
}
