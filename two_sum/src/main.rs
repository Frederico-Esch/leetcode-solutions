use std::collections::HashMap;
struct Solution;

impl Solution {
    pub fn two_sum(nums:Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        let mut index = 0;
        for num in nums {
            if let Some(&value) = map.get(&num) {
                return vec![value, index];
            }
            map.insert(target-num, index);
            index+=1;
        }
        return vec![];
    }
}

pub fn main(){
    let result = Solution::two_sum(vec![2, 7, 11, 14], 9);
    println!("{} {}", result[0], result[1]);
}

#[test]
fn example_1() {
    assert_eq!(Solution::two_sum(vec![2, 7, 11, 14], 9), vec![0, 1]);
}

#[test]
fn example_2() {
    assert_eq!(Solution::two_sum(vec![3,2,4], 6), vec![1, 2]);
}

#[test]
fn example_3() {
    assert_eq!(Solution::two_sum(vec![3,3], 6), vec![0, 1]);
}
