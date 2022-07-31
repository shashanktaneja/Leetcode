class node {
public:
	int data;
	int l;
	int r;
};

class NumArray {
public:
    vector<node> seg;
    
    int solve(int qlow, int qhigh, int idx) {
        if (seg[idx].l >= qlow and seg[idx].r <= qhigh) {
            return seg[idx].data;
        }

        if (seg[idx].l > qhigh || seg[idx].r < qlow) {
            return 0;
        }

        return solve(qlow, qhigh, 2 * idx + 1) + solve(qlow, qhigh, 2 * idx + 2);
    }
    
    void up(int qlow, int qhigh,int idx, int val){
        if(seg[idx].l==qlow and seg[idx].r==qhigh){
            seg[idx].data = val;
            return;
        }
        
        if(seg[2*idx+1].r>=qlow){
            up(qlow, qhigh,2*idx+1,val);
        }
        else{
            up(qlow, qhigh,2*idx+2,val);
        }
        
        seg[idx].data = seg[2*idx+1].data+seg[2*idx+2].data;
    }
    
    NumArray(vector<int>& v) {
        int n = v.size();
        int si = pow(2, ceil(log2(n)));        
        seg.resize(2*si-1);
        int j = 0;

        for (int i = si - 1; i < (2 * si) - 1; i++) {
            seg[i].l = j;
            seg[i].r = j;
            seg[i].data = v[j];

            if (j >= n) {
                seg[i].data = 0;
            }

            j++;
        }

        for (int i = si - 2; i >= 0; i--) {
            int l = seg[(2 * i + 1)].data;
            int r = seg[2 * i + 2].data;

            seg[i].data = (l + r);
            seg[i].l = seg[2 * i + 1].l;
            seg[i].r = seg[2 * i + 2].r;
        }
    }
    
    void update(int i, int val) {
        up(i,i,0,val);
    }
    
    int sumRange(int x, int y) {
        int ans = solve(x, y, 0);
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */