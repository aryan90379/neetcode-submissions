
class Solution {
   public:
    string encode(vector<string>& strs) {
        string s;
        for (string str : strs) {
            s+=to_string(str.size());
            s += '#';
            s += str;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.size()) {
            int j = i;
            while(s[j]!='#')
            {
                j++;
            }
            j++;
            int cnt = stoi(s.substr(i,j-1+1));
            res.push_back(s.substr(j, cnt));
            i = j + cnt;
        }
        return res;
    }
};
