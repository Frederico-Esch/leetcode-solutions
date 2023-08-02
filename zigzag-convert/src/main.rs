struct Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 || s.len() == 1{
            return s;
        }
        let s :Vec<char> = s.chars().collect();
        let mut first  = (num_rows-1) as usize;
        let mut second = 0;
        let mut result = String::new();
        for i in 0..num_rows {
            let i = i as usize;
            if i >= s.len() {
                break;
            }
            let c = s[i];
            result.push(c);

            let mut idx = i;
            loop {
                if first > 0 {
                    idx += 2*first;
                    if idx >= s.len(){
                        break;
                    }
                    let c = s[idx];
                    result.push(c);
                }
                if second > 0 {
                    idx += 2*second;
                    if idx >= s.len(){
                        break;
                    }
                    let c = s[idx];
                    result.push(c);
                }
            }
            if first > 0 {
                first  -= 1;
            }
            second += 1;
        }
        result
    }
}

pub fn main() {}

#[test]
fn example_1(){
    assert_eq!(Solution::convert("PAYPALISHIRING".into(), 3), "PAHNAPLSIIGYIR".to_string())
}

#[test]
fn example_2(){
    assert_eq!(Solution::convert("PAYPALISHIRING".into(), 4), "PINALSIGYAHRPI".to_string())
}

#[test]
fn example_3(){
    assert_eq!(Solution::convert("A".into(), 1), "A".to_string())
}
