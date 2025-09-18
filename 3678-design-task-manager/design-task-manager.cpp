class TaskManager {
public:
    map<int, set<int>> p2t;
    unordered_map<int, int> t2p;
    unordered_map<int, int> t2u;
    TaskManager(vector<vector<int>>& tasks) {
        //cout<<"tt"<<endl;
        for (auto i : tasks) {
            p2t[i[2]].insert(i[1]);
            t2p[i[1]] = i[2];
            t2u[i[1]] = i[0];
        }
    }

    void add(int u, int t, int p) {
       // cout<<"aa"<<endl;
        p2t[p].insert(t);
        t2p[t] = p;
        t2u[t] = u;
    }

    void edit(int t, int newp) {
        int oldp = t2p[t];
        auto it = p2t[oldp].lower_bound(t);
        p2t[oldp].erase(it);
        if(p2t[oldp].size()==0)
        p2t.erase(oldp);
        p2t[newp].insert(t);
        t2p[t] = newp;
    }

    void rmv(int taskId) {
        int p = t2p[taskId];
        p2t[p].erase(taskId);
        if(p2t[p].size()==0)
        p2t.erase(p);
        t2p.erase(taskId);
        t2u.erase(taskId);
    }

    int execTop() {
        if (p2t.size() == 0)
            return -1;
        auto it = prev(p2t.end()); 
        int ans = t2u[*prev(it->second.end())];
        it->second.erase(prev(it->second.end()));
        if (it->second.empty())
            p2t.erase(it);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */