class Solution {
public:
    string robotWithString(string s) {
        vector<int> v(26, 0);
        for (char c : s) v[c - 'a']++;

        int i = 0;
        string t, ans;

        for (char c : s) {
            t.push_back(c);
            v[c - 'a']--;

            // Update i to next smallest remaining char
            while (i < 26 && v[i] == 0) i++;

            // Pop from t while top <= smallest remaining character
            while (!t.empty() && (i == 26 || t.back() <= ('a' + i))) {
                ans.push_back(t.back());
                t.pop_back();
            }
        }

        // Pop any remaining from stack
        while (!t.empty()) {
            ans.push_back(t.back());
            t.pop_back();
        }

        return ans;
    }
};
