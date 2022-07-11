# PracticeCpp

Practicing some modern or advanced features and skills with some portable code snippets. Also collecting some best or good practices of cpp project.

# ## Content

- [X] singleton
- [X] lambda function
- [X] callback
- [X] chrono timer:  use \<chrono\> to implement a timer to compute the time of a program cost.
- [ ] diy: implement some features of cpp for study purpose

  - [ ] implementing smart ptr
    - [X] unique_ptr

## Build
### 3rd-party libraries
This project uses [catchorg/Catch2](https://github.com/catchorg/Catch2) as unittest framework, which is as a git submodule.

```
git clone --recurse-submodules https://github.com/charles-sun0v0/PracticeCpp 
```
Alternatively, the user could `git clone` this then `cd 3rdparty` and run `git submodule init && git submodule update` to fetch dependencies.

### build with CMake
This project uses modern CMake concepts which is target-based.

## Warning

The code is written for demonize or studying purpose without adequate tests. Therefore, it should not be applied to production directly.
