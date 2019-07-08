#!/bin/bash
#source /etc/profile.d/modules.sh
if [ -f /etc/profile.d/modules.sh ]; then source /etc/profile.d/modules.sh ; else source /etc/profile.d/mpcdf_modules.sh; fi
set -ex

source ./ci_test_scripts/.ci-env-vars
module list
echo $1

make -j $1

