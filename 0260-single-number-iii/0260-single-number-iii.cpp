class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int overall_xor = 0;
        for(int num : nums){
            overall_xor ^= num;
        }

        int dif_bit_position = 0;
        while(((overall_xor >> dif_bit_position) & 1) != 1){
            dif_bit_position++;
        }

        int first_group_xor = 0;
        int second_group_xor = 0;
        for(int num : nums){
            if(((num >> dif_bit_position) & 1) == 0){
                first_group_xor ^= num;
            } else{
                second_group_xor ^= num;
            }
        }

        return {first_group_xor, second_group_xor};
    }
};