#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <fstream>
#include <ext/hash_map>
#include "cppcommon/str_functs.h"
#include "cppcommon/vec_functs.h"
#include "cppcommon/logger.h"
#include "globals.h"


namespace CppJieba
{
    using namespace CPPCOMMON;
    using namespace std;
    using __gnu_cxx::hash_map;
    typedef uint16_t ChUnicode;
    typedef hash_map<ChUnicode, struct TrieNode*> TrieNodeHashMap;

    struct TrieNode
    {
        TrieNodeHashMap hmap;
        bool isLeaf;
    };

    class Trie
    {
        private:
            TrieNode* _root;
        public:
            Trie();
            ~Trie();
            bool init(const char* const filepath = DICT_FILE_PATH);
            bool destroy();
            void display();
            bool find(const ChUnicode* chUniStr, size_t len);
        private:
            void _display(TrieNode* node, int level);
            bool _insert(const ChUnicode* chUniBuf, size_t len);
    };
}

#endif
