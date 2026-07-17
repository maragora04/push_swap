*This project has been created as part of the 42 curriculum by mamendes, andmigue.*

# push_swap

## Description

`push_swap` is a 42 curriculum algorithmic project whose goal is to sort a stack of unique integers using two stacks (`a` and `b`) and a restricted set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), while keeping the total number of operations as low as possible.

The program takes an unsorted list of unique integers as arguments, loads them onto stack `a`, and prints to standard output the exact sequence of operations that sorts `a` in ascending order, using stack `b` only as auxiliary storage. A companion `checker_linux` binary (provided by 42) replays that sequence against the original input to verify that the result is correct.

Beyond the mandatory behavior, this implementation adds:
- A **strategy selector** (`--simple`, `--medium`, `--complex`, `--adaptive`) that lets the caller force a specific sorting algorithm, or let the program pick one automatically based on how disordered the input is.
- A **`--bench` mode** that prints the operation output and prints statistics (disorder percentage, strategy used, and a per-operation breakdown) — used to compare algorithm performance across different input sizes and shapes.

## Instructions

### Compilation

```bash
make
```

This first builds the internal `ft_printf` library (used for every formatted output instead of the standard `printf`), then compiles and links `push_swap`.

| Rule | Effect |
|---|---|
| `make` | Build the `push_swap` binary |
| `make clean` | Remove object files (including `ft_printf`'s) |
| `make fclean` | `clean` + remove the `push_swap` binary and `libftprintf.a` |
| `make re` | `fclean` + `make` |

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```

Arguments can be passed as separate integers or as a single space-separated string:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

Flags (all optional, must come before the numbers):

| Flag | Effect |
|---|---|
| *(none)* | Adaptive strategy (default) — the algorithm is picked automatically |
| `--simple` | Force bubble sort |
| `--medium` | Force chunk (bucket) sort |
| `--complex` | Force radix sort |
| `--bench` | Print statistics and the operation list |

Any invalid input — non-integer tokens, values outside the `int` range, or duplicate numbers — makes the program print `Error` to standard error and exit with status `1`, without printing any operations. If the input is empty or already sorted, no operations are printed.

### Testing

The provided `checker_linux` binary replays a sequence of operations against the original numbers and reports `OK` or `KO`:

```bash
ARG="$(shuf -i 0-500 -n 254)"
./push_swap $ARG | ./checker_linux $ARG
```

To compare the operation count of a given strategy on a larger, random input:

```bash
./push_swap --bench --complex "$(shuf -i 0-100000 -n 5000)"
```

## Algorithms and Strategy Justification

Regardless of the strategy chosen, stacks of **2 to 5 elements** are always handled by dedicated routines instead of the general-purpose algorithms below, since hardcoding these small cases is cheaper and simpler than running a generic sort on them:

- **size 2** — a single `sa` if the two values are inverted.
- **size 3** — a decision tree (`sort_three`) that compares the three values and applies at most two operations (`sa`, `ra`, `rra`, or a short combination of them) to reach the correct order.
- **size 4–5** — the smallest remaining value is repeatedly located and rotated to the top of `a` (`ra` or `rra`, whichever is cheaper given its position), then pushed to `b`, until 3 elements remain in `a`. Those 3 are sorted with `sort_three`, then pushed back from `b` to `a` one at a time. Since the values were extracted from `a` in ascending order, and `pb`/`pa` behave like a stack, they land back on top of `a` in the correct final position.

For **larger stacks**, three algorithms are available, plus an adaptive dispatcher that chooses between them:

### Simple — Bubble sort (`--simple`)

A bubble sort adapted to the two-stack model: a full pass compares adjacent elements (`sa` on inversions) while rotating (`ra`) through the whole stack, then rotates back to the original position; the pass length shrinks by one each time a full pass makes no swap. It is the simplest correct algorithm here, labeled `O(n²)`. It is kept mainly as a `--bench` baseline, and because it is genuinely efficient on **nearly-sorted** input, where very few swaps are actually needed no matter how many comparisons are made.

### Medium — Chunk / bucket sort (`--medium`)

Values are first **normalized** to a dense range `0..n-1` (their rank among the stack, preserving relative order) — necessary because the input's numeric range is arbitrary, but the chunking logic needs a compact index space. That range is then split into `⌈√n⌉` chunks. The algorithm walks stack `a` once per chunk, pushing (`pb`) every value that falls in the current chunk's range to `b` and rotating (`ra`) everything else out of the way, so that once every chunk has been processed, all elements have moved to `b`, grouped chunk by chunk. Finally, the current maximum value remaining in `b` is repeatedly located and rotated to the top (`rb`/`rrb`, whichever is closer) and pushed back (`pa`) — since this always extracts the current largest remaining value, the elements land back on `a` fully sorted, smallest on top.

Splitting the range into `√n` chunks is the classic way to avoid a full linear scan per element during distribution; it is labeled `O(n√n)` here as a practical target rather than a strict worst-case bound, since the final extraction phase still scans the remainder of `b` for the current maximum each time.

### Complex — Radix sort (`--complex`)

This is the standard LSD (least-significant-bit-first) binary radix sort adapted to two stacks:

1. Normalize the values to ranks `0..n-1`, exactly as above.
2. Compute `max_bits = ⌈log₂(n)⌉` — the number of bits needed to represent any rank.
3. For each bit position, from bit 0 (LSB) up to `max_bits - 1`:
   - For every element currently in `a`: if that bit is `0`, push it to `b` (`pb`); if it's `1`, rotate it (`ra`) so it moves to the back of `a` instead, keeping its relative order among the other bit-1 elements.
   - Once the pass over all elements is done, push everything back from `b` to `a` (`pa`), which restores the bit-0 elements ahead of the bit-1 elements.
4. After all bits have been processed, `a` is fully sorted: two elements can only be out of order because of their highest differing bit, and each pass groups the stack by one more bit than the last.

Radix sort is used as the "complex" strategy because its cost depends only on `n` and the number of bits (`log₂ n`), independent of how disordered the input is — each of the `⌈log₂ n⌉` passes touches every element exactly once, giving a predictable `O(n log n)` total regardless of input shape. That makes it the most robust choice for large or heavily shuffled inputs.

### Adaptive strategy selection (default)

When no strategy flag is given, `sort()` first computes a cheap **disorder score**: the fraction of adjacent pairs in the input that are already out of order (0 = sorted, 1 = every adjacent pair inverted). Based on that score:

| Disorder | Strategy chosen | Rationale |
|---|---|---|
| `< 0.2` | Bubble sort | Very few actual swaps are needed; simplicity outweighs the theoretical `O(n²)` bound |
| `0.2 – 0.5` | Chunk sort | Moderately shuffled input benefits from bucketing without radix's normalization overhead |
| `≥ 0.5` | Radix sort | Heavily shuffled/random input is handled most predictably by radix's input-independent cost |

This mirrors how `--bench` was actually used during development: running each strategy against inputs of varying size and disorder and comparing `total_ops`, then tuning the thresholds above from the results.

## Resources

- 42's `push_swap` subject (project specification)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Bucket sort — Wikipedia](https://en.wikipedia.org/wiki/Bucket_sort)
- [Bubble sort — Wikipedia](https://en.wikipedia.org/wiki/Bubble_sort)

### AI usage

AI (Claude, Anthropic) was used during development as a debugging and review aid, not to generate the core algorithms or parsing logic, specifically for:
- Debugging: resolving an infinite recursion between rotation helper functions, fixing a double-counted operation in the counters, and tracking down uninitialized memory.
- Discussing trade-offs between the chunk-based (medium) and radix (complex) strategies before implementation.
- Reviewing edge cases.

All algorithm design, parsing, struct layout, and final implementation were written and tested by the project authors.
