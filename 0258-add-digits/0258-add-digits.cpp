class Solution {
public:
    int sumOfDigits(int num) {
            int sum = 0;
    
        while (num != 0) {
        sum += num % 10; // Add the last digit to sum
        num /= 10;       // Remove the last digit from num
    }
    
    return sum;
}
    int addDigits(int num) 
    {
        string num_str = to_string(num);
        int length = num_str.length();
        if(length<=1)
            return num;
        else if(length>1)
        {
            int y = sumOfDigits(num);
            return addDigits(y);
        }
        
        return -1; // To handle any other case. 
        
    }
};