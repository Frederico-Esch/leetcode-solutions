use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn length_of_longest_substring(s:String) -> i32{
        let mut letters = HashMap::new();
        let mut biggest = 0usize;
        let mut index = 0usize;
        let mut last_index = 0usize;
        for c in s.chars() {
            if let Some(&i) = letters.get(&c) {
                biggest = std::cmp::max(biggest, letters.len());
                let sub = &s[last_index..(i+1)];
                //letters.clear();
                sub.chars().for_each( | to_remove | {
                    letters.remove(&to_remove);
                });
                last_index = i+1;
            }
            letters.insert(c, index);
            index+=1;
        }
        biggest = std::cmp::max(biggest, letters.len());
        return biggest as i32;
    }
}

fn main() {
    let val = Solution::length_of_longest_substring("bpfbhmipx".to_string());
    println!("{}", val);
}
