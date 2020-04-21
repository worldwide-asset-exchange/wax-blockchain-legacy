# WAX porting notes

## EOSIO 1.8 -> 2.0 update

In wax2.0 repository, EOSIO 2.0.4 was merged with WAX 1.8.4, with
necessary modifications.


The following files were taken from vanilla EOSIO as-is, because WAX
changes are not necessary:

```
libraries/testing/include/eosio/testing/tester.hpp
libraries/testing/tester.cpp
```

`scripts/eosio_build.sh`: `-r` option in wax-1.8.4 is setting
PUBLIC_ROOT_KEY, but it's not used in release binaries. Skipping in
wax-2.0.


`unittests/eosio_system_tester.hpp` line 415: set buyram sum to "0.5
WAX".




