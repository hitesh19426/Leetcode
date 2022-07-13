bool makePalindrome(char * s){
    int low = 0, high = strlen(s)-1, count = 0;
    while(low < high){
        if(s[low] != s[high])
            count++;
        if(count > 2)
            return false;
        low++, high--;
    }
    return true;
}