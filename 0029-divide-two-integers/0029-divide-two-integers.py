class Solution(object):
    def divide(self, dividend, divisor):
        # Edge case (overflow)
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        
        # Step 1: Handle sign
        sign = -1 if (dividend < 0) ^ (divisor < 0) else 1
        
        # Step 2: Convert to positive
        dividend = abs(dividend)
        divisor = abs(divisor)
        
        quotient = 0
        
        # Step 3: Bit manipulation
        while dividend >= divisor:
            temp = divisor
            multiple = 1
            
            while dividend >= (temp << 1):
                temp <<= 1
                multiple <<= 1
            
            dividend -= temp
            quotient += multiple
        
        return sign * quotient