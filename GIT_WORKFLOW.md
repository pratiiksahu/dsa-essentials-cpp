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

### PR Creation Decision Rules

**Before creating/pushing, the agent MUST ask you:**

```
You're on branch: <branch-name>

What would you like to do?
1. Push to current branch (updates existing PR or creates new one on same branch)
2. Create a new PR with a new branch
```

**If you choose Option 1 (Push):**
- Check if PR exists on current branch
- If PR exists → `git push` (updates existing PR)
- If no PR exists → `gh pr create` (creates PR on current branch)
- Stay on same branch

**If you choose Option 2 (New PR with New Branch):**
- Prompt for new branch name
- Create new branch: `git checkout -b <new-branch-name>`
- Create PR on new branch: `gh pr create ...`
- **Switch IDE to new branch** (agent notifies you to switch)
- Current branch becomes available for other work

### Smart PR Detection Logic

```bash
# Check if PR exists on current branch
gh pr view <current-branch> 2>/dev/null

# If PR exists → Just push
if [ $? -eq 0 ]; then
  git push
  echo "✅ Pushed commits to existing PR"
else
  # If no PR exists → Create new PR
  gh pr create --title "..." --body "..." --base main
  echo "✅ Created new PR on current branch"
fi
```

**Key behavior:**
- ✅ **PR exists on branch** → `git push` (updates existing PR with new commits)
- ✅ **No PR on branch** → `gh pr create` (creates new PR on same branch)
- ✅ **User wants new branch** → Create branch, create PR, switch IDE to new branch

### Multiple PRs Per Topic

You can create **multiple PRs for different learning milestones** within a topic:

```
Topic: Recursion

PR #1: Basic recursion fundamentals
├─ Branch: feat/recursion-basics
├─ Files: factorial, power, fibonacci
└─ Merge when satisfied

PR #2: Advanced recursion patterns  
├─ Branch: feat/recursion-advanced
├─ Files: tree traversal, permutations
└─ Merge when satisfied

PR #3: Recursion with memoization
├─ Branch: feat/recursion-optimization
├─ Files: memoization examples
└─ Merge when satisfied
```

**Workflow for multiple PRs:**
1. Finish learning milestone 1, merge PR #1
2. **Invoke @pr-agent** → Choose "Create new PR with new branch"
3. Agent creates `feat/recursion-advanced` branch
4. Generate code for milestone 2
5. Commit and invoke @pr-agent → Choose "Push to current branch" (updates PR #2)
6. Repeat for milestone 3+

### PR Command Template

The agent will use `gh` CLI to create PRs:

```bash
gh pr create \
  --title "Your PR Title" \
  --body "Your PR description" \
  --base main \
  --head <current-branch>
```

**Options:**
- `--draft` — Create as draft PR (for review before merge)
- `--assignee @me` — Assign to yourself
- `--label "documentation"` — Add labels
- `--reviewer` — Request specific reviewers

### Example PR Creation Flow

#### First Milestone (Option 1: Push):
```
You're on branch: feat/recursion-basics

@pr-agent
Title: Add recursion fundamentals
Description: Implements basic recursion with factorial, power, fibonacci
Target: main
Draft: false
```

**Agent prompts:**
```
What would you like to do?
1. Push to current branch
2. Create a new PR with a new branch

You choose: 1
```

**Output:** ✅ Creates PR #13 on feat/recursion-basics

#### Iterate on same PR (Option 1: Push):
```
[You add more code and commit]

@pr-agent
(on same branch: feat/recursion-basics)

You choose: 1 (Push to current branch)
```

**Output:** ✅ Pushes to PR #13 (no new PR created)

#### New Milestone (Option 2: New Branch):
```
@pr-agent
Title: Add advanced recursion patterns
Description: Implements backtracking, N-queens, permutations
Target: main
Draft: false
```

**Agent prompts:**
```
What would you like to do?
1. Push to current branch (feat/recursion-basics)
2. Create a new PR with a new branch

You choose: 2

Enter new branch name: feat/recursion-advanced
```

**Output:**
```
✅ Created branch: feat/recursion-advanced
✅ Created PR #14 on feat/recursion-advanced
🔄 Please switch IDE to branch: feat/recursion-advanced
```

---

## Workflow Summary

### Step 1: Create Feature Branch
```bash
git checkout -b docs/my-new-feature
```

### Step 2: Generate Code & Notes (Code Agent + Notes Agent)
- Provide transcript or content summary
- Agents generate `.cpp` files and `copy-notes-to-notion.md`
- Review generated code locally
- Test compilation: `g++ -std=c++17 -Wall -Wextra -pedantic "file.cpp" -o /tmp/test`

### Step 3: Commit Changes (Commit Agent)
Once you're satisfied with generated code:

```
@commit-agent
Topic: Recursion Basics
Files changed: 8 Recursion/ +4 new files
AI generation %: 85
Notes: Generated from Udemy transcript, compiled and tested successfully
```

Agent creates commit with:
- Precise message with conventional commits format
- File modifications (e.g., `GIT_WORKFLOW.md +78 -45`)
- AI% tracking only (removed Human Input %)
- Co-author trailer

### Step 4: Handle PR (PR Agent) — User Makes Decision
After committing, invoke PR agent to handle the PR:

```
@pr-agent
Title: Add recursion lesson files
Description: Implements recursion fundamentals with 4 lesson programs
Target: main
Draft: false
```

**Agent prompts you:**
```
You're on branch: feat/recursion-basics

What would you like to do?
1. Push to current branch (updates existing PR or creates new one)
2. Create a new PR with a new branch
```

**Choose Option 1** if:
- This is your first commit on this branch → Creates new PR
- You've already created a PR and want to add more commits → Pushes to same PR

**Choose Option 2** if:
- You've completed a learning milestone and want to start a new one
- You want a separate PR for a different phase/topic
- Agent creates new branch and switches IDE automatically

### Step 5: Merge When Ready
Review PR, then merge:
```bash
gh pr merge <PR_NUMBER> --squash
```

---

## Complete Example: Multi-Phase Learning Cycle

**Phase 1: Basic Recursion (Milestone 1)**
```
git checkout -b feat/recursion-basics

@code-agent 
Topic: Recursion Basics
Transcript: [video content]
Folder: 8 Recursion (new)

@commit-agent
Topic: Recursion Basics
Files changed: 8 Recursion/ +4 files
AI generation %: 85

@pr-agent
Title: Add recursion fundamentals
You choose: Option 1 → Creates PR #13
```

**Phase 1: Iterate (Add More Examples)**
```
[Still on feat/recursion-basics]

@code-agent
Topic: Recursion Basics (continued)
Add: Tree traversal examples
Folder: 8 Recursion (append)

@commit-agent
Topic: Recursion Basics (Part 1 continued)
Files changed: 8 Recursion/ +2 files
AI generation %: 90

@pr-agent
You choose: Option 1 → Pushes to PR #13 (no new PR created)
```

**Phase 1: Complete & Merge**
```
[Satisfied with phase 1]

gh pr merge 13 --squash
[Deletes feat/recursion-basics branch]
```

**Phase 2: Advanced Recursion (Milestone 2)**
```
@pr-agent
Title: Add advanced recursion patterns
Description: Backtracking, N-queens, permutations
Target: main

You choose: Option 2 → Enter branch name: feat/recursion-advanced
Agent creates branch and switches IDE to feat/recursion-advanced

@code-agent
Topic: Advanced Recursion
Transcript: [video content]
Folder: 8 Recursion (append)

@commit-agent
Topic: Advanced Recursion
Files changed: 8 Recursion/ +3 files
AI generation %: 85

@pr-agent
You choose: Option 1 → Creates PR #14
```

**Phase 2: Complete & Merge**
```
[Satisfied with phase 2]

gh pr merge 14 --squash
```

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
