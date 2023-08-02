static LETTERS: [&str;8] = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"];

fn get_range(val: u32) -> &'static str{
    let val = val - 2;
    &LETTERS[val as usize]
}

fn letter_combination(digits:String) -> Vec<String> {
    let mut result = vec![];
    for dig in digits.chars() {
        let dig = dig.to_digit(10).unwrap();

        if result.len() == 0 {
            get_range(dig).chars().for_each(|c| result.push(c.to_string()));
        }else {
            let mut new_result = vec![];
            let original = &result[0..];
            let range    = get_range(dig);
            for c in original {
                range.chars().for_each(|nc| {
                    new_result.push(c.to_owned() + &nc.to_string());
                });
            }
            result = new_result;
        }
    }
    result
}

fn main() {
    println!("{:?}", letter_combination("2".to_string()));
}
