class Solution {
public:
 void bfs(vector<vector<int>>& image,vector<vector<int>> &vis,int m,int n,int color){
        queue<pair<int,int>> q;
        q.push({m,n});
        vis[m][n]=1;
        int row=image.size();
        int col=image[0].size();
       
         while(!q.empty()){
            // auto s=q.front();
           int r=q.front().first;
           int c=q.front().second;
           int check=image[r][c];
           image[r][c]=color;
            q.pop();
            
            for(int delr=-1;delr<=1;delr++){
                for(int delc=-1;delc<=1;delc++){
                   if(delr==-1&&delc==-1)
                   continue;
                   else if(delr==1&&delc==-1)
                   continue;
                   else if(delr==-1&&delc==1)
                   continue;
                   else if(delr==1&&delc==1)
                   continue;

                   int nr=r+delr;
                   int nc=c+delc;
                    if(nr>=0&&nr<row&&nc>=0&&nc<col&&!vis[nr][nc]&&check==image[nr][nc]){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                         
                    }
                }
            }
           
           
         }  
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
                
        //     }
        // }
        vector<vector<int>> vis(m,vector<int>(n,0));
        if(!(sr>=0&&sr<m&&sc>=0&&sc<n))
        return image;
         
        bfs(image,vis,sr,sc,color);
        return image;
    }
};