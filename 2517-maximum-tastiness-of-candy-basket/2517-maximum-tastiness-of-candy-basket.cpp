/*
Problem samajh:

Hume k candies choose karni hain aise ki unke beech ka MINIMUM difference maximum ho.

Matlab:
- Har pair ka difference calculate hota hai
- Usme se minimum nikalta hai (that's tastiness)
- Aur hume us tastiness ko MAXIMIZE karna hai

👉 Yeh exactly "maximize minimum" type problem hai

Iska pattern:
- Binary Search on Answer

-----------------------------------------------------

WHY BINARY SEARCH?

Agar mai bolu:
"Can we achieve tastiness >= x ?"

Toh:
- Agar x possible hai → smaller values bhi possible hongi
- Agar x possible nahi hai → bade values bhi possible nahi honge

👉 Monotonic behaviour → Binary Search valid

-----------------------------------------------------

GREEDY CHECK:

Given x (minimum difference):
- Left se start karo (smallest price)
- Next candy tabhi lo jab difference >= x ho
- Count karo kitni candies le pa rahe ho

Agar count >= k → possible
warna → not possible

-----------------------------------------------------

FINAL IDEA:

- Sort array
- Binary search answer
- Har mid ke liye greedy check
*/


class Solution {
public:
bool check(int mid,vector<int>& price,int k){
    int cnt=1;
    int last=price[0];
    for(int i=1;i<price.size();i++){
        if(price[i]-last>=mid){
            cnt++;
            last=price[i];
        }
    }
    return cnt>=k;
}
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int lo=0;
        int hi=price[price.size()-1]-price[0];
        int ans=0;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(mid,price,k)){
                ans=mid;
                lo=mid+1;
            } else{
                hi=mid-1;
            }
        }
        return ans;
    }
};