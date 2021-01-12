int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict;
        for(string st : wordList)dict.insert(st);
        dict.insert(beginWord);
        if(dict.find(endWord) == dict.end())return 0;
        
        int lvl = 1;
        queue<string> q;
        q.push(beginWord);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                string curr = q.front();
                q.pop();
                for(int i = 0; i < curr.size(); i++){
                    string temp = curr;
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        temp[i] = ch;
                        if(dict.find(temp) == dict.end())continue;
                        if(temp == endWord)return lvl + 1;
                        q.push(temp);
                        dict.erase(temp);
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
