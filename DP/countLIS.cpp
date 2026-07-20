#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> length(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {

                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }

                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(length.begin(), length.end());
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += count[i];
            }
        }

        return result;
    }
};

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    int ans = obj.findNumberOfLIS(nums);

    cout << "Number of Longest Increasing Subsequences = " << ans << endl;

    return 0;
}