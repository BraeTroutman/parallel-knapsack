#!/bin/bash

BASELINE=$(./original 1000 100000)
echo $BASELINE

ARRAY=()
for p in {1..22}
do
  ARRAY+=$(./original 1000 100000 $p)
done

echo ${ARRAY[1]}

