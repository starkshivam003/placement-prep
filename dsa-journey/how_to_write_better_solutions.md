# How to Write Better Solutions

A living log of real mistakes and the concrete fix for each — updated whenever a
new pattern shows up, not rewritten from theory. Add rows, don't delete old ones.

| # | Mistake Pattern | Where It Showed Up | Why It Happens | Concrete Fix |
|---|---|---|---|---|
| 1 | Coding before analyzing constraints | LC3488 Missing Integer (7 failed attempts) — `B[51]` and `sum<51` were guessed from failing tests instead of derived from `nums[i]<=50` | Jumping straight to code skips the step of turning bounds into guaranteed facts | Before writing any code: write down exact bounds (n, value ranges), then write one sentence per bound stating what it *lets you assume*. Only start coding after that. |
| 2 | Bound check placed after array access instead of before/inside loop condition | LC0034, LC0219 (x2) | Loop conditions written by habit, not re-derived per problem | Before finalizing a loop, ask: "is my access guarded by the check, or does the check come too late?" Trace one boundary index by hand. |
| 3 | Signed vs unsigned comparison (`int` vs `size_t`) | Multiple problems using `.size()` | `.size()` returns unsigned; mixing with `int` silently changes comparison semantics | Prefer `int` loop vars cast deliberately, or compile with `-Wall -Wextra` and actually read the warnings, don't ignore them |
| 4 | `==` used where `=` was intended (or vice versa) | reverseKGroup — silent no-op bug | Easy to miss visually, especially under time pressure | Always compile with `-Wall -Wextra`; treat every warning as a real bug until proven otherwise |
| 5 | `static` local variable persisting across calls unintentionally | GCD trial-division infinite loop | `static` state carries between calls in ways that aren't obvious from reading top-to-bottom | Default to non-static; only use `static` with an explicit, stated reason |
| 6 | Introducing a variable to carry a value, then never reading it back | ShiftGrid `temp` bug | Started the right technique, stopped one step short of using it | After writing any temp/helper variable, trace: where is this value actually consumed? |
| 7 | Building a shortcut comparison between two proxies instead of the real final candidates | Maximum Product of Three Numbers (6 attempts) | Assumed a cheaper comparison was equivalent without proving it | Rule: don't build a shortcut comparison unless proven equivalent to comparing the real values — if real values are cheap to compute, just compute them |
| 8 | Explicit state-tracking (flags, search loops) instead of using info pointers already encode | Remove Duplicates II `seen` flag vs `nums[write-2]` | Defaulting to "track more state" instead of asking what's already recoverable | Before adding a new state variable, ask: "is this already recoverable from where my pointers currently are?" |
| 9 | C-style string habits (`'\0'`, `n+1` sizing) applied to `std::string` | Smallest Palindromic Rearrangement I | Abdul Bari's C-style teaching translated directly without adjusting for `std::string`'s self-tracked length | Remember: `std::string` tracks its own length; never manually null-terminate or oversize |
| 10 | Underestimating time, no hard-stop trigger | Multiple 3+ hour sessions estimated at 30 min | No deliberate checkpoint to decide "extend or reroute" | Set a real time-box (25-40 min unaided); when it's hit, consciously choose to extend or step back — don't drift |
| 11 | Reactive bug-hunting instead of proactive reasoning | LC3488 (this session) | Skipping constraint analysis turns debugging into "patch until tests pass" instead of solving | Trace the algorithm by hand on 2 cases (trivial + boundary-stressing) *before* running it — catch bugs by reading, not by the judge |

**Meta-rule:** when a new mistake shows up, ask "which existing row is this, or is it genuinely new?" — most bugs are old patterns wearing a new problem's clothes.
