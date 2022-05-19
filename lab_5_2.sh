#!/bin/bash

symbolic_links=$( find $1 -type l -exec sh -c 'file -b "$1" | grep -q ^broken' sh {} \; -print | wc -w)
echo $symbolic_links