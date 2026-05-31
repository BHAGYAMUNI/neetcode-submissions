class Solution {
public:
    int f(int k,vector<int>& piles, int h){
        int hours = 0;
        for(int i = 0;i < piles.size();i++){
            hours += ceil((double)piles[i]/(double)k);
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1,high = *max_element(piles.begin(),piles.end());
        long long ans = high;
        while(low <= high){
            long long mid = low + (high-low)/2;
            if(f(mid,piles,h)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
