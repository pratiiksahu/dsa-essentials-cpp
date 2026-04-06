# AGENTS.md

## Project Overview
- This repository is for learning data structures and algorithms in C++ by following a Udemy course.
- The long-term target is to stay structurally similar to `coding-minutes/dsa-essentials-course`, while only including topics that have been learned so far.
- Current progress is through vectors.
- The repository currently uses numbered topic folders at the root, for example `1 Arrays`, `2 Sorting Algorithms`, `3 Strings`, `4 2D Arrays`, `5 Pointers & Dynamic Memory`, and `6 Vector`.
- Most files are standalone `.cpp` lesson or practice programs. `6 Vector/vector.h` contains a custom vector implementation used by one of the vector lessons.

## Reference Course Roadmap
- Use the Coding Minutes reference repository as the master course outline.
- Master course sequence:
- `02 Arrays`
- `03 Basic Sorting`
- `04 Character Arrays`
- `05 2D Array`
- `06 Pointers`
- `07 Vector`
- `08 Bitmasking`
- `09 Recursion`
- `10 Divide and Conquer`
- `11 Backtracking`
- `12 Space Time Complexity`
- `13 OOPS`
- `14 LinkedList`
- `15 Stack`
- `16 Queue`
- `17 Binary Tree`
- `18 Binary Search Tree`
- `19 Heaps`
- `20 Hashtable`
- `21 Trie`
- `22 Graphs`
- `23 Dynamic Programming`
- `24 ShoppingCart`

## Current Progress Mapping
- The learner is currently at the equivalent of `07 Vector` in the reference repo.
- Current local coverage roughly maps as:
- `1 Arrays` -> `02 Arrays`
- `2 Sorting Algorithms` -> `03 Basic Sorting`
- `3 Strings` -> `04 Character Arrays`
- `4 2D Arrays` -> `05 2D Array`
- `5 Pointers & Dynamic Memory` -> `06 Pointers`
- `6 Vector` -> `07 Vector`
- Topics after vectors should be treated as future material unless the user explicitly asks for them.
- If a better solution depends on a future topic, present the current-topic solution first and label the future-topic approach as an optional preview.

## Do
- Keep code beginner-friendly, readable, and aligned with the current lesson topic.
- Prefer small, focused, standalone `.cpp` files that demonstrate one concept or one problem at a time.
- Preserve the numbered folder structure and existing naming style for lessons.
- Keep new folders and topics aligned with the Coding Minutes course progression when adding future content.
- Use explicit standard library headers required by the code.
- Prefer simple C++17-compatible solutions unless the lesson specifically requires lower-level constructs.
- Keep diffs small and scoped to the requested topic.
- Add short explanatory comments only when they help a learner understand the logic.
- After editing a `.cpp` file, compile that specific file when possible.

## Don't
- Do not introduce build systems, frameworks, or heavy tooling unless explicitly requested.
- Do not rename or reorganize lesson folders without approval.
- Do not add third-party dependencies for simple DSA exercises.
- Do not overengineer examples with advanced abstractions when the lesson is about fundamentals.
- Do not combine multiple unrelated exercises into one file.
- Do not leave repo-wide structural changes half-finished.

## Commands
- List files: `rg --files`
- Compile one lesson file: `g++ -std=c++17 -Wall -Wextra -pedantic "6 Vector/03_vector_class.cpp" -o /tmp/vector_demo`
- Run a compiled lesson: `/tmp/vector_demo`
- Prefer file-scoped compile checks instead of trying to build the whole repository at once.

## Project Structure
- Topic folders live at the repository root.
- Each topic folder usually contains self-contained lesson programs.
- `6 Vector/vector.h` is the main reusable header currently present in the repo.
- There is no single project-wide build or test harness yet.

## Good Defaults
- Match the teaching style of the existing files: direct input/output, simple helper functions, and one `main()` per exercise file.
- When improving code, preserve the educational intent of the example.
- If a concept has not been covered yet in the course, avoid jumping ahead unless the user asks for it.
- If the user seems unaware of a more advanced technique from a later course section, you may mention it briefly as context, but keep the main implementation within the learner's current scope unless asked otherwise.

## PR Checklist
- The edited file compiles successfully.
- Required headers are present.
- The file remains easy to read for someone learning DSA in C++.
- Folder placement and file naming still match the course structure.

## When Stuck
- Choose the simplest course-appropriate solution first.
- State assumptions briefly.
- Ask before making large structural changes or adding future-course material out of sequence.

## Learning & Code Generation Workflow

For fast-tracked learning with depth, see **LEARNING_WORKFLOW.md** in the repository root. It documents:
- How to provide video transcripts for code generation
- Two-agent approach: one for code, one for notes
- How `copy-notes-to-notion.md` is generated and managed
- Progression tracking through the DSA roadmap

## Git Commit & PR Workflow

For commit and PR creation agents, see **GIT_WORKFLOW.md**. It documents:
- Commit Agent: precise messages with AI-generation tracking
- PR Agent: direct PR creation using `gh` CLI
- Commit message format with AI% indicators
- Examples and best practices

---

## Quick Reference: Workflows & Documents

| Document | Purpose | Key Content |
|----------|---------|-------------|
| **AGENTS.md** | Master guidelines for repo | Do's/Don'ts, conventions, code style, build commands |
| **LEARNING_WORKFLOW.md** | Code + notes generation | @code-agent, @notes-agent, copy-notes-to-notion.md workflow |
| **GIT_WORKFLOW.md** | Commit + PR workflow | @commit-agent, @pr-agent, user choice rules, examples |
| **.github/copilot-instructions.md** | Copilot IDE entry point | Build commands, architecture, conventions (quick reference) |

### Agents Available

| Agent | Invocation | Purpose | Output |
|-------|-----------|---------|--------|
| **Code Generation** | @code-agent | Generate `.cpp` files from transcript | Standalone lesson files in appropriate folder |
| **Notes Generation** | @notes-agent | Generate learning notes from transcript | `copy-notes-to-notion.md` (Notion-ready) |
| **Commit** | @commit-agent | Create precise commits with AI% tracking | Git commit with file modifications, AI%, co-author |
| **PR** | @pr-agent | Create/push PRs with smart detection | Prompts user: Option 1 (Push) or Option 2 (New Branch) |

### Standard Workflow Order

```
Watch Video → @code-agent → @notes-agent → Test Locally → @commit-agent → @pr-agent → Merge
```

### User Choice Point

When invoking **@pr-agent**, you always choose:
- **Option 1:** Push to current branch (updates existing PR or creates new one)
- **Option 2:** Create new PR with new branch (requires IDE switch)

No PR is created without your explicit choice.
