/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 * 
 * 
 * 
 * 
 ******************** 
 * IT JUST PASSED 13/15 OF TEST CASES, 
 * WHICH I DIDN'T FIGURE THE PROBLEM OUT
 * 
 * 
 */
int palindromeIndex(string s) {
    int i = 0;
    int j = s.size() - 1;

    if (s.size() < 3) {
        if (s.size() == 1)
	    return -1;
        else
            return (s[0] == s[1]) ? -1 : 0;
    }

    // check if it's palindrome or not
    while (i < j) {
        if (s[i] != s[j])
            break; 
	i++;
	j--; 
    }
    if (i >= j)
        return -1;

    int ii = i + 1;
    int jj = j;
    while (ii < jj) {
        if (s[ii] != s[jj])
            return j;
	ii++;
	jj--; 
    }

    return i; 
}