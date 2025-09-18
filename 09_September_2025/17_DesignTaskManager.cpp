// https://leetcode.com/problems/design-task-manager/?envType=daily-question&envId=2025-09-18

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

struct Task{
    int userId;
    int taskId;
    int priority;
};
struct compare{
    bool operator()(const Task&a,const Task&b)const {
        if(a.priority==b.priority){
            return a.taskId>b.taskId;
        }
        return a.priority>b.priority;

    }
};
class TaskManager {
public:
set<Task,compare>st;
map<int,pair<int,int>>mp;
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it:tasks){
           st.insert({it[0],it[1],it[2]});
           mp[it[1]]={it[0],it[2]};

        }
        
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={userId,priority};
        st.insert({userId,taskId,priority});

        
    }
    
    void edit(int taskId, int newPriority) {
        auto it=mp[taskId];
        int userId=it.first;
        int priority=it.second;
        st.erase({userId,taskId,priority});
        st.insert({userId,taskId,newPriority});
        mp[taskId]={userId,newPriority};

        
    }
    
    void rmv(int taskId) {
        auto it=mp[taskId];
        int userId=it.first;
        int priority=it.second;
        st.erase({userId,taskId,priority});
        mp.erase(taskId);
        
    }
    
    int execTop() {
       for(auto it:st){
        auto ele=it;
        st.erase(ele);
        int taskId=ele.taskId;
        return ele.userId;
        mp.erase(taskId);

       }
       return -1;
        
    }
};


int main () {
    
    return 0;
}