// https://leetcode.com/problems/group-anagrams/

// Using counting sort based custom sorting algo, O(nk) time, O(nk) space
class Solution {
private:
    string strSort(const string& str) {
        int charCount[28] = {0};
        
        for(char ch : str)
            charCount[ch - 'a']++;
        
        string sortedStr;
        for(int i = 0; i < 28; i++)
            while(charCount[i]--)
                sortedStr += i + 'a';
        
        return sortedStr;
    }
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap; // <sorted string, all the available anagrams>
        
        for(string str : strs)
            hashmap[strSort(str)].push_back(str);
        
        int fillIdx = 0;
        vector<vector<string>> groupedAnagrams(hashmap.size());
        
        for(auto& anagrams : hashmap)
            groupedAnagrams[fillIdx++] = std::move(anagrams.second);
        
        return groupedAnagrams;
    }
};

// Super easy to solve using unoredered_map, O(N log(K)) time, O(NK) space
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap; // <sorted string, all the available anagrams>
        
        for(string str : strs) {
            string anagram = str;
            sort(anagram.begin(), anagram.end());
            hashmap[anagram].push_back(str);
        }
        
        vector<vector<string>> groupedAnagrams;
        for(auto anagrams : hashmap)
            groupedAnagrams.push_back(anagrams.second);
        
        return groupedAnagrams;
    }
};