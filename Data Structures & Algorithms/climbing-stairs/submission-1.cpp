class Solution {
    int climbStairs(int remaining_steps, vector<int> & mem) {
        if(remaining_steps == 0) return 1;
        if(remaining_steps < 0) return 0;

        if(mem[remaining_steps] == -1) {
            mem[remaining_steps] = climbStairs(remaining_steps - 1, mem) + climbStairs(remaining_steps - 2, mem);
        }

        return mem[remaining_steps];
    }
public:
    int climbStairs(int n) {
        vector<int> mem(n + 1, -1);
        return climbStairs(n, mem);
    }
};
