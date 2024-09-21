class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, unsigned int> m;
        m.clear();
        vector<int> result;
        unsigned int length = words[0].size();
        for (string word : words) {
            m[word]++;
        }

        for (unsigned int offset = 0; offset < length; ++offset) {
            unordered_map<string, unsigned int> seen;
            int size = 0;
            for (int i = offset; i + length <= s.size(); i += length) {
                string w = s.substr(i, length);

                auto it = m.find(w);
                if (it == m.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                ++seen[w];
                ++size;

                while (seen[w] > it -> second) {
                    string first = s.substr(i - (size - 1)*length, length);
                    --seen[first];
                    --size;
                }

                if (size == words.size()) {
                    result.push_back(i - (size - 1)*length);
                }
            }
        }

        return result;
    }
};