// this is the magic template for backtracking questions on leetcode
vector<vector<int>> ans;
void construct(vector<int>& temp, vector<int>& nums, int currentInd, int n)
{
    if(temp.size()<=n)
    {
        ans.push_back(temp);
        // return;
    }
    if(temp.size()>n || currentInd>=n)
        return;
    for(int i=currentInd;i<n;i++)
    {
        if(i>currentInd && nums[i]==nums[i-1])  // only in case of duplicates
            continue;
        temp.push_back(nums[i]);
        construct(temp, nums, i+1, n);
        temp.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int> temp;
    sort(nums.begin(), nums.end());
    construct(temp, nums, 0, nums.size());
    return ans;
}