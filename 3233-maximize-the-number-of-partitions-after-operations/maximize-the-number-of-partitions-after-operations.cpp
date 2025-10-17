class Solution {
public:
    int count(int n){
        return __builtin_popcount(n);
    }
    int maxPartitionsAfterOperations(string s, int k) {
        if(k==26){
            return 1;
        }
        int n=s.size();
        s='@'+s+'@';
        vector<int> pref(n+2),pval(n+2);
        int prefix=0,pbit=0;
        for(int i=1;i<=n;i++){
            int bit=(1<<(s[i]-'a'));
            pbit|=bit;
            if(count(pbit)>k){
                prefix++;
                pbit=bit;
            }
            pref[i]=prefix;
            pval[i]=pbit;
        }
        vector<int> suff(n+2),sval(n+2);
        int suffix=0,sbit=0;
        for(int i=n;i>=1;i--){
            int bit=(1<<(s[i]-'a'));
            sbit|=bit;
            if(count(sbit)>k){
                suffix++;
                sbit=bit;
            }
            suff[i]=suffix;
            sval[i]=sbit;
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            int val=pref[i-1]+suff[i+1];
            int p=pval[i-1],s=sval[i+1];
            int x=p|s;
            if(count(x)+1<=k){
                val+=1;
            }
            else if(count(p)==k&&count(s)==k&&count(x)<26){
                val+=3;
            }
            else{
                val+=2;
            }
            ans=max(val,ans);
        }
        return ans;
    }
};