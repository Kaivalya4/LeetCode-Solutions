class SORTracker {
public:
    int i =0;
    struct comp2{
        bool operator()(pair<int,string> &a , pair<int,string>&b){
            if(a.first < b.first)
                return true;
            else if(a.first == b.first){
                if(a.second > b.second)
                    return true;
            }
            return false;
        }
    };
    
    struct comp1{
        bool operator()(pair<int,string> &a , pair<int,string> &b){
            if(a.first > b.first)
                return true;
            else if(a.first == b.first){
                if(a.second < b.second)
                    return true;
            }
            return false;
        }
    };
    priority_queue<pair<int,string> , vector<pair<int,string>> , comp1> minheap;
    priority_queue<pair<int,string> , vector<pair<int,string>> , comp2> maxheap;
    SORTracker() {
        return ;
    }
    
    void add(string name, int score) {
        minheap.push(make_pair(score,name));
        
        if(minheap.size() > i+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    string get() {
        i++;
        string ans = minheap.top().second;
        if(maxheap.size() >0){
            int top1  = maxheap.top().first;
            string top2 = maxheap.top().second;
            maxheap.pop();
            add(top2 , top1);
        }
        return ans;
    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */