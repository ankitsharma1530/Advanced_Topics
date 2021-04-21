int findXor(int arr[], int n)
{
 
    // Calculate xor of all the elements
    int xoR = 0;
    for (int i = 0; i < n; i++) {
        xoR = xoR ^ arr[i];
    }
 
    // Return twice of xor value
    return xoR * 2;
}
