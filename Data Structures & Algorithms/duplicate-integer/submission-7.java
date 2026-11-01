class Solution {
    public boolean hasDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();

        for(var v : nums) {
            if(s.contains(v))
                return true;
            else 
                s.add(v);
        }

        return false;
    }
}