class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words) 
    {
        vector<int> result;
        if(words.size() == 0 || s.length()== 0) {return result;}
        unordered_map<string,int> umap;
        for(int i = 0; i < words.size(); i++)
        {
            if(umap.find(words[i])==umap.end())
                umap.insert(make_pair(words[i],1)); //Insert the words into a hash table.
            else{
                umap.find(words[i])->second++;
            }    
        }
        int totalSize = words[0].length() * words.size();
        //cout << "Total size is " << totalSize << endl;
        for(int i = 0; i < s.length()-totalSize+1;i++)
        {
            //cout << "i is " << i << " Substring is " << s.substr(i,totalSize) << endl;
            int x = 0;
            string iterator = s.substr(i,totalSize);
            bool isSubstring = false;
            unordered_map <string,int> Checker;
            while(umap.find(iterator.substr(x,words[0].length()))!=umap.end())
            {
                //cout << "Found: "<< iterator.substr(x,words[0].length()) << "  ";
                if(Checker.find(iterator.substr(x,words[0].length()))==umap.end())
                {
                    Checker.insert(make_pair(iterator.substr(x,words[0].length()),1));
                }
                else
                {
                    auto temp = Checker.find(iterator.substr(x,words[0].length()));
                    //cout << " FOR THE x" << temp->second+1 << " TIME! ";
                    if(temp->second < umap.find(iterator.substr(x,words[0].length()))->second)
                    {
                        temp->second++;
                    }
                    else{
                        isSubstring = false;
                        break;
                    }
                }
                x+=words[0].length();
                if(x == iterator.length())
                {
                    isSubstring = true;
                    break;
                }
            }
            //cout << endl;
            if(isSubstring)
                result.push_back(i);
        }
        return result;
    }
};