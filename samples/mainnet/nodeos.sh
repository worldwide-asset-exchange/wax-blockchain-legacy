#!/usr/bin/env bash

# Home inside docker
NODEOS_HOME=/root/.local/share/eosio/nodeos

# WAX data folder root on the host running this docker image
HOST_WAX_HOME=`pwd`

docker run -t --sig-proxy=true --name nodeos \
    -v $HOST_WAX_HOME/data:$NODEOS_HOME/data \
    -v $HOST_WAX_HOME/config.ini:$NODEOS_HOME/config/config.ini \
    -v $HOST_WAX_HOME/genesis.json:$NODEOS_HOME/config/genesis.json \
    -p 127.0.0.1:8888:8888 \
    -p 9876:9876 \
    waxteam/production:v2.0.13wax03 \
    nodeos --genesis-json $NODEOS_HOME/config/genesis.json
