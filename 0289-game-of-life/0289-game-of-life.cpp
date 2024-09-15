class Solution {
public:

    bool isValidNeighbour(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }

    void gameOfLife(vector<vector<int>>& board) {
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1};
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};

        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                int count_live_neighbours = 0;
                
                // Count live neighbors
                for(int i = 0; i < 8; i++) {
                    int curr_x = row + dx[i], curr_y = col + dy[i];
                    if(isValidNeighbour(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1)
                        count_live_neighbours++;
                }
                
                // Apply the Game of Life rules
                if(board[row][col] == 1 && (count_live_neighbours < 2 || count_live_neighbours > 3))
                    board[row][col] = -1; // Mark as dead (but was originally alive)
                if(board[row][col] == 0 && count_live_neighbours == 3)
                    board[row][col] = 2;  // Mark as alive (but was originally dead)
            }
        }

        // Update the board to the final state
        for(int row = 0; row < board.size(); row++) {
            for(int col = 0; col < board[0].size(); col++) {
                if(board[row][col] == -1)
                    board[row][col] = 0; // Dead
                if(board[row][col] == 2)
                    board[row][col] = 1; // Alive
            }
        }
    }
};