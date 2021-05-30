class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) {
            return false;
        }
        unordered_map<char, int> aFreq, bFreq;
        for (int i = 0; i < A.size(); i++) {
            aFreq[A[i]]++;
            bFreq[B[i]]++;
        }
        if (aFreq != bFreq) {
            return false;
        }
        int misCnt = 0;
        for (int i = 0; i < A.size(); i++) {
            if (A[i] != B[i]) {
                misCnt++;
            }
            if (misCnt > 2) {
                return false;
            }
        }
        if (misCnt == 2) {
            return true;
        }
        if (misCnt == 1 || !consecutiveLetterCheck(aFreq)) {
            return false;
        }
        return true;
    }
    
    bool consecutiveLetterCheck(unordered_map<char, int> mp) {
        for (auto elem : mp) {
            if (elem.second > 1) {
                return true;
            }
        }
        return false;
    }
};
