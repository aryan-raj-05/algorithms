package searching;

import java.util.Arrays;

public class StringMatch {
    // Time:
    //      preprocessing: O(m)
    //      searching: O(n/m) best case, O(nm) worst case
    // Typically runs in sublinear time
    public static boolean boyerMooreHorspool(String text, String pattern) {
        int patLen = pattern.length();
        if (patLen == 0) return true;

        int[] table = new int[26];
        Arrays.fill(table, patLen);

        for (int i = 0; i < patLen - 1; i++) {
            char ch = pattern.charAt(i);
            table[ch - 'a'] = Math.max(1, patLen - i - 1);
        }

        int j = patLen - 1;
        while (j < text.length()) {
            int k = j;
            int i = patLen - 1;

            while (i >= 0 && text.charAt(k) == pattern.charAt(i)) {
                k--;
                i--;
            }

            if (i < 0) return true;

            char last = text.charAt(j);
            int offset = (last >= 'a' && last <= 'z')
                ? table[last - 'a']
                : patLen;

            j += offset;
        }

        return false;
    }
}
