class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        vector<int> ans;
        
        for (int i = digits.size()- 1; i >= 0; i--)//Loop for a case of consecutive 9s.
        {
            
            if (digits[i] < 9) 
            {
                digits[i]++;
                return digits;
            }
            
            digits[i] = 0;
        }
        
        
        digits.insert(digits.begin(), 1);
        return digits;
    }
};