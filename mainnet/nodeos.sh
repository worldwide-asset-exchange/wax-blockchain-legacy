docker run -ti --sig-proxy=true --name nodeos \
    -v `pwd`/data:/root/.local/share/eosio/nodeos/data \
    -v `pwd`/config.ini:/opt/eosio/bin/data-dir/config.ini \
    -v `pwd`/genesis.json:/opt/eosio/bin/data-dir/genesis.json \
    -p 127.0.0.1:8888:8888 \
    -t waxteam/production nodeosd.sh --genesis-json data-dir/genesis.json || docker start -ai nodeos