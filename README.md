# Reinventing the Wheel

Building a computer from NAND gates to an OS kernel in C.

## About

I'm Julian, and I'm a Java developer who realized I've been taking things like `new Object()`, garbage collection, and `Thread.start()` for granted for too long.

I just wanted to humble myself real quick.

This project is my attempt to rebuild computer science fundamentals from scratch — no frameworks, no heavy libraries. Just `stdio.h`, `stdlib.h`, and a lot of pointers.

The goal: **simulate everything**, from logic gates to process schedulers.

## Roadmap

### Phase 1: Hardware Abstraction Layer
- Logic gates (NAND, XOR, OR) using only bitwise operators
- Half-adder, Full-adder
- Simple ALU with opcodes and flags (Zero, Overflow)

### Phase 2: Memory Management
- Virtual RAM using a raw `char` array
- Custom `malloc`/`free` implementation (first-fit, best-fit)
- Paging, MMU simulation, and TLB behavior

### Phase 3: Process Management
- Process Control Block (PCB) implementation
- Context switching simulation
- Scheduler: Round Robin and MLFQ

### Phase 4: File System
- Disk simulation with Superblocks, Inodes, and Data Blocks
- Basic `open`, `write`, `read` operations

## Structure
```
.
├── src
│   ├── hal/         # Gates, ALU
│   ├── memory/      # Allocator, Paging
│   ├── process/     # Scheduler, PCB
│   └── fs/          # File system
├── include/
├── tests/
├── Makefile
└── README.md
```

## Status

Work in progress.
