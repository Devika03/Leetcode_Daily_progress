class TrieNode{
public:
    vector<TrieNode*> children = vector<TrieNode*>(26, nullptr);
    bool end = false;
};

class Trie{
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if(temp->children[idx] == NULL){
                temp->children[idx] = new TrieNode();
            }
            temp = temp->children[idx];
        }
        temp->end = true;
    }

    bool search(string &word){
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); i++){
            int idx = word[i]-'a';
            if(temp->children[idx] == NULL){
                return false;
            }
            temp = temp->children[idx];
        }
        if(temp->end){
            return true;
        }
        return false;
    }

    bool startswith(string &prefix){
        TrieNode* temp = root;
        for(int i = 0; i < prefix.size(); i++){
            int idx = prefix[i]-'a';
            if(temp->children[idx] == NULL){
                return false;
            }
            temp = temp->children[idx];
        }
        return true;
    }
};

class Solution {
public:
    Trie *mytrie = new Trie();
    unordered_map<string, int> mpp;
    int solve(string s){
        if(s.size() == 0){
            return 0;
        }

        if(mpp.find(s) != mpp.end()){
            return mpp[s];
        }
        int ans = 1e9;
        for(int i = 0; i < s.size(); i++){
            for(int j = i; j < s.size(); j++){
                string temp = s.substr(i, j-i+1);
                int curr = 0;
                if(mytrie->search(temp)){
                    string nxt = s.substr(j+1);
                    curr = i+solve(nxt);
                    ans = min(ans, curr);
                }
            }
        }
        if(ans == 1e9){
            return mpp[s] = s.size();
        }
        return mpp[s] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        for(auto it: dictionary){
            mytrie->insert(it);
        }

        return solve(s);
    }
};