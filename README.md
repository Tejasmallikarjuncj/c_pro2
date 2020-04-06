The file consist of two make file i.e mkfile.mk and mkfile2.mk and two main files.

The make file mkfile.mk is for encryption and mkfile2.mk is for decryption.

step for execution of code: 

step1:
make -f mkfile.mk
make -f mkfile2.mk

step2:
./encrypt

step3:
In the prompt type the file path to be encrypted
then enter the length of the key
then enter the key

The encrypted file will be saved in the text file encpt.txt in the same directory.

step4:
./decrypt

step5:
In the prompt type the path to be decrypted or encpt.txt
then enter the length
then enter the key

The decrypted file will be saved in the text file Decpt.txt in the same directory.
