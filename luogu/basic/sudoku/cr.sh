g++ -o main.out main.cpp -O2 -Wall
if [ "$?" == 0 ]
then
    ./main.out < in.txt > out.txt
else
    echo "Compile Error!"
fi
