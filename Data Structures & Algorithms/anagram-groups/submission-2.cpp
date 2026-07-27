class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a hashmap to see every word has the same amount of letters as teach word
        // if they have thje same amount tehn group trhem up in that vector 

        // want to create like a hashmap
        unordered_map<string, vector<string>> groups;

        // now we want to make the key of the hashmap
        for(auto& word : strs)
        {
            string key = word;
            sort(key.begin(), key.end());

            //once the keys are sorted u want to push that into that key 
            groups[key].push_back(word);
        }

        // now that is done we want to push these new sorted oes into like a vector
        vector<vector<string>> result;

        for(auto& a: groups)
        {
            result.push_back(a.second);
        }

        return result;
    }
};
