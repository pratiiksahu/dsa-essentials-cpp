# Learning Workflow for DSA Mastery

This document describes how to use the two agents to fast-track your DSA learning while maintaining depth.

## Workflow Overview

**When you finish a video lesson:**
1. Send me the **transcript** (or summary)
2. Specify the **topic name** and any **special focus areas**
3. Tell me if you need a **new folder** or want to **append to existing folder**

I will then invoke two agents:

### Agent 1: Code Generation Agent
**Input:**
- Video transcript / content summary
- Topic name (e.g., "Recursion", "LinkedList Basics")
- Folder decision: new folder (e.g., "8 Recursion") or existing folder

**Output:**
- One or more `.cpp` files with:
  - Clean, well-commented implementation
  - Beginner-friendly code matching your repo style
  - Examples from the video
  - Practice problems (if relevant)

**File placement:**
- New folder: Creates `N TopicName/` and adds files
- Existing folder: Appends to the specified folder with proper naming

### Agent 2: Notes Generation Agent
**Input:**
- Same transcript / content summary
- Concept focus areas

**Output:**
- Single file: `copy-notes-to-notion.md` (overwrites previous)
- Contains:
  - **Concept Explanation** — What is this, why does it matter?
  - **Intuition & Walkthrough** — Step-by-step with examples
  - **Complexity Analysis** — Time and space complexity
  - **Key Takeaways** — Important points to remember
  - **Common Mistakes** — Things to watch out for
  - **Practice Problems** — Related problems to try
  - **Code References** — Links to files in your repo

**Format:**
- Markdown (Notion-ready)
- Copy entire content → paste into your Notion workspace

---

## Example Session

### You provide:
```
Topic: Recursion Basics
Transcript: [video transcript or summary]
Folder: New (8 Recursion)
```

### Agent 1 generates:
```
8 Recursion/
├── 01_factorial_recursion.cpp
├── 02_power_function.cpp
├── 03_fibonacci_recursive.cpp
└── ... more files
```

### Agent 2 generates:
```
copy-notes-to-notion.md
```
(Contains full notes on recursion, ready to copy-paste into Notion)

---

## File Naming Conventions

- `NN_topic_description.cpp` (e.g., `01_factorial_recursion.cpp`)
- Follow existing numbering in each folder
- Each file = one concept or problem

---

## .gitignore Handling

**`copy-notes-to-notion.md` is git-ignored** because:
- It's a temporary file for your personal note-taking
- You copy-paste it into Notion, then it can be deleted
- Prevents clutter in your repository

---

## Progression Tracking

After each session, I'll note:
- ✅ Topic completed
- 📚 Next recommended topic (following course progression)
- 🔗 Dependencies or related concepts

This keeps you on track through the full DSA roadmap.

---

## Quick Start

Ready to begin? Provide:
1. Topic name
2. Transcript or content summary
3. Folder preference (new or existing)

I'll handle the rest! 🚀
