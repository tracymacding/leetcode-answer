**题目**

Given a 32-bit signed integer, reverse digits of an integer.
Example 1:
```
Input: 123
Output:  321
```
Example 2:
```
Input: -123
Output: -321
```
Example 3:
```
Input: 120
Output: 21
```
Note:
Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

**思路**
1. 该题思路非常简单，不停地将原始输入数据%10得到余数，然后将余数往得到的结果中相加，如123进行逆置的过程就是: x=123, 123%10 = 3, x=123/10=12, res = 3 x=12, 12%10=2, x=12/10=1, res=res*10+2=32; x=1,1%10=1, res=32*10+1=321, x=1/10=0(over);得到最终结果为321;
2. 该题需要特别注意的是对于临界值的处理，因为题干明确说明了是32-bit的integer，其逆置结果也是32位integer,需要特别考虑以下几种临界情况：
   * 输入值超过了32-bit能表达的最大整数范围(2^31-1);
   * 输入值是一个负数;
   * 逆置过程中的计算得到的中间结果(1中的res)超过了32-bit整数表达范围(2^31-1)  
