// class Solution {
// public:
// map<int,map<int,bool>> row;
// map<int,map<int,bool>> col;
// map<pair<int,int>,map<int,bool>> box;
// // map<pair<int,int>,int> vis;
// bool valid(int i,int j,int n){
// if(row[i][n]||col[j][n]||box[{i/3,j/3}][n]) return false;
// return true;
// }
// vector<int> delr={+1,0};
// vector<int> delc={0,+1};
// bool check(int i,int j,vector<vector<char>>& board){
//     // int r=board.size();
//     // int c=board[0].size
//     //    for(int n=1;n<10;n++){
    
//             if((board[i][j]!='.')&&(!valid(i,j,board[i][j]-'0'))){
//                 cout<<i<<" "<<j<<board[i][j]<<"m";
//                 return false;
//             }
//             else if(board[i][j]!='.'){
//                  row[i][board[i][j]-'0']=1;
//                  col[j][board[i][j]-'0']=1;
//                  box[{i/3,j/3}][board[i][j]-'0']=1;
//             }
//             // vis[{i,j}]=1;
//             for(int k=0;k<2;k++){
//                 int ni=i+delr[k];
//                 int nj=j+delc[k];
//                 // !vis[{ni,nj}]
//                 if(ni<9&&nj<9){
//                     if(!check(ni,nj,board)) return false;
//                 }
//             }
//         //    vis[{i,j}]=0;
//             return true;
//     //    }
// }
//     bool isValidSudoku(vector<vector<char>>& board) {
//         // return check(0,0,board);
        
//     }
// };

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track seen numbers in rows, cols, and boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue;

                // Check row
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // Check column
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // Check 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};
