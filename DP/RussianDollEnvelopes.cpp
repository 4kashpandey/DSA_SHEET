class Solution {
public:
static bool mycompare(const vector<int>& a, const vector<int>& b) {
    if (a[0] == b[0]) {
        return a[1] > b[1]; 
    }
    return a[0] < b[0];
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        vector<int> lis;
        sort(envelopes.begin(),envelopes.end(),mycompare);
        lis.push_back(envelopes[0][1]);

        for (int i=1;i<envelopes.size();i++){
    
            auto it = lower_bound(lis.begin(), lis.end(),envelopes[i][1]);
        
         if (it == lis.end()) {
             lis.push_back(envelopes[i][1]);
          } else {
               *it = envelopes[i][1];
         }           
        }
        return lis.size();       
    }
};