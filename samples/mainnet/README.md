Running a WAX node
===================

Review config.ini to adjust the configuration as needed (the provided example should be enough to run a full node with only the minimal plugins)
Use the nodeos script to launch a Docker container called 'nodeos', which is a full node, mounting the data directory, configuration file and genesis.json file.
```
$ docker pull waxteam/production:wax-1.8.1-1.0.0
$ ./nodeos.sh
```

Once nodeos is running you can use cleos.sh to validate everything is working as expected.
```
$ ./cleos.sh get info
```
