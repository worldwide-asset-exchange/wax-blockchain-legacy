# WAX-BLOCKCHAIN

## Welcome to the WAX Source Code Repository!
This software enables businesses to rapidly build and deploy high-performance and high-security blockchain-based applications.

The Worldwide Asset eXchange™ (WAX) is a purpose-built blockchain and protocol token designed to make e-commerce transactions faster, easier, and safer for all participants. The WAX Blockchain mainnet uses Delegated Proof of Stake (DPoS) as its consensus mechanism and is fully backward compatible with EOS. The custom features and incentive mechanisms developed by WAX are designed to optimize the blockchain’s usability in e-commerce, and encourage voting on guilds and proposals.

WAX is creating a suite of blockchain-based tools upon which dApps, marketplaces, and native non-fungible tokens (NFTs) are built. These tools include services to support e-commerce operations such as an interactive block explorer, wallet, SSO and OAUTH, item creation, an RNG service, interactive item viewers, marketplace creation, and more. The resulting technology is a blockchain architecture that is extremely fast (500 millisecond block times), fee-less for customers and less expensive for developers, and leverages voting rewards to incentivize participation in the selection of block producers and proposals.

### Some of the features of WAX Blockchain include:
1. [Token Swap in conjunction with Genesis Block Member Rewards](https://wax.io/blog/introducing-the-genesis-block-member-program-join-and-receive-daily-token-rewards-for-3-years)
2. [Earning staking rewards](https://wax.io/blog/earn-more-wax-introducing-wax-block-rewards-staking-and-voting-guilds-and-more)
3. [Incentives and mechanics to address voter apathy](https://wax.io/blog/staking-and-voting-on-wax-a-technical-deep-dive?)
4. [Random Number Generator Native Blockchain Service](https://wax.io/blog/how-the-wax-rng-smart-contract-solves-common-problems-for-dapp-developers)
5. [WAX Account - Account Creation, Voting, Token Swap, and Balances](https://wax.io/blog/a-sneak-peek-of-wax-account-features)
6. [Integrated with the OPSkins customer base (and other reasons to run dApps on WAX)](https://wax.io/blog/the-top-10-reasons-to-run-dapps-on-wax)

These features are in addition to the benefits you will find on [EOSIO](https://wax.io/blog/the-top-10-reasons-to-run-dapps-on-wax). The WAX Blockchain is a variant of EOSIO v1.6.1

WAX is released under the open source MIT license and is offered “AS IS” without warranty of any kind, express or implied. Any security provided by the WAX software depends in part on how it is used, configured, and deployed. EOSIO is built upon many third-party libraries such as WABT (Apache License) and WAVM (BSD 3-clause), which are also provided “AS IS” without warranty of any kind. Without limiting the generality of the foregoing, WAX makes no representation or guarantee (and disclaims all implied warranties and guarantees) that WAX or any third-party libraries will perform as intended or will be free of errors, bugs or faulty code. Both may fail in large or small ways that could completely or partially limit functionality or compromise computer systems. If you use or implement WAX, you do so at your own risk. In no event will WAX be liable to any party for any damages whatsoever, even if it had been advised of the possibility of damage.

There is no public testnet running currently.
If you have previously installed wax-blockchain, please run the eosio_uninstall script (it is in the directory where you cloned wax-blockchain).
Right now we are not providing pre-compiled packages, so you have to compile the source code and after that, install it with the following instructions:

```
$ git clone https://github.com/worldwide-asset-exchange/wax-blockchain.git
$ cd wax-blockchain
$ git submodule update --init --recursive
$ ./eosio_compile.sh
$ sudo ./eosio_install.sh
```

### Supported Operating Systems
EOSIO currently supports the following operating systems:
- Amazon 2017.09 and higher
- Centos 7
- Fedora 25 and higher (Fedora 27 recommended)
- Mint 18
- Ubuntu 16.04
- Ubuntu 18.04
- MacOS Darwin 10.12 and higher (MacOS 10.14.x recommended)

### Resources
- [Website](https://wax.io)
- [Blog](https://wax.io/blog)
- [Community Telegram Group](https://t.me/wax_io)
- [White Paper](https://wax.io/uploads/WAX_White_Paper.pdf)

### License
[MIT](https://github.com/worldwide-asset-exchange/wax-blockchain/blob/master/LICENSE)

