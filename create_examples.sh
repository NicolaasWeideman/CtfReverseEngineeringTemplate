
for example in example_01 example_02 example_03; do
    gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -c -o ./examples/encode_$example.o ./examples/encode_$example.c && \
    gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -o driver_encode src/driver_encode.c ./examples/encode_$example.o && \
    gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions $(./driver_encode FLAG{$example}) -o challenge_$example ./src/challenge.c ./examples/encode_$example.o
done

gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -c -o examples/encode_demo.o examples/encode_demo.c && \
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -o driver_encode src/driver_encode.c examples/encode_demo.o && \
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions $(./driver_encode FLAG{usc_cyberfest}) -o challenge_demo src/challenge.c examples/encode_demo.o
