class Solution {
public:
set<string> st;
map<int,int> mp;
void find(string &tiles,string &p,int i){
if(i>=tiles.size()){
    st.insert(p);
    return;
}
int ans=0;
//skip
find(tiles,p,i+1);
for(int j=0;j<tiles.size();j++){
    if(mp[j])continue;
p.push_back(tiles[j]);
mp[j]++;
find(tiles,p,i+1);
mp[j]--;
p.pop_back();
}



}
    int numTilePossibilities(string tiles) {
       string s="";
        find(tiles,s,0);
        return st.size()-1;
    }
};