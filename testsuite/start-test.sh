#!/bin/bash

. clean.sh


run_test()
{
    TEST="$1"

    ../source/tiny-au3 -l $TEST.log -i $TEST.au3
}


run_test "assignment"
run_test "operator"
run_test "if-statement"
