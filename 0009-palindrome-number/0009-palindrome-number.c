bool isPalindrome(int x) {
    // Negative numbers are not palindromes
    // Numbers ending in 0 (except 0 itself) are not palindromes
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversedHalf = 0;

    // Reverse only half of the digits
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // Even number of digits:
    // x == reversedHalf
    //
    // Odd number of digits:
    // x == reversedHalf / 10
    return x == reversedHalf || x == reversedHalf / 10;
}