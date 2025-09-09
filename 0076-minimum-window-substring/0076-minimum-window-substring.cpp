class Solution {
public:
    string minWindow(string s, string t) {
        string temp = s;   // keep original string (case preserved)
        int n = s.size();
        int m = t.size();
        if (m > n) return "";

        // Support all ASCII characters (not just a-z)
        vector<int> v(128, 0);  
        for (int i = 0; i < m; i++) v[t[i]]++;

        int i = 0, j = 0;
        vector<int> vs(128, 0);
        int ans = INT_MAX;
        int sti = -1, eti = -1;

        while (i < n) {
            vs[s[i]]++;
            bool ok = true;
            for (int k = 0; k < 128; k++) {
                if (vs[k] < v[k]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (ans > i - j + 1) {
                    sti = j;
                    eti = i;
                    ans = i - j + 1;
                }
            }

            while (j < i && ok) {
                char r = s[j];
                if (vs[r] >= v[r]) {
                    vs[r]--;
                    if (vs[r] >= v[r]) {
                        if (ans > i - (j + 1) + 1) {
                            sti = j + 1;
                            eti = i;
                            ans = i - (j + 1) + 1;
                        }
                    } else {
                        j++;
                        break;
                    }
                }
                j++;
            }
            i++;
        }

        if (ans == INT_MAX) return "";

        string p;
        for (int k = sti; k <= eti; k++) {
            p.push_back(temp[k]); // preserve original case
        }
        return p;
    }
};
