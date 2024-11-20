Take K of Each Character From Left and Right
int takeCharacters(string s, int k) {
        int n = s.size();
        unordered_map<char, int> right = {{'a', 0}, {'b', 0}, {'c', 0}};
        for (char ch : s) {
            right[ch]++;
        }
        if (right['a'] < k || right['b'] < k || right['c'] < k) 
            return -1;
        int maxWindow = 0; 
        unordered_map<char, int> window;
        int left = 0;
        for (int rightIndex = 0; rightIndex < n; ++rightIndex) {
            window[s[rightIndex]]++;
            while (window['a'] > right['a'] - k || 
                   window['b'] > right['b'] - k || 
                   window['c'] > right['c'] - k) {
                window[s[left]]--;
                left++;
            }
            maxWindow = max(maxWindow, rightIndex - left + 1);
        }
        return n - maxWindow;
    }
