class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end())       return 0;

        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        int len=0;
        while(!q.empty()){
            int size=q.size();
            len++;
            
            for(int i=0;i<size;i++){
                string st=q.front();
                q.pop();
                if(st==endWord) return len;
                for(int j=0;j<st.size();j++){
                    char temp=st[j];
                    for(char ch='a';ch<='z';ch++){
                        if(ch==temp) continue;
                        st[j]=ch;
                        if(words.find(st)!=words.end()){
                            q.push(st);
                            words.erase(st);
                        }
                    }
                    st[j]=temp;
                }
            }

        }
        return 0;
    }
};