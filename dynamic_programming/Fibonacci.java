package dynamic_programming;

import java.util.HashMap;
import java.util.Map;

public class Fibonacci {
    private static Map<Integer, Long> map = new HashMap<>();

    static {
        map.put(0, 0L);
        map.put(1, 1L);
    }

    public static int recursive(int n) {
        if (n < 0) {
            throw new Error("Can't find fibonacci for negative numbers");
        }

        if (n < 2) return n;
        return recursive(n - 1) + recursive(n - 2);
    }

    public static long memo(int n) {
        if (map.containsKey(n)) {
            return map.get(n);
        }

        long res = memo(n - 1) + memo(n - 2);
        map.put(n, res);

        return map.get(n);
    }

    public static long bottomUp(int n) {
        if (n < 2) return n;
        long a = 0L;
        long b = 1L;

        for (int i = 2; i < n; i++) {
            long c = a + b;
            a = b;
            b = c;
        }

        return a + b;
    }
}
