## Upgrade to 1.8.1-1.0.0
This document describes the WAX upgrade process for Guilds and Full Nodes from v1.5.2 to v1.8.1.

Upgrading to v1.8.1 brings us to a safer and more efficient blockchain. Due to breaking changes between v1.8.1 and previous versions, all node operators and producers are required to perform these steps to complete the system-wide upgrade to v1.8.1. Not doing so before the activation time of Aug 12 17:30 UTC will render your producer/full node unable to validate chain data and unusable post upgrade. Therefore, we strongly recommend performing this upgrade by this date.

### Steps To Upgrade to 1.8.1-1.0.0
The upgrade to 1.8.1 boils down to 3 key steps:
1. Upgrading your node's docker image to our 1.8.1-1.0.0 image, or replacing your nodeos binary with a self-compiled version from our 1.8.1-1.0.0 tag on Github.
2. Deleting (and optionally backing up) your old blockchain data.
3. Resyncing the blockchain

We explain these steps in some detail assuming that the node operator is using our ready to use docker images to run their node, similar to the setup explained here: [Mainnet full node example](https://github.com/worldwide-asset-exchange/wax-blockchain/tree/develop/samples/mainnet).
If you are running a self compiled version of the WAX node, the steps are similar, but you will be simply restarting your nodeos executable rather than restarting the docker image.

#### 1. Stop your WAX node
Terminate execution of your wax docker image.
```console
$ docker stop nodeos
```

#### 2. Backup and clear existing block data
This upgrade will require a full replay of historical block data. Therefore, the block and chain state data must be deleted prior to running the 1.8.1 docker image. To be on the safe side, backup your existing nodeos data folder. On the WAX docker image, this is the path mounted to /root/.local/share/eosio/nodeos/data. Assuming your host machine uses HOST_WAX_HOME as the mount path for the wax docker image, the following commands will prepare your data folder.
```console
# back up your data directory
$ tar -Szcvf data.tar.gz $HOST_WAX_HOME/data
# clear the block data and state
$ rm -rf $HOST_WAX_HOME/data/blocks/reversible
$ rm -rf $HOST_WAX_HOME/data/state
$ rm -rf $HOST_WAX_HOME/data/state-history
```

#### 3. Update the nodeos start script
Update the docker image referenced in your start script. Also, some paths have changed in our new docker image. You should overwrite the contents of your $HOST_WAX_HOME/nodeos.sh start up script similar to this:
```console
#!/usr/bin/env bash
 
# Home inside docker
NODEOS_HOME=/root/.local/share/eosio/nodeos

# Home on host machine
HOST_WAX_HOME=<Set this to the location of your working directory for your wax node docker image>
 
docker run -t --sig-proxy=true --name nodeos \
    -v $HOST_WAX_HOME/data:$NODEOS_HOME/data \
    -v $HOST_WAX_HOME/config.ini:$NODEOS_HOME/config/config.ini \
    -v $HOST_WAX_HOME/genesis.json:$NODEOS_HOME/config/genesis.json \
    -p 127.0.0.1:8888:8888 \
    -p 9876:9876 \
    -t waxteam/production:wax-1.8.1-1.0.0 \
    nodeos --genesis-json $NODEOS_HOME/config/genesis.json
```

#### 4. Prepare the node settings
In $HOST_WAX_HOME/config.ini, the following variables are deprecated and should be removed:
```console
bnet-endpoint
bnet-threads
bnet-connect
bnet-no-trx
```

#### 5. Start nodeos
```console
$ $HOST_WAX_HOME/nodeos.sh
```

#### 6. Validate the running version
Validate that we are running the expected version.
```console
$ docker exec nodeos nodeos --version
# Output should be:
wax-1.8.1-1.0.0
```

#### 7. Review log
Check out logs to verify that everything is fine.
```console
$ docker logs nodeos
# Should see several “Received block” type lines with increasing block numbers
```

#### 8. Allow the node to complete the full sync
It may take some time for your node to fully synchronize the full chain history.

### Upgrade Notes
For wallet, and explorer type application operators, transaction traces provided by the history_plugin and state_history_plugin are flattened. This may affect application logic that expects trace data to be provided in the old format. See [#7044](https://github.com/EOSIO/eos/pull/7044) and [#7108](https://github.com/EOSIO/eos/pull/7108) for more info.
