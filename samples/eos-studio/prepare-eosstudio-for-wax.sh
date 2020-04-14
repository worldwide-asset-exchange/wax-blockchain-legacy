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

#!/usr/bin/env bash

CDT_VERSION=1.6.1
EOS_VERSION=1.8.4
WAX_SYSTEM_CONTRACTS=wax-1.7.0-1.2.0
WAX_DEV_DOCKER=wax-$CDT_VERSION-1.2.0

# Get/prepare docker images
docker pull waxteam/dev:$WAX_DEV_DOCKER
docker tag waxteam/dev:$WAX_DEV_DOCKER eostudio/eosio.cdt:v$CDT_VERSION
docker tag waxteam/dev:$WAX_DEV_DOCKER eostudio/eos:v$EOS_VERSION

# Get system contracts
git clone -b $WAX_SYSTEM_CONTRACTS https://github.com/worldwide-asset-exchange/wax-system-contracts.git ~/.eosio/contracts

echo
echo "EOS Studio was prepared for WAX, now you can execute it"



