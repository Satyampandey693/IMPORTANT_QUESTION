class Solution {
public:
map<int,map<int,int>> row;
map<int,map<int,int>> col;
map<pair<int,int>,map<int,int>> box;
map<int,map<int,int>> vis;
bool valid(int i,int j,int n){
if(row[i][n]||col[j][n]||box[{i/3,j/3}][n]) return false;
return true;
}
vector<int> delr={0,-1,0,+1};
vector<int> delc={-1,0,+1,0};
bool check(vector<vector<char>>& board){
    int c=0;
  for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]=='.'){
                    c++;
                    bool r=false;
                    for(int k=1;k<=9;k++){
                       if(!valid(i,j,k)) continue;
                       r=true;
                       board[i][j]=k+'0';
                       row[i][k]++;
                    col[j][k]++;
                    box[{i/3,j/3}][k]++;
                       if(check(board)) return true;
                       r=false;
                       board[i][j]='.';
                        row[i][k]--;
                    col[j][k]--;
                    box[{i/3,j/3}][k]--;
                    }

                 if(r==false) return false;
                }
            }
        }
        if(c==0)
        return true;
        else return false;
           
}
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                if(board[i][j]!='.'){
                    int p=board[i][j]-'0';
                    row[i][p]++;
                    col[j][p]++;
                    box[{i/3,j/3}][p]++;
                }
            }
        }
        check(board);
    }
};