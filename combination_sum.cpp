class Solution {
public:
    void solve(int i,vector<vector<int>>&result,vector<int>&candidates,int target,vector<int>&curr){
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0 || i==candidates.size()){
            return;
        }
        curr.push_back(candidates[i]);
        solve(i,result,candidates,target-candidates[i],curr);
        curr.pop_back();
        solve(i+1,result,candidates,target,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>curr;
        solve(0,result,candidates,target,curr);
        return result;
    }
};