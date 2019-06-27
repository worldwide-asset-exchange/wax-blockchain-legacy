CONTRACT_NAME=hello-world
BLOCKCHAIN_VERSION=wax-1.6.1-1.1.0
CONTAINER=${CONTRACT_NAME}-sample
WORK_DIR=/opt/${CONTRACT_NAME}

rm build -rf
mkdir build

docker rm -f ${CONTAINER} > /dev/null

docker run \
    --user $(id -u):$(id -g) \
    -it -v $(pwd):${WORK_DIR} \
    --name ${CONTAINER} \
    -w ${WORK_DIR} \
    waxteam/dev:${BLOCKCHAIN_VERSION} \
    bash -c "cd build && cmake .. && make"

