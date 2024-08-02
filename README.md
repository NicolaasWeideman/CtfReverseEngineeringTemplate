# Description
This CTF reverse engineering challenge template creates challenges if the following format:
```bash
$ ./challenge
usage: ./challenge guess
$ ./challenge asdf
Incorrect
$ ./challenge <correct flag>
Correct: <correct flag>
```
The flag is encoded using the `encode(...)` function in  `./src/encode.c`.
The flag is stored *pre-encoded* in the `challenge` binary.
(So, the plain-text flag doesn't exist in the binary)
When running `./challenge`, the user input is encoded in the same way (using `encode(...)`).
The encoded user input (`guess`) is then compared against the encoded flag.
If these are equal, the `Correct:` message is printed, otherwise `Incorrect`.
NOTE: You have to ensure that the only user input that can be encoded to the encoded flag, is the flag itself.



# Creating a Challenge
## STEP 1
In file: `./src/encode.c`
Change the line:
`unsigned int encoded_guess_len = guess_len; /* CHANGE THIS */`
to calculate the length of your encoded guess.
It's also fine to keep to keep this line as it is


## STEP 2
Now, you need to perform the encoding.
The default loop:
```C
for (i = 0; i < guess_len; i++) {
    encoded_guess[i] = guess[i];
}
```
does not encode the `guess`.
It populates the bytes of `encoded_guess` with the bytes of `guess`.
Afterwards, `encoded_guess` will be the same as `guess`.
(I.e. it copies `guess` to `encoded_guess`)

You should change the loop such that every byte `encoded_guess[i]` is a transformation of one (or more) bytes of `guess`.
See the `./examples/` for insipiration.

## STEP 3
Create the challenge!
Run `bash ./create_challenge.sh <flag>`
(Replace `<flag>` with your flag)
First, this will compile the program `./driver_encode`.
This is a separate program that will pre-encode your flag.
Second, it will compile your `./challenge` program with your `encode(...)` function while adding the pre-encoded flag.

## STEP 4
The `./challenge` binary contains your challenge.
Send it to someone!

# Exercise:
Update `./exercise/encode_exercise.c` to implement [ROT13](https://en.wikipedia.org/wiki/ROT13).
Any alphabet character should be offset with 13:
```
A->N, B->O, ..., Z->M
a->n, b->o, ..., z->m
```
Any non-alphabet character should not be changed:
```
1->1, 2->2,
.->., _->_
```
Then, build the exercise:
`bash create_exercise.sh`
This will compile the binary `./check_exercise` with your modified `./exercise/encode_exercise.c`
You can run `./check_exercise` to see if you implemented it correctly.
