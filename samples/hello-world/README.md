# Hello World sample

## The idea of this sample is to show how to build and deploy a simple smart contract project.

### Requirements
- docker, installed and configured to run without sudo
- make
- Your WAX account and its private key (to deploy the contract)

### Build and deploy

For building and deploying the contract you are going to use the *make* utility. The syntax is:

```
$ make [ build |

         test CONTRACT_ACCOUNT=<the account used to deploy the contract> |

         clean |

         create-key |

         create-account WAX_ACCOUNT=<an already created account (in WAX portal)>
                        WAX_PRIVATE_KEY=<the WAX account private key>
                        CONTRACT_ACCOUNT=<the account name to be created>
                        PUBLIC_KEY=<the public key of the new account> |

         deploy CONTRACT_ACCOUNT=<account used to deploy>
                CONTRACT_PRIVATE_KEY=<the account private key>
                [NODEOS_URL=<deployment URL>] ]
```

#### Notes:
- The building process uses our [development image](https://hub.docker.com/r/waxteam/dev) from docker hub.
- Be aware that you need:
-- to build your contract first in order to deploy it.
-- to deploy your contract first in order to test it.
- CONTRACT_ACCOUNT parameter is mandatory to deploy the contract.
- CONTRACT_PRIVATE_KEY parameter is mandatory to deploy the contract. It's the associated private key of the contract account.
- NODEOS_URL parameter is optional, its default value is https://chain.wax.io/

#### Example:
```
# To do this example, you will need a WAX Blockchain account and know your private key for it.
# Create one at https://account.wax.io/
# Note: You will need sufficient WAX on your account to buy 32 KB of RAM and to stake 1 WAX toward
# CPU and NET for your contract's account creation.

# Download the code
git clone https://github.com/worldwide-asset-exchange/wax-blockchain.git
cd wax-blockchain/samples/hello-world

# Build the smart contract
make build

# Create a pair of private/public keys for your contract account (save the results in
# a safe place, they are going to be printed on the screen)
make create-key

# Create an account for your contract
make create-account WAX_ACCOUNT=foocreator WAX_PRIVATE_KEY=<private key for your WAX account> CONTRACT_ACCOUNT=foo CONTRACT_PUBLIC_KEY=<public key from 'create-key'>

# Deploy the smart contract to the mainnet
make deploy CONTRACT_ACCOUNT=foo CONTRACT_PRIVATE_KEY=<private key from 'create-key'>

# Test your deployed contract
make test CONTRACT_ACCOUNT=foo
```
