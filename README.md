Cpp-Project-Template
====================

Creating a (large scaling) C++ project from scratch can be cumbersome. The purpose of this project is to provide a bootstrap project layout which makes this task more easy. This includes:

 * CMake build system
 * Googletest C++ Testing which has no external dependencies and builds inside the project
 * LCOV Code Coverage Report using `-fprofile-arcs` and `-ftest-coverage` compiler features
 * Doxygen code documentation generation
 * Travis configuration for CI in case one doesn't want to use Jenkins CI
 * TODO: Extra branch with optional Qt4 dependency
 * TODO: Vagrant Box with Jenkins CI

## Acknowledgments

 * Some parts of this bootstrap project template are inspired by https://code.google.com/p/cpp-project- template/.
 * Adjusted CodeCoverage from to ignore thirdparty directory
