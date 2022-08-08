class DSU{
	vector<int> parent, size;
public:
	int count = 0;
	DSU(int n) : parent(n), size(n), count(0) {
		for(int i=0; i<n; i++)
			make_set(i);
	}

	void make_set(int v){
		parent[v] = v;
		size[v] = 1;
		count++;
	}

	int find_set(int v){
		if(v == parent[v])
			return v;
		return parent[v] = find_set(parent[v]);
	}

	bool union_set(int a, int b){
		a = find_set(a);
		b = find_set(b);
		if(a != b){
			if(size[a] < size[b])
				swap(a, b);
			parent[b] = a;
			size[a] += size[b];
			count--;
			return true;
		}
		return false;
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> index;
        DSU uf(accounts.size());
        
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(index.find(accounts[i][j]) != index.end()){
                    uf.union_set(index[accounts[i][j]], i);
                }
                else{
                    index[accounts[i][j]] = i;
                }
            }
        }
        
        vector<vector<string>> mergedAccounts(accounts.size());
        for(auto &pair: index){
            int group = uf.find_set(pair.second);
            mergedAccounts[group].push_back(pair.first);
        }
        
        vector<vector<string>> ans;
        for(int i=0; i<mergedAccounts.size(); i++){
            if(!mergedAccounts[i].empty()){
                vector<string> mails{accounts[i][0]};
                for(auto &mail: mergedAccounts[i])
                    mails.push_back(mail);
                ans.push_back(mails);
            }   
        }
        
        return ans;
    }
};