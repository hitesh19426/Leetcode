class SnapshotArray {
    int snap_id = 0;
    vector<map<int, int, greater<int>>> snaps;
public:
    SnapshotArray(int length) {
        snaps.assign(length, map<int, int, greater<int>>());
        for(int i=0; i<length; i++)
            snaps[i][snap_id] = 0;
    }
    
    void set(int index, int val) {
        snaps[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        return snaps[index].lower_bound(snap_id)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */