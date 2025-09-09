class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";

        // use 128 for all ASCII chars
        vector<int> v(128, 0); 
        for (int i = 0; i < m; i++) v[t[i]]++;

        vector<int> vs(128, 0);

        int i = 0, j = 0;
        int ans = INT_MAX;
        int sti = -1, eti = -1;
        string p;

        while (i < n) {
            vs[s[i]]++;

            // check if window valid
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
                vs[r]--;

                // check again after removing
                bool stillOk = true;
                for (int k = 0; k < 128; k++) {
                    if (vs[k] < v[k]) {
                        stillOk = false;
                        break;
                    }
                }

                if (stillOk) {
                    if (ans > i - (j + 1) + 1) {
                        sti = j + 1;
                        eti = i;
                        ans = i - (j + 1) + 1;
                    }
                    j++;
                } else {
                    vs[r]++; // restore last removed
                    break;
                }
            }
            i++;
        }

        if (ans == INT_MAX) return "";

        for (int k = sti; k <= eti; k++) p.push_back(s[k]);
        return p;
    }
};
