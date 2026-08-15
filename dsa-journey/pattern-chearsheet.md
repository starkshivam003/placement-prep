# Pattern Cheat Sheet

One line per **technique**, not per problem. Problems are just evidence —
review this weekly, and before starting a new problem ask "which of these
have I already built?"

## Linked Lists

- **Head-insertion reversal (moving anchor):** to reverse a list, walk
  forward, repeatedly making the current node the new front by
  reassigning `head`/`next` pointers — no new nodes.
  *(Reverse Linked List)*
- **Head-insertion reversal (fixed anchor):** to reverse only a *window*
  of a list, keep `prev` fixed at the node before the window and `curr`
  fixed at the window's future tail; repeatedly pull the next node
  forward and splice it right after `prev`. Same core idea as above,
  different anchor style.
  *(Reverse Between, Reverse K-Group)*
- **Trailing pointer instead of "going back":** a singly linked list
  can't be traversed backward, but a pointer kept one step behind
  another achieves the same effect without ever needing to.
  *(Remove Linked List Elements)*
- **Fast/slow pointer for the midpoint:** advance one pointer 2x speed;
  when it hits the end, the slow pointer is at the middle. Same
  mechanism also detects cycles.
  *(Middle of Linked List, Linked List Cycle, Palindrome Linked List)*
- **Combine independently-built LL techniques:** fast/slow (middle) +
  in-place reversal + lockstep comparison can be composed together for
  a genuinely new problem, not just applied one at a time.
  *(Palindrome Linked List, O(1) space)*
- **Dummy node removes "no node before the window" edge cases:** when a
  problem needs "the node before position X" and X could be the very
  first node, a dummy head sidesteps the special case entirely.
  *(Reverse Between)*

## Arrays / In-Place Manipulation

- **Directional sweep for in-place overwrite:** when updating a
  structure in place using its own old values, the direction you sweep
  (left-to-right vs right-to-left) determines whether you read the old
  value before or after it gets overwritten. Sweep the direction that
  reads-before-writes.
  *(Minimum Path Sum space-optimized, Pascal's Triangle II)*
- **Bit-shift / arithmetic equivalence for binary construction:**
  `value = value*2 + bit` and `value = (value<<1) | bit` are the same
  operation here because the low bit is always guaranteed zero before
  the write — no carry is possible.
  *(Convert Binary Number in a Linked List to Integer)*
- **Carry only ever needs the original doubled value, not the
  already-mutated one:** when propagating carry through a structure,
  compute the full "new value" once into a temp variable — don't derive
  carry from a value you already overwrote.
  *(Double a Number Represented as a Linked List)*
- **Single-pass carry via lookahead:** if carry-in for position `i` only
  depends on the *original* (unmodified) value at `i+1`, and you're
  sweeping so `i+1` hasn't been touched yet, you can peek ahead instead
  of needing a full separate pass.
  *(Double a Number Represented as a Linked List, single-pass version)*

## Recursion → Memoization → Tabulation (DP)

- **Pass shared data by reference, don't make it global:** when a
  recursive helper needs access to something that doesn't change per
  call (like a grid), pass it by reference into the helper — no global
  needed.
  *(Minimum Path Sum, recursive + memoized versions)*
- **`if / else if`, not sequential `if` blocks, when only one branch
  should apply:** sequential `if`s that all assign the same variable
  let the last one silently overwrite earlier correct branches.
  *(Minimum Path Sum recursive draft bug)*
- **Static table for a fixed, input-independent, small-range answer:**
  when the full valid input range is small and fixed, and the values
  never change, compute the whole table exactly once (`static` +
  a one-time-build guard) instead of recomputing per call or per object.
  *(Tribonacci)*
- **`static` is safe when write-once-then-read-only; dangerous when
  mutated per call across logically independent inputs:** the
  distinguishing question is not "is this static" but "does this
  static value get corrupted by being reused across unrelated calls."
  *(Tribonacci vs. the earlier GCD trial-division bug)*
- **DP isn't always the fastest solution to the base problem — it's
  often the right tool for the *follow-up*:** a greedy/two-pointer
  solution can dominate the single-query version; DP earns its keep
  when the same fixed input gets queried many times.
  *(Is Subsequence)*

## Meta / Process

- **"What made this solvable?" — one sentence, every time, independent
  of the specific problem.** This is the actual transferable unit, not
  the problem itself.
- **An "Easy" difficulty rating reflects the naive solution's
  difficulty, not the optimized/follow-up version's** — struggling on
  the optimal version of an Easy problem is not a signal about ability.
- **Analyze constraints before coding, not after a failed submission**
  — bugs from unstated assumptions (array bounds, value ranges) get
  found by the judge instead of by reasoning, which is slower and
  feels like "bug hunting" instead of problem solving.
  *(Missing Integer, LC2996)*
