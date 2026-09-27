# Process Termination Message System - Flowchart

```text
                         ┌───────────────┐
                         │     START     │
                         └───────┬───────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Start Parent Process   │
                    │ Display Parent PID     │
                    └───────────┬────────────┘
                                │
                                ▼
                    ┌────────────────────────┐
                    │ Create 3 Child Processes│
                    │       using fork()      │
                    └───────────┬────────────┘
                                │
                                ▼
              ┌────────────────────────────────────┐
              │ Each child performs a different    │
              │ task                                │
              └──────────────────┬─────────────────┘
                                 │
                                 ▼
              ┌────────────────────────────────────┐
              │ Child 1 → exit(10)                 │
              │ Child 2 → exit(20)                 │
              │ Child 3 → terminate using SIGTERM  │
              └──────────────────┬─────────────────┘
                                 │
                                 ▼
                    ┌────────────────────────┐
                    │ Parent calls wait()    │
                    │ to collect child       │
                    │ termination status     │
                    └───────────┬────────────┘
                                │
                                ▼
                    ┌────────────────────────┐
                    │ Check termination type  │
                    │ WIFEXITED()             │
                    │ WIFSIGNALED()           │
                    └───────────┬────────────┘
                                │
                                ▼
                    ┌────────────────────────┐
                    │ Display child PID       │
                    │ Display exit status or  │
                    │ signal number           │
                    └───────────┬────────────┘
                                │
                                ▼
                    ┌────────────────────────┐
                    │ All children collected?│
                    └───────────┬────────────┘
                                │
                                ▼
                    ┌────────────────────────┐
                    │ No zombie processes     │
                    │ remain                  │
                    └───────────┬────────────┘
                                │
                                ▼
                         ┌───────────────┐
                         │      END      │
                         └───────────────┘
