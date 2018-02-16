#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

class Solution {
public:
    bool isDigit(char c) {
        int i = c - '0';
        return i >= 0 && i <= 9;
    }

    int myAtoi(string str) {
        bool isNeg = false;
        int64_t res = 0;
        // has_sign表示是否已经出现过符号字符(+ or -)
        bool has_sign = false;

        for (int i = 0; i < str.length(); i++) {
            // 忽略数字前面的空格
            if (!has_sign && str[i] == ' ') {
                continue;
            }
            // 记录数字前面的符号位(+ or -)
            if (!has_sign && str[i] == '-') {
                isNeg = true;
                has_sign = true;
                continue;
            }
            if (!has_sign && str[i] == '+') {
                has_sign = true;
                continue;
            }
            // 出现了数字,开始计算
            // 如果计算过程中出现溢出,返回上限
            if (isDigit(str[i])) {
                has_sign = true;
                res = res * 10 + (str[i] - '0');
                if (res > 2147483647) {
                    return isNeg ? -2147483648 : 2147483647;
                } else {
                    continue;
                }
            }
            // 如果出现其他特殊字符,中止计算
            break;
        }
        if (isNeg) {
            res = -res;
        }
        return int(res);
    }
};

int main() {
    class Solution s;
    printf("atoi(12345) = %d\n", s.myAtoi("12345"));
    printf("atoi("") = %d\n", s.myAtoi(""));
    // printf("atoi("2") = %d\n", s.myAtoi("+-2"));
    printf("atoi(-12345) = %d\n", s.myAtoi("-12345"));
    printf("atoi(+12345) = %d\n", s.myAtoi("+12345"));
    printf("atoi(12345ABC) = %d\n", s.myAtoi("12345ABC"));
    printf("atoi(12345678900) = %d\n", s.myAtoi("12345678900"));
    printf("atoi(2147483647) = %d\n", s.myAtoi("2147483647"));
    printf("atoi(-2147483647) = %d\n", s.myAtoi("-2147483647"));
    printf("atoi(   - 321) = %d\n", s.myAtoi("   - 321"));
    printf("atoi(-2147483648) = %d\n", s.myAtoi("-2147483648"));
    printf("atoi(   214748364 8  ) = %d\n", s.myAtoi("   214748364 8"));
    return 0;
}
