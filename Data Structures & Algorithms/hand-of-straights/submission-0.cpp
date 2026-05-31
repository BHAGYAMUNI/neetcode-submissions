class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int,int>mp;
        for(int it:hand){
            mp[it]++;
        }
        for(auto it:mp){
            int card = it.first;
            int count = it.second;
            if(count > 0){
                for(int i = 0;i < groupSize;i++){
                    if(mp[i+card] < count) return false;
                    mp[i+card] -= count;
                }
            }
        }
        return true;
    }
};
