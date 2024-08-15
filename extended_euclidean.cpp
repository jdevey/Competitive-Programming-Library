/*
An inverse mod is the number x such that b*x = 1, when the answer is modded by some number m. This can be rewritten:
bx + my = 1
Of course, either x or y will be negative, as the two will be negating one another, in a way.
For example, if b = 100, and m = 97, then x = 65 and y = -67 since 100*65 - 97*67 = 1. Remember, we only really care about x, the inverse modulo.

Often, when we use this algorithm, we are trying to find (a/b)%M. Knowing how inverse modulo works helps us here since if you know x such that
b*x = 1 (mod m), then you can find b*x = a (mod m) by simply multiplying your answer by a, and modding again if you please.

To proceed, we first use the euclidean algorithm to produce a chain of mod results. For example, given 100 and 97, this chain would be:
100, 97, 3, 1, 0
However, since this is the extended euclidean algorithm, we're not done yet.

We then proceed by taking the equation bx + ay = 1, and proceeding to rewrite 1 with larger and larger terms, until we arrive at an answer that is
in terms of a and b. Here's an example: 19887, 8854. (The numbers must be coprime.)

First, we create the chain of modulo results:
19887 % 8854 = 2179
8854 % 2179 = 138
2179 % 138 = 109
138 % 109 = 29
109 % 29 = 22
29 % 22 = 7
22 % 7 = 1
7 % 1 = 0 (End recursion here.)

We now have a result that equals one. (22 % 7 = 1) Once we dig deep enough, we will see that this is a linear combination of 19887 and 8854, but it takes a while to get there.

When we hit line 7 % 1 = 0, we let x = 1 and y = 0. x will denote the coefficient in front of the larger number.

We then, as we move back up the recursion ladder, let x equal the old_y, and y equal old_x - a/b * old_y.
As we are moving up the recursion ladder, if we are to eventually rewrite everything in terms of 19887 and 8554, we will have to rewrite the smallest term in each line in terms of the two larger terms above it.

For example, we start on the bottom line, and then move up. x is now 1 and y is now 3, hence 1*22 - 3*7 = 1.
We then rewrite 7 in terms of 29 and 22. 1*22 - 3*(29 - 1*22) = 1. If x is to represent the larger number, then x = -3, and y = 4.
So far we have -3*29 + 4*22 = 1.
We then rewrite 22 in terms of 109 and 29.
-3*29 + 4*(109 - 3*29) = 1 -> 4*109 - 15*29 = 1
Continuing this process...
4*109 - 15*(138 - 1*109) = 1 -> -15*138 + 19*109 = 1
-15*138 + 19*(2179 - 15*138) = 1 -> 19*2179 - 300*138 = 1
19*2179 - 300*(8854 - 4*2179) = 1 -> -300*8854 + 1219*2179 = 1
-300*8854 + 1219*(19887 - 2*8854) = 1 -> 1219*19887 - 2738*8854 = 1

1219 is our answer.

To view the entire process in full:
--------------------> 1*1 - 0*0 = 1 (x = 1 and y = 0)
1*1 - 0*(7 - 7*1) = 1 -> -0 * 7 + 1*1 = 1
-0*7 + 1*(22 - 3*7) = 1 -> 1*22 - 3*7 = 1
1*22 - 3*(29 - 1*22) = 1 -> -3*29 + 4*22 = 1
-3*29 + 4*(109 - 3*29) = 1 -> 4*109 - 15*29 = 1
4*109 - 15*(138 - 1*109) = 1 -> -15*138 + 19*109 = 1
-15*138 + 19*(2179 - 15*138) = 1 -> 19*2179 - 300*138 = 1
19*2179 - 300*(8854 - 4*2179) = 1 -> -300*8854 + 1219*2179 = 1
-300*8854 + 1219*(19887 - 2*8854) = 1 -> 1219*19887 - 2738*8854 = 1
*/

void ext(ll a, ll b, ll& x, ll& y) {
    if (!b) {
        x = 1;
        y = 0;
        return;
    }
    ext(b, a % b, x, y);
    ll temp = x - a / b * y;
    x = y;
    y = temp;
}

ll modInv(ll a) {
    ll x, y;
    ext(a, BIG, x, y);
    return x < 0 ? x + BIG : x;
}

