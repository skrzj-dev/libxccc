# libxccc

Utility library providing common components for C

## General information

The project is a [proof of concept] of following idea: 
posibility of implementation high- level concepts in C.

Project provides commonly used components such as:

1. Generic type- safe collections: vector, pool, hash; memory allocation strategy possible to be selected at runtime.
2. Safe integer operations
3. Exception- like error handling
4. Toggleable runtime debug logs
5. Typesafe wrappers over standard memory management API
6. Boundary- safe memory abstractions for memory management 
7. String operations

## General requirements

Library expected to met following postulates:

### 1. Ergonomy
A functionality must be provided with minimal "noise" (and it's C we're talking about)

### 2. Usage
Usage of a component must rely on regular C syntax.

### 3. Dependencies
- The only external dependency for components is libc.
- The only internal dependency is small core part of implementation.
- The only exception are standard system headers (if applicable for both windows and linux).
- Components relying on external dependencies must be optional.
- Components relying on internal dependencies other than the core part must be optional.

### 4. Reliability
Component must provide, if possible:
- Type safety at compilation time
- Boundary checking at runtime
- Handling null and invalid parameters at runtime (component must not crash context in which it is called)

### 5. Tested
All components must be covered at least with a functional test.

### 6. Performance
Expected performance no worse than high- level reference (eg. for collections - corresponding STL collection)

### 7. Modularity
Project expected to be highly modularized. 
The granularity is expected to be 1 component + core part.
The exception are optional components where granularity is expected to be 1 component + dependency + core part.

### 8. Portability
-  Implementation must be possible to compile with restrictive compilation flags.
-  Implementation must be possible to be used with C++ compiler
-  Implementation rely only on standard compiler features (not extensions), standard C syntax and code written by a developer.
-  Implementation compatible with ANSI C C90; there may be optional features for C99.
-  Implementation does not rely on system- specific features or platform- specific features.

### 9. Strict namespacing
-  Strict naming convention must prevent global namespace from being polluted with random identifiers.
-  All identifiers in library start with library prefix.
-  Components provide own unique name prefixes.

## Components:

### Common

General purpose utilities

| Component name in code |  Description                                      | State               | Stable API | Tests            |
| ---------------------- | ------------------------------------------------- | ------------------- | ---------- | ---------------- |
| xc_mem                 | typesafe wrappers over libc mem operations        | Done                | yes        | functional       |
| xc_err                 | exception- like error handling for C              | Done                | yes        | functional       |
| xc_p                   | struct wrappers over generic pointers             | Done                | yes        | N/A              |
| xc_rtdbg               | debug toggleable at runtime                       | Done                | yes        | none             |
| xc_si                  | safe integer operations                           | Done                | yes        | functional       |
| xc_hash                | hash functions                                    | Partial/ WIP        | yes        | none             |
| xc_rand                | randomization functions                           | Done                | yes        | none             |


Abstraction over memory management 

| Component name in code |  Description                                      | State               | Stable API | Tests            |
| ---------------------- | ------------------------------------------------- | ------------------- | ---------- | ---------------- |
| xc_amAlc               | stateful allocator operating on raw bytes         | Done                | no         | functional       |
| xc_amMdl               | access to objects in allocated memory block       | Done                | no         | functional       |
| xc_amOp                | operations over objects in allocated memory block | Done                | no         | functional       |

Available allocators:

- Sequential data, grow / shrink, capacity changes by multipication of 2
- Sequential data, grow / shrink, capacity changes by constant size step 
- Sequential data, fixed constant capacity

### String

char- based string objects

| Component name in code |  Description                                      | State               | Stable API | Tests            |
| ---------------------- | ------------------------------------------------- | ------------------- | ---------- | ---------------- |
| xc_strD                | dynamic capacity string (growing)                 | WIP (0.1)           | no         | none             |
| xc_strT                | static capacity string (compilation time fixed)   | TODO                |            |                  |
| xc_strpr               | stateless string parsing                          | TODO                |            |                  |


### Generic Collections

Generic typesafe data collections

| Component name in code |  Description                                      | State               | Stable API | Tests            |
| ---------------------- | ------------------------------------------------- | ------------------- | ---------- | ---------------- |
| xc_tcVectorD           |  dynamic capacity vector (growing)                |  Done               | yes        | functional       |
| xc_tcVectorS           |  static capacity vector (runtime fixed capacity)  |  Done               | yes        | functional       |
| xc_tcVectorT           |  static capacity vector (compilation time fixed)  |  Done               | yes        | functional       |
| xc_tcPoolD             |  dynamic pool                                     |  TODO               |            |                  |
| xc_tcPoolS             |  static pool (runtime fixed capacity)             |  DONE               | yes        | functional       |
| xc_tcPoolT             |  static pool (compilation time fixed capacity)    |  TODO               | yes        | functional       |
| xc_tcSelectD           |  dynamic hashtable/pool                           |  TODO               |            |                  |
| xc_tcSelectS           |  static hashtable/pool (runtime fixed capacity)   |  TODO               |            |                  |
| xc_tcArray2DS          |  static array 2D (runtime fixed capacity)         |  TODO               |            |                  |
| xc_tcArray2DD          |  dynamic array 2D (growing / shrinking)           |  TODO               |            |                  |


### Specialized Collections

Specialized data collections

| Component name in code |  Description                                       | State               | Stable API | Tests            |
| xc_scBitVectD          | dynamic bit vector (runtime growing)               | TODO                |            |                  |
| xc_scBitVectS          | statiic bit vector (runtime fixed)                 | TODO                |            |                  |
| xc_scBitVectT          | static bit vector (compilation time fixed)         | TODO                |            |                  |
| xc_scStrBlobT          | static bit vector (compilation time fixed)         | TODO                |            |                  |
| xc_scStrBlobS          | static bit vector (runtime fixed)                  | TODO                |            |                  |


### Optional

| Component name in code |  Description                                       | State               | Stable API | Tests            |
| xc_fs                  | abstraction over elementary file operations        | TODO                |            |                  |
| xc_ssrw                | unified stream- liike API for both string/ file    | TODO                |            |                  |


### Test

Test- related utilities

| Component name in code |  Description                                      | State               | Stable API | Tests            |
| ---------------------- | ------------------------------------------------- | ------------------- | ---------- | ---------------- |
| xc_test                | Simple API for testing (C)                        | Done/ discontinued  | yes        | none             |
| xc_test_benchmark      | API for microbenchmarking (C)                     | Done/ discontinued  | yes        | none             |
| xcc_test2              | API for testing (C++)                             | Done/ discontinued  | yes        | none             |
| xcc_test_benchmark     | API for microbenchmarking (C++)                   | Done/ discontinued  | yes        | none             |

