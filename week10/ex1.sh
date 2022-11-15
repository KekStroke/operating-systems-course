rm _ex1_1.txt _ex1_2.txt _ex1.txt ex1.txt
touch _ex1.txt
echo "Anvar Iskhakov" > _ex1.txt
ln _ex1.txt _ex1_1.txt
ln _ex1.txt _ex1_2.txt
ls -i > ex1.txt