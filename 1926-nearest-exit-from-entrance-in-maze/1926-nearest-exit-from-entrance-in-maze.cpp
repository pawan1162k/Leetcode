class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        int level=0;
        while(!q.empty()){
            int siz=q.size();
            for(int i=0;i<siz;i++){
                pair<int,int>temp=q.front();
                int c=temp.first;
                int d=temp.second;
                // cout<<c<<" "<<d<<" ";
                if(c==0 || d==0 || c==maze.size()-1 || d==maze[0].size()-1){
                    if(c!=e[0] || d!=e[1]){
                        return level;
                    }
                }
                q.pop();
                if(c-1>=0 && maze[c-1][d]=='.'){
                    q.push({c-1,d});
                    maze[c-1][d]='+';
                }
                if(c+1<maze.size() && maze[c+1][d]=='.'){
                    q.push({c+1,d});
                    maze[c+1][d]='+';
                }
                if(d-1>=0 && maze[c][d-1]=='.'){
                    q.push({c,d-1});
                    maze[c][d-1]='+';
                }
                if(d+1<maze[0].size() && maze[c][d+1]=='.'){
                    q.push({c,d+1});
                    maze[c][d+1]='+';
                }
            }
            // cout<<endl;
            level++;
        }
        return -1;
    }
};