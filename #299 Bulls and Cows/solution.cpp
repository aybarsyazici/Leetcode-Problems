#include <map>

struct Storage
{
    int value;
    int occurence;
    //vector<int> indexes;
    int index;
    
    Storage(int value, int index)
    {
        this->value = value;
        occurence = 1;
        //indexes.push_back(index);
        this->index = index;
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<Storage*> remainingSecrets;
        vector<Storage*> remainingGuesses;
        
        int bullCount = 0;
        int cowCount = 0;
        
        for(int i = 0; i < secret.length(); i++)
        {
            if(secret[i] == guess[i])
                bullCount++;
            else
            {
                if(secret[i] >= remainingSecrets.size())
                    remainingSecrets.resize(secret[i]+1);
                if(remainingSecrets[secret[i]] == nullptr)
                    remainingSecrets[secret[i]] = new Storage(secret[i],i);
                else
                {
                    remainingSecrets[secret[i]]->occurence++;
                    //remainingSecrets[secret[i]]->indexes.push_back(i);
                }
                remainingGuesses.push_back(new Storage(guess[i],i));
            }
        }
        

        for(int i = 0; i < remainingGuesses.size(); i++)
        {
            if(remainingSecrets.size() <= remainingGuesses[i]->value)
                continue;
            if(remainingSecrets[remainingGuesses[i]->value] != nullptr && remainingSecrets[remainingGuesses[i]->value]->occurence != 0)
            {
                cowCount++;
                remainingSecrets[remainingGuesses[i]->value]->occurence--;
            }
        }
        return std::to_string(bullCount)+"A"+std::to_string(cowCount)+"B";
    }
};