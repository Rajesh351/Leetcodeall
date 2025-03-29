typedef long long int ll;

const int MOD = 1e9+7;
const int N = 1e5;

#define pii pair<ll, ll>
#define F first
#define S second

class Solution {
    
    vector<int> seive;
    
    void BuildSeive () {
        seive.clear(), seive.resize(N+1);
        
        for (int j = 2; j*j <= N; j ++) {
            for (int k = j; k <= N; k += j) 
                if (seive[k] == 0) seive[k] = j;
        }
        
        for (int j = 1; j <= N; j ++)
            if (!seive[j]) seive[j] = j;
    }
    
    int PrimeScore (int x) {
        int result = 0;
        
        while (x != 1) {
            int div = seive[x];
            while (x % div == 0) x /= div;
            result ++;
        }
        return result;
    }
    
    // x^y
    ll FastPower (ll x, ll y) {
        ll result = 1;
        
        while (y) {
            if (y&1) result = (result * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }
        return result;
    }
    
public:
    int maximumScore(vector<int>& nums, int k) {
        BuildSeive();
        int n = nums.size();  
        
        vector<int> score(n);
        for (int j = 0; j < n; j ++) score[j] = PrimeScore(nums[j]);
        
        vector<ll> lft(n), rgt(n);
        stack<int> s;
        
        for (int j = 0; j < n; j ++) {
            while (!s.empty() && score[s.top()] < score[j]) s.pop();
            lft[j] = s.empty()? -1 : s.top();
            s.push(j);
        }
        
        while (!s.empty()) s.pop();
        
        for (int j = n-1; j >= 0; j --) {
            while (!s.empty() && score[s.top()] <= score[j]) s.pop();
            rgt[j] = s.empty()? n : s.top();
            s.push(j);
        }
        
        vector<pii> val_and_frq;
        for (ll i = 0; i < n; i ++) {
            ll possible = (i - lft[i]) * (rgt[i] - i);
            val_and_frq.push_back({nums[i], possible});
        }
        
        sort(val_and_frq.rbegin(), val_and_frq.rend());
        ll result = 1;
        for (auto cur: val_and_frq) {
            if (k == 0) break;
                        
            ll take = min(cur.S, (ll)k);
            k -= take;
            result = (result * FastPower(cur.F, take)) % MOD;
        }
        return result;
    }
};