class Solution {
public:
    /*vector<int> splitString(string &s , char delimeter)
    {
        vector<int>ans;
        int start=0;
        int end = s.find(delimeter);
        while(end != string::npos)
        {
            string temp = s.substr(start , end - start);
            ans.push_back(stoi(temp));
            start=end+1;
            end = s.find(delimeter);
        }
        string temp = s.substr(start, end-start);
        ans.push_back(stoi(temp));
        return ans;
    }*/
    vector<int> splitString(const string& s, char delimiter) {
        vector<int> result;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delimiter)) {
            result.push_back(stoi(token));
        }
        return result;
    }
    
    int compareVersion(string version1, string version2) 
    {
        vector<int>v1 = splitString( version1 , '.');
        vector<int>v2 = splitString( version2 , '.');
        int val1 , val2;
        for(int i =0 ; i<max(v1.size(),v2.size()); i++)
        {
            if (i < v1.size()) 
            {
                val1 = v1[i];
            } 
            else 
            {
                val1 = 0;
            }

            if (i < v2.size()) 
            {
                val2 = v2[i];
            } 
            else 
            {
                val2 = 0;
            }
            if(val1<val2) return -1;
            else if(val1 >val2) return 1;
        }
        return 0;
             
    }
};















/*
 int i = 0, j = 0;
        while (i < version1.length() || j < version2.length()) {
            int num1 = 0, num2 = 0;
            while (i < version1.length() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            i++;
            while (j < version2.length() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            if(num1!=num2)return (num1>num2)?1:-1;
        }  
        return 0;
*/