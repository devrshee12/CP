// problem link : https://leetcode.com/contest/weekly-contest-299/problems/maximum-score-of-spliced-array/


class Solution {
public:
    #define pb push_back
    
    //kadan's alogorithm
    
    pair<int, int> index(vector<int> a){
        int start=0,end=0,curr_max=0,prev_max=0,start_o=0,i;
        int n = a.size();
        prev_max = a[0];
        
        for(i=0; i<n; i++){
            curr_max += a[i];
            if(curr_max < 0){
                start = i+1;
                curr_max = 0;
            }
            else if(curr_max > prev_max){
                end = i;
                start_o = start;
                prev_max = curr_max;
            }

        }
        
        return {start_o, end};
    }
    
    
    
    int maximumsSplicedArray(vector<int>& num1, vector<int>& num2) {
        int n = num1.size();
        vector<int> diff1;// if we swap with respect to first
        vector<int> diff2;
        
        vector<int> a = num1;
        vector<int> b = num2;
        for(int i=0;i<n;i++){
            diff1.pb(num2[i] - num1[i]);
        }
        for(int i=0;i<n;i++){
            diff2.pb(num1[i] - num2[i]);
        }
        
//         for(auto it : diff1){
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
//         for(auto it : diff2){
//             cout<<it<<" ";
//         }
//         cout<<endl;
        
        pair<int, int> p1 = index(diff1);
        // cout<<p1.first<<" "<<p1.second<<endl;
        pair<int, int> p2 = index(diff2);
        // cout<<p2.first<<" "<<p2.second<<endl;
        
        int ans1 = 0;
        
        for(int i=p1.first;i<=p1.second;i++){
            swap(a[i], b[i]);
        }
        
        //calulate ans1
        int sum11 = 0;
        for(auto it : a){
            sum11 += it;
        }
        
        int sum12 = 0;
        for(auto it : b){
            sum12 += it;
        }
        
        ans1 = max(sum11, sum12);
        
        for(int i=p1.first;i<=p1.second;i++){
            swap(a[i], b[i]);
        }
        
        int ans2 = 0;
        for(int i=p2.first;i<=p2.second;i++){
            swap(a[i], b[i]);
        }
        
        //calculte ans2;
        int sum21 = 0;
        for(auto it : a){
            sum21 += it;
        }
        
        int sum22 = 0;
        for(auto it : b){
            sum22 += it;
        }
        
        ans2 = max(sum21, sum22);
        
        
        // cout<<ans1<<" "<<ans2<<endl;
        
        
        
        int res = max(ans1, ans2);
        return res;
        
        
        
        
        
        
            
        
        
        
        
        // return 0;
        
        
        
        
        
        
        
    }
};
