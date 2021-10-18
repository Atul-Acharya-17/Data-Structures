#pragma once

/*
    Only lower case letters are allowed to be stored in this example implementation
*/

struct Node {
	bool end;
    char val;
    Node* children[26];

    Node(){
        this->end = false;
        for (int i=0; i<26; ++i){
            this->children[i] = nullptr;
        }
    }
};