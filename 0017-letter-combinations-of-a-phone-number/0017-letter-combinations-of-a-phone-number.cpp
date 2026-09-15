class Solution {
public:
    void solve(string digits,int idx,string str,vector<string>&ans,vector<string> mapping){
        // base case
        if(idx>=digits.length()){
            ans.push_back(str);
            return;
        }

        // logic 
        // value find kro kon se place pa hai krke 
        int value=digits[idx]-'0';
        // use vaklue pe kon si string hai check kro 
        string mapped=mapping[value];
        // loop taki saare ch ko le ske 
        for(int i=0;i<mapped.length();i++){
            str=str+mapped[i];
            solve(digits,idx+1,str,ans,mapping);
            // return jane se pehle insert element ko nikal lo 
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        // map type taki kis buttton ko dabane par kya milega 
     vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
      vector<string> ans;
        string str="";
        int idx=0;
        solve(digits,idx,str,ans,mapping);
        return ans;


    }
};