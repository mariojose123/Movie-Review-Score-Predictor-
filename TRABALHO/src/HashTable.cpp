#include "HashTable.h"
#include "WordEntry.h"

/* HashTable constructor
*  input s is the size of the array
*  set s to be size
*  initialize array of lists of WordEntry
*/
HashTable::HashTable (int s) 
{
	hashTable= new list<WordEntry>[s];
}


/* computeHash
*  return an integer based on the input string
*  used for index into the array in hash table
*  be sure to use the size of the array to 
*  ensure array index doesn't go out of bounds
*/
int HashTable::computeHash(string s) {
 	int hash=0;
    /* TODO: implementar funcao de hash */
    for(int i = 0;i<s.size();i++){
        hash = (31*hash + s[i]) % 20000;
    }
    return hash;
}


/* put
*  input: string word and int score to be inserted
*  First, look to see if word already exists in hash table
*   if so, addNewAppearence with the score to the WordEntry
*   if not, create a new Entry and push it on the list at the
*   appropriate array index
*/
void HashTable::put(string s, int score) {
 	int hash=computeHash(s);
 	if(contains(s)){
 		for(auto &x : hashTable[hash]){
 			if(s.compare(x.getWord())==0){
 				x.addNewAppearance(score);
 			}
 		}
 	}
 	else{
 		WordEntry word=WordEntry(s,score);
 		hashTable[hash].push_back(word);
 	}
}

/* getAverage
*  input: string word 
*  output: the result of a call to getAverage()
*          from the WordEntry
*  Must first find the WordEntry in the hash table
*  then return the average
*  If not found, return the value 2.0 (neutral result)
*/

double HashTable::getAverage(string s) {
	int hash=computeHash(s);
	if(contains(s)){
		for(auto &x: hashTable[hash]){
			if(s.compare(x.getWord())==0){
				return x.getAverage();
			}
		}
	}
	else{
		return 2;
	}

}
/* contains
* input: string word
* output: true if word is in the hash table
*         false if word is not in the hash table
*/
bool HashTable::contains(string s) {
  int hash=computeHash(s);
  for(auto &x: hashTable[hash]){
  	if(s.compare(x.getWord())==0){
  		return true;
  	}
  }
  return false;
}

