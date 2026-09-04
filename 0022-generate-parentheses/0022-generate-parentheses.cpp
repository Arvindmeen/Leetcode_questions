class Solution {
public:
    void solve(int i,int n,vector<string>&res,string &temp,int f,int l){
        if(l>f)return;
        if(i==n && (f==n && l==n)){
                res.push_back(temp);       
            return;
        }
        if(f<n){
        temp.push_back('(');
        solve(i+1,n,res,temp,f+1,l);
        temp.pop_back();
        }
        if(l<f){
        temp.push_back(')');
        solve(i,n,res,temp,f,l+1);
        temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        //your code goes here
        vector<string>res;
        string temp="";
        solve(0,n,res,temp,0,0);
        return res;
    }
};