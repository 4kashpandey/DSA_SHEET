#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= nums.size() - 1) {
                return true;
            }
        }
        return true;
    }
};

int main() {
    Solution solver;

    vector<int> test1 = {2, 3, 1, 1, 4};
    cout << "Test Case 1 [2, 3, 1, 1, 4]: ";
    if (solver.canJump(test1)) {
        cout << "SUCCESS (True)" << endl;
    } else {
        cout << "FAILED (False)" << endl;
    }

    vector<int> test2 = {3, 2, 1, 0, 4};
    cout << "Test Case 2 [3, 2, 1, 0, 4]: ";
    if (solver.canJump(test2)) {
        cout << "SUCCESS (True)" << endl;
    } else {
        cout << "FAILED (False)" << endl;
    }

    vector<int> test3 = {0};
    cout << "Test Case 3 [0]: ";
    if (solver.canJump(test3)) {
        cout << "SUCCESS (True)" << endl;
    } else {
        cout << "FAILED (False)" << endl;
    }

    return 0;
}