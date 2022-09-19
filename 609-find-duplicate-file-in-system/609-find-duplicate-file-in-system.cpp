class Solution {
    pair<string, string> split(string &s){
        string name = "", content = "";
        int ind = 0;
        while(s[ind] != '(')
            name += s[ind++];
        ind++;
        while(s[ind] != ')')
            content += s[ind++];
        return {name, content};
    }
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> files;
        
        for(auto &s: paths){
            stringstream ss(s);
            string path;
            ss >> path;
            
            string file_content;
            while(ss >> file_content){
                const auto &[name, content] = split(file_content);
                
                files[content].push_back(path + "/" + name);
            }
        }
        
        vector<vector<string>> ans;
        for(auto &[content, paths]: files){
            if(paths.size() > 1)
                ans.push_back(paths);
        }
        return ans;
    }
};