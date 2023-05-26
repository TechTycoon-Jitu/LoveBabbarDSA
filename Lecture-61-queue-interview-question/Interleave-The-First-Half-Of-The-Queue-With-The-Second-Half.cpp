#include <bits/stdc++.h> 
void interLeaveQueue(queue < int > & q) {
    stack<int>s;
    int size = q.size();
    for(int i=0;i<size/2;i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
    }
    for(int i= 0;i<size/2;i++)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }
     for(int i=0;i<size/2;i++)
    {
        int val = q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty())
    {
        int val = s.top();
        s.pop();
        q.push(val);
        int element = q.front();
        q.pop();
        q.push(element);
    }
    
}