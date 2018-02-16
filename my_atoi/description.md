**题目**

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.

**思路**

1. 该题思路是:从左到右顺序遍历字符串的每一个字符,如果是数字,那就将已计算得到的结果*10加上当前该字符代表的整数;
2. 如果在计算过程中得到的中间结果超过32-bit所能表示的整数范围(大于2147483647或小于-2147483648),那么返回临界值(-2147483648或者2147483647);
3. 需要去除字符串开头所有的空格;
4. 需要判断字符串开头是否是代表正负值的特殊符号(+/-),如果遇到多个+/-字符，返回的结果是0;
5. 计算过程中如果数字后出现了非数字字符,那么计算截止到最后一个数字字符位置
