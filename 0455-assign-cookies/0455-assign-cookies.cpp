class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0)return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
          int j=0;
          int i;
          
        for(i=0;i<g.size() && j<s.size();i++){
            if(s[j]>=g[i]){
                j++;
                continue;
            }
            else{
                j++;
                i--;
            }
        }
        return i;
    }
};



// class Solution {
// public:
//     int findContentChildren(vector<int>& g, vector<int>& s) {
//         sort(g.begin(), g.end());
//         sort(s.begin(), s.end());

//         int i = 0; // child pointer
//         int j = 0; // cookie pointer

//         while (i < g.size() && j < s.size()) {
//             if (s[j] >= g[i]) {
//                 i++; // child satisfied
//             }
//             j++; // always move cookie
//         }

//         return i; // number of satisfied children
//     }
// };