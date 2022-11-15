rm _ex3.txt ex3.txt
touch _ex3.txt
echo "Anvar Iskhakov" > _ex3.txt
chmod a-x _ex3.txt > ex3.txt
ls -li _ex3.txt >> ex3.txt
chmod uo+rwx _ex3.txt >> ex3.txt
ls -li _ex3.txt >> ex3.txt
chmod g+rwx _ex3.txt >> ex3.txt
ls -li _ex3.txt >> ex3.txt
echo "1) rw- rw- --- (only owner and group members can read and write to the file)
2) rwx rwx r-x (assigns read, write, execute permissions to user, group and assigns read, execute permissions to others)
3) rwx rwx rwx (anyone can do any type of operation of read, write or execute)" >> ex3.txt