# Building problem due to FC library

## If, when compiling the blockchain on Ubuntu 18.04, you experience the following problem:

```console
Scanning dependencies of target test_cypher_suites
Scanning dependencies of target eosio_chain
[ 90%] Building CXX object libraries/fc/test/crypto/CMakeFiles/test_cypher_suites.dir/test_cypher_suites.cpp.o
[ 90%] Building CXX object libraries/chain/CMakeFiles/eosio_chain.dir/merkle.cpp.o
[ 90%] Building CXX object libraries/chain/CMakeFiles/eosio_chain.dir/name.cpp.o
[ 90%] Building CXX object libraries/chain/CMakeFiles/eosio_chain.dir/transaction.cpp.o
[ 90%] Linking CXX executable test_cypher_suites
/usr/lib/x86_64-linux-gnu/libcrypto.a(threads_pthread.o): In function `fork_once_func':
(.text+0x16): undefined reference to `pthread_atfork'
clang: error: linker command failed with exit code 1 (use -v to see invocation)
libraries/fc/test/crypto/CMakeFiles/test_cypher_suites.dir/build.make:113: recipe for target 'libraries/fc/test/crypto/test_cypher_suites' failed
make[2]: *** [libraries/fc/test/crypto/test_cypher_suites] Error 1
CMakeFiles/Makefile2:783: recipe for target 'libraries/fc/test/crypto/CMakeFiles/test_cypher_suites.dir/all' failed
make[1]: *** [libraries/fc/test/crypto/CMakeFiles/test_cypher_suites.dir/all] Error 2
make[1]: *** Waiting for unfinished jobs....
```

## You need to apply the provided patch to fix it

Just go to the patch directory and run the patcher:

```console
cd wax-blockchain/patches/fc
./apply_patch.sh
```

After patching the library, you can resume your building process

```console
cd wax-blockchain/build
make -j $(nproc)
```
