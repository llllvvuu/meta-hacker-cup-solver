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
