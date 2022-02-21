# tests the solution with generated input and outpu files
# usaage: sh tst.sh path/to/folder
N=$(ls $1/in | wc -l)

i=1
while [ "$i" -lt "$N" ]; do
  cat "$1/in/input$i.txt" | python3 "$1/solution.py" > tmp.txt
  rst=$(cmp tmp.txt "./$1/out/output$i.txt")
  if [ ! -z "$rst" ]; then echo "Failed on test $i"; fi
  i=$((i+1))
done

rm -rf tmp.txt