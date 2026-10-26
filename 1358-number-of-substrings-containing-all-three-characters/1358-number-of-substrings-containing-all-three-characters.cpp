class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mp(3,0);
        int res=0, l=0,n=s.size();

        for(int r=0;r<n;r++){
            mp[s[r]-'a']++;
            
            while(mp[0]>0 && mp[1]>0 && mp[2]>0){
                res+=n-r;
    
                mp[s[l]-'a']--;
                l++;
            }
        }
    return res;
    }
};