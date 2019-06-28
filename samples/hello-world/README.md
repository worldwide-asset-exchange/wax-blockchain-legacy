# Hello World sample

## The idea of this sample is to show how to build a simple smart contract project.

### Requirements
- docker, installed and configured to run without sudo
- make
- Your WAX account private key (to deploy the contract)

### Build and deploy

For building and deploying the contract you are going to use the *make* utility. The syntax is:

```
$ make [ build | clean | deploy CONTRACT_PRIVATE_KEY=<your contract private key> ]
```

Notes:
- The building process uses our (development image)[https://hub.docker.com/r/waxteam/dev] from docker hub.
- Be aware that you need to build your contract first in order to deploy it.
- CONTRACT_PRIVATE_KEY parameter is mandatory to deploy the contract.

