# Copilot Instructions for dsa-essentials-cpp

This is a **data structures and algorithms learning project in C++**, modeled after the Coding Minutes Udemy course. Each numbered topic folder contains standalone lesson and practice programs.

## Build & Compile Commands

**Compile a single lesson file:**
```bash
g++ -std=c++17 -Wall -Wextra -pedantic "6 Vector/03_vector_class.cpp" -o /tmp/lesson_demo
```

**Run the compiled program:**
```bash
/tmp/lesson_demo
```

**Key points:**
- No project-wide build system (by design—files are self-contained for learning)
- Always compile to a temp location (`/tmp/`) to keep the repo clean
- Use `-std=c++17` as the minimum standard
- Include all three flags: `-Wall -Wextra -pedantic` for warnings

## Project Structure & Architecture

**Topic folders** (numbered, following course progression):
- `1 Arrays` → Arrays and searching basics
- `2 Sorting Algorithms` → Sorting techniques
- `3 Strings` → Character arrays and string manipulation
- `4 2D Arrays` → 2D array operations
- `5 Pointers & Dynamic Memory` → Pointer concepts and heap management
- `6 Vector` → Dynamic arrays and vector implementation

**Reusable components:**
- `6 Vector/vector.h` — Template-based custom Vector class (demonstrates dynamic resizing, memory management)
  - Used by some vector lesson files for teaching purposes
  - Implements `pushback()`, `popback()`, `get()`, `size()`, operator overloads

**File structure:**
- Each file = one lesson or problem (not combined)
- Filenames use `NN_topic_name.cpp` format (e.g., `01_array_input_output.cpp`)
- Most files have a simple `main()` function with direct I/O for learning clarity

## Key Conventions & Guidelines

**Code style:**
- **Beginner-friendly, readable code** — prioritize clarity over cleverness
- **C++17** with standard library; no external dependencies for DSA exercises
- **Explicit headers** — include only what's needed (`#include <vector>`, `#include <algorithm>`, etc.)
- **Minimal comments** — only where logic needs clarification; don't over-comment
- **One `main()` per file** — keep programs focused on a single concept

**When adding or editing:**
- **Preserve the numbered folder structure** and existing naming style
- **Match the teaching style** of existing files (direct input/output, simple helper functions)
- **Keep diffs small and scoped** to the requested topic
- **After editing a `.cpp` file, compile and verify** that file compiles without errors
- **Respect the learning progression** — avoid introducing concepts from future topics unless explicitly asked

**What NOT to do:**
- Don't introduce build systems, frameworks, or complex tooling (keep it minimal)
- Don't combine multiple unrelated exercises into one file
- Don't rename or reorganize topic folders without approval
- Don't add third-party dependencies for basic DSA problems

## Course Progression & Current State

**Current progress:** Through Vector (`07 Vector` in the reference course)

**Future topics** (in course order, not yet covered):
- Bitmasking, Recursion, Divide & Conquer, Backtracking, Space-Time Complexity, OOPS, LinkedList, Stack, Queue, Binary Tree, BST, Heaps, Hashtable, Trie, Graphs, Dynamic Programming

When suggestions involve future topics, present the current-topic solution first and optionally mention advanced approaches with clear labeling.

## Before You Start

For more detailed guidelines on project philosophy, do's and don'ts, and design decisions, see **AGENTS.md** in the repository root.

---

**Last updated:** 2026-04-06
