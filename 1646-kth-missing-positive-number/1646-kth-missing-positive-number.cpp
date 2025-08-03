class Solution {
public:
    int findKthPositive(vector<int>& piles, int k) {
        int s = 1;
        int e = 2000;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // Count how many numbers are missing <= mid
            int missing = mid;
            int actual = upper_bound(piles.begin(), piles.end(), mid) - piles.begin();
            missing -= actual;

            if (missing < k) {
                s = mid + 1;
            } else {
                ans = mid; // potential answer
                e = mid - 1;
            }
        }
        return ans;
    }
};
