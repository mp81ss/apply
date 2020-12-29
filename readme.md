# Introduction
This is a 32-bit only implementation of the traditional *apply* function available in functional programming
It works on all i386 hardware/OS (windows/linux/bsd, etc.)
A header and an example file is provided too
# Notes
The library is a C89 library. To use the helper macro *APPLY*, a C99 compiler is required
To use the library, just assemble a single assembly file with asmc or masm
There is only a parameter you can pass when assembling: *APPLY_NESTING_LEVEL*
The default value of *APPLY_NESTING_LEVEL* is 16. BSS space is exactly anl*8+4, se bugs below
# Bugs/Limitations
No 64-bit is provided (and is not planned due to windows and linux mess on passing parameters in 64 bit mode)
The library is neither *reentrant* nor *thread-safe*
The functions that are passed to apply may not be static, especially if they take arguments
The nesting level is the number of nested apply calls permitted
pic/pie is not supported
