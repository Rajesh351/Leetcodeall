class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

 vector<int> v(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        v[s[i] - 'a']++;
    }
    priority_queue<pair<int, int>> mp;
    for (int i = 0; i <= 25; i++)
    {
        if (v[i] != 0)
            mp.push({i, v[i]});
    }

    string ans;
    while (!mp.empty())
    {
        auto it = mp.top();
        mp.pop();
        int eleindex = it.first;
        int ele = it.second;

        int count = 0;
        char ch = char('a' + eleindex);
        if (ele <= repeatLimit)
        {
            string result(ele, ch);
            ans += result;
        }
        else
        {
            count = it.second - repeatLimit;
            string result1(repeatLimit, ch);
            ans += result1;
            if (mp.empty() == true)
                return ans;
            auto it1 = mp.top();
            mp.pop();
            char ch1 = char('a' + it1.first);
            string result2(1, ch1);
            ans+=result2;
            int count1 = it1.second - 1;
            if (count1 == 0)
            {
                mp.push({eleindex, count});
            }
            else
            {
                mp.push({eleindex, count});
                mp.push({it1.first, count1});
            }
        }

       // cout << ans << endl;
    }
    return ans;

    }
};