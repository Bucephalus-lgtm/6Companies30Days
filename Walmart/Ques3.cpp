// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color

class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        int count = 0;
        int aliceCount = 0;
        int bobCount = 0;
        for(int i=0; i<n; i++){
            if(colors[i] == 'A') count++;
            else {
                if(count >= 3)
                    aliceCount += count-2;
                count = 0;    
            }
        }
        if(count >= 3)
            aliceCount += count-2;
        count = 0;
        for(int i=0; i<n; i++){
            if(colors[i] == 'B') count++;
            else {
                if(count >= 3)
                    bobCount += count-2;
                count = 0;    
            }
        }
        if(count >= 3)
            bobCount += count-2;
        return aliceCount > bobCount;
    }
};