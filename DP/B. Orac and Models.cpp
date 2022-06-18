// There are n models in the shop numbered from 1 to n, with sizes s1,s2,…,sn.

// Orac will buy some of the models and will arrange them in the order of increasing numbers (i.e. indices, but not sizes).

// Orac thinks that the obtained arrangement is beatiful, if for any two adjacent models with indices ij and ij+1 (note that ij<ij+1, because Orac arranged them properly), ij+1 is divisible by ij and sij<sij+1.

// For example, for 6 models with sizes {3,6,7,7,7,7}, he can buy models with indices 1, 2, and 6, and the obtained arrangement will be beautiful. Also, note that the arrangement with exactly one model is also considered beautiful.

// Orac wants to know the maximum number of models that he can buy, and he may ask you these queries many times.

// problem : https://codeforces.com/problemset/problem/1350/B



void solve()
{
    //write your code here
    
    ll n;
    cin>>n;
    vi arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    
    vi dp(n+1, 1);
    
    for(int i=2;i<=n;i++){
        ll mx = 0;
        // cout<<"for "<<i<<" : "<<endl;
        for(int j=1;j<=sqrt(i);j++){

            if(i%j == 0){
                if(i/j == j){
                    // cout<<"1 : "<<j<<endl;
                    // cout<<" "
                    if(j != i && arr[i] > arr[j]){
                        // cout<<"valid : "<<j<<endl;
                        mx = max(mx, dp[j]);    
                    }
                    
                }
                else{

                    // cout<<"2 : "<<j<<endl;
                    // cout<<"3 : "<<i/j<<endl;

                    if(j != i && arr[i] > arr[j]){
                        // cout<<"valid : "<<j<<endl;
                        mx = max(mx, dp[j]);
                    }
                    if(i/j != i && arr[i] > arr[i/j]){
                        // cout<<"valid : "<<i/j<<endl;
                        mx = max(mx, dp[i/j]);
                    } 
                }
            }
            
            
        }

        // cout<<endl;
        
        dp[i] = 1 + mx;
    }
    
    ll res = 1;
    for(auto it : dp){
        // cout<<it<<" ";
        res = max(res, it);
    }
    // cout<<endl;
    cout<<res<<endl;
    





    
    






    






    
    

}
   



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    int t;
    cin>>t;
   


     
    while(t--){
        solve();
    }


    // solve();
         
    
    
    
}

