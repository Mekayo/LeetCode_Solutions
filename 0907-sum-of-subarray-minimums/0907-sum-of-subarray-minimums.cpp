class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long mod=1e9+7;
        int n=arr.size();

        vector<long long> left(n),right(n);
        stack<pair<int,int>> st1, st2;

        for(int i=0;i<n;++i){
            
            int cnt=1;
            while(!st1.empty() && st1.top().first > arr[i]){
                cnt+=st1.top().second;
                st1.pop();
            }

            left[i]=cnt;
            st1.push({arr[i],cnt});
        }

        for(int i=n-1;i>=0;--i){
            
            int cnt=1;
            while(!st2.empty() && st2.top().first >=arr[i]){
                cnt+=st2.top().second;
                st2.pop();
            }
            st2.push({arr[i],cnt});
            right[i]=cnt;
        }
        // calculation
        long long ans=0;
        for(int i=0;i<n;++i){
            long long contri = (arr[i]*left[i]*right[i])%mod;
            ans=(ans+contri)%mod;
        }
        return ans%mod;
    }
};