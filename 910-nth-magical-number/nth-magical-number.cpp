class Solution {
public:
    int nthMagicalNumber(int n, int p, int q) {

        long long MOD = 1e9 + 7;

        long long lcm = (1LL * p * q) / __gcd(p, q);

        long long low = 1;
        long long high = 1LL * n * min(p, q);

        while (low < high) {

            long long mid = low + (high - low) / 2;

            long long count =
                mid / p +
                mid / q -
                mid / lcm;

            if (count >= n) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low % MOD;
    }
};