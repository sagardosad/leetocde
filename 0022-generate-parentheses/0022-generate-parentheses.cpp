class Solution {
public:
    void helper(vector<string>&str,int n,int oc,int cc,string s){
        if(oc==n && cc==n){
            str.push_back(s);
            return;
        }
        if(oc<n){
            helper(str,n,oc+1,cc,s+"(");
        }
        if(cc<oc){
            helper(str,n,oc,cc+1,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>str;
        int open_count=0;
        int close_count=0;
        helper(str,n,0,0,"");
        return str;
    }
};