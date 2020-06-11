// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<unordered_map>
#include<queue>
#include <stack>
#include<map>
#include<algorithm>
#include <string>
using namespace std;


int partition(int a[],int n)
{
    int totalSUm = 0;
    for (int i = 0; i < n; i++)
    {
        totalSUm += a[i];
    }
    if (totalSUm % 2 != 0)return -1;
    int half = totalSUm / 2;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (t + a[i] <= half)
        {
            t += a[i];
            for (int j = i + 1; j < n; j++)
            {
                if (t + a[j] == half)return 1;
                else if(t+a[j]<=half)
                {
                    t += a[j];
                }
            }
            t = 0;
        }
    }
    return 0;
}
/*
struct Node {
    Node* left;
    Node* right;
    int val;
};
void Print(Node* r)
{
    stack<Node*>odd,even;
    even.push(r);
    odd.push(NULL);
    Node* t;
    int level = 0;
    while (!even.empty() || !odd.empty())
    {
        while (!even.empty())
        {
            t = even.top();
            even.pop();
            cout << t->val << " ";
            if (t->right != NULL)
                odd.push(t->right);
            if (t->left != NULL)
                odd.push(t->left);
        }
        while (!odd.empty())
        {
            t = odd.top();
            odd.pop();
            cout << t->val << " ";
            if (t->left != NULL)
                even.push(t->left);
            if (t->right != NULL)
                even.push(t->right);
        }
    }
}*/

int maxLen(int a[], int n) {
    unordered_map<int, pair<int, int>>m;
    int sum = 0, id, ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == 0) {
            id = i + 1;
            if (id > ans)ans = id;
        }
        else {
            if (m.count(sum) == 0)
            {
                m[sum].first = i;
            }
            else
            {
                id = i - m[sum].first;
                if (id > ans)ans = id;
                m[sum].second = i;
            }
        }
    }
    return ans;
}

long stockmax(vector<int> p) {
    long s = 0, l = p.size();
    stack<long>st;
    st.push(l - 1);
    for (int i = l - 2; i > 0; i--)
    {
        if (!st.empty() && p[i] > p[st.top()])
        {
            st.push(i);
        }
    }
    if (st.size() == 0)return s;
    for (int i = 0; i < l; i++)
    {
        if (!st.empty())
        {
            if (i < st.top())
            {
                if (p[i] < p[st.top()])
                    s += p[st.top()] - p[i];
                if (!st.empty() && i == st.top())
                    st.pop();
            }
            else 
                st.pop();
        }
        else return s;
    }
    return s;
}


//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n, x;
//        cin >> n;
//        vector<int>v;
//        for (int i = 0; i < n; i++)
//        {
//            cin >> x;
//            v.push_back(x);
//        }
//        stack<int>s;
//        s.push(v[n - 1]);
//        for (int i = n-2; i >=0; i--)
//        {
//            if (v[i] >= s.top())
//                s.push(v[i]);
//        }
//        while (!s.empty())
//        {
//            cout << s.top() << " ";
//            
//        }
//        cout << endl;
//    }
//    return 0;
//}


vector<int> increasingTriplet(vector<int> nums) {
    int min1 = INT_MAX, min2 = INT_MAX;
    vector<int>ans;
    for (int x : nums) {
        if (x < min1) {
            min1 = x;
        }
        else if (x < min2) {
            min2 = x;
        }
        else {
            ans.push_back(min1);
            ans.push_back(min2);
            ans.push_back(x);
            return ans;
        }
    }
    return ans;
}

    struct compare {
        bool f;
        bool operator()(vector<int>& p, vector<int>& q) {
            f= p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
            return f;
        }
    };
vector<vector<int>> kClosest(vector<vector<int>> points, int K) {
    priority_queue<vector<int>, vector<vector<int>>, compare> pq;
    for (vector<int>& point : points) {
        pq.push(point);
        if (pq.size() > K) {
            pq.pop();
        }
    }
    vector<vector<int>> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int search(vector<int> nums, int target) {
    int n = nums.size();
    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[left])
        {
            if (target <= nums[mid] && target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if (target >= nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}
int orangesRotting(vector<vector<int>> v) {
    queue<pair<int, int>>q;
    vector<int>d{ 0,-1,0,1,0 };
    int r = v.size(), c = v[0].size();
    int ans = 0, l = 0, ct = 0, a, b;
    pair<int, int>p;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 2)
            {
                q.push({ i,j });
            }
            else if (v[i][j] == 1)ct++;
        }
    }
    while (!q.empty())
    {
        l = q.size();
        ans++;
        while (l--)
        {
            p = q.front();
            q.pop();
            for (int i = 0; i < d.size() - 1; i++)
            {
                a = p.first + d[i];
                b = p.second + d[i + 1];
                if ((a >= 0 && a < r) && (b >= 0 && b < c) && v[a][b] == 1 && v[a][b]!=2)
                {
                    q.push({ a,b });
                    ct--;
                    v[a][b] = 2;
                }
            }
        }
    }
    if (ct == 0)return ans-1;
    else return -1;
}
int monotoneIncreasingDigits(int N) {
    string ans = to_string(N);
    int len = ans.length(), idx = len;
    for (int i = len - 2; i >= 0; --i) {
        if (ans[i] > ans[i + 1]) {
            idx = i + 1;
            ans[i]--;
        }
    }
    for (int i = idx; i < len; ++i)
        ans[i] = '9';
    return stoi(ans);
}
int main()
{
    monotoneIncreasingDigits(332);
    int a[] = { 1,2,1,1,3 }; 
    orangesRotting({ {2, 1, 1}, { 1,1,0 }, { 0,1,1 } });
    vector<vector<int>>v{ {4,7},{4,8},{2,8},{8,9},{1,6},{5,8},{1,2},{6,7},{3,10},{8,10},{1,5},{7,10},{1,10},{3,5},{3,6},{1,4},{3,9},{2,3},{1,9},{7,9},{2,7},{6,8},{5,7},{3,4} };
    
}
bool canBeEqual(vector<int>& t, vector<int>& v) {
    unordered_map<int, int>m;
    int s = 0;
    for (int i = 0; i < t.size(); i++)
    {
        m[t[i]]++;
        s++;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (m.count(v[i]) > 0 && s != 0)
        {
            m[v[i]]--;
            s--;
        }
        else return false;
    }
    return true;
}

int main1()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x,a=0,b=0,c=0;
        cin >> n;
        vector<int>v;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }
    }
    return 0;
}

string removeKdigits(string s, int k) {
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        while (!ans.empty() && ans.back() > s[i] && k--)
        {
            ans.pop_back();
        }
        if (ans != "" && s[i] != '0')ans.push_back(s[i]);
    }
    while (!ans.empty() && k--)ans.pop_back();
    return ans;
}
vector<int>v;
Solution(vector<int>& w) {
    v.push_back(w[0]);
    for (int i = 1; i < w.size(); i++)
    {
        v.push_back(v.back() + w[i]);
    }
}

int pickIndex() {
    int r = rand() % v.back();
    return upper_bound(v.begin(), v.end(), r) - v.begin();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        unordered_map<char, int> m;
        for (int i = 0; i < s1.size(); i++)
        {
            m[s1[i]]++;
        }
        bool f = false;
        for (int i = 0; i < s2.size(); i++)
        {
            if (m[s2[i]] > 0)
            {
                f = true;
                break;
            }
        }
        if (f)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

bool isSubsequence(string s, string t) {
    if (s.size() > t.size())
        return false;
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        if (s[i] == t[j])
        {
            i++; j++;
        }
        else
            j++;
    }
    if (i == s.size())return true;
    return false;
}

int searchInsert(vector<int>& v, int t) {
    int l=0, r=v.size()-1, m;
    while (l<r)
    {
        m = l + (r - l) / 2;
        if (v[m] == t)
            return m;
        else if(v[m]<t)

    }
}

void sortColors(vector<int>& v) {
    int o = 0, z = 0, t = v.size() - 1;
    while (o<t)
    {
        if (v[o] == 2)
        {
            swap(v[o], v[t]);
            t--;
        }
        else if (v[o] == 1)
        {
            swap(v[o], v[z]);
            o++;
            z++;
        }
        else
            o++;
    }
}