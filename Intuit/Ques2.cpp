// https://practice.geeksforgeeks.org/problems/word-search/1

class Solution {
public:

    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int index, vector<vector<bool>>& visited){
        if(index == word.size()-1) return true;
        visited[r][c] = true;
        if(r>0 and !visited[r-1][c] and word[index+1] == board[r-1][c] and dfs(board, r-1, c, word, index+1, visited)) return true;
        if(c>0 and !visited[r][c-1] and word[index+1] == board[r][c-1] and dfs(board, r, c-1, word, index+1, visited)) return true;
        if(r<board.size()-1 and !visited[r+1][c] and word[index+1] == board[r+1][c] and dfs(board, r+1, c, word, index+1, visited)) return true;
        if(c<board[0].size()-1 and !visited[r][c+1] and word[index+1] == board[r][c+1] and dfs(board, r, c+1, word, index+1, visited)) return true;
        visited[r][c] = false;
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == word[0] and dfs(board, i, j, word, 0, visited)){
                    return true;
                }
            }
        }
        return false;
    }
};