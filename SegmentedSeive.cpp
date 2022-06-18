#include<bits/stdc++.h>
using namespace std;

vector<int> generatePrime(int N,vector<bool> &seive) {

   vector<int> ds;
   for(int i=2;i<=N;i++) {
    if(seive[i]==false) ds.push_back(i);
   }

   return ds;
}

signed  main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
    #endif

    vector<bool> seive(1000000,false);

    for(int i=2;i<seive.size();i++) {
        if(seive[i]==false) {
            for(int j=i*i;j<seive.size();j+=i) {
                seive[j]=true;
            }
        }
    }

    int l,r;
    cin>>l>>r;
    vector<int> primes=generatePrime(sqrt(r),seive);
    vector<int> ans(r-l+1,true);
    for(auto pr : primes) {

        int firstMultiple=(l/pr)*pr;
        if(firstMultiple < l) firstMultiple+=l;

        for(int j=max(firstMultiple,pr*pr);j<=r;j+=pr) {
            ans[j-l]=false;
        }
    }

    for(int i=l;i<=r;i++) {
        if(ans[i-l]==true) cout<<i<<" ";
    }

   return 0;
}


