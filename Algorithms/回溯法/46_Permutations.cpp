/**
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]
 
提示：
1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
**/
// 方法一：列表中不再遍历自身
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        backTrack( nums, path, 0);
        return res;
    }

    void backTrack(vector<int>& nums, vector<int>& path,int depth)
    {
        if (path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 如果列表中找到和当前元素相同的值则剔除
            vector<int>::iterator it = find(path.begin(), path.end(), nums[i]);
            if (it != path.end())
                continue;
            path.push_back(nums[i]);
            backTrack(nums, path, depth + 1);
            path.pop_back();
        }
    }
};