class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n = 0;
        int mn = INT_MAX;
        int mx = INT_MIN;
        int mx_freq = 0;
        int mod = 0;    
        long long sum = 0;
        vector<double>ans;
        for(int i =0; i<count.size(); i++){
            n = n + count[i];
            if(count[i]>0){
            mn = min(mn,i);
            mx = max(mx,i);
            }
            sum = sum +(long long ) count[i]*i;
            if(count[i]>mx_freq){
                mx_freq = count[i];
                mod = i;
            }
        }
        double mean = (double)sum/n;
                int mid1 = (n + 1) / 2;
        int mid2 = (n + 2) / 2;
   
        int curr = 0;

        int a = -1;
        int b = -1;

        // second pass for median
        for(int i = 0; i < 256; i++) {

            curr += count[i];

            if(a == -1 && curr >= mid1)
                a = i;

            if(b == -1 && curr >= mid2)
                b = i;
        }

        double median = (a + b) / 2.0;
        ans.push_back(mn);
        ans.push_back(mx);
        ans.push_back(mean);
        ans.push_back(median);
        ans.push_back(mod);
        return ans;
        
    

        
    }
};