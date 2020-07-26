#include<bits/stdc++.h>
using namespace std;
using ll = long long;
void nextPermutation(vector<ll>& nums) 
{
// 1) First find the element which is not in increasing order from end to start.
// 2) If no element found which means list is in last permutation so reverse the array
// 3) else find the rightmost greater element for position in Step-1 and swap them
// 4) reverse the integers from the position in step-1 (exclusive) to the end
    int eleIndx = -1;
    for(int i=nums.size()-1;i>0;i--)
    {
        if(nums[i] > nums[i-1]){
            eleIndx = i-1;
            break;
        }
    }
    if(eleIndx == -1) 
        reverse(nums.begin(),nums.end());
    else{
        int j;
        for(j=eleIndx+1;j<nums.size();j++){
            if(nums[eleIndx] >= nums[j])
                break;
        }
        swap(nums[eleIndx],nums[--j]);
        for(int i=eleIndx+1,j=nums.size()-1;i<j;i++,j--)
            swap(nums[i],nums[j]);
    }
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> v;
    for(int i=0;i<n;i++)
    {
        ll x; cin >> x;
        v.push_back(x);
    }
    nextPermutation(v);
    for(auto i: v)
        cout << i << " ";
    return 0;
}