#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<long long int>
#define pii pair<int,int>
int n;

map<int,pii>m;

void print(vii &a)
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;
}

class Solution {
public:
    bool checkSubarraySum(vector<int>& a, int k) {
        n=a.size();
        m.clear();
        if(n>=2)
        {
            for(int i=0;i<n-1;i++)
            {
                if(a[i]==0 && a[i+1]==0)return true;   
            }
        }
        if(k==1 && n>=2)return true;
        if(k==1 && n==1)return false;
        
        vii cumSum;
        cumSum.pb(a[0]);
        
        for(int i=1;i<n;i++)cumSum.pb((cumSum[i-1]+a[i]));
        
        for(int i=0;i<n;i++)cumSum[i]=cumSum[i]%k;
        
        for(int i=0;i<n;i++)
        {
            auto itr=m.find(cumSum[i]);
            if(itr==m.end())m.ins(mp(cumSum[i],mp(i,1)));
            else 
            {
                if(itr->se.fi+1!=i)
                    itr->se.se++;
            }
        }
        for(auto itr=m.begin();itr!=m.end();itr++)
        {
            if(itr->fi!=0 && itr->se.se >=2)
            {
                //cout<<"THE REM ARE "<<itr->fi<<endl;
                return true;
            }
            if(itr->fi==0 && itr->se.se >1)
            {
                //cout<<"THE REM ARE "<<itr->fi<<endl;
                return true;
            }
            if(itr->fi==0 && itr->se.se==1 && cumSum[0]!=0){
                //cout<<"THE REM ARE "<<itr->fi<<endl;
                return true;
            }
        }
        return false;
    }
};