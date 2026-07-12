# Weakness Log
## Entries
- LC3756 | Segment Tree (custom merge) | Needed a data structure I haven't
  learned yet — array-based approach is fundamentally O(n²) for this range-
  query problem. Revisit after Trees/Segment Tree in Striver. | PARKED
- LC0125 | Two Pointers / ASCII ranges | Wrote `if` instead of `else if` for
  mutually exclusive cases — double-appended characters. | RESOLVED
- LC0029 | Bit Manipulation | Typo: subtracted from wrong variable (`divs`
  instead of `divd`) — didn't dry-test before assuming logic was wrong. | RESOLVED
- LC0347 | Bounded value domain | Tried to index array directly by value
  without checking bounds — value can be negative/large. | RESOLVED
- LC0034 | Binary Search / bounds-check ordering + signed-unsigned compare |
  (1) Bound check placed AFTER array access in while-condition instead of
  before — heap-buffer-overflow, same "missing bounds check" family as
  LC0347. (2) Compared signed int against unsigned nums.size() directly —
  silent wraparound risk. Working solution passes but is O(n) worst case
  (all-same-element array); true O(log n) needs two biased binary searches
  instead of expand-outward. Revisit for optimal solution. | RESOLVED (crash)
  / OPEN (optimal complexity)
