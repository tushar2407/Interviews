struct greater1{
    bool operator()(const int& a,const int& b) const{
        return a>b;
    }
};
class SeatManager {
public:
    vector<int> h;
    SeatManager(int n) {
        for(int i=0;i<n;i++)
            h.push_back(i+1);
        make_heap(h.begin(), h.end(), greater1());
    }
    
    int reserve() {
        int ans = h.front();
        pop_heap(h.begin(), h.end(), greater1());
        h.pop_back();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        h.push_back(seatNumber);
        push_heap(h.begin(), h.end(), greater1());
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */