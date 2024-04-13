if test "$#" -ne 1; then
    echo "You need to give the flag as command line argument:"
    echo "bash $0 FLAG{this_is_the_flag}"
    exit
fi
FLAG=$1
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -c -o src/encode.o src/encode.c
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -o driver_encode src/driver_encode.c src/encode.o
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions $(./driver_encode "$FLAG") -o challenge src/challenge.c src/encode.o
