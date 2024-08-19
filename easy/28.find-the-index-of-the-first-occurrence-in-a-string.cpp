class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length()) return -1;

        int r = -1;
        for (int i = 0; i <= (haystack.length() - needle.length()); ++i) {
            if (haystack[i] == needle[0]) {
                r = i;

                for (int j = 1; j < needle.length(); ++j) {
                    if (haystack[i + j] != needle[j]) {
                        r = -1;
                        break;
                    }
                }

                if (r != -1) return r;
            }
        }
        return r;
    }
};