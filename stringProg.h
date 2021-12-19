//this function culculate the gimatria of word.
int gimatria(int src, int dest);
//this function return the index between the word end the text.
int endOfWord();
//this function check if to words have same gimatria.
void sameGim(int src, int gim);
//this function return the atbash value of specific char.
char cal_atbash(int ch);
//this function print the words with the same atbash values.
void atbash(int end, int src);
//this function check if the word contain specific char.
int charAt(char c, char arr[], int len, int count[]);
//this function restart the counter array.
void restart(int count[], int len);
//this function check if the word have same anagram.
int thisAnagram(int count[], int len);
//this function print word whith exactly same chars.
void angram(int end, int src);
//this function insert the input to array.
void insert();
