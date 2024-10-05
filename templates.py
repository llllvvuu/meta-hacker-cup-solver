ONE_SHOT_FIXED = r"""<tags>
<tag>implementation</tag>
<tag>math</tag>
<tag>greedy</tag>
<tag>dynamic programming</tag>
<tag>data structures</tag>
<tag>brute force</tag>
<tag>constructive algorithms</tag>
<tag>graphs</tag>
<tag>sorting</tag>
<tag>binary search</tag>
<tag>dfs and similar</tag>
<tag>trees</tag>
<tag>strings</tag>
<tag>number theory</tag>
<tag>combinatorics</tag>
<tag>geometry</tag>
<tag>bitmasks</tag>
<tag>two pointers</tag>
<tag>dsu</tag>
<tag>shortest paths</tag>
<tag>probabilities</tag>
<tag>divide and conquer</tag>
<tag>hashing</tag>
<tag>game theory</tag>
<tag>flows</tag>
<tag>interactive</tag>
<tag>matrices</tag>
<tag>string suffix structures</tag>
<tag>fft</tag>
<tag>graph matchings</tag>
<tag>ternary search</tag>
<tag>expression parsing</tag>
<tag>meet-in-the-middle</tag>
<tag>2-sat</tag>
<tag>chinese remainder theorem</tag>
<tag>schedules</tag>
<tag>sliding window</tag>
<tag>recursion</tag>
<tag>backtracking</tag>
<tag>segment trees</tag>
<tag>fenwick trees</tag>
<tag>maximum flow</tag>
<tag>minimum spanning tree</tag>
<tag>topological sort</tag>
<tag>trie</tag>
<tag>suffix array</tag>
<tag>kmp algorithm</tag>
<tag>z algorithm</tag>
<tag>binary lifting</tag>
<tag>heavy-light decomposition</tag>
<tag>centroid decomposition</tag>
<tag>sqrt decomposition</tag>
<tag>mo's algorithm</tag>
<tag>convex hull</tag>
<tag>line sweep</tag>
<tag>matrix exponentiation</tag>
<tag>persistent data structures</tag>
<tag>euler tour technique</tag>
<tag>lowest common ancestor</tag>
<tag>strongly connected components</tag>
<tag>biconnected components</tag>
<tag>articulation points and bridges</tag>
<tag>gaussian elimination</tag>
<tag>expected value</tag>
<tag>bfs</tag>
</tags>
<problem>
*Nim Sum Dim Sum*, a bustling local dumpling restaurant, has two game theory-loving servers named, you guessed it, Alice and Bob. Its dining area can be represented as a two-dimensional grid of \(R\) rows (numbered \(1..R\) from top to bottom) by \(C\) columns (numbered \(1..C\) from left to right\).

Currently, both of them are standing at coordinates \((1, 1)\) where there is a big cart of dim sum. Their job is to work together to push the cart to a customer at coordinates \((R, C)\). To make the job more interesting, they've turned it into a game.

Alice and Bob will take turns pushing the cart. On Alice's turn, the cart must be moved between \(1\) and \(A\) units down. On Bob's turn, the cart must be moved between \(1\) and \(B\) units to the right. The cart may not be moved out of the grid. If the cart is already at row \(R\) on Alice's turn or column \(C\) on Bob's turn, then that person loses their turn.

The "winner" is the person to ultimately move the cart to \((R, C)\) and thus get all the recognition from the customer. Alice pushes first. Does she have a guaranteed winning strategy?


# Constraints

\(1 \leq T \leq 500\)
\(2 \leq R, C \leq 10^9\)
\(1 \leq A < R\)
\(1 \leq B < C\)


# Input Format

Input begins with an integer \(T\), the number of test cases. Each case will contain one line with four space-separated integers, \(R\), \(C\), \(A\), and \(B\).


# Output Format

For the \(i\)th test case, print `"Case #i: "` followed by `"YES"` if Alice has a guaranteed winning strategy, or `"NO"` otherwise.

# Sample Input

3
2 2 1 1
5 2 3 1
4 4 3 3

# Sample Output

Case #1: NO
Case #2: YES
Case #3: NO

# Sample Explanation

The first case is depicted below, with Alice's moves in red and Bob's in blue. Alice moves down, and Bob moves right to win immediately. There is no other valid sequence of moves, so Alice has no guaranteed winning strategy.

{{PHOTO_ID:842253013944047|WIDTH:500}}

The second case is depicted below. One possible guaranteed winning strategy is if Alice moves \(3\) units down, then Bob can only move \(1\) unit, and finally Alice can win with \(1\) unit.

{{PHOTO_ID:852013469652032|WIDTH:500}}

# Solution

<tags>
<tag>game theory</tag>
<tag>greedy</tag>
<tag>math</tag>
</tags>

If Alice reaches row \(R\) before Bob reaches row \(C\), then it's game over for Alice. Since each player now wants to get to the finish as slowly as possible, both have a simple dominating strategy of only moving \(1\) unit in their direction each turn, and \(R\) and \(C\) are the only things that matter.

If \(R \le C\), Bob can always force Alice to reach row \(R\) first by moving \(1\) unit right at a time. Alice also only moves \(1\) unit at a time, because if she moves any faster, she'll just get stuck sooner. 

Example: Alice moves first:
```
[ ][ ][ ][ ]
[x][ ][ ][ ]
[ ][ ][ ][ ]
```

Bob:
```
[ ][ ][ ][ ]
[ ][x][ ][ ]
[ ][ ][ ][ ]
```

Alice moves, and gets stuck to watch Bob stroll to the finish line:
```
[ ][ ][ ][ ]
[ ][ ][ ][ ]
[ ][x][ ][ ]
```

Conversely, if \(R > C\), then Alice can always force a win by moving \(1\) step at a time. Therefore we output "`YES`" if and only if \(R > C\), regardless of the values of \(A\) and \(B\).

# Implementation
```cpp
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int R, C, A, B;
    cin >> R >> C >> A >> B;
    cout << (R > C ? "YES" : "NO") << endl;
  }
  return 0;
}
```
</problem>"""

ONE_SHOT_OBSERVATIONS_FIXED = r"""<tags>
<tag>implementation</tag>
<tag>math</tag>
<tag>greedy</tag>
<tag>dynamic programming</tag>
<tag>data structures</tag>
<tag>brute force</tag>
<tag>constructive algorithms</tag>
<tag>graphs</tag>
<tag>sorting</tag>
<tag>binary search</tag>
<tag>dfs and similar</tag>
<tag>trees</tag>
<tag>strings</tag>
<tag>number theory</tag>
<tag>combinatorics</tag>
<tag>geometry</tag>
<tag>bitmasks</tag>
<tag>two pointers</tag>
<tag>dsu</tag>
<tag>shortest paths</tag>
<tag>probabilities</tag>
<tag>divide and conquer</tag>
<tag>hashing</tag>
<tag>game theory</tag>
<tag>flows</tag>
<tag>interactive</tag>
<tag>matrices</tag>
<tag>string suffix structures</tag>
<tag>fft</tag>
<tag>graph matchings</tag>
<tag>ternary search</tag>
<tag>expression parsing</tag>
<tag>meet-in-the-middle</tag>
<tag>2-sat</tag>
<tag>chinese remainder theorem</tag>
<tag>schedules</tag>
<tag>sliding window</tag>
<tag>recursion</tag>
<tag>backtracking</tag>
<tag>segment trees</tag>
<tag>fenwick trees</tag>
<tag>maximum flow</tag>
<tag>minimum spanning tree</tag>
<tag>topological sort</tag>
<tag>trie</tag>
<tag>suffix array</tag>
<tag>kmp algorithm</tag>
<tag>z algorithm</tag>
<tag>binary lifting</tag>
<tag>heavy-light decomposition</tag>
<tag>centroid decomposition</tag>
<tag>sqrt decomposition</tag>
<tag>mo's algorithm</tag>
<tag>convex hull</tag>
<tag>line sweep</tag>
<tag>matrix exponentiation</tag>
<tag>persistent data structures</tag>
<tag>euler tour technique</tag>
<tag>lowest common ancestor</tag>
<tag>strongly connected components</tag>
<tag>biconnected components</tag>
<tag>articulation points and bridges</tag>
<tag>gaussian elimination</tag>
<tag>expected value</tag>
<tag>bfs</tag>
</tags>
<problem>
*Nim Sum Dim Sum*, a bustling local dumpling restaurant, has two game theory-loving servers named, you guessed it, Alice and Bob. Its dining area can be represented as a two-dimensional grid of \(R\) rows (numbered \(1..R\) from top to bottom) by \(C\) columns (numbered \(1..C\) from left to right\).

Currently, both of them are standing at coordinates \((1, 1)\) where there is a big cart of dim sum. Their job is to work together to push the cart to a customer at coordinates \((R, C)\). To make the job more interesting, they've turned it into a game.

Alice and Bob will take turns pushing the cart. On Alice's turn, the cart must be moved between \(1\) and \(A\) units down. On Bob's turn, the cart must be moved between \(1\) and \(B\) units to the right. The cart may not be moved out of the grid. If the cart is already at row \(R\) on Alice's turn or column \(C\) on Bob's turn, then that person loses their turn.

The "winner" is the person to ultimately move the cart to \((R, C)\) and thus get all the recognition from the customer. Alice pushes first. Does she have a guaranteed winning strategy?


# Constraints

\(1 \leq T \leq 500\)
\(2 \leq R, C \leq 10^9\)
\(1 \leq A < R\)
\(1 \leq B < C\)


# Input Format

Input begins with an integer \(T\), the number of test cases. Each case will contain one line with four space-separated integers, \(R\), \(C\), \(A\), and \(B\).


# Output Format

For the \(i\)th test case, print `"Case #i: "` followed by `"YES"` if Alice has a guaranteed winning strategy, or `"NO"` otherwise.

# Sample Input

3
2 2 1 1
5 2 3 1
4 4 3 3

# Sample Output

Case #1: NO
Case #2: YES
Case #3: NO

# Sample Explanation

The first case is depicted below, with Alice's moves in red and Bob's in blue. Alice moves down, and Bob moves right to win immediately. There is no other valid sequence of moves, so Alice has no guaranteed winning strategy.

{{PHOTO_ID:842253013944047|WIDTH:500}}

The second case is depicted below. One possible guaranteed winning strategy is if Alice moves \(3\) units down, then Bob can only move \(1\) unit, and finally Alice can win with \(1\) unit.

{{PHOTO_ID:852013469652032|WIDTH:500}}

# Solution

<paraphrasing>
- R rows and C columns in a grid
- Alice and Bob start at (1,1) and need to reach (R,C)
- Alice moves 1 to A units down, Bob moves 1 to B units right
- Players take turns, Alice goes first
- Can't move out of grid, lose turn if already at edge
- Winner is the one who reaches (R,C)
- Alice wins if she has a guaranteed winning strategy
</paraphrasing>
<paraphrased>
Alice and Bob play a turn-based game on an R x C grid. Starting at (1,1), they aim to reach (R,C). Alice moves 1-A units down, Bob moves 1-B units right. They alternate turns, with Alice going first. Players can't move beyond the grid; reaching the edge means losing that turn. The winner is whoever makes the final move to (R,C). We need to determine if Alice has a guaranteed winning strategy.
</paraphrased>
<observations>
<observation>If a player reaches the edge first, they can't make any more moves. So, they will lose.</observation>
<observation>To avoid losing, each player should try to reach the edge as late as possible.</observation>
<observation>Optimal play is to move only one unit at a time.</observation>
<observation>A and B are irrelevant.</observation>
<observation>The player who reaches the edge the latest is the player with more spaces to move. This depends on comparing R and C.</observation>
<observation>If R = C, then the first player, that is Alice, loses.</observation>
<observation>Hence, Alice wins iff R > C.</observation>
</observations>

<tags>
<tag>game theory</tag>
<tag>greedy</tag>
<tag>math</tag>
</tags>

If Alice reaches row \(R\) before Bob reaches row \(C\), then it's game over for Alice. Since each player now wants to get to the finish as slowly as possible, both have a simple dominating strategy of only moving \(1\) unit in their direction each turn, and \(R\) and \(C\) are the only things that matter.

If \(R \le C\), Bob can always force Alice to reach row \(R\) first by moving \(1\) unit right at a time. Alice also only moves \(1\) unit at a time, because if she moves any faster, she'll just get stuck sooner. 

Example: Alice moves first:
```
[ ][ ][ ][ ]
[x][ ][ ][ ]
[ ][ ][ ][ ]
```

Bob:
```
[ ][ ][ ][ ]
[ ][x][ ][ ]
[ ][ ][ ][ ]
```

Alice moves, and gets stuck to watch Bob stroll to the finish line:
```
[ ][ ][ ][ ]
[ ][ ][ ][ ]
[ ][x][ ][ ]
```

Conversely, if \(R > C\), then Alice can always force a win by moving \(1\) step at a time. Therefore we output "`YES`" if and only if \(R > C\), regardless of the values of \(A\) and \(B\).

# Implementation
```cpp
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int R, C, A, B;
    cin >> R >> C >> A >> B;
    cout << (R > C ? "YES" : "NO") << endl;
  }
  return 0;
}
```
</problem>"""

TWO_SHOT_OBSERVATIONS_FIXED = r"""<tags>
<tag>implementation</tag>
<tag>math</tag>
<tag>greedy</tag>
<tag>dynamic programming</tag>
<tag>data structures</tag>
<tag>brute force</tag>
<tag>constructive algorithms</tag>
<tag>graphs</tag>
<tag>sorting</tag>
<tag>binary search</tag>
<tag>dfs and similar</tag>
<tag>trees</tag>
<tag>strings</tag>
<tag>number theory</tag>
<tag>combinatorics</tag>
<tag>geometry</tag>
<tag>bitmasks</tag>
<tag>two pointers</tag>
<tag>dsu</tag>
<tag>shortest paths</tag>
<tag>probabilities</tag>
<tag>divide and conquer</tag>
<tag>hashing</tag>
<tag>game theory</tag>
<tag>flows</tag>
<tag>interactive</tag>
<tag>matrices</tag>
<tag>string suffix structures</tag>
<tag>fft</tag>
<tag>graph matchings</tag>
<tag>ternary search</tag>
<tag>expression parsing</tag>
<tag>meet-in-the-middle</tag>
<tag>2-sat</tag>
<tag>chinese remainder theorem</tag>
<tag>schedules</tag>
<tag>sliding window</tag>
<tag>recursion</tag>
<tag>backtracking</tag>
<tag>segment trees</tag>
<tag>fenwick trees</tag>
<tag>maximum flow</tag>
<tag>minimum spanning tree</tag>
<tag>topological sort</tag>
<tag>trie</tag>
<tag>suffix array</tag>
<tag>kmp algorithm</tag>
<tag>z algorithm</tag>
<tag>binary lifting</tag>
<tag>heavy-light decomposition</tag>
<tag>centroid decomposition</tag>
<tag>sqrt decomposition</tag>
<tag>mo's algorithm</tag>
<tag>convex hull</tag>
<tag>line sweep</tag>
<tag>matrix exponentiation</tag>
<tag>persistent data structures</tag>
<tag>euler tour technique</tag>
<tag>lowest common ancestor</tag>
<tag>strongly connected components</tag>
<tag>biconnected components</tag>
<tag>articulation points and bridges</tag>
<tag>gaussian elimination</tag>
<tag>expected value</tag>
<tag>bfs</tag>
</tags>
<problem>
*Nim Sum Dim Sum*, a bustling local dumpling restaurant, has two game theory-loving servers named, you guessed it, Alice and Bob. Its dining area can be represented as a two-dimensional grid of \(R\) rows (numbered \(1..R\) from top to bottom) by \(C\) columns (numbered \(1..C\) from left to right\).

Currently, both of them are standing at coordinates \((1, 1)\) where there is a big cart of dim sum. Their job is to work together to push the cart to a customer at coordinates \((R, C)\). To make the job more interesting, they've turned it into a game.

Alice and Bob will take turns pushing the cart. On Alice's turn, the cart must be moved between \(1\) and \(A\) units down. On Bob's turn, the cart must be moved between \(1\) and \(B\) units to the right. The cart may not be moved out of the grid. If the cart is already at row \(R\) on Alice's turn or column \(C\) on Bob's turn, then that person loses their turn.

The "winner" is the person to ultimately move the cart to \((R, C)\) and thus get all the recognition from the customer. Alice pushes first. Does she have a guaranteed winning strategy?


# Constraints

\(1 \leq T \leq 500\)
\(2 \leq R, C \leq 10^9\)
\(1 \leq A < R\)
\(1 \leq B < C\)


# Input Format

Input begins with an integer \(T\), the number of test cases. Each case will contain one line with four space-separated integers, \(R\), \(C\), \(A\), and \(B\).


# Output Format

For the \(i\)th test case, print `"Case #i: "` followed by `"YES"` if Alice has a guaranteed winning strategy, or `"NO"` otherwise.

# Sample Input

3
2 2 1 1
5 2 3 1
4 4 3 3

# Sample Output

Case #1: NO
Case #2: YES
Case #3: NO

# Sample Explanation

The first case is depicted below, with Alice's moves in red and Bob's in blue. Alice moves down, and Bob moves right to win immediately. There is no other valid sequence of moves, so Alice has no guaranteed winning strategy.

{{PHOTO_ID:842253013944047|WIDTH:500}}

The second case is depicted below. One possible guaranteed winning strategy is if Alice moves \(3\) units down, then Bob can only move \(1\) unit, and finally Alice can win with \(1\) unit.

{{PHOTO_ID:852013469652032|WIDTH:500}}

# Solution

<tags>
<tag>game theory</tag>
<tag>greedy</tag>
<tag>math</tag>
</tags>

If Alice reaches row \(R\) before Bob reaches row \(C\), then it's game over for Alice. Since each player now wants to get to the finish as slowly as possible, both have a simple dominating strategy of only moving \(1\) unit in their direction each turn, and \(R\) and \(C\) are the only things that matter.

If \(R \le C\), Bob can always force Alice to reach row \(R\) first by moving \(1\) unit right at a time. Alice also only moves \(1\) unit at a time, because if she moves any faster, she'll just get stuck sooner. 

Example: Alice moves first:
```
[ ][ ][ ][ ]
[x][ ][ ][ ]
[ ][ ][ ][ ]
```

Bob:
```
[ ][ ][ ][ ]
[ ][x][ ][ ]
[ ][ ][ ][ ]
```

Alice moves, and gets stuck to watch Bob stroll to the finish line:
```
[ ][ ][ ][ ]
[ ][ ][ ][ ]
[ ][x][ ][ ]
```

Conversely, if \(R > C\), then Alice can always force a win by moving \(1\) step at a time. Therefore we output "`YES`" if and only if \(R > C\), regardless of the values of \(A\) and \(B\).

# Implementation
```cpp
#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int R, C, A, B;
    cin >> R >> C >> A >> B;
    cout << (R > C ? "YES" : "NO") << endl;
  }
  return 0;
}
```
</problem>
<problem>
“An apple a day keeps the doctor away” is Steve’s motto. His other motto, “You can never have too much of a good thing,” holds true for both apples and mottos. Steve would like to eat two apples per day for the next \(N\) days, but with strict adherence to his third motto “Consistency is key.” Specifically, he’d like the sum of the two apple weights he eats over the next \(N\) days to be the same for each day.

Steve has already purchased \(2*N-1\) apples, the \(i\)th of which weighs \(A_i\) ounces. He'd like to buy one more apple that's as light as possible to fulfill his goal. Steve can buy an apple of any positive integer weight in ounces from the store. Is it possible for him to reach his goal, and if so, what weight apple should he buy?

{{PHOTO_ID:1563872647765708|WIDTH:600}}


*The above image depicts the solution to the first sample. Each day, Steve will eat two apples totalling \(7\) oz. Steve must buy a \(4\) oz apple to make this happen.*

# Constraints
\(1 \leq T \leq 70\)
\(1 \leq N \leq 3*10^5\)
The sum of \(N\) over all cases is at most \(600{,}000\)
\(1 \leq A_i \leq  10^9\)

# Input Format
Input begins with an integer \(T\), the number of test cases. Each test case starts with a single integer \(N\). The next line contains \(2*N-1\) space-separated integers \(A_1, ..., A_{2*N - 1}\).

# Output Format
For the \(i\)th test case, print "`Case #i:` " followed a single integer, the smallest possible apple weight in ounces that Steve can buy so that he can eat two apples for the next \(N\) days and have the sum of apple weights be the same every day, or \(-1\) if doing so is impossible.

# Sample Input

7
3
6 3 1 2 5
2
7 7 7
1
1
3
1 9 1 1 4
4
1 9 1 1 4 9 9
4
1 9 10 1 4 6 9
3
1000000000 2 10 4 999999994

# Sample Output

Case #1: 4
Case #2: 7
Case #3: 1
Case #4: -1
Case #5: 6
Case #6: -1
Case #7: 1000000002

# Sample Explanation

In the first case, if Steve buys a \(4\) oz apple, he can group his apples as shown above. For this input, there's no way to succeed by buying any apple below \(4\) oz.

In the second case, Steve can buy a \(7\) oz apple, and eat two apples totaling \(14\) oz each day.

In the third case, any apple weight will suffice, so Steve will buy the lightest one possible.

In the fourth case, no matter what weight apple Steve attempts to buy, it is impossible for him to achieve his goal.

Please note, as demonstrated in the seventh case, that it's possible for the answer to exceed \(10^9\).

# Solution

<paraphrasing>
- Steve wants to eat 2 apples per day for N days
- The sum of apple weights each day should be the same
- He has 2N-1 apples already, needs to buy one more
- The new apple should be as light as possible
- Apple weights must be positive integers
- Need to determine if it's possible and what weight to buy
</paraphrasing>
<paraphrased>
Steve aims to eat two apples daily for N days, ensuring the total weight of apples eaten each day is consistent. He currently has 2N-1 apples and needs to purchase one more. The challenge is to determine the lightest possible apple (in whole ounces) he can buy to achieve his goal, or if it's impossible to do so.
</paraphrased>
<observations>
<observation>If N=1, any positive integer weight will work, so the answer is always 1.</observation>
<observation>If we sort the array of apple weights, and insert one more apple, then the daily sum is the sum of the first and last apples, or equivalently the sum of the second and second last apples.</observation>
<observation>Hence, the only thing that affects the daily sum is whether the new apple is inserted at the beginning, end, or middle. From each of these three possibilities we can work backwards to find the daily sum from the original sorted array.</observation>
<observation>The pairs of apples are the first and last apples, second and second last apples, etc, of the new sorted array. We can find these pairs by pairing off elements of the original sorted array, except exactly one apple should be missing a partner.</observation>
<observation>We can handle each of the three possible daily sums by using two pointers. If the values of two pointers sum to the daily sum, advance each inwards. Otherwise, we can infer which apple is missing a partner by noting that incrementing the left pointer increases the sum while decrementing the right pointer decreases the sum.</observation>
</observations>
<tags>
<tag>sorting</tag>
<tag>two pointers</tag>
<tag>implementation</tag>
</tags>

If there's only one element, we don't care what it is, a \(1\) will match it. 

Otherwise, let's solve this backwards: instead of attempting to add a number in, we'll consider starting with a working solution and removing some number from it. Let's denote the daily sum of apple weights as \(K\). We can imagine having a sorted array of \(2*N\) elements where the first and last elements sum to \(K\), the second and second last sum \(K\), etc.

Now, consider removing one element from the \(2*N\) sorted numbers. There are three cases:

1. We removed the first element. Then, \(K\) is the new first element plus the second last element.
2. We removed the last element. Then, \(K\) is the new last element plus the second element.
3. We removed some element in the middle. Then, \(K\) is the sum of the first and last elements.

With \(3\) candidates for \(K\), we'll pick the smallest that works. To check if a \(K\) works, we can use two pointers \(l\) and \(r\) moving from the outside inwards on the sorted input array. If the left and right values sum less than \(K\), we record a "skip" (noting the element that would've been removed) and increment \(l\). If it sums more, we decrement \(r\), else we advance both closer. In the end, \(K\) works if there is at most a single skip (and that removed element is positive).

Running two pointers to check one candidate \(K\) takes \(\mathcal{O}(N)\) time, so the overall running time on \(3\) candidates is still \(\mathcal{O}(N)\).
</problem>"""
