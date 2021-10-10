# Update
The initial status of repo has been moved to branch [recursive](../../tree/recursive)\
The master now has a version that **does not** support recursion but supports _pic/pie_ and is **both** *reentrant* and *thread-safe*  

# Introduction
This is a 32-bit only implementation of the traditional *apply* function available in functional programming\
It works on all i386 hardware/OS (windows/linux/bsd, etc.)\
A header and an example file is provided too

# Notes
The library is a C89 library. To use the helper macro *APPLY*, a C99 compiler is required\
To use the library, just assemble a single assembly file with asmc or masm\

# Bugs/Limitations
No 64-bit is provided (and is not planned due to windows and linux mess on passing parameters in 64 bit mode)\
The functions that are passed to apply may not be static, especially if they take arguments
