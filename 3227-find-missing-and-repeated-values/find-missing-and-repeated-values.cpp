class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& nums) {
        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += nums[i][j];
            }
        }

        long long sq = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sq += (long long) (nums[i][j] * nums[i][j]);
            }
        }

        long long N = (long long) (n * n);

        long long defined_sum = N * (N + 1) / 2;
        long long sq_def_sum = N * (N + 1) * (2 * N + 1) / 6;

        long long diff_sum = sum - defined_sum;
        long long diff_sq_sum = sq - sq_def_sum;

        long long d = diff_sq_sum / diff_sum;

        long long repeated = (diff_sum + d) / 2;
        long long missing = (d - diff_sum) / 2;

        return {(int)repeated, (int)missing};
    }
};