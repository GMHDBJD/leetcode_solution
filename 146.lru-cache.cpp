/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

/*
order
*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> l;
    int cap = 0;
    LRUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (m.count(key))
        {
            l.push_front(*m[key]);
            l.erase(m[key]);
            m[key] = l.begin();
            return l.front().second;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        if (m.count(key))
        {
            m[key]->second = value;
            get(key);
            return;
        }
        if (m.size() == cap)
        {
            auto p = l.back();
            l.pop_back();
            m.erase(p.first);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
