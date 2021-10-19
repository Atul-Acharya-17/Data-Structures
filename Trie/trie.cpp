#include "node.h"
#include "trie.h"

#include <iostream>

using namespace std;

Trie::Trie(){
    this->root = new Node();
}

void Trie::insert(string word){

    for (int i=0; i<word.size(); ++i){
        if (!isalpha(word[i])){
            cout<<"Invalid Characters"<<'\n';
            return;
        }

        word[i] = tolower(word[i]);
    }

    Node* ptr = this->root;

    for (int i=0; i<word.size(); ++i){
        if (ptr->children[word[i] - 97] == nullptr){
            ptr->children[word[i] - 97] = new Node();
            ptr->children[word[i] - 97]->val = word[i];
        }

        ptr = ptr->children[word[i] - 97];
    }

    ptr->end = true;
}


bool Trie::search(string word){

    for (int i=0; i<word.size(); ++i){
        if (!isalpha(word[i])){
            cout<<"Invalid Characters"<<'\n';
            return false; 
        }

        word[i] = tolower(word[i]);
    }
    
    Node *ptr = this->root;

    for (int i=0; i<word.size(); ++i){
        if (ptr->children[word[i] - 97] == nullptr){
            return false;
        }
        ptr = ptr->children[word[i] - 97];
    }

    if (ptr->end) return true;

    return false;
}

void Trie::recursiveTraverse(Node *ptr, string word){

    if (ptr->end){
        cout << word << '\n';
    }

    for (int i=0; i<26; ++i){
        if (ptr->children[i] != nullptr){
            word.push_back(ptr->children[i]->val);
            recursiveTraverse(ptr->children[i], word);
            word.pop_back();
        }
    }
    return;

}

void Trie::traverse(){

    Node *ptr = this->root;
    
    string word = "";

    recursiveTraverse(ptr, word);
}

void Trie::prefix(string word){
    for (int i=0; i<word.size(); ++i){
        if (!isalpha(word[i])){
            cout<<"Invalid Characters"<<'\n';
            return; 
        }

        word[i] = tolower(word[i]);
    }

    Node *ptr = this->root;

    for (int i=0; i<word.size(); ++i){
        if (ptr->children[word[i] - 97] == nullptr) return;

        ptr = ptr->children[word[i] - 97];
    }

    recursiveTraverse(ptr, word);
}

string Trie::longestPrefix(){

    string prefix = "";

    Node *ptr = root;

    while (true){
        int count = this->countChildren(ptr);
        if (count == 1){
            for (int i=0; i<26; ++i){
                if (ptr->children[i] != nullptr){
                    ptr = ptr->children[i];
                    prefix.push_back(ptr->val);
                    if (ptr->end){
                        return prefix;
                    }
                    break;
                }
            }
        }

        else{
            return prefix;
        }
    }
}

void Trie::remove(string word){

    for (int i=0; i<word.size(); ++i){
        if (!isalpha(word[i])){
            cout<<"Invalid Characters"<<'\n';
            return;
        }

        word[i] = tolower(word[i]);
    }
    Node *ptr = this->root;
    int idx = 0;

    recursiveRemove(ptr, word, idx);

}

void Trie::recursiveRemove(Node *ptr, string word, int idx){
    if (idx == word.size() - 1){
        if (ptr->children[word[idx] - 97] == nullptr) return; // word doesnt exist

        if (!ptr->children[word[idx] - 97]->end) return; // word doesnt exist

        int count = this->countChildren(ptr->children[word[idx]-97]);

        ptr->children[word[idx] - 97]->end = false;

        if (count == 0){
            ptr->children[word[idx] - 97] = nullptr;
        }

        return;
    }

    if (ptr->children[word[idx] - 97] == nullptr) return; // word doesnt exist

    this->recursiveRemove(ptr->children[word[idx] - 97], word, idx + 1);

    int count = this->countChildren(ptr->children[word[idx] - 97]);

    if (count == 0 && !ptr->children[word[idx] - 97]->end){
            ptr->children[word[idx] - 97] = nullptr;
    }
    return;

}

int Trie::countChildren(Node* ptr){
    int count = 0;

    for (int i=0; i<26; ++i){
        if (ptr->children[i] == nullptr) continue;
        
        ++count;
    }

    return count;
}

Trie::~Trie(){
    Node *ptr= this->root;

    recursiveDelete(ptr);
    delete ptr;
    
}

void Trie::recursiveDelete(Node* ptr){
    for (int i=0; i<26; ++i){
        if (ptr->children[i] != nullptr){
            recursiveDelete(ptr->children[i]);
            delete ptr->children[i];
        }
    }
    return;
}