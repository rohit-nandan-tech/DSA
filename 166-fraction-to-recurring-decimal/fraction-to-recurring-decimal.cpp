class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
    
    string result;
    
    // Handle sign
    if ((numerator < 0) ^ (denominator < 0)) result += "-";
    
    long num = labs((long)numerator);
    long den = labs((long)denominator);
    
    // Integer part
    result += to_string(num / den);
    long rem = num % den;
    if (rem == 0) return result; // no fractional part
    
    result += ".";
    
    // Fractional part
    unordered_map<long, int> seen; // remainder -> index in result string
    while (rem != 0) {
        if (seen.count(rem)) {
            result.insert(seen[rem], "(");
            result += ")";
            break;
        }
        seen[rem] = result.size();
        rem *= 10;
        result += to_string(rem / den);
        rem %= den;
    }
    
    return result;
    }
};