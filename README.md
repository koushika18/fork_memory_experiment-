# Fork Memory Experiment

## Objective

The objective of this experiment is to understand what happens to variables and memory when a parent process creates a child process using `fork()`.

## Experiment

A C program was created in which a variable `value` is initialized to 100 before calling `fork()`.

After `fork()`:

- The parent process keeps the value as 100.
- The child process changes its copy of the value to 200.
- Both processes have their own process IDs.
- The variable has the same virtual memory address in both processes.

## Sample Observation

Before fork:

- Value = 100

Parent process:

- Value = 100
- Address of value = same virtual address

Child process:

- Value = 200
- Address of value = same virtual address

## Explanation

When `fork()` is called, the child process receives a copy of the parent's address space.

The parent and child therefore have independent copies of variables.

If the child modifies a variable, the parent's copy is not changed.

Linux uses a mechanism called **Copy-on-Write (COW)**. Initially, the parent and child can share the same physical memory pages. When one process modifies a page, the operating system creates a separate copy for that process.

Therefore, even though the virtual address printed for `value` is the same in both processes, the parent and child do not share the same variable after modification.

## Conclusion

The fork memory experiment demonstrates that a child process created using `fork()` gets its own logical copy of the parent's memory. Changes made by the child do not affect the parent's variables.
