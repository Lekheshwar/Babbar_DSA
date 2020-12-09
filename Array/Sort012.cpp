//https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

void sort012(int a[], int n)
{
    int ZRO = 0;
    int TWO = n - 1;
    int ONE = 0;
    
    while(ONE <= TWO){
        if(a[ONE] == 0){
            swap(a[ZRO], a[ONE]);
            ZRO++;
            ONE++;
        }
        else if(a[ONE] == 2){
            swap(a[ONE], a[TWO]);
            TWO--;
        }
        else{
            ONE++;
        }
    }
}
