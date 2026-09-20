# DFA Minimization Report

**Shanine Claire A. Besto**
**3 BSCS-A**
**CS 13a – Automata Theory and Formal Language**

This document demonstrates the process of minimizing Deterministic Finite Automata (DFA) using the partition refinement method. Four distinct DFA examples are provided along with their transition tables, equivalence partitions, minimized structures, accepted/rejected strings, and detailed explanations.

## Overview

The goal of DFA minimization is to reduce the number of states while preserving the language recognized by the original DFA. For each project example, the following elements are detailed:
- Original DFA specifications (States, Alphabet, Initial state, Final state)
- Transition tables
- Initial and successive equivalence partitions
- Minimized DFA structure and state reduction metrics
- Representative accepted and rejected strings with step-by-step trace explanations

## Example 1

The original DFA contains five states with transitions designed to recognize strings ending in specific patterns.

### Original DFA Specifications
- **States:** `{A, B, C, D, E}`
- **Alphabet:** `{0, 1}`
- **Initial state:** `A`
- **Final state:** `E`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ A** | B | C |
| **B** | B | D |
| **C** | B | C |
| **D** | B | E |
| ***E** | B | C |

*Note: A is the initial state and E is the accepting state.*

### Minimization Process

**Step 1: Initial Equivalence (0-Equivalence)**  
The states are first divided into accepting and non-accepting states: `{A, B, C, D} | {E}`  
The accepting state E cannot be equivalent to any non-accepting state.

**Step 2: First Refinement (1-Equivalence)**  
After examining the transitions of the states, state D is separated because: `D --1--> E`  
Since E is accepting, D has different transition behavior from A, B, and C.  
*Result:* `{A, B, C} | {D} | {E}`

**Step 3: Second Refinement (2-Equivalence)**  
The group `{A, B, C}` is examined again. States A and C remain equivalent because they have the same behavior with respect to current partitions. State B is separated because its transition on 1 goes to D, while A and C transition to states in `{A, C}`.  
*Result:* `{A, C} | {B} | {D} | {E}`

The number of states is successfully reduced from 5 to 4.

### Language & String Analysis
The minimized DFA accepts strings that end in `011` where Σ = `{0,1}`.

**Accepted Strings (Examples)**  
`011`, `0011`, `1011`, `00011`, `01011`, `10011`, `11011`, `000011`, `001011`, `010011`  
*Trace Example:* A,C `--0-->` B `--1-->` D `--1-->` E, therefore 011 is accepted.

**Rejected Strings (Examples)**  
`ε`, `0`, `1`, `00`, `01`, `10`, `11`, `000`, `001`, `010`  
*Trace Example:* 0 leaves the DFA in state B (non-accepting). 0110 is rejected because reading 0 after reaching E sends the DFA back to B.

---

## Example 2

The second DFA contains six states exploring structured pattern matching.

### Original DFA Specifications
- **States:** `{A, B, C, D, E, F}`
- **Alphabet:** `{0, 1}`
- **Initial state:** `A`
- **Final state:** `E`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ A** | B | C |
| **B** | A | D |
| **C** | E | F |
| **D** | E | F |
| ***E** | E | F |
| **F** | F | F |

### Minimization Process

**Step 1 (0-Equivalence):** `{A, B, F} | {C, D, E}` (Separating accepting state E).  
**Step 2 (1-Equivalence):** State F becomes separate because both of its transitions remain in F (`F --0--> F`, `F --1--> F`).  
*Result:* `{A, B} | {F} | {C, D, E}`  
**Step 3 (Final Partition):** No further refinements occur.

The minimized DFA has 3 states: `{A,B}`, `{C,D,E}`, `{F}`. The number of states is reduced from 6 to 3.

### Language & String Analysis
The minimized DFA accepts strings containing exactly one 1 (General Form: `0*10*`). Zeros before and after the 1 do not affect acceptance.

**Accepted Strings**  
`1`, `01`, `10`, `001`, `010`, `100`, `0001`, `0010`, `0100`, `1000`

**Rejected Strings**  
`ε`, `0`, `00`, `11`, `000`, `011`, `101`, `110`, `111`, `0000` *(Strings with no 1 or multiple 1s are rejected).*


---

## Example 3

The third DFA contains four states and illustrates a scenario where the DFA is already minimal.

### Original DFA Specifications
- **States:** `{S, C, A, B}`
- **Alphabet:** `{0, 1}`
- **Initial state:** `S`
- **Final state:** `B`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ S** | C | C |
| **C** | C | A |
| **A** | B | C |
| ***B** | S | C |

### Minimization Process & Analysis

**Refinement Trace:**  
- **0-Equivalence:** `{B} | {S, C, A}`  
- **1-Equivalence:** `{B} | {A} | {S, C}`  
- **2-Equivalence:** `{B} | {A} | {S} | {C}`

**Why Example 3 Is Already Minimized:**  
The crucial final split is S vs. C. On input 1, S transitions to S while C transitions to A. Since S and A are already in different equivalence classes, S and C cannot be merged. Every state becomes its own equivalence class (`{B}`, `{A}`, `{S}`, `{C}`). Original states = 4, Minimized states = 4.

### Accepted & Rejected Strings

**Accepted Examples:** `010`, `0010`, `1010`, `00010`, `01110`, `10010`, `11010`, `000010`, `001110`, `010010`  
**Rejected Examples:** `ε`, `0`, `1`, `00`, `01`, `10`, `11`, `000`, `001`, `011`


---

## Example 4

The fourth DFA contains four states and demonstrates rapid partition separation.

### Original DFA Specifications
- **States:** `{S, C, A, B}`
- **Alphabet:** `{0, 1}`
- **Initial state:** `S`
- **Final state:** `B`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ S** | A | C |
| **C** | S | B |
| **A** | B | C |
| ***B** | A | S |

### Minimization Process & Analysis

**Refinement Trace:**  
- **0-Equivalence:** `{B} | {S, C, A}`  
- **1-Equivalence:** `{B} | {C} | {A} | {S}`

**Why Example 4 Is Already Minimized:**  
The first refinement after the initial accepting/non-accepting partition separates every state immediately. All four states are distinguishable by their transition signatures. Consequently, there are no pairs left to combine. Original states = 4, Minimized states = 4.

### Accepted & Rejected Strings

**Accepted Examples:** `00`, `11`, `011`, `0000`, `1000`, `1011`, `1100`, `00011`, `00100`, `00111`  
**Rejected Examples:** `ε`, `0`, `1`, `01`, `10`, `000`, `001`, `010`, `100`, `101`


---

## Summary & Comparison of Results

The table below summarizes the original state counts, minimized state counts, and final equivalence partitions across all four examples.

| Example | Original States | Minimized States | Final Equivalence Partition |
|---------|-----------------|------------------|-----------------------------|
| Example 1 | 5 | 4 | `{A,C} {B} {D} {E}` |
| Example 2 | 6 | 3 | `{A,B} {C,D,E} {F}` |
| Example 3 | 4 | 4 | `{B} {A} {S} {C}` |
| Example 4 | 4 | 4 | `{B} {C} {A} {S}` |

---

## Conclusion

DFA minimization works by repeatedly dividing states into equivalence classes according to their acceptance status and transition behavior. A pair of states can only be merged if they are equivalent, meaning no input string can distinguish their acceptance behavior.

- **Examples 1 and 2** contained equivalent states, resulting in successful state reductions (5 → 4 and 6 → 3 respectively).
- **Examples 3 and 4** placed every state into its own equivalence class during refinement, demonstrating that the original DFAs were already minimal (4 → 4).
