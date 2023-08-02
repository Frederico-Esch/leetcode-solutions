struct Solution;

impl Solution {
    pub fn rob(nums : Vec<i32>) -> i32 {
        if nums.len() == 1 {
            return nums[0];
        } else if nums.len() == 2 {
            return std::cmp::max(nums[0], nums[1]);
        }

        let mut ant: [i32; 2] = [0,0];

        ant[0] = nums[0];
        ant[1] = std::cmp::max(nums[1], nums[0]);

        for i in 2..nums.len() {
            let atual = std::cmp::max(nums[i] + ant[0], ant[1]);
            ant[0] = ant[1];
            ant[1] = atual;
            //println!("ant[0] = {}, ant[1] = {}, {} = {}", ant[0], ant[1], i, atual);
        }
        std::cmp::max(ant[0], ant[1])
    }
}

fn main() {
    println!("{}", Solution::rob(vec![2,7,9,3,1]));
}
