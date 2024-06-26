//Think of it sequentially . First an element is exposed to a filled stack . So it'll start comparing stack.top(). 

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        int n2 = nums2.size();
        unordered_map<int,int>mp; //To store <num2 , Corresponding NGE> 
        for(int i=n2-1; i >= 0; i--)
        {
            while(!st.empty() and st.top()<nums2[i])
            st.pop();
            if(st.empty())
            mp[nums2[i]]=-1;
            else
            mp[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};


















/*class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++) 
        {
            int curr_ele = nums1[i];
            for(int j = 0; j < nums2.size(); j++) 
            {
                if(nums2[j] == curr_ele) 
                {
                    bool flag = false;
                    for(int k = j + 1; k < nums2.size(); k++) 
                    {
                        if(nums2[k] > nums2[j]) 
                        {
                            ans.push_back(nums2[k]);
                            flag = true; 
                            break;
                        }
                    }
                    if (!flag) ans.push_back(-1);
                    
                }
            }
        }
        return ans;
    }
};
*/


















/*
unordered_map<int,int> mp;
        stack<int> s;
        for(int i=nums2.size()-1;i>=0;i--){
            while(s.size()>0 && s.top()<nums2[i]){
                    s.pop();
                }
                if(s.size()==0) mp[nums2[i]]=-1;
                else mp[nums2[i]]=s.top();
            s.push(nums2[i]);   
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
*/