class Solution {
public:
string helper(string str,int k,string ans){
    int n=str.length();//str is original string
    if(n==1){//agr origina ki ek length hai to direct add krke return krdo
        ans+=str;
        return ans;
    }
    //n-1 fact calculate kro
    int fact=1;
    for(int i=2;i<=n-1;i++){
        fact*=i;
    }
    int idx=k/fact;//idx jisko extract krna hai from original string
    if(k%fact==0) idx--;//agr divisible hai to ek km rhega
    char ch=str[idx];//us charcter ko nikalo 
    string left=str.substr(0,idx);//character hatane ke bad jo left m bachi
    string right=str.substr(idx+1);//character hatane ke bad jo right m bachi
    //ab k ki value k khel
    int q=1;
    if(k%fact==0) q=fact;
    else q=k%fact;
    return helper(left+right,q,ans+ch);

}
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1;i<=n;i++){
            str+=to_string(i);
        }
        return helper(str,k,"");
    }
};