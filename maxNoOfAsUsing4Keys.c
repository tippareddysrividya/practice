/* A recursive C program to print maximum number of A's using following four keys */
#include<stdio.h>

// A recursive function that returns the optimal length string 
// for N keystrokes

int findoptimal(int n)
{
	int max = 0;
 	int b;
    // The optimal string length is N when N is smaller than 7
    if (n<= 6)
    {
        return n;
    }
    // TRY ALL POSSIBLE BREAK-POINTS
    // For any keystroke N, we need to loop from N-3 keystrokes
    // back to 1 keystroke to find a breakpoint 'b' after which we
    // will have Ctrl-A, Ctrl-C and then only Ctrl-V all the way.
   
    for (b=n-3; b>=1; b--)
    {
		// If the breakpoint is s at b'th keystroke then
		// the optimal string would have length
		// (n-b-1)*screen[b-1];
		int curr = (n-b-1)*findoptimal(b);
		if (curr > max)
		max = curr;
     }
     return max;
}

int main()
{
    int n=3;
    printf("Maximum Number of A's with %d keystrokes is %d\n",n, findoptimal(n));
    return 0;
}
