
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -c -o exercise/encode_exercise.o exercise/encode_exercise.c && \
gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -o check_exercise exercise/check_exercise.c exercise/encode_exercise.o

#gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -c -o exercise/encode_exercise_answer.o exercise/encode_exercise_answer.c && \
#gcc -fno-stack-protector -pedantic -ansi -Wall -Wextra -O0 -fno-inline-functions -o check_exercise_answer exercise/check_exercise.c exercise/encode_exercise_answer.o

