# Git Workflow & Agent Instructions

This document defines the commit and PR creation workflow using specialized agents for fast-tracked DSA learning while maintaining clean git history.

## Overview

**Two specialized agents:**
1. **Commit Agent** — Creates precise, meaningful commits with AI-generation tracking
2. **PR Agent** — Creates pull requests directly using `gh` CLI

---

## Agent 1: Commit Workflow Agent

### When to Invoke
After code generation or note-taking, invoke with:
```
@commit-agent
Topic: [Topic name]
Files changed: [list files or describe changes]
AI generation %: [estimate: 0-100%]
Human input %: [estimate: 0-100%]
Notes: [any special context]
```

### Commit Message Format

**Structure:**
```
[type]: [subject] — [AI % indicator]

[Body with changes summary]

AI Generated: X% [specific components]
Human Input: Y% [specific components]

Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>
```

**Type (conventional commits):**
- `feat` — New feature/lesson/topic
- `refactor` — Code improvements, restructuring
- `docs` — Documentation updates
- `fix` — Bug fixes or corrections
- `test` — Test files (when applicable)

**Subject line:**
- Concise, imperative mood (e.g., "Add recursion lesson files")
- Include topic name if relevant
- Keep under 50 characters

**AI Generation Tracking:**
Example breakdowns:
- **100% AI** — Entire transcript → code + notes
- **85% AI** — Generated code/notes, human verified and tested
- **60% AI** — Generated outline, human wrote most logic
- **30% AI** — Human wrote most, AI added comments/optimization

### Example Commits

#### Example 1: New Topic (High AI%)
```
feat: Add recursion lesson files — AI: 85%

- Implement 01_factorial_recursion.cpp with step-by-step examples
- Implement 02_fibonacci_recursive.cpp with recursion tree visualization
- Generate comprehensive notes on recursion fundamentals

AI Generated: 85% (transcript analysis, code generation from examples, inline comments)
Human Input: 15% (review, verification, compilation testing)

Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>
```

#### Example 2: Mixed (Medium AI%)
```
feat: Implement LinkedList basic operations — AI: 60%

- Add LinkedList class with insert, delete, traverse
- Implement search and reverse operations
- Add edge case handling for empty lists

AI Generated: 60% (structure generation, basic implementations)
Human Input: 40% (logic refinement, testing, edge cases)

Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>
```

#### Example 3: Bug Fix (Low AI%)
```
fix: Correct vector resize logic in custom vector.h

- Fix off-by-one error in pushback capacity check
- Improve memory deallocation in destructor

AI Generated: 20% (problem identification)
Human Input: 80% (debugging, solution design, testing)

Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>
```

---

## Agent 2: PR Creation Agent

### When to Invoke
After committing to a feature branch, invoke with:
```
@pr-agent
Branch: [branch name]
Title: [PR title]
Description: [what this PR accomplishes]
Target: main (or specify target branch)
Draft: [true/false]
```

### PR Command Template

The agent will use `gh` CLI to create PRs:

```bash
gh pr create \
  --title "Your PR Title" \
  --body "Your PR description" \
  --base main \
  --head docs/learning-workflow-integration
```

**Options:**
- `--draft` — Create as draft PR (for review before merge)
- `--assignee @me` — Assign to yourself
- `--label "documentation"` — Add labels
- `--reviewer` — Request specific reviewers

### Example PR Creation

```
@pr-agent
Branch: docs/learning-workflow-integration
Title: Add learning workflow integration
Description: |
  Adds LEARNING_WORKFLOW.md documenting the code generation and note-taking pipeline.
  Includes two-agent approach for fast-tracked DSA learning.
  
  - New file: LEARNING_WORKFLOW.md
  - Updated: AGENTS.md with workflow reference
  - Updated: .gitignore to exclude copy-notes-to-notion.md
Target: main
Draft: false
```

**Agent output:**
```
✅ PR created: https://github.com/pratiiksahu/dsa-essentials-cpp/pull/X
Title: Add learning workflow integration
Base: main
Head: docs/learning-workflow-integration
```

---

## Workflow Summary

### Step 1: Create Feature Branch
```bash
git checkout -b docs/my-new-feature
```

### Step 2: Generate Code & Notes (Code Agent + Notes Agent)
- Provide transcript
- Agents generate `.cpp` files and `copy-notes-to-notion.md`

### Step 3: Commit Changes (Commit Agent)
```
@commit-agent
Topic: My New Feature
Files changed: New folder "7 Recursion" with 4 lesson files
AI generation %: 85
Human input %: 15
Notes: Generated from video transcript, compiled and tested successfully
```

Agent creates commit with precise message and AI% tracking.

### Step 4: Push & Create PR (PR Agent)
```
@pr-agent
Branch: docs/my-new-feature
Title: Add recursion lesson files
Description: Implements recursion fundamentals with factorial, fibonacci, and tree examples
Target: main
Draft: false
```

Agent creates PR directly using `gh CLI`, no manual GitHub UI interaction needed.

### Step 5: Merge
Review PR, then:
```bash
gh pr merge <PR_NUMBER> --squash
```

---

## AI Generation % Guidelines

**How to estimate:**

| % Range | Meaning | Example |
|---------|---------|---------|
| 90-100% | AI generated entire deliverable | Transcript → complete code + notes |
| 70-89% | AI generated most, human verified | Generated code, tested and verified |
| 50-69% | Mixed effort, slight AI lean | AI wrote skeleton, human implemented logic |
| 30-49% | Mixed effort, human lean | Human wrote structure, AI optimized |
| 10-29% | Mostly human, AI assisted | Human coded, AI helped debug |
| 0-9% | Human generated, AI minimal | Manual implementation |

**Always be honest** — this helps track AI-assisted learning effectiveness and maintains transparency.

---

## Checklist Before Committing

- [ ] Code compiles without errors
- [ ] Files follow naming conventions
- [ ] Follows existing code style and beginner-friendly approach
- [ ] Commit message includes AI% tracking
- [ ] Co-author trailer included
- [ ] Branch name is descriptive (e.g., `docs/`, `feat/`, `fix/`)

---

## Quick Reference: gh Commands

```bash
# Create PR (auto from current branch)
gh pr create --title "Title" --body "Description"

# Create draft PR
gh pr create --title "Title" --draft

# View PR
gh pr view <PR_NUMBER>

# Check PR status
gh pr status

# Merge PR (squash commits)
gh pr merge <PR_NUMBER> --squash

# List open PRs
gh pr list

# Add reviewers
gh pr review <PR_NUMBER> --request-review @username
```

---

## Next Steps

1. **Confirm `gh` CLI is authenticated:**
   ```bash
   gh auth status
   ```

2. **When ready for next topic:**
   - Provide transcript to Code Agent
   - Provide transcript to Notes Agent
   - Invoke Commit Agent after files are ready
   - Invoke PR Agent to create PR

3. **Use this workflow for all future changes** to maintain clean, traceable history

---

**This workflow ensures:**
- ✅ Precise commit messages with AI transparency
- ✅ Fast workflow (no manual PR creation)
- ✅ Clean git history with meaningful commits
- ✅ Honest tracking of AI-assisted work
