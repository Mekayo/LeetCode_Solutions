class Solution {
public:
    vector<vector<string>> ans;
    bool ispali(string s){
        int l=0, r=s.size()-1;
        while(l<=r){
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
    return true;
    }

    void solvekar(string s,vector<string>& T){
        int n=s.size();
        if(n==0) {
            ans.push_back(T);
            return;
        }

        for(int i=0;i<n;i++){
            string temp=s.substr(0,i+1);
            
            if(ispali(temp)){
                T.push_back(temp);
                solvekar(s.substr(i+1,n),T);
                T.pop_back();
            }
        }
        return;
    }


    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solvekar(s,temp);
        return ans;
    }
};