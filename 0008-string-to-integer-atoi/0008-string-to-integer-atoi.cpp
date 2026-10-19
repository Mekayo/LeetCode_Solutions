class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        while(i<s.size() && s[i]==' ') i++;

        if(s[i]=='-') {
            sign=-1 ;
            i++;
        }
        else if(s[i]=='+') i++; 
        return helper(s,i,sign,0);
    }
    int helper(string& s, int i, int sign,long res){
        if(i>=s.size() || !isdigit(s[i])) return (int)(sign*res);
    
        res = res*10+(s[i]-'0');
        
        if(sign*res > INT_MAX) return INT_MAX;
        if(sign*res < INT_MIN) return INT_MIN;

        return helper(s,i+1,sign,res);
    }
};