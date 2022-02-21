# zips testcase in/out files for specified problem path
# usaage: sh zip.sh path/to/folder
rm -rf $1/material.zip

cd $1

zip -r material.zip "in" "out"

