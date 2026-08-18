class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur=prices[0];
        int p=0;
        for(int i=1;i<prices.size();i++){
            if(cur>prices[i]) cur=prices[i];

            else if(p<prices[i]-cur) p=prices[i]-cur;
        }
        return p;
    }
};