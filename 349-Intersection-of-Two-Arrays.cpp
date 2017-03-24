class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (0 == nums1.size() || 0 == nums2.size())
        {
            return ans;
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator i = nums1.begin(), j = nums2.begin();
        while (i != nums1.end() && j != nums2.end())
        {
            if (*i < *j)
            {
                i++;
            }
            else if (*i > *j)
            {
                j++;
            }
            else
            {
                if (0 == ans.size() || ans.back() != *i)
                {
                    ans.push_back(*i);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
