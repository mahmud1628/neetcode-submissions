class Solution {
    int climbStairs(int startStair, int remaining_steps, vector<int> & mem) {
        if(startStair >= mem.size()) {
            return 0;
        }
        if(remaining_steps == 0) {
            return mem[startStair] = 1;
        }

        if(mem[startStair] == -1) {
            mem[startStair] = climbStairs(startStair + 1, remaining_steps - 1, mem) + climbStairs(startStair + 2, remaining_steps - 2, mem);
        }

        return mem[startStair];
    }
public:
    int climbStairs(int n) {
        vector<int> mem(n + 1, -1);
        return climbStairs(0, n, mem);
    }
};
