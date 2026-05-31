class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        if(m > n) return false;
        int mp1[26] = {0};
        int mp2[26] = {0};
        for(int i = 0;i < m;i++){
            mp1[s1[i] - 'a']++;
            mp2[s2[i] - 'a']++;
        }
        if(equal(begin(mp1),end(mp1),begin(mp2))) return true;
        for(int i = m;i < n;i++){
            mp2[s2[i]-'a']++;
            mp2[s2[i-m]-'a']--;
            if(equal(begin(mp1),end(mp1),begin(mp2))) return true;
        }
        return false;
    }
};
