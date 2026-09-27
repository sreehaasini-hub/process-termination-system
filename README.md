# Process Termination Message System

## 1. Introduction

The Process Termination Message System is an Operating Systems project developed in C. It demonstrates how a parent process can monitor child processes and receive meaningful information when they terminate.

The system creates multiple child processes, assigns different tasks to each child, and uses the `wait()` system call to detect and collect child-process termination information.

## 2. Problem Statement

When a child process terminates, the parent process needs to know whether the process terminated normally or abnormally. It should also be able to identify the terminated process and obtain its exit status or the signal that caused its termination.

This project provides a mechanism for monitoring child-process termination and displaying meaningful termination messages to the parent process.

## 3. Objectives

* Create multiple child processes using `fork()`.
* Assign different tasks to each child process.
* Detect when child processes terminate.
* Use `wait()` to collect child termination status.
* Identify normally terminated processes.
* Identify processes terminated by signals.
* Display the PID of the terminated child.
* Display the child's exit status.
* Display the signal responsible for abnormal termination.
* Prevent terminated child processes from becoming zombie processes.

## 4. Technologies Used

* Programming Language: C
* Operating System: macOS / Unix-like environment
* Compiler: GCC
* System Calls and Functions:

  * `fork()`
  * `wait()`
  * `sleep()`
  * `exit()`
  * `kill()`
  * `getpid()`

## 5. System Calls and Functions

### fork()

`fork()` creates a new child process from the parent process.

### wait()

`wait()` makes the parent process wait for a child process to terminate and collects its termination status.

### exit()

`exit()` terminates a process and allows the process to return an exit status to its parent.

### kill()

`kill()` is used in this project to send `SIGTERM` to Child 3, demonstrating abnormal termination caused by a signal.

### getpid()

`getpid()` returns the process ID of the current process.

### WIFEXITED()

`WIFEXITED()` checks whether a child process terminated normally.

### WEXITSTATUS()

`WEXITSTATUS()` retrieves the exit status returned by a normally terminated child.

### WIFSIGNALED()

`WIFSIGNALED()` checks whether a child process was terminated by a signal.

### WTERMSIG()

`WTERMSIG()` returns the signal number that caused the child process to terminate.

## 6. Working of the System

The parent process starts and creates three child processes using `fork()`.

### Child 1

Child 1 performs a calculation task. After completing the task, it terminates normally with exit status `10`.

### Child 2

Child 2 performs a file-processing task. After completing the task, it terminates normally with exit status `20`.

### Child 3

Child 3 performs a monitoring task. It is then terminated using the `SIGTERM` signal to demonstrate abnormal termination.

### Parent Process

The parent calls `wait()` three times to collect all child processes.

For every terminated child, the parent displays:

* Child PID
* Termination type
* Exit status for normal termination
* Signal number for abnormal termination

Since the parent collects all three terminated children, they do not remain as zombie processes.

## 7. Program Flow

```text
Start
  |
  v
Create Parent Process
  |
  v
Create Child 1, Child 2 and Child 3
  |
  +------------------+------------------+
  |                  |                  |
  v                  v                  v
Child 1            Child 2            Child 3
Calculation        File Processing    Monitoring
  |                  |                  |
Exit(10)           Exit(20)          SIGTERM
  |                  |                  |
  +------------------+------------------+
                     |
                     v
              Parent calls wait()
                     |
                     v
          Collect termination status
                     |
                     v
          Check WIFEXITED / WIFSIGNALED
                     |
                     v
           Display PID and status
                     |
                     v
       All children collected
                     |
                     v
                    End
```

## 8. Sample Output

```text
Parent Process Started
Parent PID: 3307

Child 1 (PID 3311): Performing calculation task...
Child 2 (PID 3312): Performing file processing task...
Child 3 (PID 3313): Performing monitoring task...
Child 3: Terminating using SIGTERM.

--- Child Termination Detected ---
Terminated Child PID: 3313
Termination Type: Abnormal
Terminated by Signal: 15

Child 1: Task completed successfully.

--- Child Termination Detected ---
Terminated Child PID: 3311
Termination Type: Normal
Exit Status: 10

Child 2: Task completed successfully.

--- Child Termination Detected ---
Terminated Child PID: 3312
Termination Type: Normal
Exit Status: 20

All child processes have been collected.
No zombie processes remain.
```

## 9. Advantages

* Demonstrates process creation and termination.
* Shows how a parent monitors child processes.
* Handles both normal and abnormal termination.
* Provides meaningful termination information.
* Prevents zombie processes by collecting terminated children.

## 10. Conclusion

The Process Termination Message System successfully demonstrates child-process creation, execution, and termination monitoring in C.

The parent process uses `wait()` to collect the termination status of all child processes. The system distinguishes between normal termination and termination caused by a signal and displays the relevant PID, exit status, or signal number.

By collecting every terminated child process, the system also prevents zombie processes from remaining in the process table.
