romanos = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000
}

def romanToInt(s:str) -> int:
    last_one = 1000
    result = 0
    for c in s:
        value = romanos[c]
        if value <= last_one:
            last_one = value
            result += value
        else:
            result -= last_one*2
            result += value
    return result

print(romanToInt("XL"))
