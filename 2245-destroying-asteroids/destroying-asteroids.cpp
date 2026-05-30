class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        long long currMass = mass;

        sort(asteroids.begin(), asteroids.end());

        for (int i = 0; i < asteroids.size(); i++) {

            if (currMass >= asteroids[i]) {
                currMass += asteroids[i];
            }
            else {
                return false;
            }
        }

        return true;
    }
};