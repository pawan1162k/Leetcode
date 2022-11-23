class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i+=3){
            for(int j=0;j<board[0].size();j+=3){
                int count=0;
                unordered_set<char>st;
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.'){
                            count++;
                            st.insert(board[x][y]);
                        }
                    }
                }
                if(st.size()!=count){
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            int counti=0;
            int countj=0;
            unordered_set<char>sti;
            unordered_set<char>stj;
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    counti++;
                    sti.insert(board[i][j]);
                }
                if(board[j][i]!='.'){
                    countj++;
                    stj.insert(board[j][i]);
                }
            }
            if(sti.size()!=counti){
                return false;
            }
            if(stj.size()!=countj){
                return false;
            }
        }
        return true;
    }
};