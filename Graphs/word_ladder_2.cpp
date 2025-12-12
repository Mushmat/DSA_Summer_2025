// this is the extension of word_ladder_1.cpp
// the same problem, just that here we need to return all the valid smallest transformation sequences itself

// the algorithm this time will be slightly diff
// take a queue
// say beginWord = bat, endWord = coz
// wordList = [pat, bot, pot, poz, coz]
// sequence starts with bat for sure
// store bat in the queue as a list {bat}
// queue stores lists

// get the list with bat from the queue
// from bat, change b to pat (by changing bat to aat, bat, cat, dat...pat)
// however dont erase anything from wordList
// from bat, it can be changed to bot as well
// therefore bat can be changed to pat and bot
// therefore add in the queue a sequence {bat, pat}
// and also the sequence {bat, bot}
// now delete pat and bot from the wordList (that is, after all checks are done for a level)
// now take {bat, pat} out. 
// last guy here is pat
// now transform pat.
// pat can be converted to pot
// no other conversion of pat is possible. hence add {bat, pat, pot} but do not erase pat from wordList because one mroe sequence is pending in queue
// the entire level must be converted to erase from wordList
// pick out {bat, bot}
// bot can be converted to pot again
// therefore add {bat, bot, pot} and NOW ERASE pot from wordList
// if we had erased earlier, we would have never got pot again
// continue this until you reach coz

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList){

    unordered_set<string> st(wordList.begin(), wordList.eng());
    queue<vector<string>> q;
    q.push({beginWord});
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty()){
        vector<string> vec = q.front();
        q.pop();
        // erase all words that has been used in the previous levels to transform
        if(vec.size() > level){
            level++;
            for(auto it: usedOnLevel){
                st.erase(it);
            }
            usedOnLevel.clear();
        }

        string word = vec.back();
        if(word == endWord){
            //first sequence
            if(ans.size() == 0){
                ans.push_back(vec);
            }
            else if(ans[0].size() == vec.size()){
                ans.puch_back(vec);
            }
        }
        for(int i = 0; i < word.size(); i++){
            char original = word[i];
            for(char c = 'a'; c<= 'z'; c++){
                word[i] = c;
                if(st.count(word) > 0){
                    vec.push_back(word);
                    q.push(vec);
                    usedOnLevel.push_back(word);
                    vec.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;

}

// TC: not possible to predict, varies from example to example

