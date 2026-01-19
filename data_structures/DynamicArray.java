package data_structures;

public class DynamicArray<T> {
    private Object[] array;
    private int size;

    private static final int INIT_CAPACITY = 16;

    public DynamicArray() {
        array = new Object[INIT_CAPACITY];
        size = 0;
    }

    public void add(T x) {
        if (size == array.length) {
            int newCapacity = array.length * 2;
            var newArray = new Object[newCapacity];
            System.arraycopy(array, 0, newArray, 0, size);
            array = newArray;
        }
        array[size++] = x;
    }

    @SuppressWarnings("unchecked")
    public T remove() {
        if (size == 0) {
            throw new IllegalStateException("Array is Empty");
        }
        T removed = (T) array[--size];
        array[size] = null;
        return removed;
    }

    @SuppressWarnings("unchecked")
    public T get(int index) {
        indexCheck(index);
        return (T) array[index];
    }

    public void set(int index, T value) {
        indexCheck(index);
        array[index] = value;
    }

    public int length() {
        return size;
    }

    private void indexCheck(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }
    }
}
