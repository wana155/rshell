#!/bin/sh

#Tests are unable to run in rshelL

echo Tests for '>'

ls>ls.txt
ls -a >ls.txt
cat ls.txt

who>w.txt;ls -a;test ls;
cat w.txt

echo Testing echo > e.txt
cat e.txt
