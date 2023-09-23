class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<vector<string>> wordsByLen(16+1); //word size => vector of words with this size
        unordered_map<string, int> chainLen;//chain length of string
        //
        for(auto& word: words) {
            wordsByLen[word.size()].push_back(word);
        }
        //
        int maxChainLen=0;
        //find chain length for every word
        for(int wlen=1; wlen<=16; ++wlen) {
            //can optimize if we have a gap
            for(auto& word: wordsByLen[wlen]) {
                if (1==wlen) {
                    chainLen[word]=1;
                    maxChainLen=1;                    
                    continue;
                }
                //try to delete every char
                int predcessorMaxLen=0;
                for(int i=0;i<word.size();++i) {
                    string predcessor=word;
                    predcessor.erase(i, 1);
                    if (chainLen.count(predcessor)>0) {
                        predcessorMaxLen=max(predcessorMaxLen, chainLen[predcessor]);
                    }
                }
                chainLen[word]=predcessorMaxLen+1;
                maxChainLen=max(maxChainLen, chainLen[word]);
            }
        }
        return maxChainLen;

    }
};