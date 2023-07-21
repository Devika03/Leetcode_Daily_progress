class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        vector<set<pair<int, int>>> levels;

        //Enter the first element as {nums[0], 1}
        levels.push_back(set<pair<int, int>>());
        levels[0].insert(make_pair(nums[0], 1));

        for (int i = 1; i < nums.size(); i++)
        {
            int j;
            for (j = levels.size() - 1; j >= 0; j--)
            {
                //If current number is smaller than the largest
                //(largest will always be at the last),
                //move to previous level
                if (nums[i] < levels[j].begin()->first)
                    continue;
                //If the number already exists and is the smallest for
                //current length, add all lengths from previous level 
                //which are smaller than current number
                if (nums[i] == levels[j].begin()->first)
                {
                    int g = levels[j].begin()->second;
                    if (j == 0)
                        g += 1;
                    else
                    {
                        for (auto &itr : levels[j - 1])
                        {
                            if (itr.first < nums[i])
                                g += itr.second;
                            else
                                break;
                        }
                    }
                    //since its a set, we have to remove the current element
                    //and replace it with a new element
                    auto itr = levels[j].begin();
                    levels[j].erase(itr);
                    levels[j].insert(make_pair(nums[i], g));
                    break;
                }
                //If the current number is bigger than the largest  number

                // so far, add a new level and add the lengths from the previous row
                else
                {
                    int a = 0;
                    for (auto &itr : levels[j])
                    {
                        if (itr.first < nums[i])
                            a += itr.second;
                        else
                            break;
                    }
                    if (j == levels.size() - 1)
                    {
                        levels.push_back(set<pair<int, int>>());
                        levels[levels.size() - 1].insert(make_pair(nums[i], a));
                    }
                    else
                    {
                        levels[j + 1].insert(make_pair(nums[i], a));
                    }
                    break;
                }
            }
            //If the number is smallest so far, add this number to 0th row
            if (j == -1)
            {
                levels[0].insert(make_pair(nums[i], 1));
            }
        }
        //Calculate the sum of all lengths in the last level and return
        int ans = 0;
        for (auto itr : levels[levels.size() - 1])
            ans += itr.second;
        return ans;
    }
};