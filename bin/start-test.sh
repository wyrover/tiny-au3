#!/bin/bash

. clean.sh

../source/tiny-au3 -l debug1.log -i ../tests/assignment.au3
../source/tiny-au3 -l debug2.log -i ../tests/operator.au3
