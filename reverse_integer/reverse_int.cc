#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stdint.h>


using namespace std;

class Solution {
public:
    int reverse(int x) {
        int64_t res = 0;
	// negX是输入x的绝对值
	// 类型为uint32_t避免溢出
	// 如果x为-2147483648,不使用uit32_t会导致-x依然是-2147483648
        uint32_t negX = 0;
        bool isNeg = false;

        if (x < 0) {
            isNeg = true;
	    negX = -x;
        } else {
	    negX = x;
	}

	if (negX > 2147483647) {
            return 0;
        }

        uint32_t m, n;
        do {
            m = negX / 10;
            n = negX % 10;
            res = res * 10 + n;
            // 计算可能会溢出,此时返回0
            if (res > 2147483647) {
		return 0;
	    }
            negX = m;
        } while(negX != 0);

        if (isNeg) {
            res = -res;
        }
        return int32_t(res);
    }
};

int main() {
    class Solution s;
    printf("%d\n", s.reverse(-2147483648));
    printf("%d\n", s.reverse(123));
    printf("%d\n", s.reverse(120));
    return 0;
}
