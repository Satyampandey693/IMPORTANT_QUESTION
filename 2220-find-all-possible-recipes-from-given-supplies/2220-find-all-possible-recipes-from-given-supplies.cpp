class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> ans;
        map<string,int> mrec;
        map<string,int> msupp;
        int n=recipes.size();
        for(int i=0;i<recipes.size();i++){
           mrec[recipes[i]]=i;
        }
        vector<int> graph[n];
         vector<int> indegree(n,0);
        for(int i=0;i<supplies.size();i++){
            msupp[supplies[i]]++;
        }
        for(int i=0;i<ingredients.size();i++){
            bool p=false;
              for(int j=0;j<ingredients[i].size();j++){
               if(mrec.find(ingredients[i][j])!=mrec.end()){
                int u=mrec[ingredients[i][j]];
                int v=i;
                graph[u].push_back(v);
               }
               else if(msupp[ingredients[i][j]]==0){
                // cout<<ingredients[i][j]<<" ";
                    p=true;
                }
              }
            //   cout<<p<<endl;
              if(p)
              indegree[i]=1e9; 
               
        }
       
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                indegree[graph[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(recipes[node]);
            for(int j:graph[node]){
                indegree[j]--;
                if(indegree[j]==0){
                        q.push(j);
                }
            }
        }
        return ans;
    }
};