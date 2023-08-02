use std::cmp::max;
struct Solution;

#[derive(Copy, Clone)]
struct CharPos {
    val: usize,
    found: bool
}

struct Pointer {
    left  : usize,
    right : usize
}

impl Pointer {
    fn size(&self) -> i32{
        (self.right - self.left) as i32
    }
}

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut mask    = [ CharPos {val: 0, found: false} ; 256];
        let mut pointer = Pointer {left: 0, right: 0};
        let mut biggest = 0;
        for c in s.chars().map(|c| (c as usize)) {
            if mask[c].found {
                biggest = max(pointer.size(), biggest);
                for i in s[pointer.left..mask[c].val + 1].chars().map(|i| (i as usize)) {
                    mask[i].found = false;
                }
                pointer.left = mask[c].val+1;
            }
            mask[c].found = true;
            mask[c].val   = pointer.right;
            pointer.right += 1;
        }
        max(biggest, pointer.size())
    }
}

fn main() {
    println!("{}", Solution::length_of_longest_substring("abcd".to_string()));
}
