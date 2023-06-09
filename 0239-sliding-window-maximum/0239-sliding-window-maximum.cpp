class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    multiset<int> kp;
    int x=nums.size();
    for(int i=0; i<k; i++)kp.insert(nums[i]);
    if(k==x)return {*--kp.end()};
    vector<int> v;
    int t=0;
    v.push_back(*--kp.end());
    for(int i=k; i<x; i++){
        kp.insert(nums[i]); //will insert new element in the set
        kp.erase(kp.find(nums[t++])); //erase the first element
        //t++;
        v.push_back(*--kp.end()); //pushing the largest element in the vector
    }
    return v;
}
};