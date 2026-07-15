# Weakness Log
| Problem | Category | What Went Wrong | Status |
|---|---|---|---|
| LC3756 | Segment Tree (custom merge) | Needed a data structure I haven't learned yet — array-based approach is fundamentally O(n²) for this range-query problem. Revisit after Trees/Segment Tree in Striver. | PARKED |
| LC0125 | Two Pointers / ASCII ranges | Wrote `if` instead of `else if` for mutually exclusive cases — double-appended characters. | RESOLVED |
| LC0029 | Bit Manipulation | Typo: subtracted from wrong variable (`divs` instead of `divd`) — didn't dry-test before assuming logic was wrong. | RESOLVED |
| LC0347 | Bounded value domain | Tried to index array directly by value without checking bounds — value can be negative/large. | RESOLVED |
| LC0034 | Binary Search / bounds-check ordering + signed-unsigned compare | (1) Bound check placed AFTER array access in while-condition instead of before — heap-buffer-overflow, same "missing bounds check" family as LC0347. (2) Compared signed int against unsigned `nums.size()` directly — silent wraparound risk. Working solution passes but is O(n) worst case (all-same-element array); true O(log n) needs two biased binary searches instead of expand-outward. | RESOLVED (crash) / OPEN (optimal complexity) |
| LC0043 | Big-number arithmetic / digit-array construction | No built-in integer type holds a 200-digit number — couldn't independently derive the grade-school multiplication + carry-propagation approach or the pos_high/pos_low index formula; needed heavy structural guidance. Reproduced and verified the solution, made small independent choices (broader zero-check, ASCII +/-48 instead of `to_string`), but not an authentic independent solve. Rewrite from scratch, from memory, required before marking resolved. | OPEN |
