#!/bin/bash

CC=gcc
FILES=src/*.c
OUTPUT="-o blackjack"

set -xe
$CC $FILES $OUTPUT
