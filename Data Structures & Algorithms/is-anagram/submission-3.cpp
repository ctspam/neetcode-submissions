class Solution {
public:
    bool isAnagram(string s, string t){

    //first test if they are even the same lengths
    if(s.length() != t.length()) return false;

    // now we want to count the S and the T so we make hashmaps for both of them
        unordered_map<char, int> countS;
        unordered_map<char, int> countT;

        for(int i = 0; i < s.length(); ++i)
        {
            ++countS[s[i]];
            ++countT[t[i]];
        }
        return countS == countT;
    }
};
