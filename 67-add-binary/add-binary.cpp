// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string ans="";
//         int carray=0;
//         int i=a.length()-1;
//         int j=b.length()-1;
//         while(i>=0 && j>=0){
//             int sum=0;
//             sum=(a[i]-'0')+(b[j]-'0'+carray);
//             if(sum==2){
//                 ans=ans+'0';
//                 carray=1;
//             }
//             else if(sum==0){
//                 ans=ans+'0';
//                 carray=0;
//             }
//             else{
//                 ans=ans+'1';
//                 carray=0;
//             }
//             i--;
//             j--;
//         }
//         while(i>=0){
//                 int sum=0;
//                 sum=a[i]-'0'+carray;
//                  if(sum==2){
//                 ans=ans+'0';
//                 carray=1;
//             }
//              else if(sum==0){
//                 ans=ans+'0';
//                 carray=0;
//             }
//             else{
//                 ans=ans+'1';
//                 carray=0;
//             }
                
//                 i--;
//         }
//         while(j>=0){
//              int sum=0;
//                 sum=b[j]-'0'+carray;
//                  if(sum==2){
//                 ans=ans+'0';
//                 carray=1;
//             }
//              else if(sum==0){
//                 ans=ans+'0';
//                 carray=0;
//             }
//             else{
//                 ans=ans+'1';
//                 carray=0;
//             }
//             j--;
//         }
//         if(carray==0){
//              reverse(ans.begin(),ans.end());
//              return ans;
//         }
//         else{
//             ans=ans+'1';
//             reverse(ans.begin(),ans.end());
//             return ans;
//         }
//     }
// };


class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {

            int sum = carry;

            if (i >= 0)
                sum += a[i--] - '0';

            if (j >= 0)
                sum += b[j--] - '0';

            ans += (sum % 2) + '0';
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};