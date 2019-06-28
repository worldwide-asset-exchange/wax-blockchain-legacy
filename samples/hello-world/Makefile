# Copyright (c) 2019, The WAX Team and respective Authors, all rights reserved.
#
# The MIT License
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

CONTRACT_NAME = helloworld
CONTRACT_ACCOUNT = ${CONTRACT_NAME}
BLOCKCHAIN_DEV_VERSION = wax-1.6.1-1.1.1
NODEOS_URL = https://chain.wax.io/
CONTAINER = ${CONTRACT_NAME}-sample
WORK_DIR = /opt/${CONTRACT_NAME}
DOCKER_COMMON = -v `pwd`:${WORK_DIR} --name ${CONTAINER} -w ${WORK_DIR} waxteam/dev:${BLOCKCHAIN_DEV_VERSION}
AS_LOCAL = --user $(shell id -u):$(shell id -g)
CLEOS=/usr/local/eosio/bin/cleos
CLEOSN=${CLEOS} -u ${NODEOS_URL}

.PHONY: build
build: dev-docker-stop
	@mkdir -p build
	docker run ${AS_LOCAL} ${DOCKER_COMMON} bash -c "cd build && cmake .. && make"

.PHONY: clean
clean:
	-rm -rf build

.PHONY: deploy
deploy: dev-docker-stop
ifndef CONTRACT_PRIV_KEY
	$(error CONTRACT_PRIV_KEY is undefined)
endif
	docker run ${DOCKER_COMMON} bash -c \
       "rm -f ~/eosio-wallet/${CONTRACT_NAME}.wallet && \
        ${CLEOS} wallet create -n ${CONTRACT_NAME} --to-console && \
        ${CLEOS} wallet import -n ${CONTRACT_NAME} --private-key ${CONTRACT_PRIV_KEY} && \
        ${CLEOSN} set contract ${CONTRACT_ACCOUNT} ${WORK_DIR}/build ${CONTRACT_NAME}.wasm ${CONTRACT_NAME}.abi"

.PHONY: dev-docker-stop
dev-docker-stop:
	@-docker rm -f ${CONTAINER}

# Useful for interactive docker work
.PHONY: dev-docker-stop
dev-docker-start: dev-docker-stop
	docker run -it ${DOCKER_COMMON} bash

