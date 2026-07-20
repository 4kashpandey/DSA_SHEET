#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool compare(string &s1, string &s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int i = 0, j = 0;

        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }

        if (i == s1.size() && j == s2.size())
            return true;

        return false;
    }

    int longestStrChain(vector<string>& words) {

        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        vector<int> dp(words.size(), 1);

        int maxi = 1;

        for (int i = 1; i < words.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (compare(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxi)
                maxi = dp[i];
        }

        return maxi;
    }
};

int main() {
    int n;

    cout << "Enter number of words: ";
    cin >> n;

    vector<string> words(n);

    cout << "Enter the words:\n";
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Solution obj;

    int ans = obj.longestStrChain(words);

    cout << "Longest String Chain Length = " << ans << endl;

    return 0;
}