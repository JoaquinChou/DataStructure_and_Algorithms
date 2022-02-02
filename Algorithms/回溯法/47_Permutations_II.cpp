/**
 * 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
示例 1：

输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10
**/

// 1.使用辅助数组
class Solution {

public:
    vector<int> vis;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vis.resize(nums.size());
        sort(nums.begin(), nums.end());
        backTrack(path, nums, 0);
        return res;
    }

    void backTrack(vector<int>& path, vector<int>& nums, int depth)
    {
        if(path.size() == nums.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            // 以输入为[1,1,2]为例,若当前位置被访问过，
            // 或者当前值（第二个"1"）和前一个值（第一个"1"）相同并且前一个位置（第一个"1"）没有被访问过，则跳过，因为前面的（1，1，2）已经被访问过了
            if (vis[i] || (i > 0 && (nums[i] == nums[i - 1]) && !vis[i - 1]))
                continue;
            path.push_back(nums[i]);
            vis[i] = 1;
            backTrack(path, nums, depth + 1);
            path.pop_back();
            vis[i] = 0;
        }
    }

};