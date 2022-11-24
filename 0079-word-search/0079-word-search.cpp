class Solution {
    bool solve(int i,int j,vector<vector<char>>&board,int k,string &word){
        if(k>=word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='.' || board[i][j]!=word[k]){
            return false;
        }
        char temp=board[i][j];
        board[i][j]='.';
        bool a=solve(i+1,j,board,k+1,word);
        bool b=solve(i-1,j,board,k+1,word);
        bool c=solve(i,j+1,board,k+1,word);
        bool d=solve(i,j-1,board,k+1,word);
        board[i][j]=temp;
        return a||b||c||d;
    }
public:
    bool exist(vector<vector<char>>& board, string &word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(i,j,board,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};