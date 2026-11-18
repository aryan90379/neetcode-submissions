class Solution {
   public:
    string encode(vector<string>& strs) {
        string code;

        for (auto str : strs) {
            code += to_string(str.size()) + '#';
            code.append(str);
        }
        return code;
    }

        vector<string> decode(string s) {
            int i = 0;
            vector<string> res;
            while (i < s.size()) {
                string sz = "";
                while (s[i] != '#') sz += s[i++];
                int len = stoi(sz);

                res.push_back(s.substr(i + 1, len));
                i += 1 + len;
            }
            return res;
        }

        
    
};
