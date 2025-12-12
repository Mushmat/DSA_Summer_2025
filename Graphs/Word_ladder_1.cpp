// Word Ladder 1
// given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lenghts. Find the lenght of the shortest transformation sequence from startWord to targetWord. 
// a word can only consist of lowercase characters
// one one letter can be changed in each transformation
// each trandsformed word must exist in the wordList incl targetWord
// startWord may or may not be the part of wordList

// eg if the startWOrd is hit, and endWord is Cog
// hit -> hot -> dot -> dog -> cog
// assuming all words except hit as there in the word list
// then 4 transformations were done and sequence length is 5

// return 0 if not possible
// wordList = [hot, dot, dog, lot, log, cog]
// to change hit, we can change it to ait, bit, cit, dit .... zit
// h can be changed to a to z
// smrly i can be changed to a to z
// when we change i to o, hot exists in the wordList
// smrly t can also be changed from a to z
// This is the brute force
// we will change each character from a to z to check whether it is in the wordList or not
// and count the min length 
// keeping hit as level 1, level 2 will be ait, bit, cit....zit
// but since none of these are in wordList, remove
// now hat, hbt, hct...hzt will be in level 2
// in these, hot does exist in the wordList
// therefore from hit we can go to hot
// hot is now on level 2, but also check by replacing t. hia, hib....hiz. (since no word is there in wordList, remove)
// now again do this with hot at level 2, going to level 3
// this can be repeated until the targetWord is reached
// since levels are used. the level at which the word appears, the length of the shortest sequence
// therefore use BFS Traversal

// start with a queue
// put startWord, 1 in the queue (hit, 1)
// take the word out from queue and then
// take a set DS to store the wordList so that searching in wordList is easier (less time)
// check all ait bit .. zit
// then check hat, hbt.. hot... hzt
// hot exists, put that in the queue and increase level by 1. (hot,2)
// now we wont take hot in any other level (that is not repeat them since that will elongate the sequence unnecessarily)
// take the next from queue (hot, 2)
// again change first h, then o, then t
// we can go to (dot, 3) and (lot 3)
// no other transformation of hot is there
// pick dot, and try to change
// we can now put (dog, 4)
// pick (lot, 3) and we can put (log, 4)
// now pick (dog, 4) and we can put (cog, 5)
// hence we got the ans

// once we reach cog, the word list has already been emptied. now next time we take out from queue, it will get COG, but cog is now not in wordlist
// as already encountered
// hence we wont need that path 

int wordLadderLength(string startWord, string targetWord, vector<string> & wordList){
    queue<pair<string int>> q;
    q.push({startWord, 1});
    unordered_set<int> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord) return steps;

        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){ // means the word exists
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

// TC: the two for loops run for Word Length * 26, and while loop runs for the number of words in the wordList + 1 that is N times
// therefore, TC: N x word.length x 26 * logn (logn is from set)