class Solution {
public:
    bool isVow(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int left=0; int max_cnt=0, cnt=0;

        for(int right=0;right<s.size();right++){
            if(isVow(s[right])) cnt++;

            if(right-left+1==k){
                max_cnt=max(max_cnt,cnt);
                if(isVow(s[left])) cnt--;
                left++;
            }
        }
        return max_cnt;
    }
};